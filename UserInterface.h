//
// Created by Jun-Sik Choi on 3/24/24.
//

#ifndef ADDRESSBOOK_USERINTERFACE_H
#define ADDRESSBOOK_USERINTERFACE_H

#include <iostream>
#include "AddressBook.h"

class UserInterface {
public:
    UserInterface() = delete;

    explicit UserInterface(AddressBook &);

    ~UserInterface();

    void run();

    void quit();

private:
    void showMenu();

    static void showSubMenu(const std::function<void(bool &)> &);

    static void clearScreen();

    void showAllAddresses(bool &);

    void addNewAddress(bool &);

    void deleteAddress(bool &);

    AddressBook &data;

    bool shouldQuit = false;
};


#endif //ADDRESSBOOK_USERINTERFACE_H
