/**
 *#############################################################################
 *#---------------------------- Header---------------------------------------
 *# Borrow class extending Transaction class
 *# # @author 	Joshua Landron
 *# # @date     22May2019
 *# # @version  30May2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#############################################################################
 *Implements the doTransaction method that is required from the base class
 *Transaction.
 *Assumptions:
 *Borrow commands should be ordered correctly, thought they can contain
 *incorrect data. The format of a borrow command depends on the genre requested.
 *the three genres currently implemented are Classic, Drama, and Comedy. The
 *Commands for each should be formatted as such:
 *
 * Comedy:  B customerID D F Movie_Title, ReleaseYear
 * Drama:   B customerID D D DirectorName, MovieTitle,
 * Classic: B customerID D C ReleaseMonth ReleaseYear LeadActor
 *
 *This class will search for duplicates of any movie if available when it
 *detects low inventory and give out the alternate movie as needed.
 *This class will add the movie to the customer inventory as well as the
 *customer history along with a checked out message.
 **/

#ifndef BORROW_H_
#define BORROW_H_

#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include "Transaction.h"

class Borrow : public Transaction {
   public:
    Borrow();
    virtual ~Borrow();
    virtual void doTransaction(map<char, vector<Movie*>>*, HashTable*, string);
};

#endif /* !BORROW_H_ */
