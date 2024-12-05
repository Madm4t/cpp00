#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <utility>	//for std::pair
#include <cctype>	//for std::isdigit

class Contact {

public:
	void		inputContact();
	void		setFirstName(const std::string &_firstName);
	void		setLastName(const std::string &_lastName);
	void		setNickname(const std::string &_nickname);
	void		setPhoneNumber(const std::string &_phoneNumber);
	void		setDarkestSecret(const std::string &_darkestSecret);

	std::string	getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif