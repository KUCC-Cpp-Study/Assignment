#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{  }
	void ShowPosition() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl; 
	}
    Point& operator+=(const Point &pos2)
    {
        xpos+=pos2.xpos;
        ypos+=pos2.ypos;
        return *this;
    }
    Point& operator-=(const Point &pos2)
    {
        xpos+=pos2.xpos;
        ypos+=pos2.ypos;
        return *this;
    }

    friend Point operator-(const Point &, const Point &);
    friend bool operator==(const Point &, const Point &);
    friend bool operator!=(const Point &, const Point &);

};

Point operator-(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos);
	return pos;
} 

bool operator==(const Point &pos1, const Point &pos2)
{
    return pos1.xpos==pos2.xpos && pos1.ypos==pos2.ypos;        
}

bool operator!=(const Point &pos1, const Point &pos2)
{
    return pos1.xpos!=pos2.xpos && pos1.ypos!=pos2.ypos;        
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);	
	(pos1-pos2).ShowPosition();
    (pos1+=pos2).ShowPosition();
    (pos1-=pos2).ShowPosition();

    cout<<(pos1==pos2)<<endl;
    cout<<(pos1!=pos2);

    
	return 0;
}
