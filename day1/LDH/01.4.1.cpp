// 본 파일에선 헤더파일을 먼저 선언한다.
// 함수 앞에, 소속된 namespace를 명시해야 한다.
// 여기선 using namespace AddProgram하면 오류난다.

#include "01.4.h"

int AddProgram::add(int a, int b)
{
    return a+b;
}

int MutipleProgram::multiple(int a, int b)
{
    return a*b;
}