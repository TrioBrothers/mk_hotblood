#include "AccountHandler.h"
AccountHandler::AccountHandler()
	:cnt(0) { }

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

	acc[cnt++] = new Account(name, idNum, bal);
}

void AccountHandler::Deposit() {
	int accID, money;
	cout << "[�Ա�]" << endl;

	cout << "����ID: ";
	cin >> accID;
	cout << "�Աݾ�: ";
	cin >> money;

	int idx = CheckId(accID);
	if (idx > -1) {
		UpdateBalance(idx, money);
		return;
	}
	cout << "ID�� �ٽ� Ȯ�����ּ���." << endl;
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
	cout << "[���]" << endl;

	cout << "����ID: ";
	cin >> accID;
	cout << "��ݾ�: ";
	cin >> money;

	int idx = CheckId(accID);
	if (idx > -1) {
		if (!CheckBalance(idx, money)) {
			cout << "�ܾ��� �����մϴ�." << endl;
			return;
		}
		UpdateBalance(idx, money * (-1));
		return;
	}
	cout << "ID�� �ٽ� Ȯ�����ּ���." << endl;
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