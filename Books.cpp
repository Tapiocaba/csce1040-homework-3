/*
Lisa Lin (lisalin@my.unt.edu)
Homework 3 Assignment - Library Management System
Started: 3/12/2021
Books storage cpp file
*/


#include "Books.h"
#include "Book.h"
#include <iostream>
#include <iterator>
#include <fstream>
#include <map>

using namespace std;

bool Books::emptyBook() {
    return books.empty();
}

Book* Books::findBook(int id) {
    map<int, Book*>::iterator it = books.find(id);
    if (it != books.end()) {
        return it->second;
    }
    return NULL;
}

void Books::addBook() {
    Book* book;
    int bookID, isbn;
    float cost;
    string status = "IN";
    string author, title;
    char choice;

    cout << "<<< ADD BOOK >>>" << endl << endl;
    do {
        cout << "Enter book ID number: ";
        cin >> bookID;
        book = findBook(bookID);
        if (book != NULL) { // if book ID already exists
            cout << "Book with this ID alreay exists." << endl;
            do {
                cout << "Would you like to enter a new book ID? (y/n) ";
                cin >> choice;
                if ((choice != 'y') && (choice != 'n'))
                {
                    cout << "Invalid option. Please try again." << endl;
                }
                else
                {
                    if (choice == 'n')
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
    } while (book != NULL);

    cin.ignore();

    cout << "Enter the title: ";
    getline(cin, title);
    cout << "Enter the author: ";
    getline(cin, author);
    cout << "Enter the book's ISBN: ";
    cin >> isbn;
    cout << "Enter the book's cost (in USD): ";
    cin >> cost;

    books[bookID] = new Book(author, title, bookID, isbn, cost, status);
    cout << title << " by " << author << " has been added!" << endl;
    // add book to the map
}

void Books::editBook() {
    int edit;
    char c = 'y';
    Book* book;
    int id, isbn;
    string author, title;
    float cost;
    string status;

    cout << "<<< EDIT BOOK >>>" << endl << endl;
    if (books.empty())
    {
        cout << "No books have been entered." << endl;
        return;
    }

    do {
        cout << "Enter the book ID: ";
        cin >> id;
        book = findBook(id);
        if (book == NULL) {
            cout << "Book not found" << endl;
            do {
                cout << "Would you like to enter a new book ID? (y/n) ";
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
    } while (book == NULL);

    cout << endl;


    do {
          book->printBook();
        cout << "<<< EDITING MENU FOR " << book->getTitle() << " >>>" << endl;
        cout << endl << "----------" << endl;
        cout << "0 - Exit editing menu" << endl;
        cout << "1 - Edit title" << endl;
        cout << "2 - Edit author" << endl;
        cout << "3 - Edit ID" << endl;
        cout << "4 - Edit ISBN" << endl;
        cout << "5 - Edit cost" << endl;
        cout << "6 - Edit status" << endl;
        cout << "NOTE - To edit book status to repair for a book associated with a loan, enter loan operations." << endl << endl;
        cout << "Select an option: ";
        cin >> edit;

        switch(edit)
        {
            case 0:
                break;
            case 1:
            { //edit title
                cin.ignore();
                cout << "Enter new title: "; 
                getline(cin, title);
                book->setTitle(title);
                cout << "Successfully updated title." << endl;
                break;
            }
            case 2:
            { //edit author
                cout << "Enter new author: ";
                cin.ignore();
                getline(cin, author);
                book->setAuthor(author);
                cout << "Successfully updated author." << endl;
                break;
            }
            case 3:
            { //edit ID
                cout << "Enter new ID: ";
                cin >> id;
                book->setID(id);
                cout << "Successfully updated ID." << endl;
                break;
            }
            case 4:
            { //edit ISBN
                cout << "Enter new ISBN: ";
                cin >> isbn;
                book->setIsbn(isbn);
                cout << "Successfully updated ISBN." << endl;
                break;
            }
            case 5:
            { //edit cost
                cout << "Enter new cost: ";
                cin >> cost;
                book->setCost(cost);
                cout << "Successfully updated cost." << endl;
                break;
            }
            case 6:
            {
              string status = book->getStatus();
              string selection;
              if (status == "OUT") {
                cout << "Book is currently being checked out. Please enter loans to edit." << endl;
              }
              else if (status == "IN") {
                cout << "Book is currently IN." << endl;
                cout << "Enter new status in all CAPS that is not OUT: " << endl;
                getline(cin, selection);
                if (selection == status) {
                  cout << "Book has this status.";
                }
                else if (selection == "OUT") {
                  cout << "Book must be associated with patron if it is to be marked OUT. Please check out book." << endl;
                }
                else if (selection == "REPAIR") {
                  book->setStatus(selection);
                  cout << "Book status updated to repair." << endl;
                }
                else if (selection == "LOST") {
                  cout << "Book must be reported lost by a patron. Please go to patron operations." << endl;

                }

              }
              break;
            }
            default:
              cout << "Invalid option." << endl;
                break;
        }
    } while (edit != 0);
}

void Books::deleteBook(int bookID) {
    cout << "<<< DELETE BOOK >>>" << endl;
    Book* book = findBook(bookID);
    if (book != NULL)
    {
        delete book; // deletes the book
        books.erase(bookID); // deletes the map entity using bookID
    }
}

void Books::searchBook() {
    Book* book;
    int id; //book id

    cout << "<<< FIND BOOK >>>" << endl << endl;
    cout << "Enter book ID to check if it exists: ";
    cin >> id;
    book = findBook(id);
    if (book != NULL)
    {
        cout << "Book ID " << id << " exists in the system." << endl;
    }
    else
    {
        cout << "Book ID " << id << " does not exist in the system." << endl;
    }
}

void Books::printAllBooks() {
    cout << "<<< PRINT ALL BOOKS >>>" << endl << endl;
    if (books.empty())
    {
        cout << "No books have been created." << endl;
        return;
    }

    map<int, Book*>::iterator it;

    cout << "Information for All Books" << endl;
    for (it = books.begin(); it != books.end(); it++) {
        ((*it).second)->printBook();
    }
}

void Books::findAndPrint() {
    int id;

    cout << "<<< FIND AND PRINT BOOKS>>>" << endl << endl;
    if (books.empty())
    {
        cout << "No books have been stored." << endl;
        return;
    }

    do {
        cout << "Enter book ID: ";
        cin >> id;
        if (findBook(id) == NULL)
            cout << "Book cannot be found." << endl;
    } while (findBook(id) == NULL);
    books.at(id)->printBook();
}

int Books::numOfBooks() {
   Book* book;
    map<int, Book*>::iterator it;
    int n = 0;
    for (it = books.begin(); it != books.end(); it++)
    {
        n++;        
    }
    return n; //returns number of books
}

void Books::store(){
  ofstream fout;
  fout.open("books.dat");
  Book* book;
  map<int, Book*>::iterator it;
    
  fout << numOfBooks() << endl;
  for (it = books.begin(); it != books.end(); it++)
  {
      cout << (*it).first << endl;
    book = ((*it).second);
        
    fout << book->getID() << endl;
    fout << book->getAuthor() << endl;
    fout << book->getTitle() << endl;
    fout << book->getCost() << endl;
    fout << book->getIsbn() << endl;
    fout << book->getStatus() << endl; 
  }
    fout.close();
}

void Books::load() {
  ifstream fin;
  int numBooks;
  fin.open("books.dat"); // u should probably check to see if it actually opened
  /*
  * variable declarations
  */
  string title;
  int id, isbn;
  string status, author;
  float cost;
    
  fin >> numBooks;
  for (int i = 0; i < numBooks; i++)
  {
    fin >> id;
    fin.ignore();
    getline(fin, author);
    getline(fin, title);
    fin >> cost;
    fin >> isbn;
    getline(fin, status);
    books[id] = new Book(author, title, id, isbn, cost, status);
    }
    fin.close();
}


