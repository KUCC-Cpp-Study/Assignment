#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    {

    }
    void ShowPosition() const
    {
        cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
    }
    template<typename T>
    friend void Interchange(T, T);
    template<typename T>
    friend void Show(T, T);
};

template<typename T>
void Interchange(T p1, T p2)
{
    int x=p1.xpos;
    int y=p1.ypos;

    p1.xpos=p2.xpos;
    p1.ypos=p2.ypos;
    p2.xpos=x;
    p2.ypos=y;

}

template<typename T>
void Show(T p1, T p2)
{
    cout<<p1.xpos<<", "<<p1.ypos<<endl;
    cout<<p2.xpos<<", "<<p2.ypos<<endl;
}

int main(void)
{
    Point a(1,3);
    Point b(2,4);

    Interchange<Point&>(a,b);
    Show(a,b);
}