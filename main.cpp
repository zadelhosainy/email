

#include <iostream>
#include <string>
#include <map>
#include "utils.hpp"

int main() {
    std::map<std::string, std::string> users;
    bool logged_in = false;
    std::string current_user;

    int choice;

    while (true) {
        std::cout << "\nMenu:\n";

        if (!logged_in) {
            std::cout << "1. Sign up\n";
            std::cout << "2. Login\n";
        } else {
            std::cout << "3. Logout\n";
        }

        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 0) {
            break;
        }

        if (!logged_in && choice == 1) {
            std::string email, password;

            while (true) {
                std::cout << "Enter email: ";
                std::getline(std::cin, email);

                try {
                    check_email(email);
                    break;
                } catch (const std::invalid_argument& e) {
                    std::cout << e.what() << std::endl;
                }
            }

            std::cout << "Enter password: ";
            std::getline(std::cin, password);

            users[email] = password;
            std::cout << "Sign up successful.\n";
        }
        else if (!logged_in && choice == 2) {
            std::string email, password;

            std::cout << "Enter email: ";
            std::getline(std::cin, email);

            std::cout << "Enter password: ";
            std::getline(std::cin, password);

            if (users.find(email) != users.end() && users[email] == password) {
                logged_in = true;
                current_user = email;
                std::cout << "Login successful.\n";
            } else {
                std::cout << "Invalid email or password.\n";
            }
        }
        else if (logged_in && choice == 3) {
            logged_in = false;
            current_user = "";
            std::cout << "Logged out successfully.\n";
        }
        else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}
