#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) { }
	void showPosition()const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

template <typename T> void SwapData(T& data1, T& data2) {
	T tmp = data1;
	data1 = data2;
	data2 = tmp;
}
template <typename T> T SumArray(T arr[], int len) {
	T sum = 0;
	for (int i = 0; i < len; ++i) {
		sum += arr[i];
	}
	return sum;
}

namespace part13_1 {
	void problem1() {
		Point p1(1, 2);
		Point p2(2, 3);
		
		p1.showPosition();
		p2.showPosition();
		cout << endl;
		SwapData<Point>(p1, p2);
		p1.showPosition();
		p2.showPosition();
	}

	void problem2() {
		cout << SumArray(new int[3]{1,2,3}, 3) << endl;
		cout << SumArray(new double[3] {1.2, 2.3, 3.4}, 3) << endl;
	}
}
