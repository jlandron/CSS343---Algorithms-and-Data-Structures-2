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

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <iostream>
#include <string>
#include "Transaction.h"

using namespace std;

class Inventory : public Transaction {
   public:
    Inventory();
    virtual ~Inventory();
    virtual void doTransaction(map<char, vector<Movie*>>*, HashTable*, string);
};

#endif /* !INVENTORY_H_ */
