#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

namespace probelev
{
	class Gun
	{
	private:
		int bullet;
	public:
		Gun(int bnum) : bullet(bnum)
		{

		}

		void Shot()
		{
			cout << "Shot Bullet" << endl;
			bullet--;
		}
		int GetBullet()
		{
			return bullet;
		}
	};

	class Police
	{
	private:
		int handCuffs;
		Gun* pistol;

	public:
		Police(int bnum, int bcuff) : handCuffs(bcuff)
		{
			if (bnum > 0)
				pistol = new Gun(bnum);
			else
				pistol = NULL;
		}

		Police(const Police& pman) : handCuffs(pman.handCuffs)
		{
			if (pman.pistol!=NULL)
			{
				int bnum = pman.pistol->GetBullet();
				pistol = new Gun(bnum);
			}
			else
				pistol = NULL;
		}
		Police& operator=(const Police& ref)
		{
			cout << "operator= called" << endl;
			handCuffs = ref.handCuffs;
			pistol = ref.pistol;
			return *this;
		}
		void PutHandCuff()
		{
			cout << "HandCuffed bad guy" << endl;
			handCuffs--;
		}
		void Shoot()
		{
			if (pistol == NULL)
				cout << "No Bullet" << endl;
			else
				pistol->Shot();
		}
		~Police()
		{
			cout << "delete" << endl;
			if (pistol != NULL)
				delete pistol;
		}
	};

	class Book
	{
	private:
		char* title;
		char* isbn;
		int price;

	public:
		Book(const char* bookt, const char* bookisbn, int bookprice) : price(bookprice)
		{
			title = new char[strlen(bookt) + 1];
			isbn = new char[strlen(bookisbn) + 1];
			strcpy(title, bookt);
			strcpy(isbn, bookisbn);
		}

		void ShowBookInfo()
		{
			cout << "제목 : " << title << endl;
			cout << "ISBN : " << isbn << endl;
			cout << "가격 : " << price << endl;
		}
	};

	class EBook : public Book
	{
	private:
		char* DRMKey;

	public:
		EBook(const char* bookt, const char* bookisbn, int bookprice, const char* key) : Book(bookt, bookisbn, bookprice)
		{
			DRMKey = new char[strlen(key) + 1];
			strcpy(DRMKey, key);
		}

		void ShowEBookInfo()
		{
			ShowBookInfo();
			cout << "인증키 : " << DRMKey << endl;
		}

	};

	void Problem1()
	{
		Police pol1(0, 3);
		Police pol2(5, 5);
		pol1 = pol2;
		pol1.Shoot();

		
	}
}

int main()
{
	probelev::Problem1();
}