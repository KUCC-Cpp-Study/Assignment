#include <iostream>

int main(void)
{
	char callnum[100];

	std::cout << "전화번호를 작성하세요 ";
	std::cin >> callnum;

	std::cout << callnum << std::endl;

	return 0;
}