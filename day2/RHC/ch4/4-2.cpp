#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo()const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle {
private:
	Point center;
	int radius;
public:
	void Init(int x, int y, int r) {
		center.Init(x, y);
		radius = r;
	}
	void ShowCircleInfo()const {
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring {
private:
	Circle inner_circle;
	Circle outter_circle;
public:
	void Init(int x1, int y1, int r1, int x2, int y2, int r2) {
		inner_circle.Init(x1, y1, r1);
		outter_circle.Init(x2, y2, r2);
		return;
	}
	void ShowRingInfo()const {
		cout << "Inner Circle Info..." << endl;
		inner_circle.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outter_circle.ShowCircleInfo();
	}
};

namespace part4_2 {
	void problem() {
		Ring ring;
		ring.Init(1, 1, 4, 2, 2, 9);
		ring.ShowRingInfo();
	}
}