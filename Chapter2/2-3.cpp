#include <iostream>

using namespace std;

namespace newdelete
{
	typedef struct __Point
	{
		int xpos;
		int ypos;
	}Point;

	Point PntAdder(const Point& p1, const Point& p2)
	{
		Point * p3 = new Point;
		p3->xpos = p1.xpos + p2.xpos;
		p3->ypos = p1.ypos + p2.ypos;

		return *p3;
	}
	
	void Problem()
	{
		Point* p1 = new Point;
		p1->xpos = 3;
		p1->ypos = 3;

		Point* p2 = new Point();
		p2->xpos = 5;
		p2->ypos = 5;

		Point newPoint = PntAdder(*p1, *p2);

		cout << newPoint.xpos << endl;
		cout << newPoint.ypos << endl;
	}
}

