#include<iostream>
#include<string>
#include"Account.h"
#include"Savings_Account.h"
#include"Checking_Account.h"
#include"Trust.h"
#include<vector>

//Pregled objekata u vektoru
void display(const std::vector<Account>& accounts)
{
	std::cout << "*****Accounts********" << std::endl;
	for (const auto& acc : accounts)
		std::cout << acc << std::endl;
}

// dodavanje depozita svim clanovima vektora
void deposit(std::vector<Account>& accounts, double amount)
{
	std::cout << "*****Deposit to Accounts********" << std::endl;
	for (auto& acc : accounts)
	{
		if (acc.deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed deposit of " << amount << " to " << acc << std::endl;
	}
}

//uzimanje para svim objektima koji su clanovi vektora
void withdraw(std::vector<Account>& accounts, double amount)
{
	std::cout << "*****withdrawing to Accounts********" << std::endl;
	for (auto& acc : accounts)
		if (acc.withdraw(amount))
			std::cout << "Withdrew " << amount << " from " << acc << std::endl;
		else
			std::cout << " Failed withdrawal of " << amount << " from " << acc << std::endl;

}

void displays(const std::vector<Savings_Account>& accounts)
{

	std::cout << "*****Saving Accounts********" << std::endl;
	for (const auto& acc : accounts)
		std::cout << acc << std::endl;


}

void deposits(std::vector<Savings_Account>& accounts, double amount)
{
	std::cout << "*****Deposit to Savings Accounts********" << std::endl;
	for (auto& acc : accounts)
	{
		if (acc.deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed deposit of " << amount << " to " << acc << std::endl;
	}
}

void withdraws(std::vector<Savings_Account>& accounts, double amount)
{
	std::cout << "*****Withdraws to Savings Accounts********" << std::endl;
	for (auto& acc : accounts)
		if (acc.withdraw(amount))
			std::cout << "Withdrew " << amount << " from " << acc << std::endl;
		else
			std::cout << "Failed withdrawal of " << amount << "  from " << acc << std::endl;
}
int main()
{
	std::cout.precision(2);

	//Accounts
	std::vector<Account> accounts;
	accounts.push_back(Account{});
	accounts.push_back(Account{ "Ante" });
	accounts.push_back(Account{ "Mate",2000.0 });
	accounts.push_back(Account{ "Ivan",5000.0 });

	display(accounts);
	deposit(accounts, 250.0);
	withdraw(accounts, 450.0);

	std::vector<Savings_Account> sav_acc;
	sav_acc.push_back(Savings_Account());
	sav_acc.push_back(Savings_Account("Ivica",8000.0,1.5));
	sav_acc.push_back(Savings_Account("Vinko", 4500.0, 5.9));

	displays(sav_acc);
	deposits(sav_acc, 535.5);
	withdraws(sav_acc, 856.0);

	std::vector<Checking_Account> che_acc;
	che_acc.push_back(Checking_Account());
	che_acc.push_back(Checking_Account("Marko,6500.0"));

	std::vector<Trust> trust;
	trust.push_back(Trust("Berni,67890.0,5.0"));
	

	system("pause");
}