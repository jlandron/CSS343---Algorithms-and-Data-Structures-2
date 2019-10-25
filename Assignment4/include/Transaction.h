/**
 *#############################################################################
 *#---------------------------- Header---------------------------------------
 *# Abstract Transaction class
 *# # @author 	Joshua Landron
 *# # @date     22May2019
 *# # @version  30May2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#############################################################################
 *Assumptions:
 * all transaction derived classes will fully implement the doTransaction
 *method.
 **/

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "HashTable.h"
#include "Movie.h"

using namespace std;

class Transaction {
   public:
    Transaction();
    virtual ~Transaction();
    virtual void doTransaction(map<char, vector<Movie*>>*, HashTable*,
                               string) = 0;

    char m_Code;
    char m_Genre;
    int m_CustomerID;
    char m_MediaType;
    string m_Description;
};

#endif /* !TRANSACTION_H_ */
