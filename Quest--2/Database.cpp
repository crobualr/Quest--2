#include "Database.h"
#include <algorithm>

Database::Database() {}

void Database::append(Account const& a) {
	Database::accounts.push_back(a);
}

bool Database::find(Account const& account) {
	//vector<Account>::iterator it = accounts.begin(); it != accounts.end(); it++) 
	vector<Account>::iterator it = std::find(accounts.begin(), accounts.end(), account);
	if (it != accounts.end()) {
		return true;
	}

	return false;
}

vector<Account> Database::getAccounts() const {
	return accounts;
}
