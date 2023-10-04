#include <iostream>

namespace part1_1
{
	void problem1() {
		int sum = 0;
		int tmp;
		for (int i = 1; i <= 5; ++i) {
			std::cout << i << "번째 정수 입력: ";
			std::cin >> tmp;
			sum += tmp;
		}
		std::cout << "합계 : " << sum << std::endl;
	}

	void problem2() {
		char name_num[100];
		std::cout << "enter name and number without space : ";
		std::cin >> name_num;
		std::cout << name_num << std::endl;
	}

	void problem3() {
		int num;
		std::cout << "enter a number between 1~9 : ";
		std::cin >> num;
		for (int i = 1; i <= 9; ++i) {
			std::cout << num << "X" << i << "=" << num * i << std::endl;
		}
	}

	void problem4() {
		int input = 0;
		while (input != -1) {
			std::cout << "판매 금액을 만원 단위로 입력(-1 to end) : ";
			std::cin >> input;
			std::cout << "이번 달 급여 : " << 50 + input * (0.12) << "만원" << std::endl;
		}
		std::cout << "프로그램을 종료합니다." << std::endl;
	}
}
