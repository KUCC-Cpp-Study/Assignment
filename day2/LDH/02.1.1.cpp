#include <iostream>
using namespace std;


void plus_address(int &num)
{
    num++;
}

void sign_change(int &num)
{
    num*=-1;
}

main(void)
{
    int a=0, b=-1;
    cout<<"a = "<<a<<"\n";
    plus_address(a);
    cout<<"a = "<<a<<"\n";
    cout<<"b = "<<b<<"\n";
    sign_change(b);
    cout<<"b = "<<b;
}