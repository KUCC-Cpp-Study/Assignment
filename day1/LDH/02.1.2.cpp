void SwapByRef2(int &ref1, int &ref2)
{
    int temp=ref1;
    ref1=ref2;
    ref2=temp;
}

// SwapByRef(23, 45)로 호출하면 오류 발생하는 이류
// 변수명이 아닌, 변수의 값(상수)를 인자로 투입했기 때문.