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
			flag = 0;			//���α׷� ����
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}
	}
	return 0;
}

void ShowMenu() {
	cout << "----------Menu----------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
}

void CreateAccount() {
	if (cnt == ACCNUM)
		return;
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> customer[cnt].id;
	cout << "�̸�: ";
	cin >> customer[cnt].name;
	cout << "�Աݾ�: ";
	cin >> customer[cnt].balance;
	cnt++;
}

void Deposit() {
	int accID, money;
	cout << "[�Ա�]" << endl;
	
	cout << "����ID: ";
	cin >> accID;
	cout << "�Աݾ�: ";
	cin >> money;

	for (int i = 0; i < cnt; i++) {
		if (customer[i].id == accID) {
			customer[i].balance += money;
			return;
		}
	}
	cout << "ID�� �ٽ� Ȯ�����ּ���." << endl;
}

void Withdraw() {
	int accID, money;
	cout << "[���]" << endl;

	cout << "����ID: ";
	cin >> accID;
	cout << "��ݾ�: ";
	cin >> money;

	for (int i = 0; i < cnt; i++) {
		if (customer[i].id == accID) {
			if (customer[i].balance < money) {
				cout << "�ܾ��� �����մϴ�." << endl;
				return;
			}
			customer[i].balance -= money;
			return;
		}
	}
	cout << "ID�� �ٽ� Ȯ�����ּ���." << endl;
}
void ShowInfo() {
	cout << "-------------------------" << endl;
	for (int i = 0; i < cnt; i++) {
		cout << "����ID: " << customer[i].id << endl;
		cout << "�̸�: " << customer[i].name << endl;
		cout << "�Աݾ�: " << customer[i].balance << "\n" <<endl;
	}
}