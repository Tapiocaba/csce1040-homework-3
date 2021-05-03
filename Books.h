/*
Lisa Lin (lisalin@my.unt.edu)
Homework 3 Assignment - Library Management System
Started: 3/12/2021
Books storage header file
*/

#ifndef LL0484HW3_BOOKS_H
#define LL0484HW3_BOOKS_H

#include "Book.h"
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Books {
public:
    /*
     * menu options
     */
    void addBook();
    void editBook();
    void deleteBook(int bookID);
    void printAllBooks();
    void findAndPrint();
    bool emptyBook();
    Book* findBook(int bookID);
    void searchBook();

    /*
    store and load
    */
    int numOfBooks(); //for use in storing
    void store();
    void load();

private:
    map <int, Book*> books; //integer value of book
};


#endif //LL0484HW3_BOOKS_H
