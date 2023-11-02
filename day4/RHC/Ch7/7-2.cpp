#include <iostream>
using namespace std;

class Rectangle {
protected:
	int area;
public:
	Rectangle(int n1, int n2):area(n1*n2){}
	Rectangle(){}

	void ShowAreaInfo() {
		cout << "면적 : " << area << endl;
	}
};
class Square :public Rectangle {
public:
	Square(int n):Rectangle(n,n){}
};

class Book {
protected:
	char* name;
	char* ISBN;
	int price;
public:
	Book(const char* myname, const char* myISBN, int myprice) : price(myprice) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);

		len = strlen(myISBN) + 1;
		ISBN = new char[len];
		strcpy_s(ISBN, len, myISBN);
	}
	void ShowBookInfo() {
		cout << "제목: " << name << endl;
		cout << "INBN: " << ISBN << endl;
		cout << "가격: " << price << endl;
	}
	~Book() { delete[] name; delete[]ISBN; }
};
class EBook : Book {
private:
	char* key;
public:
	EBook(const char* myname, const char* myISBN, int myprice, const char* mykey) :Book(myname, myISBN, myprice) {
		int len = strlen(mykey) + 1;
		key = new char[len];
		strcpy_s(key, len, mykey);
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << key << endl;
	}
	~EBook() { delete[]key; }
};

namespace part7_2 {
	void problem1() {
		Rectangle rec(4, 3);
		rec.ShowAreaInfo();

		Square sqr(7);
		sqr.ShowAreaInfo();
	}

	void problem2() {
		Book book("좋은 C++", "555-12345-890-0", 20000);
		book.ShowBookInfo();
		cout << endl;
		EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
		ebook.ShowEBookInfo();
	}
}