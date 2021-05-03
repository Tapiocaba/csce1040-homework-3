/*
Lisa Lin (lisalin@my.unt.edu)
Homework 3 Assignment - Library Management System
Started: 3/12/2021
Patron entity cpp file
*/

#include "Patron.h"
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

Patron::Patron(){
    this->name = "";
    this->patronID = 0;
    this->fine = 0.0;
    this->booksChecked = 0;
}

Patron::Patron(string name, int patronID, float fine, int booksChecked) {
    this->name = name;
    this->patronID = patronID;
    this->fine = fine;
    this->booksChecked = booksChecked;
}

void Patron::setName(string pName){
    this->name = pName;
}

string Patron::getName(){
    return name;
}

void Patron::setID(int id){
    this->patronID = id;
}

int Patron::getID(){
    return patronID;
}

void Patron::setFine(float pFine){
    this->fine = pFine;
}

float Patron::getFine(){
    return fine;
}

void Patron::setBooksChecked(int numBooks){
    this->booksChecked = numBooks;
}

int Patron::getBooksChecked(){
    return booksChecked;
}

void Patron::printPatronInfo() {
    cout << endl << "----------" << endl;
    cout << "Patron Name: " << name << endl;
    cout << "Patron ID: " << patronID << endl;
    cout << fixed << setprecision(2);
    cout << "Fine Amount: " << fine << endl;
    cout << "Books Checked: " << booksChecked << endl;
}