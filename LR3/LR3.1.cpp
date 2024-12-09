#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class Detail
{
protected:
    Detail() { cout << "класс Деталь создан" << endl; }
public:
    virtual ~Detail() { cout << "класс Деталь Удален" << endl; }

    virtual void info() const { cout << "Это класс деталь" << endl; }

    template<typename T>
    static T* create() {
        cout << "Создаем объект типа " << typeid(T).name() << endl;
        return new T();
    }
};

class Assembly : public Detail
{
protected:
    Assembly() { cout << "класс Сборка создан" << endl; };
public:  
    virtual ~Assembly() { cout << "Класс Cборка удален" << endl; }

    void info() const override { cout << "Это класс Сборка" << endl; }
    friend class Detail; 
};

template<typename T>
void create_and_collect(vector<Detail*>& storage)
{
    storage.push_back(Detail::create<T>());
}

int main()
{
    setlocale(LC_ALL, "rus");
    vector <Detail*> storage;   

    create_and_collect<Assembly>(storage);

    if (storage.empty()) {
        throw runtime_error("Контейнер пуст после создания объектов.");
    }
   
    for (const auto& obj : storage) {
        if (obj) {  
            obj->info();
        }
        else {
            throw runtime_error("Найден пустой указатель на объект.");
        }
    }

    for (auto& obj : storage) 
    {
        delete obj;
        obj = nullptr;
    }


    storage.clear();

}
