/*
Lisa Lin (lisalin@my.unt.edu)
Homework 3 Assignment - Library Management System
Started: 3/12/2021
Patrons storage cpp file
*/

#include "Patrons.h"
#include "Patron.h"
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <fstream>
#include <iomanip>

using namespace std;

bool Patrons::emptyNewPatron() {
  return patrons.empty();
}

Patron* Patrons::findPatron(int patronID){
    map<int, Patron*>::iterator it = patrons.find(patronID);
    if(it != patrons.end())
    {
        return it->second;
    }
    return NULL;
}

void Patrons::addPatron(){
    Patron* patron;
    string name;
    int patronID, numBooks = 0;
    float fine = 0.0;
    char c;
    
    cout << " <<< ADD PATRON >>> " << endl << endl;
    do {
        cout << "Enter patron ID number: ";
        cin >> patronID;
        patron = findPatron(patronID);
        if (patron != NULL) {
            cout << "Patron with this ID already exists." << endl;
            do {
                cout << "Would you like to enter a new patron ID? (y/n) ";
                cin >> c;
                if ((c != 'y') && (c != 'n'))
                {
                    cout << "Invalid option. Please try again." << endl;
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
    } while (patron != NULL);
    
    cin.ignore();
    cout << "Enter patron name: ";
    getline(cin, name);
    
    patrons[patronID] = new Patron(name, patronID, fine, numBooks);
    cout << "Patron " << name << " with ID #" << patronID << " has been added." << endl;

}


void Patrons::editPatron(){

    cout << "<<< EDIT PATRON >>>" << endl << endl;
    int edit;
    char c = 'y';
    Patron* patron;
    int id;
    string name;

    if (patrons.empty())
    {
        cout << "No patrons have been entered" << endl;
        return;
    }

    do {
        cout << "Enter the patron ID: ";
        cin >> id;
        patron = findPatron(id);

        if (patron == NULL) {
            cout << "Patron not found" << endl;
            do {
                cout << "Would you like to enter a new patron ID? (y/n) ";
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
    } while (patron == NULL);

    cout << endl;

    do {
        patron->printPatronInfo();
        cout << endl << "----------" << endl;
        cout << "0 - Exit editing menu" << endl;
        cout << "1 - Edit name" << endl;
        cout << "2 - Edit id" << endl;

        cin >> edit;

        switch(edit)
        {
            case 0:
                break;
            case 1:
            { //edit name
                cin.ignore();
                cout << "Enter new name: "; 
                getline(cin, name);
                patron->setName(name);
                cout << "Successfully updated name." << endl;
                break;
            }
            case 2:
            { //edit ID
                cout << "Enter new patron ID: ";
                cin >> id;
                patron->setID(id);
                cout << "Successfully updated ID." << endl;
                break;
            }
            default:
              cout << "Invalid option." << endl;
                break;
        }
    } while (edit != 0);
}

void Patrons::deletePatron(int patronID){
    cout << "<<< DELETE PATRON >>>" << endl << endl;

    Patron* patron = findPatron(patronID);
    if (patron != NULL)
    {
        delete patron;
        patrons.erase(patronID); // deletes the map entry
    }
}

void Patrons::searchPatron(){
    cout << "<<< FIND PATRON >>>" << endl << endl;
    Patron* patron;
    int id; //patron id

    cout << "Enter patron ID to check if it exists: ";
    cin >> id;
    patron = findPatron(id);
    if (patron != NULL)
    {
        cout << "Patron ID " << id << " exists in the system." << endl;
    }
    else
    {
        cout << "Patron ID " << id << " does not exist in the system." << endl;
    }
}

void Patrons::printAllPatrons(){
    cout << "<<< PRINT ALL PATRONS >>>" << endl << endl;
    if (patrons.empty())
    {
        cout << "No patrons have been created." << endl;
        return;
    }

    map<int, Patron*>::iterator it;

    cout << "Information for All Patrons" << endl;
    for (it = patrons.begin(); it != patrons.end(); it++)
        ((*it).second)->printPatronInfo();
}

void Patrons::findAndPrintPatron(){
    cout << "<<< FIND AND PRINT PATRON >>>" << endl << endl;
    int id;

    if (patrons.empty())
    {
        cout << "No patrons have been stored." << endl;
        return;
    }

    do {
        cout << "Enter patron ID: ";
        cin >> id;
        if (findPatron(id) == NULL)
            cout << "Patron cannot be found." << endl;
    } while (findPatron(id) == NULL);
    patrons.at(id)->printPatronInfo();
}

int Patrons::numOfPatrons() {
   Patron* patron;
    map<int, Patron*>::iterator it;
    int n = 0;
    for (it = patrons.begin(); it != patrons.end(); it++)
    {
        n++;        
    }
    return n; //returns number of books
}

void Patrons::store(){
  ofstream fout;
  fout.open("patrons.dat");
  Patron* patron;
  map<int, Patron*>::iterator it;
    
  fout << numOfPatrons() << endl;
  for (it = patrons.begin(); it != patrons.end(); it++)
  {
    patron = ((*it).second);
        
    fout << patron->getID() << endl;
    fout << patron->getFine() << endl;
    fout << patron->getName() << endl;
    cout << patron->getBooksChecked() << endl;

  }
    fout.close();
}

void Patrons::load() {
  ifstream fin;
  int numBooks;
  fin.open("patrons.dat");
  /*
  * variable declarations
  */
  int id, numBooksChecked, numPatron;
  float fine;
  string name;
  vector<Patron*> patrons;
    
  fin >> numPatron;
  for (int i = 0; i < numPatron; i++)
  {
    fin >> id;
    fin >> fine;
    fin.ignore();
    getline(fin, name);
    fin >> numBooksChecked;

    patrons[id] = new Patron(name, id, fine, numBooksChecked);
    }
    fin.close();
}

void Patrons::payFines() {
  int id;
  float fine, payFine, remain;
  char c;
  Patron* patron;
  cout << "<<< PAY FINES >>>" << endl << endl;

  if (patrons.empty()) {
    cout << "No patrons have been stored." << endl;
    return;
  }

   do {
        cout << "Enter the patron ID: ";
        cin >> id;
        patron = findPatron(id);

        if (patron == NULL) {
            cout << "Patron not found" << endl;
            do {
                cout << "Would you like to enter a new patron ID? (y/n) ";
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
    } while (patron == NULL);
  
  fine = patron->getFine();
  //fine = 12; //for debugging
  if (fine == 0) {
    cout << "Your current fine balance is $0.00" << endl;
    cout << "No payment necessary" << endl;
    return;
  }
  else {
    cout << "Enter amount you would like to pay: ";
    cin >> payFine;

    if (payFine > fine) {
      cout << "Amount entered is greater than fine amount. Payment will be set to fine amount." << endl;
      payFine = fine;
    }
    remain = fine - payFine;
    patron->setFine(remain);
    cout << "Fine paid. The amount remaining is: $" << fixed << setprecision(2) << remain << endl;

  }
  
}