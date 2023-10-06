#include <iostream>
using namespace std;

void SwapPointer(int *p, int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}

int main(void)
{
    int num1=5;
    int *ptr1=&num1;
    int num2=10;
    int *ptr2=&num2;

    SwapPointer(ptr1, ptr2);
    cout<<"num1 = "<<num1<<"\n";
    cout<<"num2 = "<<num2;;
}