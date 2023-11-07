#include <iostream>
#include <cstdlib>
using namespace std;

class Point1 {
private:
	int xpos, ypos;
public:
	Point1(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point1* pos);
};
ostream& operator<<(ostream& os, const Point1* pos) {
	os << "[" << pos->xpos << ", " << pos->ypos << "]" << endl;
	return os;
}
typedef Point1* POINT_PTR;

class BoundCheckPointArray {
private:
	POINT_PTR* arr;
	int arrlen;
	BoundCheckPointArray(const BoundCheckPointArray& arr) {}
	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) {}
public:
	BoundCheckPointArray(int len) :arrlen(len) {
		arr = new POINT_PTR[len];
	}
	POINT_PTR& operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	POINT_PTR& operator[](int idx)const {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrlen()const { return arrlen; }
	~BoundCheckPointArray() { delete[]arr; }
};
class BoundCheckIntArray {
	int* arr;
	int col;
	BoundCheckIntArray(const BoundCheckIntArray& arr) {}
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}
public:
	BoundCheckIntArray(int col_):col(col_) {
		arr = new int[col_];
	}
	int& operator[](int idx) {
		if (idx < 0 || idx >= col) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int& operator[](int idx)const {
		if (idx < 0 || idx >= col) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int Getcol()const { return col; }
	~BoundCheckIntArray() { delete[]arr; }
};
class BoundCheck2DIntArray {
private:
	BoundCheckIntArray** arr2d;
	int row;
	BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) {}
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr) {}
public:
	BoundCheck2DIntArray(int row_, int col_) :row(row_) {
		arr2d = new BoundCheckIntArray*[row];
		for (int i = 0; i < row_; ++i)arr2d[i] = new BoundCheckIntArray(col_);
	}
	BoundCheckIntArray& operator[](int idx) {
		if (idx < 0 || idx >= row) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return *(arr2d[idx]);
	}
	int GetRow()const { return row; }
	~BoundCheck2DIntArray() { delete[]arr2d; }
};

namespace part11_2 {
	void problem1() {
		BoundCheckPointArray arr(3);
		arr[0] = new Point1(3, 4);
		arr[1] = new Point1(5, 6);
		arr[2] = new Point1(7, 8);

		for (int i = 0; i < arr.GetArrlen(); i++) cout << arr[i];
		delete arr[0];
		delete arr[1];
		delete arr[2];
	}

	void problem2() {
		BoundCheck2DIntArray arr2d(3, 4);
		for (int n = 0; n < 3; n++) for (int m = 0; m < 4; m++)arr2d[n][m] = n + m;
		for (int n = 0; n < 3; n++) {
			for (int m = 0; m < 4; m++) {
				cout << arr2d[n][m] << " ";
			}
			cout << endl;
		}
	}
}