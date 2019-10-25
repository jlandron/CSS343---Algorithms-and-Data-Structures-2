/**
 *#############################################################################
 *#---------------------------- Header---------------------------------------
 *# Classic class extending Movie class
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
 * C, inventory, director, title, leadActor releaseMonth releaseYear
 *
 **/

#ifndef CLASSIC_H_
#define CLASSIC_H_

#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
#include "Movie.h"

using namespace std;

class Classic : virtual public Movie {
   public:
    Classic();
    virtual ~Classic();

    virtual void setData(string ClassicData);
    virtual void display() const;
    virtual string getDescription() const;
    virtual bool operator==(const Movie&) const;
    virtual bool operator!=(const Movie&) const;
    virtual bool operator<(const Movie&) const;
    virtual bool operator>(const Movie&) const;
    virtual bool operator<=(const Movie&) const;
    virtual bool operator>=(const Movie&) const;
};

#endif /* !CLASSIC_H_ */
