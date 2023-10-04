#include <iostream>
using namespace std;

namespace part2_1 {
	void add1(int* num) {
		*num += 1;
	}
	void reverse(int* num) {
		*num *= -1;
	}
	void problem1() {
		int test = 5;
		add1(&test);
		cout << test << endl;
		reverse(&test);
		cout << test << endl;
	}

	void problem2() {
		//인자로 reference가 아닌 정수값이 들어왔기 때문이다.
	}
	void swapPointer(int* ptr1, int* ptr2) {
		int tmp = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = tmp;
	}

	void problem3() {
		int num1 = 5;
		int* ptr1 = &num1;
		int num2 = 10;
		int* ptr2 = &num2;

		cout << *ptr1 << " " << *ptr2 << endl;
		swapPointer(ptr1, ptr2);
		cout << *ptr1 << " " << *ptr2 << endl;
	}
}
