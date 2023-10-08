#include <iostream>
#include <cstring>
using namespace std;

class Printer
{
private:
	char svstr[30];
public:
	void Setstring(const char* str);
	void ShowString();
};

void Printer::Setstring(const char* str)
{
	strcpy_s(svstr, str);
}

void Printer::ShowString()
{
	cout << svstr << endl;
}

int main(void)
{
	Printer pnt;
	pnt.Setstring("Hello world!");
	pnt.ShowString();

	pnt.Setstring("I love C++");
	pnt.ShowString();
	return 0;
}