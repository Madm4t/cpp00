#include "contact.hpp"

std::string	trim(const std::string &str) {
	size_t	first = str.find_first_not_of("\t\n\r");
	if (first == std::string::npos)
		return "";
	size_t	last = str.find_last_not_of("\t\n\r");
	return (str.substr(first, last - first + 1));
}

bool	isDigits(const std::string &str) {
	for (char c : str) {
		if (!std::isdigit(static_cast<unsigned char>(c))) {
			return (false);
		}
	}
	return (true);
}

void	Contact::inputContact(){

	typedef void (Contact::*Setter)(const std::string&);
	std::pair<const char*, Setter> fields[] = {
		{"First Name", &Contact::setFirstName},
		{"Last Name", &Contact::setLastName},
		{"Nickname", &Contact::setNickname},
		{"Phone Number", &Contact::setPhoneNumber},
		{"Darkset Secret", &Contact::setDarkestSecret}
	};

	std::string	input;
	for (const auto& [fieldName, setter] : fields) {
		while (true) {
			std::cout << "Enter " << fieldName << ": ";
			std::getline(std::cin, input);
			input = trim(input);
			if (input.empty()) {
				std::cout << fieldName << " cannot be empty. Please try agian." << std::endl;
			}
			else {
				if (fieldName == std::string("Phone Number") && !isDigits(input)) 
					std::cout << fieldName << " must contain only digits. Please try agian." << std::endl;
				else {
					(this->*setter)(input);
					break;
				}
			}
		}
	}
}

void		setFirstName(const std::string &_firstName) {
	this->_firsName = trim(_firstName);
}

void		setLastName(const std::string &_lastName) {
	this->_lastName = trim(_lastName);
}

void		setNickname(const std::string &_nickname) {
	this->_nickname = trim(_nickname);
}

void		setPhoneNumber(const std::string &_phoneNumber) {
	this->_phoneNumber = trim(_phoneNumber);
}

void		setDarkestSecret(const std::string &_darkestSecret) {
	this->_darkestSecret = trim(_darkestSecret);
}
