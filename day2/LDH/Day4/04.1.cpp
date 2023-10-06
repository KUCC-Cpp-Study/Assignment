#include <iostream>
using namespace std;

class FruitSeller
{
    private:
        int Apple_Price;
        int numofApples;
        int myMoney;
    public:
        void InitMembers(int price, int num, int money)
        {
            Apple_Price=price;
            numofApples=num;
            myMoney=money;
        }
        int SaleApples(int money)
        {
            if(money<0){
                cout<<"음수 감지, 재입력 요망"<<endl;
                return 0;
            }
            int num=money/Apple_Price;
            numofApples-=num;
            myMoney+=money;
            return num;
        }
        void ShowSalesResult() const // 이 함수에 멤버함수 값 바꾸는 구문 입력 방지
        { 
            cout<<"남은 사과: "<<numofApples<<endl;
            cout<<"판매 수익: "<<myMoney<<endl<<endl;
        }
};

class FruitBuyer
{
    private:
        int numofApples;
        int myMoney;
    public:
        void InitMembers(int money)
        {
            numofApples=0;
            myMoney=money;
        }
        int BuyApples(FruitSeller &seller,  int money)
        {
            numofApples+=seller.SaleApples(money);
            myMoney-=money;
        }
        void ShowSalesResult() const
        {
            cout<<"현재 잔액: "<<myMoney<<endl;
            cout<<"사과 개수: "<<numofApples<<endl<<endl;
        }
};


int main(void)
{
    FruitSeller seller;
    seller.InitMembers(1000,20,0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    cout<<"과일 판매자의 현황"<<endl;
    seller.ShowSalesResult();
    cout<<"과일 구매자의 현황"<<endl;
    buyer.ShowSalesResult();
}