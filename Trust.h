#pragma once
#include"Account.h"
#include"Savings_Account.h"
#include<iostream>
#include<string>
class Trust:public Savings_Account
{
	friend std::ostream& operator<<(std::ostream os, const Trust& account);

private:
	static constexpr const char* def_name = "Unnamed Trust Account";
	static constexpr double  def_balance = 0.0;
	static constexpr double def_int_rate = 0.0;
	static constexpr double bonus_amount = 50.0;
	static constexpr double bonus_threshold = 5000.0;
	static constexpr int max_withdrawal = 3;
	static constexpr double max_withdrawal_percent = 0.2;
protected:
	int num_withdraw;
public:
	Trust(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
	bool deposit(double amount);//depositi veci od 5000 dobivaju bonus od 50
	bool withdraw(double amount);
};

