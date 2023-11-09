#include <iostream>

using namespace std;

namespace OneOpndOverload
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

		
		friend Point& operator~(Point& pos);

		Point& operator-()
		{
			Point pos(-xpos, -ypos);

			return pos;
		}
	};

	Point& operator~(Point& pos)
	{
		Point p(pos.ypos, pos.xpos);

		return p;
	}

	void problem()
	{
		Point pos1(1, 2);

		Point pos2 = -pos1;

		Point pos3 = ~pos1;

		pos1.ShowPosition();
		pos2.ShowPosition();
		pos3.ShowPosition();
	}
}