#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

namespace part2_4 {
	void problem1() {
		char str1[10] = "abcd", str2[5] = "efgd", str3[10];
		cout << "strlen : " << strlen(str1) << ", " << strlen(str2) << endl;
		strcpy_s(str3, str1);
		cout << "strcpy : " << str1 << ", " << str3 << endl;
		cout << "strcmp : " << strcmp(str1, str2) << ", " << strcmp(str1, str3) << endl;
		strcat_s(str1, str2);
		cout << "strcat : " << str1 << endl;
	}

	void problem2() {
		srand(time(NULL));
		for (int i = 0; i < 5; ++i) {
			cout << rand() % 100<<" ";
		}
	}
}