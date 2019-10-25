/**
 *#############################################################################
 *#---------------------------- Header---------------------------------------
 *# Abstract Movie class
 *# # @author 	Joshua Landron
 *# # @date     22May2019
 *# # @version  25May2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#############################################################################
 *Implements methods that will never be different for different types of movies.
 *Transaction.
 *Assumptions:
 * all members are public to allow inheritance of all properties of a movie.
 * This base class contains all possible data members for different movie types
 * even if a type of movie does not use it.
 **/

#ifndef MOVIE_H_
#define MOVIE_H_

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Movie {
   public:
    Movie();
    bool borrowMovie();
    void returnMovie();
    int getInventory();
    // methods to be implemented in child classes
    virtual ~Movie();

    virtual void setData(string) = 0;
    virtual void display() const = 0;
    virtual string getDescription() const = 0;

    virtual bool operator==(const Movie&) const = 0;
    virtual bool operator!=(const Movie&) const = 0;
    virtual bool operator<(const Movie&) const = 0;
    virtual bool operator>(const Movie&) const = 0;
    virtual bool operator<=(const Movie&) const = 0;
    virtual bool operator>=(const Movie&) const = 0;

    char m_Genre;
    int m_Inventory;
    string m_Director;
    string m_Title;
    int m_ReleaseYear;
    // added two extra data members for classic Classics
    string m_LeadActor;
    int m_ReleaseMonth;
    string m_Description;
};

#endif /* !MOVIE_H_ */
