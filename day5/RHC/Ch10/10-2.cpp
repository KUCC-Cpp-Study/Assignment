#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	void ShowPosition()const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	Point& operator++() {
		xpos += 1;
		ypos += 1;
		return *this;
	}
	friend Point& operator--(Point& ref);
	Point& operator-() {
		Point pos(-this->xpos, -this->ypos);
		return pos;
	}
	friend Point& operator~(Point& ref);
};
Point& operator--(Point& ref) {
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}
Point& operator~(Point& ref) {
	Point pos(ref.ypos, ref.xpos);
	return pos;
}

namespace part10_2 {
	void problem() {
		Point pos1(3, 4);
		Point pos2 = -pos1;
		Point pos3 = ~pos1;

		pos1.ShowPosition();
		pos2.ShowPosition();
		pos3.ShowPosition();
	}
}