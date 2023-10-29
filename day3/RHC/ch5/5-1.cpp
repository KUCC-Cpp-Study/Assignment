#include <iostream>
using namespace std;

namespace COMP_POS2 {
	enum { CLERK, SENIOR, ASSIST, MANAGER };
	const char* pos_str[] = { "CLERK", "SENIOR", "ASSIST", "MANAGER" };
}

class Point {
private:
	int xpos, ypos;
public:
	Point(int x, int y) :xpos(x), ypos(y) {	}
	void ShowPointInfo()const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle {
private:
	Point center;
	int radius;
public:
	Circle(int x, int y, int r) : center(x, y), radius(r) {	}
	void ShowCircleInfo()const {
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring {
private:
	Circle inner_circle;
	Circle outter_circle;
public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2) : inner_circle(x1, y1, r1), outter_circle(x2, y2, r2) {	}
	void ShowRingInfo()const {
		cout << "Inner Circle Info..." << endl;
		inner_circle.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outter_circle.ShowCircleInfo();
	}
};


class NameCard {
private:
	char* name;
	char* company_name;
	char* phone_number;
	int position;

public:
	NameCard(const char* my_name, const char* my_company_name, const char* my_phone_number, int my_position)
	{
		int len = strlen(my_name) + 1;
		name = new char[len];
		strcpy_s(name, len, my_name);

		len = strlen(my_company_name) + 1;
		company_name = new char[len];
		strcpy_s(company_name, len, my_company_name);

		len = strlen(my_phone_number) + 1;
		phone_number = new char[len];
		strcpy_s(phone_number, len, my_phone_number);

		position = my_position;
	}
	NameCard(const NameCard& copy) {
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy_s(name, len, copy.name);

		len = strlen(copy.company_name) + 1;
		company_name = new char[len];
		strcpy_s(company_name, len, copy.company_name);

		len = strlen(copy.phone_number) + 1;
		phone_number = new char[len];
		strcpy_s(phone_number, len, copy.phone_number);
	}
	void ShowNameCardInfo()const {
		cout << "이름: " << name << endl;
		cout << "회사: " << company_name << endl;
		cout << "전화번호: " << phone_number << endl;
		cout << "직급: " << COMP_POS2::pos_str[position] << endl << endl;
	}
	~NameCard() {
		delete[]name;
		delete[]company_name;
		delete[]phone_number;
	}
};

namespace part5_1 {
	void problem() {
		NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS2::CLERK);
		NameCard copy1 = manClerk;
		NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS2::SENIOR);
		NameCard copy2 = manSENIOR;
		copy1.ShowNameCardInfo();
		copy2.ShowNameCardInfo();
	}
}
