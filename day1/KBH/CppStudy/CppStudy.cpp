// CppStudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

void inputOutput()
{
    int val = 0;

    for (size_t i = 1; i < 6; i++)
    {
        std::cout << i << "번째 정수 입력: ";
        int input;
        std::cin >> input;
        val += input;
    }

    std::cout << "합계: " << val;
}
void nameNumber()
{
    std::string myName = "";
    std::string number = "";

    std::cout << "\n이름: ";
    std::cin >> myName;
    std::cout << "전화번호: ";
    std::cin >> number;

    std::cout << "내 이름은 " << myName << "이고" << " 전화번호는 " << number << "이란다!";
}
void printGuGuDan()
{
    int number;

    std::cout << "숫자를 입력하십시오: ";

    std::cin >> number;

    std::cout << "계산중...";

    for (size_t i = 1; i < 10; i++)
    {
        std::cout << "\n";
        std::cout << number << "*" << i <<"의 결과는 " << number*i;
    }
}
void calculatePayment()
{
    int def = 50;
    int sell = 0;

    while (sell>=0)
    {
        std::cout << "\n";

        std::cout << "이번 달 얼마나 팔았니?: ";

        std::cin >> sell;

        if (sell>=0)
        {
            float result = def + sell * .12;

            std::cout << "이번달 급여: " << result;
        }

        else 
        {
            std::cout << "음수네요? 프로그램을 종료할게염";
            break;
        }
    }

}
void Swap(int *x, int *y)
{
    int a = *x;
    *x = *y;
    *y = a;
}
void Swap(char *x, char *y)
{
    int a = *x;
    *x = *y;
    *y = a;
}
void Swap(double *x, double *y)
{
    int a = *x;
    *x = *y;
    *y = a;
}
int BoxVolume(int length)
{
    return length * 1 * 1;
}
int BoxVolume(int length, int width)
{
    return length * width * 1;
}
int BoxVolume(int length, int width, int height)
{
    return length * width * height;
}

int Main()
{
    std::cout << BoxVolume(3, 3, 3) << std::endl;
    std::cout << BoxVolume(5, 5) << std::endl;
    std::cout << BoxVolume(7) << std::endl;
    /*int num1 = 10, num2 = 20;
    Swap(&num1, &num2);
    std::cout << num1 << num2;
    calculatePayment();*/
    
    /*printGuGuDan();

    inputOutput();

    nameNumber();*/
    return 0;
}



// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
