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
	int idNum, bal, interest, credit;
	int sel;
	char name[NAME_LEN];

	if (cnt == ACCNUM)
		return;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cin >> sel;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> idNum;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> bal;
	cout << "이자율: ";
	cin >> interest;
	if (sel == 2) {
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> credit;
		acc[cnt++] = new HighCreditAccount(name, idNum, bal, interest, credit);
		return;
	}
	acc[cnt++] = new NormalAccount(name, idNum, bal, interest);
}

void AccountHandler::DepositMenu() {
	int accID, money;
	cout << "[입금]" << endl;

	cout << "계좌ID: ";
	cin >> accID;
	cout << "입금액: ";
	cin >> money;

	int idx = CheckAccountID(accID);
	if (idx > -1) {
		acc[idx]->DepositMoney(money);
		return;
	}
	cout << "ID를 다시 확인해주세요." << endl;
}

int AccountHandler::CheckAccountID(int id) {
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

void AccountHandler::WithdrawMenu() {
	int accID, money;
	cout << "[출금]" << endl;

	cout << "계좌ID: ";
	cin >> accID;
	cout << "출금액: ";
	cin >> money;

	int idx = CheckAccountID(accID);
	if (idx > -1) {
		if (!IsThereEnoughBalance(idx, money)) {
			cout << "잔액이 부족합니다." << endl;
		}else {
			UpdateBalance(idx, money * (-1));
		}
	}else {
		cout << "ID를 다시 확인해주세요." << endl;
	}
}

bool AccountHandler::IsThereEnoughBalance(int idx, int money) {
	return (acc[idx]->GetBalance() - money) > 0 ? true : false;
}

void AccountHandler::ShowAllCustomerInfo() {
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