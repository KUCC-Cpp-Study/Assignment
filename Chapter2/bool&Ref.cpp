#include <iostream>
using namespace std;

namespace ref 
{
	void SwapByValue(int val1, int val2)
	{
		int temp = val1;
		val1 = val2;
		val2 = temp;
	}
	void SwapByRef(int* ptr1, int* ptr2)
	{
		int temp = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = temp;
	}
	void SwapByRef2(int& ref1, int& ref2)
	{
		int temp = ref1;
		ref1 = ref2;
		ref2 = temp;
	}

	void Problem()
	{

		int val1 = 10;
		int val2 = 20;

		ref::SwapByValue(val1, val2);
		cout << val1 << endl;
		cout << val2 << endl;

		ref::SwapByRef2(val1, val2);
		cout << val1 << endl;
		cout << val2 << endl;
	}
}