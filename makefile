
ll0484hw3: main.o Loan.o Loans.o Book.o Books.o Patron.o Patrons.o
	g++ -o hw3 main.o Loan.o Loans.o Book.o Books.o Patron.o Patrons.o

main.o: main.cpp Loan.o Loans.o Book.o Books.o Patron.o Patrons.o
	g++ -c main.cpp

Loan.o: Loan.cpp Loan.h
	g++ -c Loan.cpp

Loans.o: Loans.cpp Loans.h
	g++ -c Loans.cpp

Book.o: Book.cpp Book.h
	g++ -c Book.cpp

Books.o: Books.cpp Books.h
	g++ -c Books.cpp

Patron.o: Patron.cpp Patron.h
	g++ -c Patron.cpp

Patrons.o: Patrons.cpp Patrons.h
	g++ -c Patrons.cpp

run:
	make && ./ll0484hw3
