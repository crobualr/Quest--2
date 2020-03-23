#pragma once
#include <vector>
#include<iostream>
#include "Account.h"
using namespace std;
class Database {
public:
	Database();
	void append(Account const& a);
	bool find(Account const& account);
	float findBalance(int ID, int Pin);
	Account& findAccount(int ID, int Pin);
	vector<Account>getAccounts() const;
private:
	vector<Account>accounts;
};