#include <iostream>

namespace part1_2 
{
	void swap(int*, int*);
	void swap(char*, char*);
	void swap(double*, double*);
}

namespace part1_2
{
	void problem() {
		int num1 = 20, num2 = 30;
		swap(&num1, &num2);
		std::cout << num1 << " " << num2 << std::endl;

		char ch1 = 'A', ch2 = 'Z';
		swap(&ch1, &ch2);
		std::cout << ch1 << " " << ch2 << std::endl;

		double db1 = 1.111, db2 = 5.555;
		swap(&db1, &db2);
		std::cout << db1 << " " << db2 << std::endl;
	}

	void swap(int* num1, int* num2) {
		int tmp = *num1;
		*num1 = *num2;
		*num2 = tmp;
	}

	void swap(char* ch1, char* ch2) {
		char tmp = *ch1;
		*ch1 = *ch2;
		*ch2 = tmp;
	}

	void swap(double* db1, double* db2) {
		double tmp = *db1;
		*db1 = *db2;
		*db2 = tmp;
	}
}
