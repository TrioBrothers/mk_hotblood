/*
	Banking System Ver 0.4.2
	작성자 : 정민규
	내 용 : 함수별 기능 세분화
*/

#include <iostream>
#include <cstring>	
#include "Account.h"
#define ACCNUM 50
#define NAME_LEN 15

using namespace std;

Account* acc[ACCNUM];		//객체 포인터 배열
int cnt = 0;

void ShowMenu();
void CreateAccount();
void Deposit();
int CheckId(int id);
void Withdraw();
void CheckBalance(int idx, int money);
void ShowInfo();
void Delete();

int main() {
	int num;

	while (1) {
		ShowMenu();
		cin >> num;
		switch (num) {
		case 1:
			CreateAccount();	//계좌개설
			break;
		case 2:
			Deposit();			//입금
			break;
		case 3:
			Withdraw();			//출금
			break;
		case 4:
			ShowInfo();			//계좌정보 출력
			break;
		case 5:
			return 0;			//프로그램 종료
		default:
			cout << "잘못 입력하셨습니다." << endl;
			break;
		}
	}
	Delete();
	return 0;
}

void ShowMenu() {
	int num = 0;
	cout << "----------Menu----------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}

void CreateAccount() {
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

void Deposit() {
	int accID, money, idx;
	int afterBal;					//입금 후 잔액
	cout << "[입금]" << endl;
	cout << "계좌ID: ";
	cin >> accID;
	cout << "입금액: ";
	cin >> money;

	idx = CheckId(accID);		
	cout << idx << endl;
	if (idx > -1) {
		afterBal = acc[idx]->GetBalance() + money;
		acc[idx]->SetBalance(afterBal);
		return;
	}
	return;
}

int CheckId(int id) {					//존재하는 ID인지 확인하는 함수
	for (int i = 0; i < cnt; i++) {
		if (acc[i]->GetId() == id) {
			return i;
		}
	}
	cout << "ID를 다시 확인해주세요." << endl;
	return -1;
}

void Withdraw() {
	int accID, money, idx;
	cout << "[출금]" << endl;
	cout << "계좌ID: ";
	cin >> accID;
	cout << "출금액: ";
	cin >> money;

	idx = CheckId(accID);
	if (idx > -1) {
		CheckBalance(idx, money);
	}
}

void CheckBalance(int idx, int money) {			//출금이 가능한지 확인하는 함수
	int afterBal;
	afterBal = acc[idx]->GetBalance() - money;
	if (afterBal < 0) {
		cout << "잔액이 부족합니다." << endl;
		return;
	}
	acc[idx]->SetBalance(afterBal);
	return;
}

void ShowInfo() {
	cout << "-------------------------" << endl;
	for (int i = 0; i < cnt; i++) {
		acc[i]->ShowCustomerInfo();
	}
}

void Delete() {
	for (int i = 0; i < cnt; i++) {
		delete acc[i];
	}
}