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
	NameCard(const char* _name,const char* _company,const char* _phone, int pos)
		:position(pos)
	{
		name = new char[strlen(_name) + 1];
		company = new char[strlen(_company) + 1];
		phone = new char[strlen(_phone) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
		strcpy_s(company, strlen(_company) + 1, _company);
		strcpy_s(phone, strlen(_phone) + 1, _phone);
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