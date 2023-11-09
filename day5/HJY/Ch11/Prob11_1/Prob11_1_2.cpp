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
	Book(const char* title, const char* isbn, int value)
		:price(value)
	{
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];
		strcpy_s(this->title, strlen(title) + 1, title);
		strcpy_s(this->isbn, strlen(isbn) + 1, isbn);
	}

	Book(const Book& ref)
		: price(ref.price)
	{ 
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy_s(title, strlen(ref.title) + 1, ref.title);
		strcpy_s(isbn, strlen(ref.isbn) + 1, ref.isbn);
	}

	Book& operator=(const Book& ref)
	{
		delete[]title;
		delete[]isbn;
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy_s(title, strlen(ref.title) + 1, ref.title);
		strcpy_s(isbn, strlen(ref.isbn) + 1, ref.isbn);
		price = ref.price;
		return *this;
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

class EBook : public Book
{
private:
	char* DBMKey;
public:
	EBook(const char* title, const char* isbn, int value, const char* key)
		:Book(title, isbn, value)
	{
		DBMKey = new char[strlen(key) + 1];
		strcpy_s(DBMKey, strlen(key) + 1, key);
	}

	EBook(const EBook& ref)
		: Book(ref)
	{
		DBMKey = new char[strlen(ref.DBMKey) + 1];
		strcpy_s(DBMKey, strlen(ref.DBMKey) + 1, ref.DBMKey);
	}

	EBook& operator=(const EBook& ref)
	{
		Book::operator=(ref);
		delete[]DBMKey;
		DBMKey = new char[strlen(ref.DBMKey) + 1];
		strcpy_s(DBMKey, strlen(ref.DBMKey) + 1, ref.DBMKey);
		return *this;
	}

	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "인증키: " << DBMKey << endl;
	}
	~EBook()
	{
		delete[]DBMKey;
	}
};

int main(void)
{
	EBook ebook1("개발은 싫지만 코테는 하고싶어", "555-12345-678-0", 10000, "fdx9w0i8kiw");
	ebook1.ShowEBookInfo();
	EBook ebook2 = ebook1;
	ebook2.ShowEBookInfo();
	cout << endl;
	EBook ebook3("dummy", "dummy", 0, "dummy");
	ebook3 = ebook2;
	ebook3.ShowEBookInfo();
	return 0;
}