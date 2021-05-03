/*
Lisa Lin (lisalin@my.unt.edu)
Homework 3 Assignment - Library Management System
Started: 3/12/2021
Loan entity cpp file
*/

#include "Loan.h"
#include "Patron.h"
#include "Patrons.h"
#include <string>
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

Loan::Loan() {
    this->loanID = 0;
    this->bookID = 0;
    this->patronID = 0;
    this->status = "NORMAL";
    this->recheck = false;
}

Loan::Loan(int lID, int bID, int pID,  string bstatus, time_t coDate, time_t dDate, bool recheck) {
   this->loanID  = lID;
  this->bookID = bID;
  this->patronID = pID;
  this->status = bstatus;
  this->checkoutDate = coDate;
  this->dueDate = dDate;
  this->recheck = false;
}

void Loan::setLoanID(int id){
    this->loanID = id;
}

int Loan::getLoanID() {
    return loanID;
}

void Loan::setBookID(int bID) {
  this->bookID = bID;
}

int Loan::getBookID(){
  return bookID;
}

void Loan::setPatronID(int pID) {
    this->patronID = pID;
}

int Loan::getPatronID(){
    return patronID;
}

void Loan::setStatus(string lStatus){
    this->status = lStatus;
}

string Loan::getStatus(){
    return status;
}

void Loan::setCheckoutDate(time_t coDate){
  this->checkoutDate = coDate;
}

time_t Loan::getCheckoutDate() {
  return checkoutDate;
}

void Loan::setDueDate(time_t dDate){
  this->dueDate = dDate;
}

time_t Loan::getDueDate() {
  return dueDate;
}

void Loan::setRecheck(bool recheck) {
  this->recheck = recheck;
}

bool Loan::getRecheck() {
  return recheck;
}

void Loan::setAllDates() {

    time_t timeNow = time(0); // epoch Time
    time(&timeNow); //set to current time
    time_t dueTime = timeNow + 864000; // set due date to 10 days after (864000 seconds)

    setCheckoutDate(timeNow);
    setDueDate(dueTime);
    /* to print out value
    cout << asctime(localtime(&dueTime));
    */


}

void Loan::dueDateToMonth(time_t date){
  cout << asctime(localtime(&date));
}

void Loan::printLoanInfo() {

    time_t coDate= getCheckoutDate();
    time_t dueDate = getDueDate();

    cout << endl << "<<< LOAN INFORMATION >>>" << endl << endl;
    cout << "Loan ID: " << loanID << endl;
    cout << "Book ID: " << bookID << endl;
    cout << "Patron ID: " << patronID << endl;
    cout << "Loan Status: " << status << endl;
    cout << "Checkout date: ";
    dueDateToMonth(coDate);
    cout << "Due date: ";
    dueDateToMonth(dueDate);
}

void Loan::markLoanOverdue(){

    Patrons* patrons;
    Patron* patron;
    Loan* loan;
    time_t currentTime = time(0);
    time(&currentTime);
    time_t dueDate = dueDate;

    time_t difference = currentTime - dueDate;
    time_t counter = difference / 86400; //86400 seconds in 24 hours
    float overdueCost = counter * 0.25; //25 cents every 24 hours
    int patronID = loan->getPatronID();
    patron = patrons->findPatron(patronID);

    if(status == "NORMAL")
    {
        if (dueDate <= currentTime)
        {
            status = "OVERDUE";
            patron->setFine(overdueCost);
        }
    }
}