/*
Lisa Lin (lisalin@my.unt.edu)
Homework 3 Assignment - Library Management System
Started: 3/12/2021
Book entity header file
*/

#ifndef LL0484HW3_BOOK_H
#define LL0484HW3_BOOK_H

#include <string>
#include <iostream>

using namespace std;

class Book {
public:
    /*
     * constructors
     */

    Book();
    Book(string author, string title, int id, int isbn, float cost, string status);

    /*
     * getters setters
     */

    void setAuthor(string author);
    string getAuthor();
    void setTitle(string title);
    string getTitle();
    void setID(int id);
    int getID();
    void setIsbn(int isbn);
    int getIsbn();
    void setCost(float cost);
    float getCost();
    void setStatus(string status);
    string getStatus();

    /*
     * prints individual book info
     */
    void printBook();

private:
    string author;
    string title;
    int id;
    int isbn;
    float cost;
    string status;

};


#endif //LL0484HW3_BOOK_H
