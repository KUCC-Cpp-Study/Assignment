#include <iostream>
using namespace std;

class Car {
private:
	int gasolinGauge;
public:
	Car(int n):gasolinGauge(n){}
	int GetGasGauge() {
		return gasolinGauge;
	}
};

class HybridCar : public Car {
private:
	int electricGauge;
public:
	HybridCar(int n1, int n2):Car(n1),electricGauge(n2){}
	int GetElecGauge() {
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar {
private:
	int waterGauge;
public:
	HybridWaterCar(int n1, int n2, int n3):HybridCar(n1, n2), waterGauge(n3) {}
	void ShowCurrentGauge() {
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};

class MyFriendInfo {
private:
	char* name;
	int age;
public:
	MyFriendInfo(int n, const char* myname) : age(n) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
	}

	void ShowMyFriendInfo() {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~MyFriendInfo() { delete[]name; }
};
class MyFriendDetailInfo :MyFriendInfo {
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(int age, const char* myname, const char* myaddr,const char* myphone):MyFriendInfo(age, myname) {
		int len = strlen(myaddr) + 1;
		addr = new char[len];
		strcpy_s(addr, len, myaddr);

		len = strlen(myphone) + 1;
		phone = new char[len];
		strcpy_s(phone, len, myphone);
	}
	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}

	~MyFriendDetailInfo() { 
		delete[]addr;
		delete[]phone;
	}
};
namespace part7_1 {
	void problem1() {
		HybridWaterCar hwcar(10, 20, 30);
		hwcar.ShowCurrentGauge();
	}

	void problem2() {
		MyFriendDetailInfo detail(15, "김박최김", "북한", "010-1111-2222");
		detail.ShowMyFriendDetailInfo();
	}
}
