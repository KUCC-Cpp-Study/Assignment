#include <iostream>
#include <cstring>
#include "Calculator.h"
#include "Printer.h"
using namespace std;

//C++���� �������� ����Ͽ� ����� ���ϰ� ������ �� �ִ�
//������ ����� ���� �ٸ� �̸����� �ȿ� �����ϴ� �͵� ����

//����ü �ȿ��� �Լ��� ����θ� �����ϰ� ���� ���� �ִ�
//���Ǵ� ���� ���� ������ ���̱�

namespace Car_Const
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STP = 10
	};
}

//struct Car
//{
//	/*enum
//	{
//		ID_LEN = 20,
//		MAX_SPD = 200,
//		FUEL_STEP = 2,
//		ACC_STEP = 10,
//		BRK_STP = 10
//	};*/
//	char gamerID[Car_Const::ID_LEN];
//	int fuelGauge;
//	int curSpeed;
//
//	void ShowCarState()
//	{
//		cout << "ID: " << gamerID << endl;
//		cout << "���ᷮ: " << fuelGauge << endl;
//		cout << "�ӵ�: " << curSpeed << endl;
//	}
//
//	void Accel();
//
//	void Break()
//	{
//		if (curSpeed < Car_Const::BRK_STP)
//		{
//			curSpeed = 0;
//			return;
//		}
//
//		curSpeed -= Car_Const::BRK_STP;
//	}
//};
//
//void Car::Accel()
//{
//	if (fuelGauge < 0) return;
//
//	else
//		fuelGauge -= Car_Const::FUEL_STEP;
//
//	if (curSpeed + Car_Const::ACC_STEP >= Car_Const::MAX_SPD)
//	{
//		curSpeed = Car_Const::MAX_SPD;
//		return;
//	}
//
//	cout << "Accelerating.." << endl;
//
//	curSpeed += Car_Const::ACC_STEP;
//}

class Car
{
private:
	char gamerID[Car_Const::ID_LEN];
	int fuelGauge;
	int curSpeed;

public:
	void InitMembers(const char* ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

void Car::InitMembers(const char* ID, int fuel)
{
	strcpy_s(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}
void Car::ShowCarState()
{
	cout << "ID: " << gamerID << endl;
	cout << "���ᷮ: " << fuelGauge << endl;
	cout << "�ӵ�: " << curSpeed << endl;
}
void Car::Accel()
{
	if (fuelGauge < 0) return;

	else
		fuelGauge -= Car_Const::FUEL_STEP;

	if (curSpeed + Car_Const::ACC_STEP >= Car_Const::MAX_SPD)
	{
		curSpeed = Car_Const::MAX_SPD;
		return;
	}

	cout << "Accelerating.." << endl;

	curSpeed += Car_Const::ACC_STEP;
}
void Car::Break()
{
	if (curSpeed < Car_Const::BRK_STP)
	{
		curSpeed = 0;
		return;
	}

	curSpeed -= Car_Const::BRK_STP;
}

//class Calculator
//{
//private:
//	int plusCount;
//	int minusCount;
//	int multiplyCount;
//	int divisionCount;
//
//public:
//	void Init();
//	void ShowOPCount();
//	float Add(float a, float b);
//	float Min(float a, float b);
//	float Mul(float a, float b);
//	float Div(float a, float b);
//};

void Calculator::Init()
{
	plusCount = 0;
	minusCount = 0;
	multiplyCount = 0;
	divisionCount = 0;
}

void Calculator::ShowOPCount()
{
	cout << "����: " << plusCount << " ����: " << minusCount
		<< " ����: " << multiplyCount << " ������: " << divisionCount << endl;
}

float Calculator::Add(float a, float b)
{
	plusCount++;

	float answer = a + b;

	return answer;
}

float Calculator::Min(float a, float b)
{
	minusCount++;

	float answer = a - b;

	return answer;
}

float Calculator::Mul(float a, float b)
{
	multiplyCount++;

	float answer = a * b;

	return answer;
}

float Calculator::Div(float a, float b)
{
	divisionCount++;

	float answer = a / b;

	return answer;
}

void Problem()
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.5 = " << cal.Add(3.2, 2.5) << endl;
	cal.ShowOPCount();
}

void Printer::SetString(const char* str)
{
	myString = str;
}

void Printer::ShowString()
{
	cout << myString << endl;
}

void Problem2()
{
	Printer pnt;
	pnt.SetString("Hello World!");
	pnt.ShowString();

	pnt.SetString("hihi");
	pnt.ShowString();
}