int SimpleFunc(int a=10)
{
    return a+1;
}

int SimpleFunc(void)
{
    return 10;
}

// SimpleFunc()로 함수를 호출할 경우, 어떤 함수를 호출해야 하는 지 판단하지 못해 오류가 발생한다.