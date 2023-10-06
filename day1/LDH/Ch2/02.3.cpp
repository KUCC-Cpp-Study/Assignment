#include <iostream>
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
}Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point* p=new Point; // 힙 영역에 할당 되었기 때문에, 별다른 해제 없으면 계속 할당된 채로 존재
    p->xpos=p1.xpos+p2.xpos;
    p->ypos=p1.ypos+p2.ypos;
    return *p; // 힙영역에 생성된 공간도 변수로 친다.
}

int main(void)
{
    Point *a= new Point;
    Point *b= new Point;
    

    a->xpos=10;
    a->ypos=20;
    b->xpos=5;
    b->ypos=7;

    Point &c=PntAdder(*a,*b);

    cout<<c.xpos<<"\n";
    cout<<c.ypos;

    delete a;
    delete b;
    delete &c;
}