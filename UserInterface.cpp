//
// Created by Jun-Sik Choi on 3/24/24.
//

#include <iostream>
#include "UserInterface.h"

using namespace std;

UserInterface::UserInterface(AddressBook &addressBook) : data(addressBook) {
}

UserInterface::~UserInterface() = default;

void UserInterface::run() {
    char menuChoice = -1;
    while (!shouldQuit) {
        if (menuChoice == -1) {
            this->showMenu();
            cin >> menuChoice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clearScreen();
        }
        switch (menuChoice) {
            case 'S':
            case 's':
                showSubMenu([this](bool &done) { this->showAllAddresses(done); });
                break;
            case 'N':
            case 'n':
                showSubMenu([this](bool &done) { this->addNewAddress(done); });
                break;
            case 'D':
            case 'd':
                showSubMenu([this](bool &done) { this->deleteAddress(done); });
                break;
            case 'Q':
            case 'q':
                this->quit();
                break;
            default:
                cout << "Invalid choice, Try Again." << endl;
        }
        menuChoice = -1;
        clearScreen();
    }
}

void UserInterface::quit() {
    this->shouldQuit = true;
}

void UserInterface::showMenu() {
    cout << "Simple Address Management System" << endl;
    cout << "[S]: Show All Address" << endl;
    cout << "[N]: Add New Address" << endl;
    cout << "[D]: Delete Address" << endl;
    cout << "[Q]: Quit Program" << endl;
}

void UserInterface::showSubMenu(const std::function<void(bool &)> &subMenuFn) {
    bool back = false;
    char response = -1;
    while (!back) {
        subMenuFn(back);
        if (!back) {
            cout << "[B]: Back to main menu " << endl;
            cin >> response;
            if (response == 'b' || response == 'B') {
                back = true;
            } else {
                clearScreen();
            }
        }
    }
}

void UserInterface::clearScreen() {
    system("clear");
}

void UserInterface::showAllAddresses(bool &done) {
    if (this->data.getLength() == 0) {
        cout << "No Record" << endl;
    } else {
        UserData *current = this->data.begin();
        int idx = 1;
        cout << "[index] / [NAME] / [Phone Number]" << endl;
        while (current != nullptr) {
            cout << idx << " " << current->getName() << " " << current->getPhoneNumber() << endl;
            current = dynamic_cast<UserData *>(current->getNext());
            idx++;
        };
    }
}

void UserInterface::addNewAddress(bool &done) {
    while (!done) {
        clearScreen();
        string name;
        string phoneNumber;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Phone Number: ";
        cin >> phoneNumber;

        clearScreen();
        bool confirm = false;
        char confirmResponse;
        while (!confirm) {
            clearScreen();
            cout << "Name: " << name << "/Phone Number: " << phoneNumber << endl;
            cout << "Confirm Add this contact information?" << endl;
            cout << "[Y] Confirm / [N] Back to Main Menu" << endl;
            cin >> confirmResponse;
            switch (confirmResponse) {
                case 'Y':
                case 'y':
                    this->data.append(name, phoneNumber);
                    confirm = true;
                    done = true;
                    break;
                case 'N':
                case 'n':
                    confirm = true;
                    done = true;
                    break;
                default:
                    cout << "Invalid Input, Try Again." << endl;
            }
        }
    }
}

void UserInterface::deleteAddress(bool &done) {
    if (this->data.getLength() == 0) {
        cout << "No Records to delete." << endl;
        return;
    } else {
        UserData *current = this->data.begin();
        cout << "[ID] / [NAME] / [Phone Number]"<<endl;
        while (current != nullptr) {
            cout << current->getUid() << " " << current->getName() << " " << current->getPhoneNumber() << endl;
            current = dynamic_cast<UserData *>(current->getNext());
        };
        int uidToDelete;
        cout << "Enter id of contact to delete" << endl;
        cin >> uidToDelete;
        int result = this->data.remove(uidToDelete);
        if (result == -1) {
            clearScreen();
            cout << "Invalid id, try again." << endl;
            return;
        }
        done = true;
        return;
    }

}
