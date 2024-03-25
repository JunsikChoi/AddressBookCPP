//
// Created by Jun-Sik Choi on 3/24/24.
//

#include "UserData.h"

#include <utility>

UserData::~UserData() = default;

UserData::UserData(std::string name, std::string phoneNumber) : name(std::move(name)),
                                                                phoneNumber(std::move(phoneNumber)) {}

void UserData::setUid(int id) {
    this->uid = id;
}

std::string UserData::getName() const {
    return this->name;
}

std::string UserData::getPhoneNumber() const {
    return this->phoneNumber;
}

int UserData::getUid() const {
    return this->uid;
}
