/**
 *#############################################################################
 *#---------------------------- Header---------------------------------------
 *# Inventory class extending Transaction class
 *# # @author 	Joshua Landron
 *# # @date     22May2019
 *# # @version  30May2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#############################################################################
 *Implements the doTransaction method that is required from the base class
 *Transaction.
 *Assumptions:
 *Inventory commands should be a single char I.
 *There is no safety checking if there is anyting on the line after the initial
 *I is encountered, it will be thrown out and the current inventory printed
 **/

#ifndef MOVIESTORE_H_
#define MOVIESTORE_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Customer.h"
#include "HashTable.h"
#include "Movie.h"
#include "MovieFactory.h"
#include "Transaction.h"
#include "TransactionFactory.h"

using namespace std;

class MovieStore {
   public:
    MovieStore();
    ~MovieStore();
    void buildTrees(ifstream &);
    void buildCustomers(ifstream &);
    void doTransactions(ifstream &);

    void printMovies();
    void printMovies(char genre) const;
    void printCustomers() const;

    // map to hold vectors of different Genres
    map<char, vector<Movie *>> *m_MovieLists;
    // custom haslist to hold customers
    HashTable *m_Customers;
};
#endif
