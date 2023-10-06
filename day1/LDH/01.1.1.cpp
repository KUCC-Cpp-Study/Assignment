#include<iostream>
using namespace std;
int main(void)
{
    int i=0;
    int n=0;
    int sum=0;

    for(i=1; i<=5; i++)
    {
        cin>>n;
        cout<<i<<"번째 정수입력: "<<n<<"\n";
        sum+=n;
    }
    cout<<"합계: "<<sum;
}