#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "사원" << endl;
		case SENIOR:
			cout << "주임" << endl;
		case ASSIST:
			cout << "대리" << endl;
		case MANAGER:
			cout << "과장" << endl;
		}
	}
}

class NameCard
{
private:
	char* name;
	char* company;
	char* phone;
	int position;

public:
	NameCard(const char* name, const char* company, const char* phone, int pos)
		:position(pos)
	{
		this -> name = new char[strlen(name) + 1];
		this -> company = new char[strlen(company) + 1];
		this -> phone = new char[strlen(phone) + 1];
		strcpy_s(this -> name, strlen(name) + 1, name);
		strcpy_s(this -> company, strlen(company) + 1, company);
		strcpy_s(this -> phone, strlen(phone) + 1, phone);
	}

	NameCard(const NameCard& ref) : position(ref.position)
	{
		name = new char[strlen(ref.name) + 1];
		company = new char[strlen(ref.company) + 1];
		phone = new char[strlen(ref.phone) + 1];
		strcpy_s(name, strlen(ref.name) + 1, ref.name);
		strcpy_s(company, strlen(ref.company) + 1, ref.company);
		strcpy_s(phone, strlen(ref.phone) + 1, ref.phone);
	}
	void ShowNameCarInfo()
	{
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << phone << endl;
		cout << "직급: "; COMP_POS::ShowPositionInfo(position);
		cout << endl;
	}
	~NameCard()
	{
		delete[]name;
		delete[]company;
		delete[]phone;
	}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCarInfo();
	manSenior.ShowNameCarInfo();
	manAssist.ShowNameCarInfo();
	return 0;
}
