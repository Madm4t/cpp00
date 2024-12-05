#include "phonebook.hpp"

int main() {
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (std::cin.eof() || std::cin.fail()) {
            std::cout << std::endl;
            break;
        }

        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContacts();
        } else if (command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}