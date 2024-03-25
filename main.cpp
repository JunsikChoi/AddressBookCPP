#include "AddressBook.h"
#include "UserInterface.h"

int main() {
    AddressBook book;
    UserInterface UI(book);

    UI.run();

    return 0;
}
