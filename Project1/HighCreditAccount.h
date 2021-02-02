#pragma once
#include "NormalAccount.h"
#include <iostream>
#include <cstring>
using namespace std;

class HighCreditAccount : public NormalAccount {
public:
	HighCreditAccount(AccountInfo info, int credit)
		:NormalAccount(info) , creditRating(credit){ 		}

	virtual void DepositMoney(int money) {
		int afterBal = GetBalance() + money * (1 + GetInterestRate() + AddInterestRate());
		SetBalance(afterBal);
	}
	double AddInterestRate() {
		switch (creditRating) {
		case 1: 
			return 0.07;
		case 2:
			return 0.04;
		case 3:
			return 0.02;
		}
	}
	~HighCreditAccount() {}
private:
	int creditRating;
};