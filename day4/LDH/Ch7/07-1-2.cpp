#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
    char *name;
    int age;
public:
    MyFriendInfo(char* friendName, int friendAge ) :  age(friendAge)
    {
        name = new char[strlen(friendName)+1];
        strcpy(name,friendName);
    }
    void ShowMyFriendInfo()
    {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;

    }
    ~MyFriendInfo()
    {
        delete[] name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char *addr;
    char *phone;
public:
    MyFriendDetailInfo(char * friendName, int friendAge, char * friendAddr, char *friendPhone ) : MyFriendInfo(friendName, friendAge)
    {
        phone=new char[strlen(friendPhone)+1];
        addr=new char[strlen(friendAddr)+1];
        strcpy(phone,friendPhone);
        strcpy(addr,friendAddr);
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout<<"주소: "<<addr<<endl;
        cout<<"전화: "<<phone<<endl<<endl;

    }
    ~MyFriendDetailInfo()
    {
        delete[] addr;
        delete[] phone;
    }
};


int main(void)
{
    MyFriendDetailInfo myFriendDetailInfo("UnityChan", 15, "Tokyo-Marunouchi", "1111-9999-0000");
    myFriendDetailInfo.ShowMyFriendDetailInfo();
}