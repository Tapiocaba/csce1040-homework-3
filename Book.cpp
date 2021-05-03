/*
Lisa Lin (lisalin@my.unt.edu)
Homework 3 Assignment - Library Management System
Started: 3/12/2021
Book entity cpp file
*/

#include "Book.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Book::Book() {
    this->author = "";
    this->title = "";
    this->id = 0;
    this->isbn = 0;
    this->cost = 0.0;
    this->status = "IN";
}

Book::Book(string author, string title, int id, int isbn, float cost, string status) {
    this->author = author;
    this->title = title;
    this->id = id;
    this->isbn = isbn;
    this->cost = cost;
    this->status = status;
}

void Book::setAuthor(string bookAuthor) {
    this->author = bookAuthor;
}

string Book::getAuthor(){
    return author;
}

void Book::setTitle(string bookTitle){
    this->title = bookTitle;
}

string Book::getTitle(){
    return title;
}

void Book::setID(int bookID){
    this->id = bookID;
}

int Book::getID() {
    return id;
}

void Book::setIsbn(int bookISBN) {
    this->isbn = bookISBN;
}

int Book::getIsbn() {
    return isbn;
}

void Book::setCost(float bookCost) {
    this->cost = bookCost;
}

float Book::getCost(){
    return cost;
}

void Book::setStatus(string bookStatus){
    this->status = bookStatus;
}

string Book::getStatus(){
    return status;
}

void Book::printBook() {
    cout << endl << "-------------" << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Library ID: " << id << endl;
    cout << "ISBN: " << isbn << endl;
    cout << fixed << setprecision(2);
    cout << "Cost: $" << cost << endl;
    cout << "Status: " << status << endl;
 }
