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
			handler.CreateAccount();	//���°���
			break;
		case 2:
			handler.DepositMenu();			//�Ա�
			break;
		case 3:
			handler.WithdrawMenu();			//���
			break;
		case 4:
			handler.ShowAllCustomerInfo();			//�������� ���
			break;
		case 5:
			return 0;					//���α׷� ����
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}
	}
	return 0;
}