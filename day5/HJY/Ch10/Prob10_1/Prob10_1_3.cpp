#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << " ]" << endl;
	}
	friend bool operator==(const Point&, const Point&);
	friend bool operator!=(const Point&, const Point&);
};

bool operator==(const Point& pos1, const Point& pos2)
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	else
		return false;
}

bool operator!=(const Point& pos1, const Point& pos2)
{
	if (pos1.xpos == pos2.xpos && pos1.ypos ==pos2.ypos)
		return false;
	else
		return true;
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(3, 4);
	Point pos3(5, 8);
	Point pos4(9, 7);
	
	if (pos1 == pos2) {
		cout << "equal" << endl;
	}
	else {
		cout << "not equal" << endl;
	}

	if (pos3 != pos4) {
		cout << "not equal" << endl;
	}
	else {
		cout << "equal" << endl;
	}

	return 0;
}