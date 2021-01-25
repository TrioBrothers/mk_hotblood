#pragma once
#include <cstring>
#include <iostream>
#include "Account.h"
#define ACCNUM 50
#define NAME_LEN 15

using namespace std;

class AccountHandler{
public:
	AccountHandler();
	void ShowMenu();
	void CreateAccount();
	void DepositMenu();
	int CheckAccountID(int id);
	void UpdateBalance(int idx, int money);
	void WithdrawMenu();
	bool IsThereEnoughBalance(int idx, int money);
	void ShowAllCustomerInfo();
	~AccountHandler();
private:
	int cnt;
	Account* acc[ACCNUM];
};