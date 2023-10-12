#include <iostream>
using namespace std;

namespace Initializer
{
	class Point
	{
	private:
		
		int xPos, yPos;

	public:
		
		Point(int x, int y)
		{
			xPos = x;
			yPos = y;
		}
		/*void Init(int x, int y)
		{
			xPos = x;
			yPos = y;
		}*/

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
		
		Circle(Point& center, int radius) : centerPoint(center)
		{
			circleRadius = radius;
		}

		/*void Init(Point& center, int radius)
		{
			centerPoint = center;
			circleRadius = radius;
		}*/

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
		Ring(Circle &inCircle, Circle &outCircle) : innerCircle(inCircle), outterCircle(outCircle)
		{
			cout << "New Ring Initialized" << endl;
		}
		//�� �̵����� �ؾ��ϴ���?
		//void Init(int innerX, int innerY, int innerRad, int outterX, int outterY, int outterRad)
		//{
		//	Point inCentPnt(innerX, innerY);
		//	//inCentPnt.Init(innerX, innerY);

		//	cout << "InnerCenterPoint initialized" << endl;

		//	Point outCentPnt(outterX, outterY);
		//	//outCentPnt.Init(outterX, outterY);

		//	cout << "OutterCenterPoint initialized" << endl;

		//	Circle innerCircle(inCentPnt, innerRad);

		//	cout << "InnerCircle Initialized" << endl;

		//	Circle outterCircle(outCentPnt, outterRad);

		//	cout << "OutterCircle Initialized" << endl;
		//}

		void ShowRingInfo() const
		{
			cout << "Inner Circle Info..." << endl;
			innerCircle.ShowCircleInfo();
			cout << "Outer Circle Info..." << endl;
			outterCircle.ShowCircleInfo();
		}
	};

	void Problem()
	{
		//��Ű�´�� �ϱ������ 
		//ring.Init(1, 1, 4, 2, 2, 9);

		Point point1(1, 1);
		Point point2(2, 2);

		Circle circle1(point1, 4);
		Circle circle2(point2, 9);

		Ring ring(circle1, circle2);
		ring.ShowRingInfo();
	}

	namespace COMP_POS
	{
		enum 
		{
			CLERK,
			SENIOR,
			ASSIST,
			MANAGER
		};
	}

	class NameCard
	{
		const char* humanName;
		const char* companyName;
		const char* tele;
		const char* posName;
		int pos;

		void EnumToString(int num)
		{
			if (num == 0)
				posName = "���";
			else if (num == 1)
				posName = "����";
			else if (num == 2)
				posName = "�븮";
			else posName = "�Ŵ���";
		}

	public:

		NameCard(const char* hname, const char* coname, const char* tel, int p)
		{
			humanName = hname;
			companyName = coname;
			tele = tel;
			EnumToString(p);
		}

		

		void ShowNameCardInfo()
		{
			cout << "�̸�: " << humanName << endl;
			cout << "ȸ��: " << companyName << endl;
			cout << "��ȭ��ȣ: " << tele << endl;
			cout << "����: " << posName << endl;
		}
	};

	void Problem2()
	{
		NameCard manClerk("Kim", "ArtygenSpace", "010-6690-3978", COMP_POS::MANAGER);
		manClerk.ShowNameCardInfo();
	}
}



int main()
{
	Initializer::Problem2();
	return 0;
}