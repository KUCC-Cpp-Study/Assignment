#include <iostream>
using namespace std;

class Calculator {
private:
	int add_count;
	int min_count;
	int mul_count;
	int div_count;

public:
	void Init() {
		add_count = 0;
		min_count = 0;
		mul_count = 0;
		div_count = 0;
	}

	double Add(double a, double b) {
		add_count++;
		return a + b;
	}

	double Min(double a, double b) {
		min_count++;
		return a - b;
	}
	double Mul(double a, double b) {
		mul_count++;
		return a * b;
	}
	double Div(double a, double b) {
		if (b == 0) return 0;
		div_count++;
		return a / b;
	}

	void ShowOpCount() {
		cout << "µ¡¼À : " << add_count << " »¬¼À : " << min_count << " °ö¼À : " << mul_count << " ³ª´°¼À : " << div_count << endl;
	}
};

class Printer {
private:
	char string[100];
public:
	void SetString(const char* input);
	void ShowString();
};

void Printer::SetString(const char* input) {
	strcpy_s(string, input);
}
void Printer::ShowString() {
	cout << string << endl;
}

namespace part3_2 {
	void problem1() {
		Calculator cal;
		cal.Init();
		cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
		cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
		cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
		cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
		cal.ShowOpCount();
	}

	void problem2() {
		Printer pnt;
		pnt.SetString("Hello World!");
		pnt.ShowString();

		pnt.SetString("I love C++");
		pnt.ShowString();
	}
}