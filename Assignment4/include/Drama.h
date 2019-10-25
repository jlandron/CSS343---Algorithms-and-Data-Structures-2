/**
 *#############################################################################
 *#---------------------------- Header---------------------------------------
 *# Drama class extending Movie class
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
 * D, inventory, director, title, releaseYear
 *
 **/

#ifndef DRAMA_H_
#define DRAMA_H_

#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include "Movie.h"

using namespace std;

class Drama : virtual public Movie {
   public:
    Drama();
    virtual ~Drama();

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

#endif /* !DRAMA_H_ */
