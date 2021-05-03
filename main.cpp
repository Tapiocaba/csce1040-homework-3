/*
Lisa Lin (lisalin@my.unt.edu)
Homework 3 Assignment - Library Management System
Started: 3/12/2021
Main file
*/
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include "Book.h"
#include "Books.h"
#include "Loan.h"
#include "Loans.h"
#include "Patron.h"
#include "Patrons.h"
using namespace std;


/*
store/load functions
*/
void storeAll(Books books, Patrons patrons, Loans loans) {
  books.store();
  patrons.store();
  loans.store();

  cout << "Stored successfully." << endl << endl;
}

void loadAll(Books books, Patrons patrons, Loans loans) {
    ifstream fin;
    
    /*
    NOTE ABOUT FILES
    If one file is missing/can't be found then none of them can be loaded - use individual loading.
    */
    fin.open("books.dat");
    if (fin.fail())
    {
	    cout << "File could not be found." << endl;
	    return;
    }
    fin.close();
    fin.open("patrons.dat");
    if (fin.fail())
    {
        cout << "File could not be found." << endl;
        return;
    }
    fin.close();
    fin.open("loans.dat");
    if (fin.fail())
    {
        cout << "File could not be found." << endl;
        return;
    }
    fin.close();
    // load
    cout << "Loaded successfully." << endl << endl;
}


