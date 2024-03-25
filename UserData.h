//
// Created by Jun-Sik Choi on 3/24/24.
//

#ifndef ADDRESSBOOK_USERDATA_H
#define ADDRESSBOOK_USERDATA_H

#include <iostream>
#include "Node.h"

class UserData : public Node {
private:
    int uid{};
    std::string name;
    std::string phoneNumber;

public:
    UserData() = delete;

    UserData(std::string, std::string);

    ~UserData() override;

    void setUid(int uid);

    [[nodiscard]] int getUid() const;

    std::string getName() const;

    std::string getPhoneNumber() const;
};


#endif //ADDRESSBOOK_USERDATA_H
