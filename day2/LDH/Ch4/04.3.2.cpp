#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum
    {
        CLERK, SENIOR, ASSIST, MANAGER
    };
    void ShowRank(int n)
    {
        if(n==CLERK)
            cout<<"사원"<<endl;
        else if(n==SENIOR)
            cout<<"주임"<<endl;
        else if(n==ASSIST)
            cout<<"대리"<<endl;
        else
            if(n==MANAGER)
                cout<<"과장"<<endl;
    }
}

class NameCard
{    
    char *name;
    char *cname;
    char *phone;
    int rank;
    public:
        void ShowCardInfo()
        {
            cout<<"이름: "<<name<<endl;
            cout<<"회사: "<<cname<<endl;
            cout<<"전화번호: "<<phone<<endl;
            cout<<"직급: ";
            COMP_POS::ShowRank(rank);
        }
        NameCard(char *a, char *b, char *c, int r)
        : rank(r)
        {
            name=new char[strlen(a)+1];
            strcpy(name,a);
            cname=new char[strlen(b)+1];
            strcpy(cname, b);
            phone=new char[strlen(c)+1];
            strcpy(phone, c);
        }
        ~NameCard()
        {
            delete[] name;
            delete[] phone;
            delete[] cname;
        }

};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowCardInfo();
    manSenior.ShowCardInfo();
    manAssist.ShowCardInfo();
}