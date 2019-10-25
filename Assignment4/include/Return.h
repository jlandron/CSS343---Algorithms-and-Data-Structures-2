/**
 *#############################################################################
 *#---------------------------- Header---------------------------------------
 *# Return class extending Transaction class
 *# # @author 	Joshua Landron
 *# # @date     22May2019
 *# # @version  30May2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#############################################################################
 *Implements the doTransaction method that is required from the base class
 *Transaction.
 *Assumptions:
 *Return commands should be ordered correctly, thought they can contain
 *incorrect data. The format of a return command depends on the genre requested.
 *the three genres currently implemented are Classic, Drama, and Comedy. The
 *Commands for each should be formatted as such:
 *
 * Comedy:  R customerID D F Movie_Title, ReleaseYear
 * Drama:   R customerID D D DirectorName, MovieTitle,
 * Classic: R customerID D C ReleaseMonth ReleaseYear LeadActor
 *
 * This class will check the Customer inventory for the movie, and return it to
 *the store, deleting it from the users inventory and adding a new line of text
 *to the customer history in regards to the return.
 **/

#ifndef RETURN_H_
#define RETURN_H_

#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include "Transaction.h"

using namespace std;

class Return : public Transaction {
   public:
    Return();
    virtual ~Return();
    virtual void doTransaction(map<char, vector<Movie*>>*, HashTable*, string);
};

#endif /* !RETURN_H_ */
