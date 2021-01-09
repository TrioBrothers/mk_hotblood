#include <iostream>
#include <cstring>
#define ACCNUM 20
void ShowMenu();
void CreateAccount();
void Deposit();
void Withdraw();
void ShowInfo();

using namespace std;

typedef struct {
	int id;
	int balance;
	char name[20];
}Account;

Account customer[ACCNUM];
int cnt = 0;

int main(){
	int num;
	int flag = 1;

	while (flag) {
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
			flag = 0;			//프로그램 종료
			break;
		default:
			cout << "잘못 입력하셨습니다." << endl;
			break;
		}
	}
	return 0;
}

void ShowMenu() {
	cout << "----------Menu----------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}

void CreateAccount() {
	if (cnt == ACCNUM)
		return;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> customer[cnt].id;
	cout << "이름: ";
	cin >> customer[cnt].name;
	cout << "입금액: ";
	cin >> customer[cnt].balance;
	cnt++;
}

void Deposit() {
	int accID, money;
	cout << "[입금]" << endl;
	
	cout << "계좌ID: ";
	cin >> accID;
	cout << "입금액: ";
	cin >> money;

	for (int i = 0; i < cnt; i++) {
		if (customer[i].id == accID) {
			customer[i].balance += money;
			return;
		}
	}
	cout << "ID를 다시 확인해주세요." << endl;
}

void Withdraw() {
	int accID, money;
	cout << "[출금]" << endl;

	cout << "계좌ID: ";
	cin >> accID;
	cout << "출금액: ";
	cin >> money;

	for (int i = 0; i < cnt; i++) {
		if (customer[i].id == accID) {
			if (customer[i].balance < money) {
				cout << "잔액이 부족합니다." << endl;
				return;
			}
			customer[i].balance -= money;
			return;
		}
	}
	cout << "ID를 다시 확인해주세요." << endl;
}
void ShowInfo() {
	cout << "-------------------------" << endl;
	for (int i = 0; i < cnt; i++) {
		cout << "계좌ID: " << customer[i].id << endl;
		cout << "이름: " << customer[i].name << endl;
		cout << "입금액: " << customer[i].balance << "\n" <<endl;
	}
}