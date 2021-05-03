/*
Lisa Lin (lisalin@my.unt.edu)
Homework 3 Assignment - Library Management System
Started: 3/12/2021
Loan entity header file
*/

#ifndef LL0484HW3_LOAN_H
#define LL0484HW3_LOAN_H

#include <string>
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

class Loan {
public:
    /*
     * constructor
     */
    Loan();
    Loan(int loanID, int bookID, int patronID,  string status, time_t checkoutDate, time_t dueDate, bool recheck);

    /*
     * getters/setters
     */
    void setLoanID(int loanID);
    int getLoanID();
    void setBookID(int bookID);
    int getBookID();
    void setPatronID(int patronID);
    int getPatronID();
    void setStatus(string status);
    string getStatus();
    void setRecheck(bool recheck);
    bool getRecheck();
    void setCheckoutDate(time_t checkoutDate);
    time_t getCheckoutDate();
    void setDueDate(time_t dueDate);
    time_t getDueDate();
    void dueDateToMonth(time_t date);
    void setAllDates();
    void markLoanOverdue();
    /*
     * print info
     */
    void printLoanInfo();


private:
    int loanID;
    int bookID;
    int patronID;
    string status;
    bool recheck;
    time_t checkoutDate;
    time_t dueDate;

};


#endif //LL0484HW3_LOAN_H
