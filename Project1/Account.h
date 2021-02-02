#pragma once
#include <cstring>
#include <iostream>
#define MAX_LEN 30
#define NAME_LEN 15
using namespace std;

struct AccountInfo {
	int idNum;
	char name[NAME_LEN];
	int bal;
	int interest;
};
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
	virtual void DepositMoney(int money) {
		balance = GetBalance() + money;
	}
	void ShowCustomerInfo() const {
		cout << "계좌ID: " << id << endl;
		cout << "이름: " << name << endl;
		cout << "잔액: " << balance << endl << endl;
	}
	~Account() { }
private:
	char name[MAX_LEN];			//회원명
	int id;						//회원ID
	int balance;				//잔액
};