int main() {

    /*
     * declaring variables
     */
    Books books;
    //Loans loans;
    Patrons patrons;
    Loans loans;
    string libraryName;


    /*
     * time
     */
    time_t currentTime = time(0);
    time(&currentTime); //current time

    /*
     * print out due date (after 10 days)
     * time_t newTime = currentTime + 864000;
     * cout << asctime(localtime(&newTime));
     */

    /*
     * KEY for variables
     * c = first choice
     * bookC = choice for book menu
     * patronC = choice for patron menu
     * loanC = choice for loan menu
     */

    int c, bookC, patronC, loanC;
    cout << "Welcome to the Library Management System!" << endl;
    cout << "CSCE 1040 HW3 - Lisa Lin" << endl;
    cout << "Contact information: lisalin@my.unt.edu" << endl;
    cout << "---------------------------------------" << endl << endl;
    cout << "Enter library name: ";
    getline(cin, libraryName);

    /*
     * program menu
     */
    do {
        cout << endl << "- " << libraryName << " Management System -" << endl;
        cout << "Today's Date: " << ctime(&currentTime) << endl;
        cout << " - Main Menu -" << endl;
        cout << "What would you like to do?\n" << endl;
        cout << "0 - Quit program" << endl;
        cout << "1 - Book operations" << endl;
        cout << "2 - Patron operations" << endl;
        cout << "3 - Loan operations" << endl;
        cout << "4 - Store all information" << endl;
        cout << "5 - Load all information" << endl;
        cout << "6 - More information about program" << endl << endl;
        cout << "Enter your choice: ";
        cin >> c;

        switch (c)
        {
            case 0:
                cout << "Thank you for using the library management system. " << endl;
                return 0;
            case 1:
            {
                do {
                    // book operations menu
                    cout << endl << "<<< BOOK OPERATIONS >>>" << endl << endl;
                    cout << "0 - Return to main menu" << endl;
                    cout << "1 - Add a book" << endl;
                    cout << "2 - Edit a book" << endl;
                    cout << "3 - Delete a book" << endl;
                    cout << "4 - Find a book" << endl;
                    cout << "5 - Print all book information" << endl;
                    cout << "6 - Find and print single book information" << endl;
                    cout << "7 - Store book information" << endl;
                    cout << "8 - Load book information" << endl << endl;
            
                    cout << "Select an option: ";
                    cin >> bookC;
                    cout << endl;

                    switch (bookC)
                    {
                        case 0:
                            cout << "Exiting book menu..." << endl << endl;
                            break;
                        case 1:
                        {
                            /*
                             * Add book
                             */
                            books.addBook();
                            break;
                        }
                        case 2:
                        {
                            /*
                             * edit book
                             */
                            books.editBook();
                            break;
                        }
                        case 3:
                        {
                            /*
                            * delete book
                            */
                            if (books.emptyBook())
                            {
                                cout << "No books have been created." << endl;
                                break;
                            }
                            int bookID;
                            cout << "Enter book ID to be deleted: ";
                            cin >> bookID;
                            if (books.findBook(bookID) == NULL)
                            { // if the book can't be found
                                cout << "Invalid book ID. Please try again." << endl;
                                break;
                            }
                            if (books.findBook(bookID) == NULL)
                            {
                                books.deleteBook(bookID);
                            }
                            else
                            {
                                cout << "Book has been assigned to a loan already, so it cannot be deleted." << endl;
                            }
                            break;
                        }
                        case 4:
                        {
                            /*
                             * find book
                             */
                            books.searchBook();
                            break;
                        }
                        case 5:
                        {
                            /*
                             * print all books
                             */
                            books.printAllBooks();
                            break;
                        }
                        case 6:
                        {
                            /*
                             * find and print
                             */
                            books.findAndPrint();
                            break;
                        }
                        case 7:
                        {
                            /*
                            * store book information
                            */
                            books.store();
                            break;
                        }
                        case 8:
                        {
                            /*
                            * load patron information
                            */
                            books.load();
                            break;
                        }
                        default:
                            cout << "Invalid option, please select another." << endl;
                            break;
                    }
                } while (bookC != 0);
                break;
            }
            case 2:
            {
                do {
                    // Patron operations menu
                    cout << endl << "<<< PATRON OPERATIONS >>>" << endl << endl;
                    cout << "0 - Return to main menu" << endl;
                    cout << "1 - Add a patron" << endl;
                    cout << "2 - Edit a patron" << endl;
                    cout << "3 - Delete a patron" << endl;
                    cout << "4 - Find a patron" << endl;
                    cout << "5 - Print all patrons' information" << endl;
                    cout << "6 - Find and print single patron information" << endl;
                    cout << "7 - Pay fines" << endl;
                    cout << "8 - Store patron information" << endl;
                    cout << "9 - Load patron information" << endl << endl;
                    cout << "Select an option: ";
                    cin >> patronC;
                    cout << endl;

                    switch (patronC)
                    {
                        case 0:
                            /*
                             * exit
                             */
                            cout << "Exiting patron menu..." << endl << endl;
                            break;
                        case 1:
                        {
                           /*
                            * add patron
                            */
                            patrons.addPatron();
                            
                            break;
                        }
                        case 2:
                        {
                            /*
                             * edit patron
                             */
                             patrons.editPatron();
                            break;
                        }
                        case 3:
                        {
                            /*
                             * delete patron
                             */
                           if (patrons.emptyNewPatron())
                            {
                                cout << "No patrons have been created." << endl;
                                break;
                            }
                            int patronID;
                            cout << "Enter patro ID to be deleted: ";
                            cin >> patronID;
                            if (patrons.findPatron(patronID) == NULL)
                            { // if the patron can't be found
                                cout << "Invalid patron ID. Please try again." << endl;
                                break;
                            }
                            if (patrons.findPatron(patronID) == NULL)
                            {
                                patrons.deletePatron(patronID);
                            }
                            else
                            {
                                cout << "Patron has been assigned to a loan already, so it cannot be deleted." << endl;
                            }
                            break;
                        }
                        case 4:
                        {
                            /*
                             * find patron
                             */
                            patrons.searchPatron();
                            break;
                        }
                        case 5:
                        {
                            /*
                             * print all patron info
                             */
                             patrons.printAllPatrons();
                            break;
                        }
                        case 6:
                        {
                            /*
                             * find and print single patron info
                             */
                             patrons.findAndPrintPatron();
                            break;
                        }
                        case 7:
                        {
                            /*
                            * pay fines
                            */
                            patrons.payFines();
                            break;
                        }
                        case 8:
                        {
                            /*
                            * store patron information
                            */
                            patrons.store();
                            break;
                        }
                        case 9:
                        {
                          /*
                          * load patron information
                          */
                          patrons.load();
                        }

                        default:
                            cout << "Invalid option, please select another." << endl;
                            break;
                    }
                } while (patronC != 0);
                break;
            }
            case 3:
            {

                do {
                    // Patron operations menu
                   cout << endl << " <<< LOAN OPERATIONS >>>" << endl;
                    cout << endl << "0 - Return to main menu" << endl;
                    cout << "1 - Check out book" << endl;
                    cout << "2 - Check in book" << endl;
                    cout << "3 - List all overdue books" << endl;
                    cout << "4 - List all overdue books for a patron" << endl;
                    cout << "5 - Recheck book" << endl;
                    cout << "6 - Report lost book" << endl;
                    cout << "7 - Edit loan" << endl;
                    cout << "8 - Update loan status" << endl;
                    cout << "9 - Print all loan information" << endl;
                    cout << "10 - Store loan information" << endl;
                    cout << "11 - Load loan information" << endl << endl;
                    cout << "Select an option: ";
                    cin >> loanC;
                    cout << endl;

                    switch (patronC)
                    {
                        case 0:
                            /*
                             * exit
                             */
                            cout << "Exiting loan menu..." << endl << endl;
                            break;
                        case 1:
                        {
                           /*
                            * check out 
                            */
                            loans.checkOutBook(&books, &patrons);
                            
                            break;
                        }
                        case 2:
                        {
                            /*
                             * check in
                             */
                             loans.checkInBook(&books, &patrons);
                            break;
                        }
                        case 3:
                        {
                            /*
                             * list overdue books
                             */
                             loans.listAllOverdue();
                           
                            break;
                        }
                        case 4:
                        {
                            /*
                             * list overdue for patron
                             */
                            loans.listSpecificOverdue();
                            break;
                        }
                        case 5:
                        {
                            /*
                             * recheck
                             */
                             loans.recheckBook();
                            break;
                        }
                        case 6:
                        {
                            /*
                             * rep lost
                             */
                             loans.reportLost(&books, &patrons);
                            break;
                        }
                        case 7:
                        {
                            /*
                            * edit loan
                            */
                            loans.editLoan(&books, &patrons);
                            break;
                        }
                        case 8:
                        {
                            /*
                            * update loan status
                            */
                            loans.updateLoan(&books, &patrons);
                            break;
                        }
                        case 9:
                        {
                          /*
                          * print all
                          */

                          loans.printAllLoans();
                          break;
                        }
                        case 10:
                        {
                          /*
                            store
                          */
                          loans.store();
                          break;
                        }
                        case 11:
                        {
                          //load
                          loans.load();
                          break;
                        }

                        default:
                            cout << "Invalid option, please select another." << endl;
                            break;
                    }
                } while (loanC != 0);
                break;
            }
            case 4: {
              /*
              * store all information
              */
              storeAll(books, patrons, loans);
              break;
            }
            case 5: {
              /*
              * Load all information
              */
              loadAll(books, patrons, loans);
              break;
            }
            case 6: {
              cout << "<<< MORE INFORMATION ABOUT PROGRAM >>>" << endl << endl;
              cout << "This program was created by Lisa Lin for Homework 3 for CSCE 1040." << endl;
              cout << "Patrons can borrow a maximum of 6 books, and cannot borrow books if they have any overdue books." << endl;
              cout << "When books are reported as lost, the loan is deleted and the fine amount is added to the patron's file." << endl;
              cout << "The loan period is 10 days, with the recheck adding 10 days to the end." << endl;
              cout << "The fine is $0.25 every 24 hours." << endl;
              cout << "Please enjoy using the management system!" << endl;
              break;
            }

            default:
                cout << "Invalid Option, please try again." << endl;
                break;
        }
    } while (c != 0);

    return 0;
}
