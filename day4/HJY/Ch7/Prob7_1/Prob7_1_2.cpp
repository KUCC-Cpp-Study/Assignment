#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* fname, int fage) : age(fage)
	{
		name = new char[strlen(fname) + 1];
		strcpy_s(name, strlen(fname) + 1, fname);
	}
	void ShowMyFriendInfo()
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* fname, int fage, const char* adr, const char* pnum) : MyFriendInfo(fname, fage)
	{
		addr = new char[strlen(adr) + 1];
		phone = new char[strlen(pnum) + 1];
		strcpy_s(addr, strlen(adr) + 1, adr);
		strcpy_s(phone, strlen(pnum) + 1, pnum);
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}
};

int main(void) 
{
	MyFriendDetailInfo fren1("홍길동", 22, "경북 구미", "010-1234-5678");
	MyFriendDetailInfo fren2("나생문", 22, "경기 용인", "010-1592-4452");
	fren1.ShowMyFriendDetailInfo();
	fren2.ShowMyFriendDetailInfo();
	return 0;
}