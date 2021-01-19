/*
	Banking System Ver 0.2
	�ۼ��� : ���α�
	�� �� : Account Ŭ����, ��ü ������ �迭 �߰�
*/

#include <iostream>
#include <cstring>	
#include "Account.h"
#define ACCNUM 50
#define NAME_LEN 15

using namespace std;

Account* acc[ACCNUM];		//��ü ������ �迭
int cnt = 0;

void ShowMenu();
void CreateAccount();
void Deposit();
void Withdraw();
void ShowInfo();
void Delete();

int main() {
	int num;

	while (1) {
		ShowMenu();
		cin >> num;
		switch (num) {
		case 1:
			CreateAccount();	//���°���
			break;
		case 2:
			Deposit();			//�Ա�
			break;
		case 3:
			Withdraw();			//���
			break;
		case 4:
			ShowInfo();			//�������� ���
			break;
		case 5:
			return 0;			//���α׷� ����
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}
	}
	Delete();
	return 0;
}

void ShowMenu() {
	int num = 0;
	cout << "----------Menu----------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
}

void CreateAccount() {
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

	acc[cnt] = new Account(name, idNum, bal);
	cnt++;
}

void Deposit() {
	int accID, money;
	int modBal;					//�Ա� �� �ܾ�
	cout << "[�Ա�]" << endl;

	cout << "����ID: ";
	cin >> accID;
	cout << "�Աݾ�: ";
	cin >> money;

	for (int i = 0; i < cnt; i++) {
		if (acc[i]->GetId() == accID) {
			modBal = acc[i]->GetBalance() + money;
			acc[i]->SetBalance(modBal);
			return;
		}
	}
	cout << "ID�� �ٽ� Ȯ�����ּ���." << endl;
}

void Withdraw() {
	int accID, money;
	int modBal;				//���� �� �ܾ�
	cout << "[���]" << endl;

	cout << "����ID: ";
	cin >> accID;
	cout << "��ݾ�: ";
	cin >> money;

	for (int i = 0; i < cnt; i++) {
		if (acc[i]->GetId() == accID) {
			modBal = acc[i]->GetBalance() - money;	
			if (modBal < 0) {					
				cout << "�ܾ��� �����մϴ�." << endl;
				return;
			}
			acc[i]->SetBalance(modBal);
			return;
		}
	}
	cout << "ID�� �ٽ� Ȯ�����ּ���." << endl;
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