#ifndef __ACCOUNT_H_
#define __ACCOUNT_H_
#include <cstring>
#include <iostream>
using namespace std;

class Account {
private:
	char* name;			//회원명
	int id;				//회원ID
	int balance;		//잔액
public:
	Account(char* name, int id, int bal)
		:balance(bal), id(id)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	Account(const Account& copy)					//깊은 복사생성자
		: id(copy.id),balance(copy.balance){
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	int GetId() const {
		return id;
	}
	int GetBalance() {
		return balance;
	}
	void SetBalance(int modBalance) {
		balance = modBalance;
	}
	void ShowCustomerInfo() {
		cout << "계좌ID: " << id << endl;
		cout << "이름: " << name << endl;
		cout << "입금액: " << balance << endl << endl;
	}
	~Account() {
		delete[]name;
	}
};
#endif