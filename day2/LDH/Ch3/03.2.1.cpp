#include <iostream>
using namespace std;

class Calculator
{
    int addcnt;
    int divcnt;
    int mincnt;
    int mulcnt;

    public:
        void Init()
        {
            addcnt=0;
            divcnt=0;
            mincnt=0;
            mulcnt=0;
        }
        float Add(float x, float y)
        {
            addcnt++;
            return x+y;
        }
        float Div(float x, float y)
        {
            divcnt++;
            return x/y;
        }
        float Min(float x, float y)
        {
            mincnt++;
            return x-y;
        }
        float Mul(float x, float y)
        {
            mulcnt++;
            return x*y;
        }
        void ShowOpCount()
        {
            cout<<"덧셈: "<<addcnt<<' ';
            cout<<"뺄셈: "<<mincnt<<' ';
            cout<<"곱셈: "<<mulcnt<<' ';
            cout<<"나눗셈: "<<divcnt;

        }
};

int main(void)
{
    Calculator cal;
    cal.Init();
    cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
    cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
    cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
    cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
    cal.ShowOpCount();
    return 0;
}