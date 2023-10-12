#pragma once

class Calculator
{
private:
	int plusCount;
	int minusCount;
	int multiplyCount;
	int divisionCount;

public:
	void Init();
	void ShowOPCount();
	float Add(float a, float b);
	float Min(float a, float b);
	float Mul(float a, float b);
	float Div(float a, float b);
};