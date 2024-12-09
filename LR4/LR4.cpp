#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Human {
protected:
    int age;
    string Name;
    string sex;
public:
    Human(const int& age, const string& Name, const string& sex)
        : age(age), Name(Name), sex(sex) 
    {
        if (age <= 0 || age > 150)
        {
            throw range_error("Возраст должен быть в диапазоне от 1 до 150 лет.");
        }
        if (Name.empty()) {
            throw invalid_argument("Имя не может быть пустым.");
        }
        if (sex != "Мужской" && sex != "Женский") {
            throw invalid_argument("Пол должен быть либо 'Мужской', либо 'Женский'.");
        }
    }
    virtual void describe() const = 0;
    virtual ~Human() = default;
};

class Preschooler : public Human 
{
public:
    Preschooler(const int& age, const string& Name, const string& sex)
        : Human(age, Name, sex) {}

    void describe() const override 
    {
        cout << "Это возраст дошкольника: " << age << endl;
        cout << "Это его имя: " << Name << endl;
        cout << "Пол дошкольника: " << sex << endl;
    }
};

class SchoolBoy : public Human 
{
public:
    SchoolBoy(const int& age, const string& Name, const string& sex)
        : Human(age, Name, sex) {}

    void describe() const override 
    {
        cout << "Это возраст школьника: " << age << endl;
        cout << "Это его имя: " << Name << endl;
        cout << "Пол школьника: " << sex << endl;
    }
};

class Student : public Human {
private:
    int income;
public:
    Student(const int& age, const string& Name, const string& sex, int& income)
        : Human(age, Name, sex), income(income) 
    {
        if (income < 0 || income > 1000000) 
{
            throw range_error("Заработок студента должен быть в диапазоне от 0 до 1 000 000.");
        }
    }

    void describe() const override {
        cout << "Это возраст студента: " << age << endl;
        cout << "Это его имя: " << Name << endl;
        cout << "Пол студента: " << sex << endl;
        cout << "Заработок студента: " << income << endl;
    }
};

class Worker : public Human {
private:
    int salary;
    bool marriage;
public:
    Worker(const int& age, const string& Name, const string& sex, int& salary, bool& marriage)
        : Human(age, Name, sex), salary(salary), marriage(marriage) 
    {
        if (salary <= 0 || salary > 10000000) 
        {
            throw range_error("Зарплата рабочего должна быть в диапазоне от 1 до 10 000 000.");
        }
    }

    void describe() const override {
        cout << "Это возраст рабочего: " << age << endl;
        cout << "Это его имя: " << Name << endl;
        cout << "Пол рабочего: " << sex << endl;
        cout << "Зарплата рабочего: " << salary << endl;
        cout << "Семейное положение рабочего: " << (marriage ? "Женат/Замужем" : "Не женат/Не замужем") << endl;
    }
};

template <typename T>
class PointerArray {
private:
    vector<T*> data;

public:
    void add(T* element) 
    {
        if (!element) 
        {
            throw invalid_argument("Нельзя добавить null-указатель.");
        }
        data.push_back(element);
    }

    T*& operator[](size_t index)
    {
        if (index >= data.size())
        {
            throw out_of_range("Индекс выходит за пределы массива.");
        }
        return data[index];
    }

    size_t size() const 
    {
        return data.size();
    }

    ~PointerArray() {
        for (T* element : data) 
        {
            delete element;
        }
    }
};

int main() 
{
    setlocale(LC_ALL, "rus");

    try 
    {
        

        PointerArray<Human> humans;

        humans.add(new Preschooler(5, "Андрей", "Мужской"));
        humans.add(new SchoolBoy(10, "Мария", "Женский"));

        int studentIncome = 15000;
        humans.add(new Student(20, "Иван", "Мужской", studentIncome));

        int workerSalary = 50000;
        bool workerMarriage = true;
        humans.add(new Worker(35, "Анна", "Женский", workerSalary, workerMarriage));

        for (size_t i = 0; i < humans.size(); ++i) 
        {
            cout << "Объект " << i + 1 << ":" << endl;
            humans[i]->describe();
            cout << endl;
        }

        cout << "Пытаемся создать объект с некорректным возрастом..." << endl;
        humans.add(new Preschooler(0, "Петя", "Мужской"));

    }
    catch (const range_error& e) 
    {
        cerr << "Произошла ошибка диапазона: " << e.what() << endl;
    }
    catch (const invalid_argument& e) 
    {
        cerr << "Некорректный аргумент: " << e.what() << endl;
    }
    catch (const exception& e) 
    {
        cerr << "Общая ошибка: " << e.what() << endl;
    }

}

