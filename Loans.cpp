/*
Lisa Lin (lisalin@my.unt.edu)
Homework 3 Assignment - Library Management System
Started: 3/12/2021
Loans storage cpp file
*/

#include "Loans.h"
#include "Loan.h"
#include "Books.h"
#include "Book.h"
#include "Patrons.h"
#include "Patron.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <time.h>
#include <iterator>

using namespace std;

Loan* Loans::findLoan(int lID) {
    map<int,Loan*>::iterator it = loans.find(lID);
    if(it != loans.end())
    {
        return it->second;
    }
    return NULL;
}

void Loans::searchLoan() {
    Loan* loan;
    int loanID;
    
    cout << "Enter loan ID: ";
    cin >> loanID;
    
    loan = findLoan(loanID);
    if (loan != NULL)
    {
        cout << "Loan #" << loanID << " exists in the system." << endl;
    }
    else
    {
        cout << "Loan #" << loanID << " does not exist in the system." << endl;
    }
}

  /*
  * menu functions
  */
  void Loans::checkOutBook(Books* books, Patrons* patrons){
    Loan* loan;
    Book* book;
    Patron* patron;
    int loanID, bookID, patronID, tempPatronID;
    int numBook = 1;

    time_t checkoutDate, checkinDate;
    string status;
    char c; //choice    

    cout << endl << "<<< CREATE LOAN >>>" << endl << endl;
    do {
        cout << "Enter loan ID: ";
        cin >> loanID;
        loan = findLoan(loanID);

        if (loan != NULL) { //checks if loan with entered Loan ID exists
            cout << "Loan with this loan ID already exists in the system." << endl;
            do {
                cout << "Would you like to enter a different loan ID? (y/n): ";
                cin >> c;
                if ((c != 'y') && (c != 'n'))
                {
                    cout << "Invalid option." << endl;
                }
                else
                {
                    if (c == 'n')
                    {
                        return;
                    }
                    else
                    {
                        break;
                    }
                }
            } while (true);
        }
    } while (loan != NULL);
    loan = new Loan();
    loan->setLoanID(loanID);
  
        do {
            cout << "Enter patron ID: ";
            cin >> patronID;
            patron = patrons->findPatron(patronID);
            if (patron == NULL) {
                cout << "Entered patron ID does not exist." << endl;
                do {
                    cout << "Would you like to enter a different patron ID? (y/n): ";
                    cin >> c;
                    if ((c != 'n') && (c != 'y'))
                    {
                        cout << "Invalid option." << endl;
                    }
                    else
                    {
                        if (c == 'n')
                        {
                            return;
                        }
                        else
                        {
                            break;
                        }
                    }
                } while (true);
            }
        } while (patron == NULL); 

    loan->setPatronID(patronID);

    //check to see if patron has more than 6 books checked out / if they would exceed 6 books upon checkout 
    patron = patrons->findPatron(patronID);
    int currentBooksChecked = patron->getBooksChecked();
    patron->setBooksChecked(currentBooksChecked);    

    if (currentBooksChecked >= 6) { //stops user from checking out > 6 books
      cout << "You can only check out a maximum of 6 books. Please return a book first." << endl;
      cout << "You have " << currentBooksChecked << " books checked out." << endl; //debuggin purposes
      return;
    }

    //check to see if patron has any overdue books
    /*
    string tempStatus = "OVERDUE";
    map<int, Loan*>::iterator it;

    if (it->second->getStatus() == tempStatus){
        cout << "Patron has overdue book. Please check in book first." << endl;
        return;
    }
    */

        do {
        cout << "Enter book ID: ";
        cin >> bookID;
        book = books->findBook(bookID);

        if (book == NULL) { //checks if book with entered book ID exists
            cout << "Book with entered book ID does not exist." << endl;
                do {
                    cout << "Would you like to enter a different book ID? (y/n): ";
                    cin >> c;
                    if ((c != 'n') && (c != 'y'))
                    {
                        cout << "Invalid option." << endl;
                    }
                    else
                    {
                        if (c == 'n')
                        {
                            return;
                        }
                        else
                        {
                            break;
                        }
                    }
                } while (true);
        }
    } while (book == NULL);

     string statusString = book->getStatus();
      if (statusString == "IN") {
      cout << "Book found." << endl;;
      loan->setBookID(bookID);
    }
    else if (statusString == "OUT") {
    cout << "Book is already checked out."<< endl;
      book = NULL;
      return;
     }          
     else if (statusString == "LOST") {
     cout << "Book is lost. It cannot be checked out." << endl;
      book = NULL;
      return;
                }       
    else if (statusString == "REPAIR") {
      cout << "Book is out for repair. It cannot be checked out." << endl;
      book = NULL;
      return;
    }
    
    /*
     * time
     */
    checkoutDate = time(0);
    time(&checkoutDate); //current time

    checkinDate = checkoutDate + 864000; //sets check in date to 10 days after checkout date

    loan->setDueDate(checkinDate);
    loan->setCheckoutDate(checkoutDate);

    /*
    set recheck to false
    */
    //loan->setRecheck(false); 

    //changes values in other objects
    loans[loanID] = loan; // makes a loan
    book->setStatus("OUT");
    patron->setBooksChecked(currentBooksChecked + 1);
    time_t dueDate = loan->getDueDate();

    cout << book->getTitle() << " has been successfully loaned. Enjoy your book! It is due on ";
    loan->dueDateToMonth(dueDate);
    cout << "Returning to main menu..." << endl << endl;

  }

  void Loans::checkInBook(Books* books, Patrons* patrons){
    Loan* loan;
    Book* book;
    Patron* patron;
    int loanID, bookID, patronID;
    char c;
    
    cout << "<<< CHECK IN BOOK >>>" << endl << endl;

    do {
        cout << "Enter loan ID: ";
        cin >> loanID;
        loan = findLoan(loanID);
        if (loan == NULL) {
            cout << "Loan with loan ID #" << loanID << " does not exist." << endl;
            do {
                cout << "Would you like to enter a ifferent loan ID? (y/n): ";
                cin >> c;
                if ((c != 'y') && (c != 'n'))
                {
                    cout << "Invalid option." << endl;
                }
                else
                {
                    if (c == 'n')
                    {
                        return;
                    }
                    else
                    {
                        break;
                    }
                }
            } while (true);
        }
    } while (loan == NULL);


    bookID = loan->getBookID();
    patronID = loan->getPatronID(); 
    book = books->findBook(bookID);  
    patron = patrons->findPatron(patronID);
  
    //delete from other functions
    int numBooksChecked = patron->getBooksChecked();
    string bookStatus = "IN";

    book->setStatus(bookStatus); //sets status to IN
    patron->setBooksChecked(numBooksChecked - 1);
    //erases entities
    loans.erase(loanID);
    delete loan;
    cout << book->getTitle() << " has been checked in. Thank you!" << endl;
    
  }
  
  void Loans::recheckBook() {
          int loanID;
      char c;
      Loan* loan;

      cout << "<<< RECHECK BOOK >>>" << endl << endl;
      do {
        cout << "Enter loan ID: ";
        cin >> loanID;
        loan = findLoan(loanID);
        if (loan == NULL) {
            cout << "Loan with loan ID #" << loanID << " does not exist." << endl;
            do {
                cout << "Would you like to enter a ifferent loan ID? (y/n): ";
                cin >> c;
                if ((c != 'y') && (c != 'n'))
                {
                    cout << "Invalid option." << endl;
                }
                else
                {
                    if (c == 'n')
                    {
                        return;
                    }
                    else
                    {
                        break;
                    }
                }
            } while (true);
        }
      } while (loan == NULL);

    //checks if book has been rechecked before
    loan = findLoan(loanID);
    bool recheck = loan->getRecheck(); //this line is having problems
    if (recheck == true) {
      cout << "Books can only be rechecked once." << endl;
      return;
    }
    /*
    time_t currentTime = time(0);
    time(&currentTime);
    */
    time_t currentDate = time(0);
    time(&currentDate);
    time_t newDueDate = currentDate + 864000;

    loan->setDueDate(newDueDate); //sets new due date
    loan->setRecheck(true); // sets recheck bool to be true in loan

    //confirmation message
    cout << "Book has been rechecked and is due ten days from today. The new due date is ";
    loan->dueDateToMonth(newDueDate);
    
  }

  void Loans::editLoan(Books* books, Patrons* patrons){
    int o;
    char c;
    Patron* patron;
    Loan* loan;
    Book* book;
    int loanID;

    if (loans.empty())
    {
        cout << "No loans have been created." << endl;
        return;
    }
    

    do {
        cout << "Enter the loan ID: ";
        cin >> loanID;
        loan = findLoan(loanID);
        if (loan == NULL) {
            cout << "Loan not found." << endl;
            do {
                cout << "Would you like to enter a new loan ID? (y/n) ";
                cin >> c;
                if ((c != 'y') && (c != 'n'))
                {
                    cout << "Choice not recongized, please try again." << endl;
                }
                else
                {
                    if (c == 'n')
                    {
                        return;
                    }
                    else
                    {
                        break;
                    }
                }
            } while (true);
        }
    } while (loan == NULL);

    cout << endl;
    loan = findLoan(loanID);
    int patronID = loan->getPatronID(), bookID = loan->getBookID();
    do {
        cout << "<<< EDITING MENU FOR LOAN #" << loanID << " >>>" << endl;
        cout << endl << "----------" << endl;
        cout << "0 - Exit editing menu" << endl;
        cout << "1 - Edit loan ID" << endl;
        cout << "2 - Edit book status to repair and delete loan." << endl;
        cout << "Select an option: ";
        cin >> o;

        switch(o)
        {
            case 0:
                break;
            case 1:
            { 
              cout << "Enter new loan ID: ";
              cin >> loanID;
              loan->setLoanID(loanID);
              cout << "Loan ID successfully updated." << endl;
              break;
            }
            case 2:
            {
              cout << "<<< CHANGE BOOK STATUS TO REPAIR >>> " << endl << endl;
              book->setStatus("REPAIR"); //sets status to repair
              //delete from other functions
               int numBooks = patron->getBooksChecked();
                patron->setBooksChecked(numBooks - 1);
               //erases entities
               loans.erase(loanID); //deletes loan
               delete loan;
               break;
            }
            default:
              cout << "Invalid option." << endl;
                break;
        }
    } while (o != 0);

  }

  void Loans::reportLost(Books* books, Patrons* patrons){

    cout << endl << "<<< REPORT LOST BOOK >>>" << endl << endl;

    if (loans.empty()) { //checks to see if any loans are there
      cout << "No loans have been created." << endl;
      return;
    }
    string status;
    int loanID, bookID, patronID;
    float fine, oldfine;
    char c;
    Book* book;
    Patron* patron;
    Loan* loan;

    do {
        cout << "Enter loan ID: ";
        cin >> loanID;
        loan = findLoan(loanID);
        if (loan == NULL) {
            cout << "Loan with loan ID #" << loanID << " does not exist." << endl;
            do {
                cout << "Would you like to enter a ifferent loan ID? (y/n): ";
                cin >> c;
                if ((c != 'y') && (c != 'n'))
                {
                    cout << "Invalid option." << endl;
                }
                else
                {
                    if (c == 'n')
                    {
                        return;
                    }
                    else
                    {
                        break;
                    }
                }
            } while (true);
        }
    } while (loan == NULL);
    loan = findLoan(loanID); //find loan
    bookID = loan->getBookID(); //get book id from loan
    patronID = loan->getPatronID(); //get patron id from loan
    book = books->findBook(bookID); //find book from book id
    patron = patrons->findPatron(patronID); //find patron from patron id
    
    /*
    changing patron and book class variables
    */

    oldfine = patron->getFine(); //find patron old fine
    fine = book->getCost(); //set fine to book cost
    cout << "Fine of $" << fine << " has been added to the patron." << endl;

    fine += oldfine; // finds overall fine
    cout << "Loan has been deleted." << endl;
    
    patron->setFine(fine); // sets patron fine to sum of both

    //delete from other functions
    int numBooks = patron->getBooksChecked();
    book->setStatus("LOST"); //sets status to IN
    patron->setBooksChecked(numBooks - 1);
    //erases entities
    loans.erase(loanID); //deletes loan
    delete loan;
  }


  void Loans::updateLoan(Books* books, Patrons* patrons){
    cout << "<<< UPDATE LOANS >>>" << endl;
    if (loans.empty()) {
      cout << "No loans have been created." << endl;
      return;
    }

    map<int, Loan*>::iterator it;    

    string status = "OVERDUE";
    for (it = loans.begin(); it != loans.end(); it++)
    {
        (it->second)->markLoanOverdue(); //updates loan status
    }
    cout << "Loans successfully updated." << endl;
  }
  
  void Loans::listAllOverdue(){
    cout << "<<< PRINT ALL OVERDUE >>>" << endl << endl;

    if (loans.empty())
    {
        cout << "No loans have been created." << endl;
        return;
    }
    
    string status = "OVERDUE";
    
    do {
        if ((status != "IN") && (status != "OVERDUE")) {
          cout << "Status could not be found." << endl;
        } //debugging
    } while ((status != "IN") && (status != "OVERDUE"));

    map<int, Loan*>::iterator it;


    if (it->second->getStatus() == status){
            it->second->printLoanInfo();
    }

    cout << "All overdue books:" << endl;
    for (it = loans.begin(); it != loans.end(); it++) {
        ((*it).second)->printLoanInfo();
    }
    
  }

  void Loans::listSpecificOverdue(){
    cout << "<<< LIST SPECIFIC PATRON'S OVERDUE BOOKS >>>" << endl << endl;
    if (loans.empty()) {
      cout << "No loans have been created." << endl;
      return;
    }
    map<int, Loan*>::iterator it;

    string status = "OVERDUE";
    for (it = loans.begin(); it != loans.end(); it++)
    {
        (it->second)->markLoanOverdue(); //updates loan status
        if (it->second->getStatus() == status)
        {
            it->second->printLoanInfo();
    
        }
    }

  }

  void Loans::printAllLoans() {
    cout << "<<< PRINT ALL BOOKS >>>" << endl << endl;
    if (loans.empty())
    {
        cout << "No loans have been created." << endl;
        return;
    }

    map<int, Loan*>::iterator it;

    cout << "Information for All Books" << endl;
    for (it = loans.begin(); it != loans.end(); it++) {
        ((*it).second)->printLoanInfo();
    }
}

  /*
  store and load
  */
  /*
  int Loans::numOfLoans(){

  } //for use in storing
*/
  void Loans::store(){
  ofstream fout;
  fout.open("loans.dat");
  Loan* loan;
  map<int, Loan*>::iterator it;
  fout << numOfLoans() << endl;
  for (it = loans.begin(); it != loans.end(); it++)
  {
    cout << (*it).first << endl;
    loan = ((*it).second);
        
    fout << loan->getLoanID() << endl;
    fout << loan->getPatronID() << endl;
    fout << loan->getBookID() << endl;
    fout << loan->getStatus() << endl;
    fout << loan->getCheckoutDate() << endl;
    fout << loan->getDueDate() << endl; 
    fout << loan->getRecheck() << endl;
  }
    fout.close();
  }

  void Loans::load(){
  ifstream fin;
  int numLoans;
  fin.open("books.dat"); // u should probably check to see if it actually opened
  /*
  * variable declarations
  */
  int loanID, patronID, bookID;
  string status;
  bool recheck;
  time_t checkoutDate, checkinDate;

  fin >> numLoans;
  for (int i = 0; i < numLoans; i++)
  {
    fin >> loanID;
    fin >> patronID;
    fin >> bookID;
    fin.ignore();
    getline(fin, status);
    fin >> checkoutDate;
    fin >> checkinDate;
    loans[loanID] = new Loan(loanID, bookID, patronID, status, checkoutDate, checkinDate, recheck);
    }
    fin.close();
  }

int Loans::numOfLoans() {
   Loan* loan;
    map<int, Loan*>::iterator it;
    int n = 0;
    for (it = loans.begin(); it != loans.end(); it++)
    {
        n++;        
    }
    return n; //returns number of books
}