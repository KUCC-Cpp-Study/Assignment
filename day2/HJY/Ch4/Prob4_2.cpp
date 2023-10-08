#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private:
	int rad;
	Point center;
public:
	void Init(int x, int y, int r)
	{
		rad = r;
		center.Init(x, y);
	}

	void ShowCircleInfo() const
	{
		cout << "radius : " << rad << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle innerC;
	Circle outerC;
public:
	void Init(int inX, int inY, int inR, int outX, int outY, int outR)
	{
		innerC.Init(inX, inY, inR);
		outerC.Init(outX, outY, outR);
	}
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		innerC.ShowCircleInfo();
		cout << "Outer Circle Info..." << endl;
		outerC.ShowCircleInfo();
	}
};

int main(void)
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}