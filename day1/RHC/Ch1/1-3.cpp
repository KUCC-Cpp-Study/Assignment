#include <iostream>

namespace part1_3
{
	int BoxVolume(int length, int width, int height) {
		return length * width * height;
	}
	int BoxVolume(int length, int width) {
		return length * width;
	}
	int BoxVolume(int length) {
		return length;
	}
	void problem1() {
		std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
		std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
		std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
	}

	int SimpleFunc(int a = 10) {
		return a + 1;
	}
	int SimpleFunc(void) {
		return 10;
	}

	void problem2() {
		//void�� a=10���� defalut value�� �����ϸ� �μ� ����� ��ġ�ϹǷ� � �Լ��� �����ߴ��� �� �� ����.
	}
}