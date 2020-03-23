#pragma once
class Account {
public:
	//Account();
	Account(int id, int pin, float balance);

	bool payin(float amount);
	bool payout(float amount);

	void setID(int id);
	int getID() const;

	void setPin(int pin);
	int getPin() const;

	void setAcctBalance(float balance);
	float getAcctBalance() const;

private:
	int acctNumber;
	int pinNumber;
	float acctBalance;
};
void transfer(Account accountFrom, Account accountTo);