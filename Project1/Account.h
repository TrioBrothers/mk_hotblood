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
	Account(const Account& copy)					//���� ���������
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
		cout << "����ID: " << id << endl;
		cout << "�̸�: " << name << endl;
		cout << "�Աݾ�: " << balance << endl << endl;
	}
	~Account() { }
private:
	char name[MAX_LEN];			//ȸ����
	int id;						//ȸ��ID
	int balance;				//�ܾ�
};