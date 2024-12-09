#include <iostream>
#include <string>

using namespace std;

class sales
{
public:
	float arr[3];
	void get_sales()
	{
		cout << "Введите данные о продажах за послдение 3 месяца: " << endl;
		for (int i = 0; i < 3; i++)
		{
			cin >> arr[i];
		}
	}
	void put_sales()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "Продаж в " << i + 1 << " месяце: " << arr[i] << endl;
		}
	}
};


class Publication
{
public:
	void getdataP()
	{

		cout << "Введите название книги: " << endl;
		cin.ignore();
		getline(cin, Name);
		cout << "Введите цену: " << endl;
		cin >> cost;
	}

	void putdataP()
	{
		cout << "Название книги: " << Name << endl;
		cout << "Стоимость книги: " << cost << endl;
	}

protected:
	string Name;
	float cost;
};

class Book : public Publication, sales
{
private:
	int pages;
public:

	void getdata()
	{
		getdataP();
		cout << "Ввелите количество страниц: " << endl;
		cin >> pages;
		get_sales();
	}

	void putdata()
	{
		putdataP();
		cout << "Количество страниц в книге: " << pages << endl;
		put_sales();
	}
};

class Tape : public Publication, sales
{
private:
	float booktime;
public:
	void getdata()
	{
		getdataP();
		cout << "Введиите длительность книги в минутах: " << endl;
		cin >> booktime;
		get_sales();
	}

	void putdata()
	{
		putdataP();
		cout << "Длительность книги в минутах: " << booktime;
		put_sales();
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	Book book;
	book.getdata();
	book.putdata();

	Tape tape;
	tape.getdata();
	tape.putdata();

}
