#include <iostream>
using namespace std;

class Car
{
private:
    int gasolineGauge;
public:
    Car(int gas) : gasolineGauge(gas)
    {}
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;
public:
    HybridCar(int gas, int elec) :  Car(gas), electricGauge(elec)
    {}
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGague;
public:
    HybridWaterCar(int gas, int elec, int water) : HybridCar(gas, elec), waterGague(water)
    {}
    void ShowCurrentGauge()
    {
        cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
        cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
        cout<<"잔여 워터량: "<<GetWaterGauge()<<endl;

    }
    int GetWaterGauge()
    {
        return waterGague;
    }    
};

int main(void)
{
    HybridWaterCar hwCar(3, 10, 7);
    hwCar.ShowCurrentGauge();
}