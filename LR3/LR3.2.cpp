#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class Base
{
public:
	virtual ~Base() { cout << "Объект класса Base удалён" << endl; }

	virtual void info() const { cout << "Это Base класс" << endl; }
};

class Derived: public Base
{
public:
	virtual ~Derived() { cout << "Объект класса Derived удалён" << endl; }

	void info() const override { cout << "Это Derived класс" << endl; }

};

void add(vector<Base*>& storage, Base* obj)
{
	storage.push_back(obj);
}

int main()
{
	
	setlocale(LC_ALL, "rus");
	int num;
	srand(time(0));

	vector<Base*> storage;
	cout << "Введите целое количество объектов для создания классов" << endl;

	while (true) {
		if (cin >> num && num > 0) {
			break; 
		}
		else {
			cout << "Ошибка ввода! Введите положительное целое число: ";
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  
		}
	}

	try {
		for (int i = 0; i < num; i++)
		{
			if (rand() % 2 == 0)
			{
				add(storage, new Base());
			}
			else
			{
				add(storage, new Derived());
			}
		}

		for (const auto& obj : storage)
		{
			obj->info();
		}

		for (auto& obj : storage)
		{
			delete obj;
		}

	}
	catch (const bad_alloc& e) 
	{
	cout << "Ошибка выделения памяти: " << e.what() << endl;
	}
	catch (const runtime_error& e) 
	{
	cout << "Ошибка: " << e.what() << endl;
	}
	catch (...) 
	{
	cout << "Произошла неизвестная ошибка!" << endl;
	}
}
