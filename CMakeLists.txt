cmake_minimum_required(VERSION 3.28)
project(Library_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(Library_system main.cpp
        Book.cpp
        Book.h
        VIPbook.cpp
        VIPbook.h
        Person.cpp
        Person.h)
