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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}

void AccountHandler::CreateAccount() {
	int idNum, bal;
	char name[NAME_LEN];

	if (cnt == ACCNUM)
		return;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> idNum;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> bal;

	acc[cnt] = new Account(name, idNum, bal);
	cnt++;
}

void AccountHandler::Deposit() {
	int accID, money;
	int afterBal;					//입금 후 잔액
	cout << "[입금]" << endl;

	cout << "계좌ID: ";
	cin >> accID;
	cout << "입금액: ";
	cin >> money;

	for (int i = 0; i < cnt; i++) {
		if (acc[i]->GetId() == accID) {
			afterBal = acc[i]->GetBalance() + money;
			acc[i]->SetBalance(afterBal);
			return;
		}
	}
	cout << "ID를 다시 확인해주세요." << endl;
}

void AccountHandler::Withdraw() {
	int accID, money;
	int modBal;				//인출 후 잔액
	cout << "[출금]" << endl;

	cout << "계좌ID: ";
	cin >> accID;
	cout << "출금액: ";
	cin >> money;

	for (int i = 0; i < cnt; i++) {
		if (acc[i]->GetId() == accID) {
			modBal = acc[i]->GetBalance() - money;
			if (modBal < 0) {
				cout << "잔액이 부족합니다." << endl;
				return;
			}
			acc[i]->SetBalance(modBal);
			return;
		}
	}
	cout << "ID를 다시 확인해주세요." << endl;
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
		cout << "바보" << endl;
	}
}
#endif __ACCOUNTHANDLER_H_
