#include <iostream>
using namespace std;

namespace constRef
{
	const int num = 12;

	const int* ptr = &num;

	const int*& ref = ptr;

	void problem()
	{
		cout << ref << endl;
		cout << *ref << endl;
	}
	 
}
