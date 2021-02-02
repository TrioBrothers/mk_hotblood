#pragma once
#include <cstring>
#include <iostream>
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#define ACCNUM 50
#define NAME_LEN 15

using namespace std;
//struct AccountInfo {
//	int idNum;
//	char name[NAME_LEN];
//	int bal;
//	int interest;
//};
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
	Account* acc[ACCNUM];
};