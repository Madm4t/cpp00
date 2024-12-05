#include "phonebook.hpp"


std::string truncate(const std::string &str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

void    PhoneBook::addContact() {
    Contact newContact;
    newContact.inputContact();

    int index = contactCount % 8;
    contacts[index] = newContact;

    contactCount++;
}

void    PhoneBook::searchContacts() const {
    if (contactCount == 0) {
        std::cout << "The phonebook is empty. Add some contacts." << std::endl;
        return;
    }
    std::cout   << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << std::endl;
    
    for (int i = 0; i < contactCount && i < 8; ++i) {
        std::cout   << std::setw(10) << i << "|"
                    << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
					<< std::setw(10) << truncate(contacts[i].getLastName()) << "|"
					<< std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;

    }

	std::string	input;
	int	index = -1;
	std::cout << "Enter the index of the contact to display: ";
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << "EOF. Exiting phonebook." << std::endl;
		std::exit(0);
	}
	try {
		index = std::stoi(input);
		if (index >= 0 && index < contactCount && index < 8) {
			const Contact	&contact = contacts[index];
			std::cout << "First Name: " << contact.getFirstName() << std::endl;
			std::cout << "Last Name: " << contact.getLastName() << std::endl;
			std::cout << "Nickname: " << contact.getNickname() << std::endl;
			std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
		}
		else {
			std::cout << "Invalid Index. Please try agian." << std::endl;
		}
	}
	catch (std::exception&) {
		std::cout << "Invalid input. Please enter a valid index." << std::endl;
	}
}