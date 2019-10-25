/**
 *#############################################################################
 *#---------------------------- Header---------------------------------------
 *# History class extending Transaction class
 *# # @author 	Joshua Landron
 *# # @date     22May2019
 *# # @version  30May2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#############################################################################
 *Implements the doTransaction method that is required from the base class
 *Transaction.
 *Assumptions:
 *History Commands should be formatted as such:
 *
 * H customerID
 *
 * any other text after the ID will be thrown out and the history printed.
 * If the customer ID is not registered, an error message will display
 **/

#ifndef HISTORY_H_
#define HISTORY_H_

#include <iostream>
#include <sstream>
#include <string>
#include "Transaction.h"

using namespace std;

class History : public Transaction {
   public:
    History();
    virtual ~History();
    virtual void doTransaction(map<char, vector<Movie*>>*, HashTable*, string);
};

#endif /* !HISTORY_H_ */
