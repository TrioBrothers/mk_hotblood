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
	if (cnt == ACCNUM)
		return;
	int sel;
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cin >> sel;
	AccountInfo info = EnterAccountInfo();
	if (sel == 1) {
		acc[cnt++] = new NormalAccount(info.name, info.idNum, info.bal, info.interest);
	}
	else if (sel == 2) {
		int credit;
		cout << "�ſ���(1toA, 2toB, 3toC): ";
		cin >> credit;
		acc[cnt++] = new HighCreditAccount(info.name, info.idNum, info.bal, info.interest, credit);
	}
	else {
		cout << "1,2 �߿� �������ּ���" << endl;
	}
	
}

AccountInfo AccountHandler::EnterAccountInfo() {
	AccountInfo acc;
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> acc.idNum;
	cout << "�̸�: ";
	cin >> acc.name;
	cout << "�Աݾ�: ";
	cin >> acc.bal;
	cout << "������: ";
	cin >> acc.interest;

	return acc;
}
void AccountHandler::DepositMenu() {
	int accID, money;
	cout << "[�Ա�]" << endl;

	cout << "����ID: ";
	cin >> accID;
	cout << "�Աݾ�: ";
	cin >> money;

	int idx = CheckAccountID(accID);
	if (idx > -1) {
		acc[idx]->DepositMoney(money);
		return;
	}
	cout << "ID�� �ٽ� Ȯ�����ּ���." << endl;
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
	cout << "[���]" << endl;

	cout << "����ID: ";
	cin >> accID;
	cout << "��ݾ�: ";
	cin >> money;

	int idx = CheckAccountID(accID);
	if (idx > -1) {
		if (!IsThereEnoughBalance(idx, money)) {
			cout << "�ܾ��� �����մϴ�." << endl;
		}else {
			UpdateBalance(idx, money * (-1));
		}
	}else {
		cout << "ID�� �ٽ� Ȯ�����ּ���." << endl;
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