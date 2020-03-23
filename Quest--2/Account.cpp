#include "Account.h"
#include <iostream>
using namespace std;

void transfer(Account accountFrom, Account accountTo);
void transfer(Account accountFrom, Account accountTo) {
	cout << "Enter Account Withdrawal Amount: " << endl;
	float amountFrom;
	cin >> amountFrom;
	accountFrom.payin(amountFrom);
	
	cout << "Enter Account Deposit Amount: " << endl;
	float amountTo;
	cin >> amountTo;
	accountTo.payout(amountTo);
	if (accountFrom.payin(amountFrom) == true && accountTo.payout(amountTo) == true) {
		float newBalance = accountFrom.getAcctBalance() - amountFrom;
		accountFrom.setAcctBalance(newBalance);
		float addBalance = accountTo.getAcctBalance() + amountTo;
		accountTo.setAcctBalance(addBalance);
	}
}

/*Account::Account(){}*/

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
	else if (amount > acctBalance) {
		cout << "Insufficient funds. Enter a valid amount: " << endl;
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
	return true;
}

void Account::setID(int id) {
	acctNumber = id;
}

int Account::getID() const {
	return acctNumber;
}

void Account::setPin(int pin) {
	pinNumber = pin;
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
