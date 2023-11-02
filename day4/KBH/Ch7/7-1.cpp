#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

namespace inheritance
{
	class Human
	{
	private:
		int age;
		char name[50];
	public:
		Human(int myage, const char* myname) :age(myage)
		{
			strcpy(name, myname);
		}

		void ShowYourName() const
		{
			cout << "내 이름은 " << name << "이다ㅋ" << endl;
		}

		void ShowYourAge() const
		{
			cout << "내 나이는 " << age << "이다ㅋ" << endl;
		}
	};

	class Student : public Human
	{
	private:
		char major[50];

	public:
		Student(const char* name, int age, const char* mymajor) : Human(age, name)
		{
			strcpy(major, mymajor);
		}

		void ShowStat() const
		{
			ShowYourName();
			ShowYourAge();
			cout << "내 전공은 " << major << endl;
		}
	};

	void Problem()
	{
		Student std("hoho", 20, "Wtf");

		std.ShowStat();
	}
}

namespace creationOrder
{
	class Base
	{
	private:
		int baseNum;
	public:
		Base() : baseNum(100)
		{
			cout << "Base constructor" << endl;
		}
		Base(int n) : baseNum(n)
		{
			cout << "Base constructor with parameter" << endl;
		}

		void ShowBaseData()
		{
			cout << baseNum << endl;
		}
	};

	class Derived : public Base
	{
	private:
		int derivedNum;

	public:
		Derived() : derivedNum(1000)
		{
			cout << "Derived Constructor" << endl;
		}

		Derived(int n) : derivedNum(n)
		{
			cout << "Derived Constructor with parameter" << endl;
		}

		Derived(int n1, int n2) : Base(n1), derivedNum(n2)
		{
			cout << "Derived Constructor with 2 params" << endl;
		}
		void ShowDerivData()
		{
			ShowBaseData();
			cout << derivedNum << endl;
		}
	};

	void problem()
	{
		cout << "case1" << endl;
		Derived case1;
		case1.ShowDerivData();
		cout << "case2" << endl;
		Derived case2(1050);
		case2.ShowDerivData();
		cout << "case3" << endl;
		Derived case3(10,20);
		case3.ShowDerivData();

	}
}

namespace problem71
{
	class Car
	{
	private:
		int gasolineGauge;
	public:
		Car()
		{
			cout << "Car instantiated with default Param" << endl;
		}
		Car(int n) : gasolineGauge(n)
		{
			cout << "Car instantiated with selected gasoline n" << endl;
		}
		int GetGasGauge()
		{
			return gasolineGauge;
		}
	};

	class HybridCar : public Car
	{
	private:
		int electricGauge;

	public:

		HybridCar()
		{
			cout << "Hybird instantiated with default param" << endl;
		}

		HybridCar(int n) : electricGauge(n)
		{
			cout << "Hybrid instantiated with selected electric n" << endl;
		}

		HybridCar(int n1, int n2) : Car(n1), electricGauge(n2)
		{
			cout << "Hybrid instantiated with selected n1,n2" << endl;
		}

		int GetElectricGauge()
		{
			return electricGauge;
		}
	};

	class HybridWaterCar : public HybridCar
	{
	private: 
		int waterGauge;
	public:
		HybridWaterCar(int n1, int n2, int n3) : HybridCar(n1,n2), waterGauge(n3)
		{
			cout << "HybridWater instantiated with Hybrid constructor" << endl;
		}
		void ShowCurrentStat()
		{
			cout << "Remaining Gas : " << GetGasGauge() << endl;
			cout << "Remaining Elec : " << GetElectricGauge() << endl;
			cout << "Remaining Wat : " << waterGauge << endl;
		}
	};

	void problem()
	{
		HybridWaterCar hwCar(10, 10, 10);

		hwCar.ShowCurrentStat();
	}
}

namespace problem72
{
	class MyFriendInfo
	{
	private:
		char* name;
		int age;

	public:

		MyFriendInfo(const char* myname, int n) :age(n)
		{
			name = new char[strlen(myname) + 1];
			strcpy(name, myname);
		}

		~MyFriendInfo()
		{
			delete[] name;
			cout << "Myfriend delete complete" << endl;
		}

		void ShowMyFriendInfo()
		{
			cout << "name : " << name << endl;
			cout << "age : " << age << endl;
		}
	};

	class MyFriendDetailInfo : public MyFriendInfo
	{
	private:
		char* addr;
		char* phone;
	public:
		MyFriendDetailInfo(const char* name, int age, const char * ads, const char* pn) : MyFriendInfo(name,age)
		{
			addr = new char[strlen(ads) + 1];
			phone = new char[strlen(pn) + 1];
			strcpy(addr, ads);
			strcpy(phone, pn);
		}
		~MyFriendDetailInfo()
		{
			delete[] addr;
			delete[] phone;

			cout << "myfriend detail delete complete" << endl;
		}

		void ShowMyFriendDetailInfo()
		{
			ShowMyFriendInfo();
			cout << "address : " << addr << endl;
			cout << "tele : " << phone << endl;
		}
	};

	void problem()
	{
		MyFriendDetailInfo mfdi("kbh", 23, "somewhere", "010xxxxxxxx");

		mfdi.ShowMyFriendDetailInfo();
	}
}