#include <iostream>
#include "Account.h"
#include "Database.h"
using namespace std;

int main() {
	enum class ATM { newAccount = 1, balance = 2, transfer = 3, logOut = 4, exit = 5 };
	int bankOption = 0;
	//Database bankAccounts;
	//bool validAccount;

	while ((ATM)bankOption != ATM::exit) {
		cout << "Choose from the following Banking Options: " << endl;
		cout << "Press (1) to create a new account:\nPress (2) to check balance:\nPress (3) to transfer:\nPress (4) to log out\nPress (5) to exit" << endl;
		cin >> bankOption;
		switch ((ATM)bankOption) {
		case ATM::newAccount:
			cout << "Create a (5 Digit) Account Member ID: " << endl;
			int idNum;
			cin >> idNum;
			cout << "Create a (4 Digit) Account Member Pin: " << endl;
			int pinNum;
			cin >> pinNum;
			cout << "Enter initial balance: " << endl;
			float balanceAmount;
			cin >> balanceAmount;
			Account accountNew(idNum, pinNum, balanceAmount);
			//validAccount = bankAccounts.find(accountNew);*/
			/*if (validAccount == false) {
				cout << "Bank Member account successfully created. " << endl;
				bankAccounts.append(newAccount);
			}
			else {
				cout << "Account Member ID or Pin Invalid. Please try again. " << endl;
			}*/
			break;
		case ATM::balance:
			cout << "Enter Account Member ID: " << endl;

			cout << "Enter Account Member Pin: " << endl;

			cout << "Account Balance: " << endl;
			break;
		case ATM::transfer:

			cout << "Transfer from: Enter Account Member ID: " << endl;

			cout << "Enter Account Withdrawal Amount: " << endl;

			cout << "Transfer to: Enter Account Member ID: " << endl;

			cout << "Enter Account Deposit Amount: " << endl;
			break;
		case ATM::logOut:
			char acctMember;
			cout << "Do you wish to log in to another account?\nPress (Y)es or (N)o" << endl;
			cin >> acctMember;
			if (acctMember == 'y' || acctMember == 'Y') {
				cout << "Enter Account Member ID: " << endl;

				cout << "Enter Account Member Pin: " << endl;

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