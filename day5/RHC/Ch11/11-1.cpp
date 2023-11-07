#include <iostream>
#include <cstring>
using namespace std;

class Gun {
private:
	int bullet;
public:
	Gun(int bnum) :bullet(bnum) {}
	void Shot() {
		cout << "BBANG!" << endl;
		bullet--;
	}
};
class Police {
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff) :handcuffs(bcuff) {
		if (bnum > 0) pistol = new Gun(bnum);
		else pistol = NULL;
	}
	Police(const Police& copy) :handcuffs(copy.handcuffs) {
		if (copy.pistol != NULL)pistol = new Gun(*(copy.pistol));
		else pistol = NULL;
	}
	Police& operator=(const Police& ref) {
		delete this->pistol;
		this->handcuffs = ref.handcuffs;
		if (ref.pistol != NULL)this->pistol = new Gun(*(ref.pistol));
		else this->pistol = NULL;
		return *this;
	}
	void PutHandcuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot() {
		if (pistol == NULL)cout << "Hut BBANG!" << endl;
		else pistol->Shot();
	}
	~Police() { if (pistol != NULL)delete pistol; }
};

class Book {
protected:
	char* title;
	char* ISBN;
	int price;
public:
	Book(const char* myname, const char* myISBN, int myprice) : price(myprice) {
		int len = strlen(myname) + 1;
		this->title = new char[len];
		strcpy_s(this->title, len, myname);

		len = strlen(myISBN) + 1;
		ISBN = new char[len];
		strcpy_s(ISBN, len, myISBN);
	}
	Book(const Book& copy) :price(copy.price) {
		int len = strlen(copy.title) + 1;
		this->title = new char[len];
		strcpy_s(this->title, len, copy.title);

		len = strlen(copy.ISBN) + 1;
		ISBN = new char[len];
		strcpy_s(ISBN, len, copy.ISBN);
	}
	Book& operator=(const Book& ref) {
		delete[] this->title;
		delete[] this->ISBN;

		this->price = ref.price;
		int len = strlen(ref.title) + 1;
		this->title = new char[len];
		strcpy_s(this->title, len, ref.title);

		len = strlen(ref.ISBN) + 1;
		ISBN = new char[len];
		strcpy_s(ISBN, len, ref.ISBN);
		return *this;
	}
	void ShowBookInfo() {
		cout << "제목: " << this->title << endl;
		cout << "INBN: " << this->ISBN << endl;
		cout << "가격: " << this->price << endl;
	}
	~Book() { delete[] this->title; delete[]ISBN; }
};
class EBook : Book {
private:
	char* key;
public:
	EBook(const char* myname, const char* myISBN, int myprice, const char* mykey) :Book(myname, myISBN, myprice) {
		int len = strlen(mykey) + 1;
		this->key = new char[len];
		strcpy_s(this->key, len, mykey);
	}
	EBook(const EBook& copy) : Book(copy) {
		int len = strlen(copy.key) + 1;
		this->key = new char[len];
		strcpy_s(this->key, len, copy.key);
	}
	EBook& operator=(const EBook& ref) {
		Book::operator=(ref);
		delete[] key;

		int len = strlen(ref.key) + 1;
		this->key = new char[len];
		strcpy_s(this->key, len, ref.key);
		return *this;
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << this->key << endl;
	}
	~EBook() { delete[]this->key; }
};

namespace part11_1 {
	void problem1() {
		Police p1(10, 2);
		Police p1cpy = p1;
		Police p2cpy(1,1);
		p2cpy = p1;

		p1.Shot();
		p1.PutHandcuff();
		p1cpy.Shot();
		p1cpy.PutHandcuff();
		p2cpy.Shot();
		p2cpy.PutHandcuff();
	}

	void problem2() {
		EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
		ebook.ShowEBookInfo();

		EBook ebcpy1 = ebook;
		EBook ebcpy2("x", "x", 1, "x");
		ebcpy2 = ebook;

		ebcpy1.ShowEBookInfo();
		ebcpy2.ShowEBookInfo();
	}
}
