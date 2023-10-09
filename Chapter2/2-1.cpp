#include <iostream>
using namespace std;

namespace callByRef
{
	void RefPlusOne(int& val)
	{
		val += 1;
	}

	void RefAbs(int& val)
	{
		val = -val;
	}

	void Problem1()
	{
		int val = 1;
		callByRef::RefPlusOne(val);
		callByRef::RefAbs(val);

		cout << val << endl;
	}

	void SwapPointer(int* &ptr1, int* &ptr2)
	{
		int* temp = ptr1;
		ptr1 = ptr2;
		ptr2 = temp;
	}

	void Problem2()
	{
		int num1 = 5;
		int* ptr1 = &num1;
		int num2 = 10;
		int* ptr2 = &num2;

		cout << ptr1 << endl;
		cout << ptr2 << endl;

		SwapPointer(ptr1, ptr2);

		cout << ptr1 << endl;
		cout << ptr2 << endl;
	}
}