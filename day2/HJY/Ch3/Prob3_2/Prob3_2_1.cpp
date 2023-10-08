#include <iostream>

using namespace std;

class Calculator
{
private:
	int addNum;
	int minNum;
	int mulNum;
	int divNum;
public:
	void Init();
	double Add(double num1, double num2);
	double Min(double num1, double num2);
	double Mul(double num1, double num2);
	double Div(double num1, double num2);
	void ShowOpCount();
};

void Calculator::Init()
{
	addNum = 0;
	minNum = 0;
	mulNum = 0;
	divNum = 0;
}

double Calculator::Add(double num1, double num2)
{
	addNum++;
	return num1 + num2;
}

double Calculator::Min(double num1, double num2)
{
	minNum++;
	return num1 - num2;
}

double Calculator::Mul(double num1, double num2)
{
	mulNum++;
	return num1 * num2;
}

double Calculator::Div(double num1, double num2)
{
	divNum++;
	return num1 * num2;
}

void Calculator::ShowOpCount()
{
	cout << "µ¡¼À: " << addNum << " »¬¼À: " << minNum << " °ö¼À: " << mulNum << " ³ª´°¼À: " << divNum << endl << endl;
	return;
}

int main(void)
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}