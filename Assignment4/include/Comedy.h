/**
 *#############################################################################
 *#---------------------------- Header---------------------------------------
 *# Comedy class extending Movie class
 *# # @author 	Joshua Landron
 *# # @date     22May2019
 *# # @version  25May2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#############################################################################
 *Implements setData, display, getDescription, and comparison operators as
 *required by the base class Movie.
 *Assumptions:
 * The string passed to setData should be formatted correctly as such:
 *
 * F, inventory, director, title, releaseYear
 *
 **/

#ifndef COMEDY_H_
#define COMEDY_H_

#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include "Movie.h"

using namespace std;

class Comedy : virtual public Movie {
   public:
    Comedy();
    virtual ~Comedy();

    virtual void setData(string data);
    virtual void display() const;
    virtual string getDescription() const;
    virtual bool operator==(const Movie&) const;
    virtual bool operator!=(const Movie&) const;
    virtual bool operator<(const Movie&) const;
    virtual bool operator>(const Movie&) const;
    virtual bool operator<=(const Movie&) const;
    virtual bool operator>=(const Movie&) const;
};

#endif /* !COMEDY_H_ */
