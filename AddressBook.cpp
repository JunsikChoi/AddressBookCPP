//
// Created by Jun-Sik Choi on 3/24/24.
//

#include <random>
#include "AddressBook.h"

#include <utility>

// 난수 생성기 설정
std::random_device rd; // 시드 생성기
std::mt19937 gen(rd()); // 메르센 트위스터 엔진을 사용한 난수 생성기
std::uniform_int_distribution<> dis(100, 999); // 100부터 999까지의 난수 분포

AddressBook::AddressBook() = default;

AddressBook::~AddressBook() {
    if (this->head != nullptr) {
        UserData* current = this->head;
        UserData* backup = nullptr;
        while (current != nullptr) {
            backup = current;
            current = dynamic_cast<UserData *>(current->getNext());
            delete backup;
        }
    }
};


int AddressBook::append(std::string name, std::string phoneNumber) {
    auto *newUser = new UserData(std::move(name), std::move(phoneNumber));
    newUser->setUid(dis(gen));

    if (this->head == nullptr) {
        this->head = newUser;
        this->tail = newUser;
    } else {
        this->tail->setNext(newUser);
        this->tail = newUser;
    }

    this->length++;

    return this->length;
}

int AddressBook::remove(int uid) {
    UserData *before = nullptr;
    UserData *current = this->head;
    bool found = false;

    while (current != nullptr) {
        if (current->getUid() == uid) {
            found = true;
            break;
        }
        before = current;
        current = dynamic_cast<UserData *>(current->getNext());
    };

    if (!found) {
        return -1;
    } else {
        if (before == nullptr) {
            this->head = dynamic_cast<UserData *>(current->getNext());
        } else {
            before->setNext(current->getNext());
        }
        delete current;
        this->length--;
        return this->length;
    }
}

int AddressBook::getLength() {
    return this->length;
}

UserData *AddressBook::begin() {
    if (this->head == nullptr) {
        throw std::runtime_error("AddressBook is empty.");
    } else {
        return this->head;
    }
}

UserData *AddressBook::end() {
    if (this->tail == nullptr) {
        throw std::runtime_error("AddressBook is empty.");
    } else {
        return this->tail;
    }
}

