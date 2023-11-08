#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray 
{
private:
	int * arr;
	int arrlen;

	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }

public:
	BoundCheckIntArray(int len) :arrlen(len)
	{
		arr=new int[len];
	}
	int& operator[] (int idx)
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		
		return arr[idx];
	}
	~BoundCheckIntArray()
	{
		delete []arr;
	}
};

typedef BoundCheckIntArray* BoundCheckIntArrayPtr;

class BoundCheckInt2DArray 
{
private:
    BoundCheckIntArrayPtr *arr;
	int arrlen;

	BoundCheckInt2DArray(const BoundCheckInt2DArray& arr) { }
	BoundCheckInt2DArray& operator=(const BoundCheckInt2DArray& arr) { }

public:
	BoundCheckInt2DArray(int row, int col) :arrlen(col)
	{
        for(int i=0; i<col; i++)
        {
            arr=new BoundCheckIntArrayPtr();
            for(int i=0; i<col; i++)
                arr[i]=new BoundCheckIntArray(row);
        }

	}
	BoundCheckIntArray& operator[](int idx)
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Error";
			exit(1);
		}
		return *(arr[idx]);
	}
	~BoundCheckInt2DArray()
	{
		for(int i=0; i<arrlen; i++)
			delete arr[i];
	}

};

int main(void)
{
	BoundCheckInt2DArray arr2d(4,5);

	int num=1;
	for(int i=0; i<5; i++)
		for(int j=0; j<4; j++)
			arr2d[i][j]=num++;
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<4; j++)
			cout<<arr2d[i][j]<<' ';
		cout<<endl;
	}

	return 0;
}
