#include <iostream>
using namespace std;

class Rectangle
{
private :
    int width;
    int height;
public :
    Rectangle(int w, int h) : width(w), height(h)
    {

    }
    void ShowAreaInfo()
    {
        cout<<"면적: "<<width*height<<endl;
    }
};

class Square : public Rectangle
{ 
public :
    Square(int n) : Rectangle(n,n)
    {

    }
};

int main(void)
{
    Rectangle rec(4,3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    
}