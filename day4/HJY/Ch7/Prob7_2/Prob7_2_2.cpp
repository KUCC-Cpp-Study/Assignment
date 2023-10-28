#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* title,const char* isbn, int value)
		:price(value)
	{
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];
		strcpy_s(this->title, strlen(title) + 1, title);
		strcpy_s(this->isbn, strlen(isbn) + 1, isbn);
	}
	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book()
	{
		delete[]title;
		delete[]isbn;
	}
};

class Ebook : public Book
{
private:
	char* DBMKey;
public:
	Ebook(const char* title, const char*isbn, int value, const char* key)
		:Book(title, isbn, value)
	{
		DBMKey = new char[strlen(key) + 1];
		strcpy_s(DBMKey, strlen(key) + 1, key);
	}

	void ShowBookInfo()
	{
		ShowBookInfo();
		cout << "인증키: " << DBMKey << endl;
	}
	~Ebook()
	{
		delete[]DBMKey;
	}
};

int main(void)
{
	Book book("개같은 Cpp", "555-12345-678-9", 20000);
	book.ShowBookInfo();
	cout << endl;
	Ebook ebook("개같은 Cpp ebook", "555-12345-678-0", 10000, "fdx9w0i8kiw");
	ebook.ShowBookInfo();
	return 0;
}