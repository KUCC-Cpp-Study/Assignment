#include <iostream>

using namespace std;

namespace overload
{
	class Point
	{
	private:
		int xpos, ypos;

	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y)
		{

		}

		void ShowPosition() const
		{
			cout << '[' << xpos << ", " << ypos << ']' << endl;
		}

		friend Point operator+(const Point& pos1, const Point& pos2);
		friend Point operator-(const Point& pos1, const Point& pos2);
		friend bool operator==(const Point& pos1, const Point& pos2);
		friend bool operator!=(const Point& pos1, const Point& pos2);

		Point operator+=(const Point& pnt)
		{
			xpos += pnt.xpos;
			ypos += pnt.ypos;

			return *this;
		}

		Point operator-=(const Point& pnt)
		{
			xpos -= pnt.xpos;
			ypos -= pnt.ypos;

			return *this;
		}
	};

	Point operator+(const Point& p1, const Point&p2)
	{
		Point pos(p1.xpos + p2.xpos, p1.ypos + p2.ypos);
		return pos;
	}

	Point operator-(const Point& p1, const Point& p2)
	{
		Point pos(p1.xpos - p2.xpos, p1.ypos - p2.ypos);
		return pos;
	}

	bool operator==(const Point& p1, const Point& p2)
	{
		if (p1.xpos == p2.xpos && p1.ypos == p2.ypos)
		{
			return true;
		}
		return false;
	}

	bool operator!=(const Point& p1, const Point& p2)
	{
		bool result = (p1 == p2);
		return !result;
	}

	void problem()
	{
		Point pos1(3, 4);
		Point pos2(3, 5);
		Point pos3 = pos1 + pos2;
		Point pos4 = pos2 - pos1;
		Point pos5 = pos1 += pos2;
		Point pos6(1, 1);
		Point pos7(1, 1);

		pos1.ShowPosition();
		pos2.ShowPosition();
		pos3.ShowPosition();
		pos4.ShowPosition();
		pos5.ShowPosition();

		const char* result;
		result = (pos6 == pos7) ? "true" : "false";

		cout << result << endl;
	}
}

