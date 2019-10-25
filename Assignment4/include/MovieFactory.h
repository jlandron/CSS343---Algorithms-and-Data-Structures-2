/**
 *#############################################################################
 *#---------------------------- Header---------------------------------------
 *# MovieFactory class for use in MovieStore
 *# # @author 	Joshua Landron
 *# # @date     22May2019
 *# # @version  25May2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#############################################################################
 * Implements a single function buildMovie that creates the correct type of
 *movie object in the Heap and returns a pointer to it or NULL
 * Assumptions:
 * Movie additions should be formatted correctly, though they may have incorrect
 * genre or media type which will be checked.
 **/
#ifndef MOVIEFACTORY_H_
#define MOVIEFACTORY_H_

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
#include "Movie.h"

using namespace std;

class MovieFactory {
   public:
    MovieFactory();
    ~MovieFactory();
    Movie* buildMovie(string movieDescription);
};

#endif /* !MOVIEFACTORY_H_ */
