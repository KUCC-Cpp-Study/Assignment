#include <iostream>
using namespace std;

namespace circleProblem
{
	class Point
	{
	private:
		int xPos, yPos;

	public:
		void Init(int x, int y)
		{
			xPos = x;
			yPos = y;
		}

		void ShowPointInfo() const
		{
			cout << "[" << xPos << ", " << yPos << "]" << endl;
		}
	};

	class Circle
	{
		Point centerPoint;
		int circleRadius;

	public:
		void Init(Point& center, int radius)
		{
			centerPoint = center;
			circleRadius = radius;
		}

		void ShowCircleInfo() const
		{
			cout << "Radius of Circle: " << circleRadius << endl;
			cout << "Center of Circle: ";
			centerPoint.ShowPointInfo();
		}
	};

	class Ring
	{
		Circle innerCircle;
		Circle outterCircle;

	public:
		//왜 이따구로 해야하는지?
		void Init(int innerX, int innerY, int innerRad, int outterX, int outterY, int outterRad)
		{
			Point inCentPnt;
			inCentPnt.Init(innerX, innerY);

			cout << "InnerCenterPoint initialized" << endl;

			Point outCentPnt;
			outCentPnt.Init(outterX, outterY);

			cout << "OutterCenterPoint initialized" << endl;

			innerCircle.Init(inCentPnt, innerRad);

			cout << "InnerCircle Initialized" << endl;

			outterCircle.Init(outCentPnt, outterRad);

			cout << "OutterCircle Initialized" << endl;
		}

		void ShowRingInfo()
		{
			cout << "Inner Circle Info..." << endl;
			innerCircle.ShowCircleInfo();
			cout << "Outer Circle Info..." << endl;
			outterCircle.ShowCircleInfo();
		}
	};

	void Problem()
	{
		Ring ring;
		ring.Init(1, 1, 4, 2, 2, 9);
		ring.ShowRingInfo();
	}
}


