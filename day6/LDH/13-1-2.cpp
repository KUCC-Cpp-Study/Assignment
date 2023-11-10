#include <iostream>
using namespace std;


template<typename T>
T SumArray(T arr[], int len)
{
    T sum=0;
    for(int i=0; i<len; i++)
        sum+=arr[i];
    return sum;
}

int main(void)
{
    double a[]={1.3,4.6,8.96};
    int b[]={1,3,4,5};

    cout<<SumArray(a,sizeof(a)/sizeof(double))<<endl;
    cout<<SumArray(b,sizeof(b)/sizeof(int))<<endl;


}