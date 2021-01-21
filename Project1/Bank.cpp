#include <iostream>
#include <cstring>	
#include "Account.h"
#include "AccountHandler.h"

using namespace std;

int main() {
	int num;
	AccountHandler handler;

	while (1) {
		handler.ShowMenu();
		cin >> num;
		switch (num) {
		case 1:
			handler.CreateAccount();	//계좌개설
			break;
		case 2:
			handler.Deposit();			//입금
			break;
		case 3:
			handler.Withdraw();			//출금
			break;
		case 4:
			handler.ShowInfo();			//계좌정보 출력
			break;
		case 5:
			return 0;					//프로그램 종료
		default:
			cout << "잘못 입력하셨습니다." << endl;
			break;
		}
	}
	return 0;
}