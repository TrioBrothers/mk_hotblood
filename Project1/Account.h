#ifndef __ACCOUNT_H_
#define __ACCOUNT_H_
#include <cstring>
#include <iostream>
using namespace std;

class Account {
private:
	char* name;			//ȸ����
	int id;				//ȸ��ID
	int balance;		//�ܾ�
public:
	Account(char* name, int id, int bal)
		:balance(bal), id(id)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	Account(const Account& copy)					//���� ���������
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
		cout << "����ID: " << id << endl;
		cout << "�̸�: " << name << endl;
		cout << "�Աݾ�: " << balance << endl << endl;
	}
	~Account() {
		delete[]name;
	}
};
#endif