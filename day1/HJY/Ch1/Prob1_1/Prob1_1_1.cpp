#include <iostream>

int main(void)
{
	int int1;
	int int2;
	int int3;
	int int4;
	int int5;

	std::cout << "1번째 정수 입력: ";
	std::cin >> int1;

	std::cout << "2번째 정수 입력: ";
	std::cin >> int2;

	std::cout << "3번째 정수 입력: ";
	std::cin >> int3;

	std::cout << "4번째 정수 입력: ";
	std::cin >> int4;

	std::cout << "5번째 정수 입력: ";
	std::cin >> int5;

	int total = int1 + int2 + int3 + int4 + int5;

	std::cout << "합계 : " << total << std::endl;

}