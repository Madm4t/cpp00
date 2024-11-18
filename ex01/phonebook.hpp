#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include <iomanip>

class PhoneBook {
public:
	void	addContact();
	void	searchContacts() const;
private:

	Contact contacts[8];
	int	contactCount = 0;
};

#endif