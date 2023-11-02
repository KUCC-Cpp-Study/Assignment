#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

namespace ISAInheritance
{
	class Rectangle
	{
	private:
		int x;
		int y;

	public:
		Rectangle(int n1, int n2) : x(n1),y(n2)
		{
		}
		void ShowAreaInfo()
		{
			cout << "면적 : " << x * y << endl;
		}
	};

	class Square : public Rectangle
	{
	public:
		Square(int n):Rectangle(n,n)
		{
		}
	};

	void problem1()
	{
		Rectangle rec(4, 3);
		rec.ShowAreaInfo();

		Square sqr(7);
		sqr.ShowAreaInfo();
	}

	class Book
	{
	private:
		char* title;
		char* isbn;
		int price;

	public:
		Book(const char* bookt, const char* bookisbn, int bookprice) : price(bookprice)
		{
			title = new char[strlen(bookt) + 1];
			isbn = new char[strlen(bookisbn) + 1];
			strcpy(title, bookt);
			strcpy(isbn, bookisbn);
		}

		void ShowBookInfo()
		{
			cout << "제목 : " << title << endl;
			cout << "ISBN : " << isbn << endl;
			cout << "가격 : " << price << endl;
		}
	};

	class EBook : public Book
	{
	private:
		char* DRMKey;

	public:
		EBook(const char* bookt, const char* bookisbn, int bookprice, const char* key) : Book(bookt,bookisbn,bookprice)
		{
			DRMKey = new char[strlen(key) + 1];
			strcpy(DRMKey, key);
		}

		void ShowEBookInfo()
		{
			ShowBookInfo();
			cout << "인증키 : " << DRMKey << endl;
		}

	};

	void problem2()
	{
		Book book("C++", "555-12345", 20000);
		book.ShowBookInfo();
		cout << endl;

		EBook ebook("My C++", "555-123456", 10000, "faedfasx213");
		ebook.ShowEBookInfo();
	}
}

int main()
{
	ISAInheritance::problem2();
	return 0;
}
