#include "AccountHandler.h"
AccountHandler::AccountHandler()
	:cnt(0) { }

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

	acc[cnt++] = new Account(name, idNum, bal);
}

void AccountHandler::Deposit() {
	int accID, money;
	cout << "[입금]" << endl;

	cout << "계좌ID: ";
	cin >> accID;
	cout << "입금액: ";
	cin >> money;

	int idx = CheckId(accID);
	if (idx > -1) {
		UpdateBalance(idx, money);
		return;
	}
	cout << "ID를 다시 확인해주세요." << endl;
}

int AccountHandler::CheckId(int id) {
	for (int i = 0; i < cnt; i++) {
		if (id == acc[i]->GetId()) {
			return i;
		}
	}
	return -1;
}

void AccountHandler::UpdateBalance(int idx, int money) {
	int afterBal = acc[idx]->GetBalance() + money;
	acc[idx]->SetBalance(afterBal);
}

void AccountHandler::Withdraw() {
	int accID, money;
	cout << "[출금]" << endl;

	cout << "계좌ID: ";
	cin >> accID;
	cout << "출금액: ";
	cin >> money;

	int idx = CheckId(accID);
	if (idx > -1) {
		if (!CheckBalance(idx, money)) {
			cout << "잔액이 부족합니다." << endl;
			return;
		}
		UpdateBalance(idx, money * (-1));
		return;
	}
	cout << "ID를 다시 확인해주세요." << endl;
}

bool AccountHandler::CheckBalance(int idx, int money) {
	return (acc[idx]->GetBalance() - money) > 0 ? true : false;
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
	}
}