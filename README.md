# CPP Module 00

**An introduction to Object-Oriented Programming with C++.**

This project represents the first steps into C++ programming, focusing on the basics of classes, member functions, and fundamental OOP concepts. It demonstrates the transition from procedural C programming to object-oriented programming in C++.

## Structure

### ex00/
The `ex00` directory contains the first exercise focusing on basic input/output:
- **megaphone.cpp**: A simple program that converts input strings to uppercase, demonstrating basic string manipulation in C++.

### ex01/
The `ex01` directory implements a basic phonebook:
- **phonebook.cpp**: Contains the PhoneBook class implementation for storing and managing contacts.
- **contact.cpp**: Defines the Contact class for individual contact information.
- **main.cpp**: The driver program that handles user interaction with the phonebook.

### ex02/
The `ex02` directory focuses on Account class usage:
- **Account.cpp**: Implementation of the Account class for managing bank account operations.
- **tests.cpp**: Contains test cases to verify Account class functionality.

## Features

- **Object-Oriented Design**: Implementation of classes and objects
- **Data Encapsulation**: Proper use of public and private members
- **Input Validation**: Robust handling of user input
- **Memory Management**: Proper resource handling

## Usage

To compile each exercise, navigate to its directory and run:
```bash
make
```

### Running the Programs

For ex00 (Megaphone):
```bash
./megaphone "shhhhh... I think the students are asleep..."
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
./megaphone
```

For ex01 (PhoneBook):
```bash
./phonebook
```
Then use commands:
- ADD: to add a new contact
- SEARCH: to search for a contact
- EXIT: to quit the program

For ex02 (Account):
```bash
./account
```

## Compilation

All exercises are compiled with:
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp
```

## Learning Objectives

- Understanding the basics of C++ syntax
- Learning about classes and objects
- Working with member functions and attributes
- Understanding access specifiers (public/private)
- Basic string manipulation in C++
- Input/output operations in C++
