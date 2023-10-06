#include <iostream>
using namespace std;

int main(void)
{
    int cash=50;
    int price=0;
    int result=0;

    cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
    cin>>price;
    while(price!=-1)
    {
        result=cash+price*0.12;
        cout<<"이번 달 급여: "<<result<<"만원"<<"\n";
        cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
        cin>>price;
    }
    cout<<"프로그램을 종료합니다.";
}