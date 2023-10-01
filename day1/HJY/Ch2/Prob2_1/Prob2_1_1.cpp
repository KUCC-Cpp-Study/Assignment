#include <iostream>
using namespace std;

void Increase(int& num)
{
	int tmp = num;
	num = tmp + 1;
}

void Swapsign(int& num)
{
	int tmp = num;
	num = tmp * (-1);
}

int main(void)
{
	int num1;

	cout << "num1 입력 : ";
	cin >> num1;
	

	Increase(num1);
	cout << "num1 + 1: " << num1 << endl;

	Swapsign(num1);
	cout << "(num1 + 1) * (-1) : " << num1 << endl;
	
}

/* 모범 답안
void Increase(int& num)
{
	num += 1;
}

void Swapsign(int& num)
{
	num *= -1;
}*/

/*포인터 이용하기
void Increase(int* num)
{
	int tmp = *num;
	*num = tmp + 1;
}

void Swapsign(int *num)
{
	int tmp = *num;
	*num = tmp * (-1);
}

int main(void)
{
	int num1;

	cout << "num1 입력 : ";
	cin >> num1;


	Increase(&num1);
	cout << "num1 + 1: " << num1 << endl;

	Swapsign(&num1);
	cout << "(num1 + 1) * (-1) : " << num1 << endl;

}
*/