#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include <iomanip>			//for formatting output, example setting field width (std::setw)
#include <iostream>			//input/output operation (std::cout, std::cin)
#include <string>

class PhoneBook {

public:
	void	addContact();
	void	searchContacts() const;

private:
	Contact contacts[8];
	int	contactCount = 0;
};

#endif