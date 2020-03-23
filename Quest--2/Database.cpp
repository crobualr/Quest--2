#include "Database.h"
#include <algorithm>

Database::Database() {}

void Database::append(Account const& a) {
	Database::accounts.push_back(a);
}

bool Database::find(Account const& account) {
	//vector<Account>::iterator it = accounts.begin(); it != accounts.end(); it++ 
	/*vector<Account>::iterator it = std::find(accounts.begin(), accounts.end(), account);
	if (it != accounts.end()) {
		return true;
	}*/
	
	for (auto& accountMember : accounts) {
		if (accountMember.getID() == account.getID()) {
			 return true;
		}
	}
	return false;
}
float Database::findBalance(int ID, int Pin) {
	for (auto& accountMember : accounts) {
		if (accountMember.getID() == ID && accountMember.getPin() == Pin) {
			return accountMember.getAcctBalance();
		}
	}
	cout << "Could not find account with given ID and Pin" << endl;
	return 0;
}
Account& Database::findAccount(int ID, int Pin) {
	for (auto& accountMember : accounts) {
		if (accountMember.getID() == ID && accountMember.getPin() == Pin) {
			return accountMember;
		}
	}
	cout << "Could not find account with given ID and Pin" << endl;
}
vector<Account> Database::getAccounts() const {
	return accounts;
}
