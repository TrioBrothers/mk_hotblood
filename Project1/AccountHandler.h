#pragma once
#include <cstring>
#include <iostream>
#include "AccountArray.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

using namespace std;
class AccountHandler{
public:
	AccountHandler();
	void ShowMenu();
	void CreateAccount();
	AccountInfo EnterAccountInfo();
	void DepositMenu();
	int CheckAccountID(int id);
	void UpdateBalance(int idx, int money);
	void WithdrawMenu();
	bool IsThereEnoughBalance(int idx, int money);
	void ShowAllCustomerInfo();
	~AccountHandler();
private:
	int cnt;
	BoundCheckAccountPtrArray acc;
};