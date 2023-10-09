#include <iostream>
#include <sstream>
#include <string>
#include <list>

//static class StringStorage
//{
//	
//public:
//	static std::list<std::string> userInfoList;
//};

class AccountInfo
{
	int ID;
	std::string name;
	int money;
};

class AccountFeature
{
	

public : 
	virtual void Print()
	{

	}
public:
	virtual void Input(int* intAdress)
	{
		int input;
		
		std::cin >> input;

		*intAdress = input;
		//std::cin >> input;
	}
public:
	virtual void Input(std::string* strAdress)
	{
		std::string input;

		std::cin >> input;

		*strAdress = input;
		//std::cin >> input;
	}
};

class Controller
{
	
//public: AccountFeature featureArray[5] = {main,account,deposit,withdrawal, exit};
};

class ProgramExit : public AccountFeature
{

};

class Deposit : public AccountFeature
{

};
class WithDrawal : public AccountFeature
{

};
class MainMenu : public AccountFeature
{
	
	int selectedFunc;
public:
	void Print() override
	{
		MainMenuFunc();
	}

	void MainMenuFunc()
	{
		std::cout << "-----Menu-----" << std::endl;
		std::cout << "1. ���°���" << std::endl;
		std::cout << "2. �Ա�" << std::endl;
		std::cout << "3. ���" << std::endl;
		std::cout << "4. �������� ��ü ���" << std::endl;
		std::cout << "5. ���α׷� ����" << std::endl;
		
		std::cout << "����: "; Input(&selectedFunc);

		//featureArray[selectedFunc].Print();
	}
};

class OpenAccount : public AccountFeature
{
	int ID;
	std::string name;
	int money;

	std::list<std::string> userInfoList;

//public:
//	void Input(int input) override
//	{
//		std::cin >> input;
//	
//	}
	//void Input(std::string input) override
	//{
	//	std::cin >> input;
	//}
public:
	void Print() override
	{
		for (size_t i = 0; i < 3; i++)
		{
			OpenAccountFunc();
		}
		
	}

	void OpenAccountFunc()
	{
		std::cout << "[���°���]" << std::endl;
		std::cout << "����ID: "; Input(&ID);
		std::cout << "�̸�: "; Input(&name);
		std::cout << "�Աݾ�: "; Input(&money);

		SaveAccount(ID,name,money);
		printAllAccount();
	}

	void SaveAccount(int ID, std::string name, int money)
	{
		std::ostringstream os;
		os << "����ID: " << ID << "\n";
		os << "�̸�: " << name << "\n";
		os << "�Աݾ�: " << money << "\n";
		std::string info = os.str();
		userInfoList.push_back(info);
	}

	void printAllAccount()
	{
		std::list<std::string>::iterator it;

		for (it = userInfoList.begin(); it!=userInfoList.end(); ++it)
		{
			std::cout << *it << std::endl;
		}
		
	}
};



int main()
{
	MainMenu menu;
	OpenAccount account;
	Deposit deposit;
	WithDrawal withdrawal;
	ProgramExit exit;

	AccountFeature featureArray[5] = { menu,account,deposit,withdrawal, exit };

	featureArray[0].Print();
	

	/*MainMenu m;
	m.Print();*/

	return 0;
}

