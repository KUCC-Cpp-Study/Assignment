#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STP 10

// C++에선 구조체에 함수를 삽입할 수 있다

struct Car
{
	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState()
	{
		cout << "ID: " << gamerID << endl;
		cout << "연료량: " << fuelGauge << endl;
		cout << "속도: " << curSpeed << endl;
	}

	void Accel()
	{
		

		if (fuelGauge < 0) return;

		else
			fuelGauge -= FUEL_STEP;

		if (curSpeed+ACC_STEP >= MAX_SPD)
		{
			curSpeed = MAX_SPD;
			return;
		}

		cout << "Accelerating.." << endl;

		curSpeed += ACC_STEP;
	}

	void Break()
	{
		if (curSpeed < BRK_STP)
		{
			curSpeed = 0;
			return;
		}

		curSpeed -= BRK_STP;
	}
};

namespace FuncInStruct
{
	struct Point
	{
		int xPos;
		int yPos;

		void MovePos(int x, int y)
		{
			xPos += x;
			yPos += y;
		}

		void AddPoint(const Point &pos)
		{
			xPos += pos.xPos;
			yPos += pos.yPos;
		}

		void ShowPosition()
		{
			cout << "[" << xPos << "," << yPos << "]" << endl;
		}
	};

	void Problem()
	{
		Point pos1 = { 12,4 };
		Point pos2 = { 20, 30 };

		pos1.MovePos(-7, 10);
		pos1.ShowPosition();

		pos1.AddPoint(pos2);
		pos1.ShowPosition();
	}
}
