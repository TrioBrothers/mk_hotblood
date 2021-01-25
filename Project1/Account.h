#pragma once
#define __ACCOUNT_H_
#include <cstring>
#include <iostream>
#define MAX_LEN 30
using namespace std;

class Account {
public:

	Account(char* name, int id, int bal)
		:balance(bal), id(id)
	{
		strcpy(this->name, name);
	}
	Account(const Account& copy)					//깊은 복사생성자
		: id(copy.id),balance(copy.balance){
		strcpy(name, copy.name);
	}
	int GetId() const {
		return id;
	}
	int GetBalance() const {
		return balance;
	}
	void SetBalance(int modBalance) {
		balance = modBalance;
	}
	void ShowCustomerInfo() const {
		cout << "계좌ID: " << id << endl;
		cout << "이름: " << name << endl;
		cout << "입금액: " << balance << endl << endl;
	}
	~Account() { }
private:
	char name[MAX_LEN];			//회원명
	int id;						//회원ID
	int balance;				//잔액
};