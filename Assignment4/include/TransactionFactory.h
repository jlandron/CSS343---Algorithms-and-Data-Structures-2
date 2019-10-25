/**
 *#############################################################################
 *#---------------------------- Header---------------------------------------
 *# TransactionFactory class for use in MovieStore
 *# # @author 	Joshua Landron
 *# # @date     22May2019
 *# # @version  30May2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#############################################################################
 * Implements a single function makeTransaction that creates the correct type of
 *transaction object and calls doTransaction().
 *Assumptions:
 * Transaction input should be correctly formatted as per each trancation type
 *that is wanted.
 **/

#ifndef TRANSACTIONFACTORY_H_
#define TRANSACTIONFACTORY_H_

#include <iostream>
#include <string>
#include "Borrow.h"
#include "History.h"
#include "Inventory.h"
#include "Return.h"

class TransactionFactory {
   public:
    TransactionFactory();
    ~TransactionFactory();
    Transaction *makeTransaction(string);
};

#endif /* !TRANSACTIONFACTORY_H_ */
