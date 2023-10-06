#include <iostream>
using namespace std;

class Circle
{
    private:
        int xpos, ypos, radius;
    public:
        Circle(int x, int y, int r) 
            :xpos(x), ypos(y), radius(r)
            {

            }

        void ShowPointInfo() const
        {
            cout<<"radius: "<<radius<<endl;
            cout<<"["<<xpos<<" , "<<ypos<<"]"<<endl;
        }
};

class Ring
{
    Circle c1, c2;
    public:
        Ring(int a, int b, int c, int d, int e, int f)
            : c1(a,b,c), c2(d,e,f)
            {

            }

        void ShowRingInfo() const
        {
            cout<<"Inner Circle Info..."<<endl;
            c1.ShowPointInfo();
            cout<<"Outer Circle Info..."<<endl;
            c2.ShowPointInfo();            
        }
};

int main(void)
{
    Ring ring(1,1,4,2,2,9);
    ring.ShowRingInfo();
    
}