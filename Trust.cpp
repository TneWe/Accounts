#include "Trust.h"

Trust::Trust(std::string name, double balance, double int_rate):
	Savings_Account{ name,balance,int_rate }, num_withdraw{ 0 }
{
}

bool Trust::deposit(double amount)//ako se uplati vise od 5000 dobije se 50 bonusa
{
	if (amount >= bonus_threshold)
		amount += bonus_amount;
	return Savings_Account::deposit(amount);
}

//dozvoljena samo 3 podizanja novca,svaki maximalno u iznosu 20% balansa
bool Trust::withdraw(double amount)
{
	if (num_withdraw >= max_withdrawal || (amount > balance* max_withdrawal_percent))
		return false;
	else
	{
		num_withdraw++;
		return Savings_Account::withdraw(amount);
	}
}

std::ostream& operator<<(std::ostream os, const Trust& account)
{
	os << "[ Trust account name:" << account.name << ", balance: " << account.balance << " interest rate:" << account.int_rate << "%,withdrawals :" << account.num_withdraw << "]";
	return os;
}
