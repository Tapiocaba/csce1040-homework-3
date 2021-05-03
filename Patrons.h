/*
Lisa Lin (lisalin@my.unt.edu)
Homework 3 Assignment - Library Management System
Started: 3/12/2021
Patron storage header file
*/

#ifndef LL0484HW3_PATRONS_H
#define LL0484HW3_PATRONS_H

#include "Patron.h"
#include "Book.h"
#include "Loan.h"
#include <iostream>
#include <map>
using namespace std;

class Patrons {
public:

  bool emptyNewPatron();
  Patron* findPatron(int patronID);
  void addPatron();
  void editPatron();
  void deletePatron(int patronID);
  void searchPatron();
  void printAllPatrons();
  void findAndPrintPatron();
  void payFines(); //pay fines

  /*
  * store and load
  */
  int numOfPatrons(); //for use in storing
  void store();
  void load();

private:
  map <int, Patron*> patrons; //sort by patron id (int)
};


#endif //LL0484HW3_PATRONS_H
