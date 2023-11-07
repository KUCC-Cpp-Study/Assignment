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
	friend Point operator+(const Point& pos1, const Point& pos2);
	friend Point operator-(const Point& pos1, const Point& pos2);
	Point operator+=(const Point& pos) {
		this->xpos += pos.xpos;
		this->ypos += pos.ypos;
		return Point(this->xpos, this->ypos);
	}
	Point operator-=(const Point& pos) {
		this->xpos -= pos.xpos;
		this->ypos -= pos.ypos;
		return Point(this->xpos, this->ypos);
	}
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);
};
Point operator+(const Point& pos1, const Point& pos2) {
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}
Point operator-(const Point& pos1, const Point& pos2) {
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}
bool operator==(const Point& pos1, const Point& pos2) {
	if (pos1.xpos != pos2.xpos) return false;
	if (pos1.ypos != pos2.ypos)return false;
	return true;
}
bool operator!=(const Point& pos1, const Point& pos2) {
	if (pos1 == pos2)return false;
	return true;
}

namespace part10_1 {
	void problem() {
		Point pos1(3, 4);
		Point pos2(10, 20);
		Point pos3 = pos2 - pos1;

		pos1.ShowPosition();
		pos2.ShowPosition();
		pos3.ShowPosition();

		pos1 += pos2;
		pos1.ShowPosition();

		pos1 -= pos2;
		pos1.ShowPosition();

		if (pos1 == pos2) cout << "True" << endl;
		else cout << "False" << endl;

		if (pos1 != pos2) cout << "True" << endl;
		else cout << "False" << endl;
	}
}
