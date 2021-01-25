#ifndef __ACCOUNTHANDLER_H_
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
	void Withdraw();
	void ShowInfo();
	~AccountHandler();
private:
	int cnt;
	Account* acc[ACCNUM];
};

AccountHandler::AccountHandler()
	:cnt(0){ }

void AccountHandler::ShowMenu() {
	int num = 0;
	cout << "----------Menu----------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
}

void AccountHandler::CreateAccount() {
	int idNum, bal;
	char name[NAME_LEN];

	if (cnt == ACCNUM)
		return;
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> idNum;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> bal;

	acc[cnt] = new Account(name, idNum, bal);
	cnt++;
}

void AccountHandler::Deposit() {
	int accID, money;
	int afterBal;					//�Ա� �� �ܾ�
	cout << "[�Ա�]" << endl;

	cout << "����ID: ";
	cin >> accID;
	cout << "�Աݾ�: ";
	cin >> money;

	for (int i = 0; i < cnt; i++) {
		if (acc[i]->GetId() == accID) {
			afterBal = acc[i]->GetBalance() + money;
			acc[i]->SetBalance(afterBal);
			return;
		}
	}
	cout << "ID�� �ٽ� Ȯ�����ּ���." << endl;
}

void AccountHandler::Withdraw() {
	int accID, money;
	int modBal;				//���� �� �ܾ�
	cout << "[���]" << endl;

	cout << "����ID: ";
	cin >> accID;
	cout << "��ݾ�: ";
	cin >> money;

	for (int i = 0; i < cnt; i++) {
		if (acc[i]->GetId() == accID) {
			modBal = acc[i]->GetBalance() - money;
			if (modBal < 0) {
				cout << "�ܾ��� �����մϴ�." << endl;
				return;
			}
			acc[i]->SetBalance(modBal);
			return;
		}
	}
	cout << "ID�� �ٽ� Ȯ�����ּ���." << endl;
}
void AccountHandler::ShowInfo() {
	cout << "-------------------------" << endl;
	for (int i = 0; i < cnt; i++) {
		acc[i]->ShowCustomerInfo();
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < cnt; i++) {
		delete acc[i];
		cout << "�ٺ�" << endl;
	}
}
#endif __ACCOUNTHANDLER_H_
