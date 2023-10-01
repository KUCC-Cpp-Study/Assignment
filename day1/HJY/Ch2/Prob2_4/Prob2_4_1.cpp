#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str1[] = "ABC 121";
	char str2[] = "DEF 687";
	char str3[30];

	cout << "str1의 길이는" << strlen(str1) << "이다." << endl;
	cout << "str2의 길이는" << strlen(str2) << "이다." << endl;

	strcpy(str3, str1);
	cout << "str3는" << str3 << "이다." << endl;

	strcat(str3, str2);
	cout << "str3는" << str3 << "이다." << endl;

	if (strcmp(str1, str2) == 0)
		cout << "str1과 str2는 같다." << endl;
	else
		cout << "str1과 str2는 다르다." << endl;

	return 0;
}