#include <iostream>

using namespace std;

namespace mystd
{
	using namespace std;

	class ostream
	{
	public:
		void operator<<(const char* str)
		{
			printf("%s", str);
		}

		void operator<<(const char str)
		{
			printf("%c", str);
		}

		void operator<<(int num)
		{
			printf("%d", num);
		}

		void operator<<(double e)
		{
			printf("%g", e);
		}

		void operator<<(ostream& (*fp)(ostream& ostm))
		{
			fp(*this);
		}
	};

	ostream& �������(ostream& ostm)
	{
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}

	ostream ���ƿ�;

	void problem()
	{
		using mystd::�������;
		using mystd::���ƿ�;

		���ƿ� << "������ ���ڿ�";
		���ƿ� << �������;
		���ƿ� << 3.14;
		���ƿ� << �������;
		���ƿ� << 123;
		�������(���ƿ�);
	}


}

namespace pro2
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
			cout << '[' << xpos << ', ' << ypos << ']' << endl;
		}

		friend ostream& operator<<(ostream&, const Point&);
		friend istream& operator>>(istream&, Point&);

	};

	ostream& operator<<(ostream& os, const Point& pos)
	{
		os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return os;
	}

	istream& operator>>(istream& is, Point& pos)
	{
		int input1,input2;
		is >> input1 >> input2;
		pos.xpos = input1;
		pos.ypos = input2;
		

		return is;
	}

	void problem()
	{
		Point pos1;
		cout << "x,y ��ǥ ������ �Է�: ";
		cin >> pos1;
		cout << pos1;
	}

}



int main()
{
	//mystd::problem();
	pro2::problem();
}