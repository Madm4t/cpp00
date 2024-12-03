#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

#define RST "\033[0m"
#define BL	"\033[34m"

//Initialize static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//Constructor
Account::Account(int initial_deposit)
	:	_accountIndex(_nbAccounts),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << "index:" << BL << _accountIndex << RST
			  << ";amount:" << BL << _amount << RST
			  << ";created" << std::endl;
}

//Destructor
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << BL << _accountIndex << RST
			  << ";amount:" << BL << _amount << RST
			  << ";closed" << std::endl;
}

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << BL << getNbAccounts() << RST
			  << ";total:" <<  BL << getTotalAmount() << RST
			  << ";deposits:" <<  BL << getNbDeposits() << RST
			  << ";withdrawls:" <<  BL << getNbWithdrawals() << RST
			  << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << BL << _accountIndex << RST
			  << ";p_amount:" << BL <<  p_amount << RST
			  << ";deposit:" << BL <<  deposit << RST
			  << ";amount:" << BL <<  _amount << RST
			  << ";nb_deposits:" << BL <<  _nbDeposits << RST
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = _amount;

	_displayTimestamp();
	if (_amount >= withdrawal)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;

		std::cout << "index:" << BL <<  _accountIndex << RST
				  << ";p_amount:" << BL <<  p_amount << RST
				  << ";withdrawal:" << BL <<  withdrawal << RST
				  << ";amount:" << BL <<  _amount  << RST
				  << ";nb_withdrawals:" << BL <<  _nbWithdrawals << RST
				  << std::endl;
		return true;
	}
	else
	{
		std::cout << "index;" << BL << _accountIndex << RST
				  << ";p_amount:" << BL << p_amount << RST
				  << ";withdrawal;refused"
				  << std::endl;
		return false;
	}
}

int Account::checkAmount(void) const {
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << BL << _accountIndex << RST
			  << ";amount:" << BL << _amount << RST
			  << ";deposits:" << BL << _nbDeposits << RST
			  << ";withdrawals:" << BL << _nbWithdrawals << RST
			  << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);
	std::cout << "[" << std::put_time(localTime, "%Y%m%d_%H%M%S") << "]";
}