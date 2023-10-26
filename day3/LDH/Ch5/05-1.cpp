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
        NameCard(const NameCard &copy) : name(copy.name), cname(copy.cname), phone(copy.phone)
        {
            int name_len=strlen(copy.name)+1;
            int cname_len=strlen(copy.cname)+1;
            int phone_len=strlen(copy.phone)+1;

            name=new char[strlen(copy.name)+1];
            strcpy(name, copy.name);
            cname=new char[strlen(copy.cname)+1];
            strcpy(cname, copy.cname);
            phone=new char[strlen(copy.phone)+1];
            strcpy(phone, copy.phone);                        
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
    NameCard copy1=manClerk;
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2=manSenior;
    copy1.ShowCardInfo();
    copy2.ShowCardInfo();
    return 0;
}