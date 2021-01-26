#pragma once
#include "Account.h"
#include <iostream>
#include <cstring>
using namespace std;

class NormalAccount : public Account {
public:
	NormalAccount(char* name, int id, int bal, int interRate)
		: Account(name, id, bal), interestRate(interRate){ }
	
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
