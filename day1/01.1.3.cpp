#include <iostream>
using namespace std;

int main(void)
{
    int n=0;
    int i=0;
    int val=0;

    cout<<"숫자 입력: ";
    cin>>n;
    for(int i=1; i<=9; i++)
    {
        val=n*i;
        cout<<n<<" * "<<i<<" = "<<val<<"\n";
    }
}