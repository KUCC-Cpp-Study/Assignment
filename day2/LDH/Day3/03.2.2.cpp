#include <iostream>
using namespace std;

class Printer
{
    private:
        string s;
    public:
        void SetString(string data)
        {
            s=data;
        }
        void ShowString()
        {
            cout<<s<<endl;
        }

};


int main(void)
{
    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();    
}