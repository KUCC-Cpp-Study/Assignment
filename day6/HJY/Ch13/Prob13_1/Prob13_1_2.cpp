#include <iostream>
using namespace std;

template<typename T>
T SumArray(T arr[], int len)
{
	T sum = (T)0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

int main(void)
{
	int arr1[] = { 10, 20, 30 };
	cout << SumArray(arr1, sizeof(arr1) / sizeof(int)) << endl;
	double arr2[] = { 12.1,68.7,11.1 };
	cout << SumArray(arr2, sizeof(arr2) / sizeof(double)) << endl;
	return 0;
}