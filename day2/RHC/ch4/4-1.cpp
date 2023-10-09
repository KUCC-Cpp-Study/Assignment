#include <iostream>
using namespace std;

class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(const int price, const int num, const int money) {
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(const int money) {
		if (money < 0) return 0;
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const{
		cout << "남은 사과 : " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
	}
};

class FruitBuyer {
	int myMoney;
	int numOfApples;

public:
	void InitMembers(const int money) {
		myMoney = money;
		numOfApples = 0;
	}

	void BuyApples(FruitSeller& seller, int money) {
		if (money < 0) return;

		numOfApples += seller.SaleApples(money);
		myMoney -= money;
		return;
	}
	void ShowBuyResult() const{
		cout << "현재 잔액 : " << myMoney << endl;
		cout << "사과 개수 : " << numOfApples << endl << endl;
	}
};

namespace part4_1 {
	void problem() {
		FruitSeller seller;
		seller.InitMembers(1000, 20, 0);
		FruitBuyer buyer;
		buyer.InitMembers(5000);
		buyer.BuyApples(seller, 2000);

		cout << "과일 판매자 현황" << endl;
		seller.ShowSalesResult();
		cout << "과일 구매자 현황" << endl;
		buyer.ShowBuyResult();
	}
}
