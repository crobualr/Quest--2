#include "Account.h"
#include <iostream>
using namespace std;

void transfer(int accountFrom, int accountTo);
void transfer(int accountFrom, int accountTo) {
	cout << "Enter Account Deposit Amount: " << endl;
}

//Account::Account(){
//	acctNumber = null;
//
//}

Account::Account(int id, int pin, float balance) {
	acctNumber = id;
	pinNumber = pin;
	acctBalance = balance;
}

bool Account::payin(float amount)
{
	if (amount < 0) {
		cout << "Enter a valid amount" << endl;
		return false;
	}
	return true;
}

bool Account::payout(float amount)
{
	if (amount < 0) {
		cout << "Enter a valid amount" << endl;
		return false;
	}
	else if (amount > acctBalance) {
		cout << "Insufficient funds. Enter a valid amount: " << endl;
		return false;
	}
	return true;
}

void Account::setID(int id) {
}

int Account::getID() const {
	return acctNumber;
}

void Account::setPin(int pin) {
}

int Account::getPin() const {
	return pinNumber;
}

void Account::setAcctBalance(float balance) {
	acctBalance = balance;
}

float Account::getAcctBalance() const {
	return acctBalance;
}
