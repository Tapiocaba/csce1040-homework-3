/*
Lisa Lin (lisalin@my.unt.edu)
Homework 3 Assignment - Library Management System
Started: 3/12/2021
Loans storage header file
*/

#ifndef LL0484HW3_LOANS_H
#define LL0484HW3_LOANS_H

#include "Loan.h"
#include "Patrons.h"
#include "Patron.h"
#include "Books.h"
#include "Book.h"
#include <string>
#include <map>
#include <iostream>
#include <time.h>
using namespace std;

class Loans {
public:
  Loan* findLoan(int loanID);
  void searchLoan();

  /*
  * menu functions
  */
  void checkOutBook(Books* books, Patrons* patrons);
  void checkInBook(Books* books, Patrons* patrons);
  void recheckBook();
  void reportLost(Books* books, Patrons* patrons);
  void editLoan(Books* books, Patrons* patrons);
  void updateLoan(Books* books, Patrons* patrons);
  
  void listAllOverdue();
  void listSpecificOverdue();
  void printAllLoans();

  /*
  store and load
  */
  int numOfLoans(); //for use in storing
  void store();
  void load();
  
private:
  map<int, Loan*> loans; //loan id (int) to store loans
  map<int, vector<Loan*>*> bookIDtoLoan; // book id to loan
  map<int, vector<Loan*>*> patronIDtoLoan;
};


#endif //LL0484HW3_LOANS_H