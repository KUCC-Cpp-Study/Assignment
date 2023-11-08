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
    Point operator-()
    {
		Point pos(-xpos, -ypos);
		return pos;
    }
	Point& operator++()
	{
		xpos+=1;
		ypos+=1;
		return *this;
	}
	friend Point& operator--(Point &ref);
    friend Point operator~(Point &ref);
};


Point operator~(Point &ref)
{
    Point pos=Point((ref.ypos), (ref.xpos));
    return pos;
}

int main(void)
{
	Point pos1(1, 2);
    Point pos2;
    pos2=-pos1;
    

    pos2.ShowPosition();
    Point pos3=~pos1;
    pos3.ShowPosition();

    
}