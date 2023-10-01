#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(void)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++)
		cout << i << "th random number : " << rand() % 100 << endl;
	return 0;
}