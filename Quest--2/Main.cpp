#include <iostream>
#include "Account.h"
#include "Database.h"
using namespace std;

int main() {
	enum class ATM { newAccount = 1, balance = 2, transfer = 3, logOut = 4, exit = 5 };
	int bankOption = 0;
	Database bankAccounts;
	int IDMember;
	int PINMember; 
	while ((ATM)bankOption != ATM::exit) {
		cout << "Choose from the following Banking Options: " << endl;
		cout << "Press (1) to create a new account:\nPress (2) to check balance:\nPress (3) to transfer:\nPress (4) to log out\nPress (5) to exit" << endl;
		cin >> bankOption;
		switch ((ATM)bankOption) {
		case ATM::newAccount: {
			cout << "Create a (5 Digit) Account Member ID: " << endl;
			cin >> IDMember;
			cout << "Create a (4 Digit) Account Member Pin: " << endl;
			cin >> PINMember;
			cout << "Enter initial balance : " << endl;
			float balanceAmount;
			cin >> balanceAmount;
			if (balanceAmount <= 0) {
				cout << "Balance invalid! Initial Balance must be at least 5.00" << endl;
				cout << "Enter initial balance" << endl;
				cin >> balanceAmount;
			}
			Account accountNew(IDMember, PINMember, balanceAmount);
			bool validAccount;
			validAccount = bankAccounts.find(accountNew);
			if (validAccount == false) {
				cout << "Bank Member account successfully created. " << endl;
				bankAccounts.append(accountNew);
			}
			else {
				cout << "Account Member ID Invalid. Please try again. " << endl;
			}
			break;
		}
		case ATM::balance: {
			if (IDMember == 0 || PINMember == 0) {
				cout << "Enter Correct Account Member ID: " << endl;
				cin >> IDMember;
				cout << "Enter Correct Account Member Pin: " << endl;
				cin >> PINMember;
			}
			float amount = bankAccounts.findBalance(IDMember, PINMember);
			cout << "Account Balance: " << amount << endl;
			
			break; }
		case ATM::transfer: {
			cout << "Transfer from: Enter Account Member ID: " << endl;
			cin >> IDMember;
			cout << "Transfer from: Enter Account Member Pin: " << endl;
			cin >> PINMember;
			Account& const account1 = bankAccounts.findAccount(IDMember, PINMember);
			cout << "Transfer to: Enter Account Member ID: " << endl;
			cin >> IDMember;
			cout << "Transfer to: Enter Account Member Pin: " << endl;
			cin >> PINMember;
			Account& const account2 = bankAccounts.findAccount(IDMember, PINMember);
			transfer(account1, account2);
			break; }
		case ATM::logOut:
			char acctLogout;
			cout << "Do you wish to log in to another account?\nPress (Y)es or (N)o" << endl;
			cin >> acctLogout;
			if (acctLogout == 'y' || acctLogout == 'Y') {
				cout << "Enter Account Member ID: " << endl;
				cin >> IDMember;
				cout << "Enter Account Member Pin: " << endl;
				cin >> PINMember;
			}
			else {
				IDMember = 0;
				PINMember = 0;
			}
			break; 
		case ATM::exit:
			cout << "Exiting program" << endl;
			break;
		}
	}
	system("PAUSE");
	return 0;
}