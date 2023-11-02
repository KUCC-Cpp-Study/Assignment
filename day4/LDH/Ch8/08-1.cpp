#include <iostream>
#include <cstring>
using namespace std;
namespace RISK_LEVEL
{
    enum{
        RISK_A=3,
        RISK_B=2,
        RISK_C=1
    };
    
}

class Employee
{
private:
	char name[100];
public:
	Employee(char * name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout<<"name: "<<name<<endl;
	}
	virtual int GetPay() const
	{
		return 0;
	}
	virtual void ShowSalaryInfo() const
	{  }
};

class PermanentWorker : public Employee
{
private:
	int salary; // 임금
public:
	PermanentWorker(char * name, int money)
		: Employee(name), salary(money)
	{  }
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(char * name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{  }
	void AddWorkTime(int time)
	{
		workTime+=time;
	}
	int GetPay() const
	{
		return workTime*payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;    // 영업실적
	double bonusRatio;   // 0.1
public:
	SalesWorker(char * name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{  }
	void AddSalesResult(int value)
	{
		salesResult+=value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay()  
					+ (int)(salesResult*bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) 
	{ }
	void AddEmployee(Employee* emp)
	{
		empList[empNum++]=emp;
	}
	void ShowAllSalaryInfo() const
	{
		
		for(int i=0; i<empNum; i++)
			empList[i]->ShowSalaryInfo();
		
	}
	void ShowTotalSalary() const
	{
		int sum=0;
		
		for(int i=0; i<empNum; i++)
			sum+=empList[i]->GetPay();
		
		cout<<"salary sum: "<<sum<<endl;
	}
	~EmployeeHandler()
	{
		for(int i=0; i<empNum; i++)
			delete empList[i];
	}
};

class ForeignSalesWorker : public SalesWorker
{
private:
    const int riskLevel;
public:
    ForeignSalesWorker(char *n, int m, float r, int l) :
        SalesWorker(n, m, r), riskLevel(l) // 상속된 SalesWorker(이름, 기본급, 비율) 생성, ForeignSalesWorker는 위험도만 받아서 생성
    {}
    int GetRiskPay() const
    {
        return (int)(SalesWorker::GetPay()*riskLevel/10.0f); // SalesWorker의 GetPay에 위험비율 곱한걸, ForeignSalesWorker의 GetRiskPay로 반환
    }
    int GetPay() const
    {
        return SalesWorker::GetPay()+GetRiskPay(); // ForeignSalesWorker의 총 급여는, SalesWorker GetPay(기본급) + RiskPay(위험수당)
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"salary: "<<SalesWorker::GetPay()<<endl;
        cout<<"risk pay: "<<GetRiskPay()<<endl;
        cout<<"sum: "<<GetPay()<<endl<<endl;
    }

};

int main(void)
{
    EmployeeHandler handler;

    ForeignSalesWorker * fseller1=new ForeignSalesWorker("Hong",1000,0.1,RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSalesWorker * fseller2=new ForeignSalesWorker("Yoon",1000,0.1,RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSalesWorker * fseller3=new ForeignSalesWorker("Lee",1000,0.1,RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);

    handler.ShowAllSalaryInfo();

}