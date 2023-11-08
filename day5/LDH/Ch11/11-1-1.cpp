#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;    
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void Shut()
	{
		cout<<"BBANG!"<<endl;
		bullet--;
	}
    friend class Police;
};

class Police
{
private:
	int handcuffs;    
	Gun * pistol;     
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if(bnum>0)
			pistol=new Gun(bnum);
		else
			pistol=NULL;
	}
    Police(const Police& police)
        : handcuffs(police.handcuffs)
    {
        pistol=police.pistol;
    }
	void PutHandcuff() 
	{
		cout<<"SNAP!"<<endl;
		handcuffs--;
	}
	void Shut()
	{
		if(pistol==NULL)
			cout<<"Hut BBANG!"<<endl;
		else
			pistol->Shut();
	}
	~Police()
	{
		if(pistol!=NULL)
			delete pistol;
	}
    Police& operator= (const Police& police)
    {
        if(this->pistol!=NULL)
            delete []pistol;
        handcuffs=police.handcuffs;
        pistol = new Gun(police.pistol->bullet);
        return *this;
    }
    void ShowInfo()
    {
        cout<<handcuffs<<endl;
        cout<<pistol->bullet<<endl;
    }
};

int main(void)
{
	Police pman1(5, 3);
    Police pman2(4, 7);

    pman2=pman1;
    pman2.ShowInfo();
    pman2.PutHandcuff();
    pman2.Shut();

    Police pman3=pman1;
    pman3.ShowInfo();
    pman3.PutHandcuff();
    pman3.Shut();    
	return 0;
}