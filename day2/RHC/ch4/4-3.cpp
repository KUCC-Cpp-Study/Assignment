#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point (int x, int y):xpos(x), ypos(y) {	}
	void ShowPointInfo()const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle {
private:
	Point center;
	int radius;
public:
	Circle(int x, int y, int r): center(x,y), radius(r) {	}
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
	Ring(int x1, int y1, int r1, int x2, int y2, int r2): inner_circle(x1,y1,r1), outter_circle(x2,y2,r2) {	}
	void ShowRingInfo()const {
		cout << "Inner Circle Info..." << endl;
		inner_circle.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outter_circle.ShowCircleInfo();
	}
};

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };
	const char* pos_str[] = { "CLERK", "SENIOR", "ASSIST", "MANAGER" };
}

class NameCard {
private:
	char* name;
	char* company_name;
	char* phone_number;
	int position;

public:
	NameCard(const char* my_name, const char* my_company_name, const char*my_phone_number, int my_position)
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
	void ShowNameCardInfo()const {
		cout << "이름: " << name << endl;
		cout << "회사: " << company_name << endl;
		cout << "전화번호: " << phone_number << endl;
		cout << "직급: " <<COMP_POS::pos_str[position]<< endl<<endl;
	}
	~NameCard() {
		delete[]name;
		delete[]company_name;
		delete[]phone;
	}
};
namespace part4_3 {
	void problem1() {
		Ring ring(1, 1, 4, 2, 2, 9);
		ring.ShowRingInfo();
	}

	void problem2() {
		NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
		NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
		NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
		manClerk.ShowNameCardInfo();
		manSENIOR.ShowNameCardInfo();
		manAssist.ShowNameCardInfo();
	}
}
