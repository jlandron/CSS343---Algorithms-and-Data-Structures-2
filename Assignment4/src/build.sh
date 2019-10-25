#!/bin/bash

#Run in terminal to compile and run the program
echo "---- Compiling .cpp files ----"
g++ -std=c++11 -I ../include Driver.cpp MovieStore.cpp MovieFactory.cpp Movie.cpp Classic.cpp Drama.cpp Comedy.cpp HashTable.cpp HashNode.cpp Customer.cpp Transaction.cpp TransactionFactory.cpp Borrow.cpp Return.cpp Inventory.cpp History.cpp

echo "---- Running Program with valgrind----"
valgrind ./a.out | cowsay -n -f duck
#valgrind --track-origins=yes ./a.out

exit 0
