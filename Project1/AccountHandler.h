#pragma once
#define __ACCOUNTHANDLER_H_
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
	void Deposit();
	int CheckId(int id);
	void UpdateBalance(int idx, int money);
	void Withdraw();
	bool CheckBalance(int idx, int money);
	void ShowInfo();
	~AccountHandler();
private:
	int cnt;
	Account* acc[ACCNUM];
};