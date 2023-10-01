#include <iostream>

int salary(int sale)
{
	return (int)(50 + sale * 0.12);
}

int main(void)
{
	int sale;
	while (1) {
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin >> sale;
		if (sale == -1)
			break;
		std::cout << "이번 달 급여: ";
		std::cout << salary(sale) << "만원" << std::endl;
	}
	std::cout << "프로그램을 종료합니다." << std::endl;
	return 0;
}