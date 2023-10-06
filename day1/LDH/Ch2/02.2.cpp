#include <iostream>
using namespace std;

int main(void)
{
    const int num=12; // num의 값을 바꾸지 못한다.
    const int *p=&num; // 포인터가 num을 가리키며, num의 값을 변경하지 못하도록, 포인터가 가리키는 값을 상수화
    const int *(&q)=p; // q를 통해 num의 값을 못 바꾸게 한다. 

    cout<<*p<<"\n";
    cout<<*q;
}