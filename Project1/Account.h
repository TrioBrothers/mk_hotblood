#pragma once
#include <cstring>
#include <iostream>
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
	Account(const Account& copy)					//±íÀº º¹»ç»ý¼ºÀÚ
		: id(copy.id),balance(copy.balance){
		strcpy(name, copy.name);
	}
	Account& operator=(const Account& ref) {
		id = ref.id;
		balance = ref.balance;
		strcpy(name, ref.name);
		return *this;
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
		cout << "°èÁÂID: " << id << endl;
		cout << "ÀÌ¸§: " << name << endl;
		cout << "ÀÜ¾×: " << balance << endl << endl;
	}
	~Account() { }
private:
	char name[NAME_LEN];			//È¸¿ø¸í
	int id;						//È¸¿øID
	int balance;				//ÀÜ¾×
};