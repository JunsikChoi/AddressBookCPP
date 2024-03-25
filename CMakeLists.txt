cmake_minimum_required(VERSION 3.27)
project(addressBook)

set(CMAKE_CXX_STANDARD 17)

add_executable(addressBook main.cpp
        Node.cpp
        Node.h
        UserData.cpp
        UserData.h
        AddressBook.cpp
        AddressBook.h
        UserInterface.cpp
        UserInterface.h)
