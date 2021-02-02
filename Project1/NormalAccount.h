#pragma once
#include "Account.h"
#include <iostream>
#include <cstring>
#define NAME_LEN 15
using namespace std;

struct AccountInfo {
	int idNum;
	char name[NAME_LEN];
	int bal;
	int interest;
};
class NormalAccount : public Account {
public:
	NormalAccount(AccountInfo info)
		: Account(info.name, info.idNum, info.bal), interestRate(info.interest){ }
	
	virtual void DepositMoney(int money) {
		int afterBal = GetBalance() + money * (1 + GetInterestRate());
		SetBalance(afterBal);
	}

	double GetInterestRate() {
		return interestRate/100;
	}
	~NormalAccount() {}
private:
	double interestRate;		//¿Ã¿⁄¿≤
};
