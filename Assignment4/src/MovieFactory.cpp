#include "MovieFactory.h"

using namespace std;
/**--------------------------------MovieFactory::MovieFactory--------------------------
 * default no arg constructor
 */
MovieFactory::MovieFactory() {}
/**--------------------------------MovieFactory::~MovieFactory-------------------------
 *destructor to ensure all fields are deleted properly.
 */
MovieFactory::~MovieFactory() {}
/**----------------------------------------buildMovie----------------------------------
 *builds a new movie object on the heap and returns the pointer. returns NULL if
 *the Genre code is incorrect
 *
 * @param  {string} movieDescription : Complete description of the movie to be
 *                                      built
 * @return {Movie*}                  : pointer to movie on created on the heap
 *                                      to be put in a data structure.
 */
Movie* MovieFactory::buildMovie(string movieDescription) {
    // save the first char, and enter the switch statement
    char genre = movieDescription[0];
    Movie* moviePtr;
    // checks the genre and creates the correct child object for Movie
    switch (genre) {
        case 'F': {
            moviePtr = new Comedy();
            moviePtr->setData(movieDescription);
            return moviePtr;
        }
        case 'D': {
            moviePtr = new Drama();
            moviePtr->setData(movieDescription);
            return moviePtr;
        }
        case 'C': {
            moviePtr = new Classic();
            moviePtr->setData(movieDescription);
            return moviePtr;
        }
        default: {
            cerr << "Error: Movie Genre " << genre << " not found" << endl;
            moviePtr = NULL;
            return moviePtr;
        }
    }
}