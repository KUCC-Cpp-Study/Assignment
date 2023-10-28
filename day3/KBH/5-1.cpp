#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//���������? �����װԾô���~
namespace copyconstructor
{
	//��ȣ�� ���� �� ������ �ʱ�ȭ ����
	int num(100);
	int& repls(num);

	class SoSimple
	{
	private:
		int num1;
		int num2;

	public:
		SoSimple(int n1, int n2):num1(n1),num2(n2)
		{}
		void ShowData()
		{
			cout << num1 << endl;
			cout << num2 << endl;
		}
	};
	
	void simpleprob()
	{
		SoSimple sim1(10, 20);
		SoSimple sim2(sim1); //Sosimple sim2 = sim1�� ������ �ڵ�� ������ ��ȯ
		sim2.ShowData();
	}

	class Person
	{
	private:
		char* name;
		int age;

	public:
		Person(const char* myname, int myage)
		{
			int len = strlen(myname) + 1;
			name = new char[len];
			strcpy(name, myname);
			age = myage;
		}

		Person(const Person& newPerson) : age(newPerson.age)
		{
			int len = strlen(newPerson.name) + 1;
			name = new char[len];
			strcpy(name, newPerson.name);
		}

		void ShowPersonInfo()
		{
			cout << name << endl;
			cout << age << endl;
		}

		~Person()
		{
			delete[]name;
			cout << "destructor called"<<endl;
		}
	};

	void personprob()
	{
		Person willy("Willy", 20);
		Person willytwin(willy);

		willy.ShowPersonInfo();
		willytwin.ShowPersonInfo();
	}
}


namespace ch5prob
{
	namespace COMP_POS
	{
		enum
		{
			CLERK,
			SENIOR,
			ASSIST,
			MANAGER
		};
	}
	class NameCard
	{
		char* humanName;
		char* companyName;
		char* tele;
		const char* posName;
		int pos;

		void EnumToString(int num)
		{
			if (num == 0)
				posName = "���";
			else if (num == 1)
				posName = "����";
			else if (num == 2)
				posName = "�븮";
			else posName = "�Ŵ���";
		}

	public:

		NameCard(const char* hname, const char* coname, const char* tel, int p)
		{
			humanName = new char[strlen(hname) + 1];
			companyName = new char[strlen(coname) + 1];
			tele = new char[strlen(tel) + 1];
			pos = p;

			strcpy(humanName, hname);
			strcpy(companyName, coname);
			strcpy(tele, tel);
			EnumToString(p);
		}

		NameCard(NameCard &cardCopy) : pos(cardCopy.pos)
		{
			humanName = new char[strlen(cardCopy.humanName) + 1];
			companyName = new char[strlen(cardCopy.companyName) + 1];
			tele = new char[strlen(cardCopy.tele) + 1];

			strcpy(humanName, cardCopy.humanName);
			strcpy(companyName, cardCopy.companyName);
			strcpy(tele, cardCopy.tele);
			EnumToString(pos);
		}



		void ShowNameCardInfo()
		{
			cout << "�̸�: " << humanName << endl;
			cout << "ȸ��: " << companyName << endl;
			cout << "��ȭ��ȣ: " << tele << endl;
			cout << "����: " << posName << endl;
		}

		~NameCard()
		{
			delete[] humanName;
			delete[] companyName;
			delete[] tele;

			cout << "deletion complete" << endl;
		}
	};

	void problem5()
	{
		NameCard mycard("kbh", "Kuniv", "010-6690-3978", COMP_POS::MANAGER);
		NameCard urCard = mycard;
		NameCard seniorcard("Hong", "Yuniv", "010-xxxx-xxxx", COMP_POS::MANAGER);
		NameCard hisCard = seniorcard;
		urCard.ShowNameCardInfo();
		hisCard.ShowNameCardInfo();
	}
}
