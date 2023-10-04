#include <iostream>
using namespace std;

namespace part2_3 {
	typedef struct __Point {
		int xpos;
		int ypos;
	} Point;

	Point& PntAdder(const Point& p1, const Point& p2) {
		Point* p = new Point;
		p->xpos = p1.xpos + p2.xpos;
		p->ypos = p1.ypos + p2.ypos;
		return *p;
	}

	void problem() {
		Point* p1 = new Point;
		p1->xpos = 1;
		p1->ypos = 2;
		Point* p2 = new Point;
		p2->xpos = 3;
		p2->ypos = 4;
		Point p3 = PntAdder(*p1, *p2);
		cout << p3.xpos << " " << p3.ypos;
	}
}