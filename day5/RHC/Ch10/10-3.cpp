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
	friend ostream& operator<<(ostream&, const Point&);
	friend ostream& operator>>(ostream&, const Point&);
};
ostream& operator<<(ostream& os, const Point& pos) {
	os << "[" << pos.xpos << ", " << pos.ypos << "]" << endl;
	return os;
}
istream& operator>>(istream& os, Point& pos) {
	int x, y;
	os >> x >> y;
	pos = Point(x, y);
	return os;
}

namespace part10_3 {
	void problem() {
		Point pos1;
		cout << "x,y 좌표 순으로 입력: ";
		cin >> pos1;
		cout << pos1;

		Point pos2;
		cout << "x,y 좌표 순으로 입력: ";
		cin >> pos2;
		cout << pos2;
	}
}