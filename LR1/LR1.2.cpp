#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include<vector>


using namespace std;

class Book
{
public:

	string authorName;
	string bookName;
	string bookType;

	Book()
	{
		authorName = "None";
		bookName = "None";
		bookType = "None";
	}

	Book(string aN, string bN, string bT)
	{
		authorName = aN;
		bookName = bN;
		bookType = bT;
	}

};

class Library
{
private:
	vector<Book> arr;
public:
	void addBook(Book book)
	{
		if (book.authorName == "None" || book.bookName == "None")
			cout << "Книга не может быть добавлена" << endl;
		else if (book.bookType != "Tech" && book.bookType != "Art")
			cout << "Книга неправильного типа" << endl;
		else
			arr.push_back(book);
	}

	void displayBooksIf()
	{
		if (!arr.empty())
		{
			int Tech = 0;
			int Art = 0;
			for (int i = 0; i < size(arr); i++)
			{
				if (arr[i].bookType == "Tech")
					Tech++;
				else
					Art++;
			}

			cout << "Количество технической литературы: " << Tech << endl;
			cout << "Количество художественной литературы: " << Art << endl;
		}
	}
		
};



int main()
{
	setlocale(LC_ALL, "rus");
	Book book1("Pudge", "crypto", "Tech");
	Book book2("Dota2", "smartgaming", "Art");
	Book book3;
	Library library;
	library.addBook(book1);
	library.addBook(book2);
	library.addBook(book3);
	library.displayBooksIf();
}
