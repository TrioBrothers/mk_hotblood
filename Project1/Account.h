#ifndef __ACCOUNT_H_
#define __ACCOUNT_H_
#include <cstring>
#include <iostream>
#define MAX_LEN 30
using namespace std;

class Account {
private:
	char name[MAX_LEN];			//ȸ����
	int id;						//ȸ��ID
	int balance;				//�ܾ�
public:
	Account(char* name, int id, int bal)
		:balance(bal), id(id)
	{
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
	~Account() {
		delete[]name;
	}
};
#endif