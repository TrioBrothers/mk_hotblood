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
	if (cnt == ACCNUM)
		return;
	int sel;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cin >> sel;
	AccountInfo info = EnterAccountInfo();
	if (sel == 1) {
		acc[cnt++] = new NormalAccount(info.name, info.idNum, info.bal, info.interest);
	}
	else if (sel == 2) {
		int credit;
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> credit;
		acc[cnt++] = new HighCreditAccount(info.name, info.idNum, info.bal, info.interest, credit);
	}
	else {
		cout << "1,2 중에 선택해주세요" << endl;
	}
	
}

AccountInfo AccountHandler::EnterAccountInfo() {
	AccountInfo acc;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> acc.idNum;
	cout << "이름: ";
	cin >> acc.name;
	cout << "입금액: ";
	cin >> acc.bal;
	cout << "이자율: ";
	cin >> acc.interest;

	return acc;
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