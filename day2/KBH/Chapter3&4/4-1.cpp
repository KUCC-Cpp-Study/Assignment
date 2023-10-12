#include <iostream>
using namespace std;

namespace Fruit
{
	class FruitSeller
	{
	private:
		int APPLE_PRICE;
		int numOfApples;
		int myMoney;

	public:
		void InitMembers(int price, int num, int monsy)
		{
			APPLE_PRICE = price;
			numOfApples = num;
			myMoney = monsy;
		}

		int SaleApples(int money)
		{
			int saleNum = money / APPLE_PRICE;
			numOfApples -= saleNum;
			myMoney += money;

			return saleNum;
		}

		void ShowSalesREsult()
		{
			cout << "�������: " << numOfApples << endl;
			cout << "�Ǹż���: " << myMoney << endl;
		}
	};

	class FruitBuyer
	{
		int myMoney;
		int numOfApples;

	public:
		void InitMemebers(int money)
		{
			myMoney = money;
			numOfApples = 0;
		}

		void BuyApples(FruitSeller& seller, int money)
		{
			if (money < 0)
			{
				cout << "���Ÿ� �������� ������ ������ �� �����ϴ�." << endl;
				return;
			}

			numOfApples += seller.SaleApples(money);
			myMoney -= money;

		}

		int GetMoney() const
		{
			return myMoney;
		}

		int GetNum() const
		{
			return numOfApples;
		}

		void ShowBuyResult() const
		{
			cout << "���� �ܾ�: " << GetMoney() << endl;
			cout << "��� ����: " << GetNum() << endl;
		}
	};

	void Problem()
	{
		FruitSeller seller;
		seller.InitMembers(1000, 20, 0);
		FruitBuyer buyer;
		buyer.InitMemebers(5000);
		buyer.BuyApples(seller, -1000);

		seller.ShowSalesREsult();
		buyer.ShowBuyResult();
	}
}


