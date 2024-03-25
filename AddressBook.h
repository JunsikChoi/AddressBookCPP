//
// Created by Jun-Sik Choi on 3/24/24.
//

#ifndef ADDRESSBOOK_ADDRESSBOOK_H
#define ADDRESSBOOK_ADDRESSBOOK_H


#include "UserData.h"

class AddressBook {
private:
    UserData *head = nullptr;
    UserData *tail = nullptr;
    int length = 0;
public:
    AddressBook();

    ~AddressBook();

    int append(std::string, std::string);

    int remove(int);

    int getLength();

    UserData* begin();

    UserData* end();
};


#endif //ADDRESSBOOK_ADDRESSBOOK_H
