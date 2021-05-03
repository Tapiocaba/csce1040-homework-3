/*
Lisa Lin (lisalin@my.unt.edu)
Homework 3 Assignment - Library Management System
Started: 3/12/2021
Patron entity header file
*/

#ifndef LL0484HW3_PATRON_H
#define LL0484HW3_PATRON_H
#include <string>
#include <iostream>
using namespace std;

class Patron {
public:
    /*
     * constructor
     */
    Patron();
    Patron(string name, int patronID, float fine, int booksChecked);

    /*
     * setters/getters
     */
    void setName(string name);
    string getName();
    void setID(int patronID);
    int getID();
    void setFine(float fine);
    float getFine();
    void setBooksChecked(int bookChecked);
    int getBooksChecked();

    /*
    * print
    */

    void printPatronInfo();


private:
    string name;
    int patronID;
    float fine;
    int booksChecked;
};


#endif //LL0484HW3_PATRON_H
