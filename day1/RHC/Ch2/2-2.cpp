#include <iostream>
using namespace std;

namespace part2_2 {
	void problem() {
		const int num = 12;
		const int* ptr = &num;
		const int& ref = *ptr;

		cout << num << " " << *ptr << " " << ref;
	}
}