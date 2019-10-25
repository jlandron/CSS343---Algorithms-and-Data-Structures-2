#include "Movie.h"

using namespace std;
/**-----------------------------Movie::Movie---------------------------------
 * default no arg constructor
 */
Movie::Movie()
    : m_Director{""},
      m_Genre{' '},
      m_Inventory{0},
      m_ReleaseYear{0},
      m_Title{""},
      m_LeadActor{""},
      m_ReleaseMonth{0},
      m_Description{""} {}
/**----------------------------Movie::~Movie---------------------------------
 * standard destructor to make sure fields are deleted
 */
Movie::~Movie() {}
/**----------------------------borrowMovie----------------------------------
 *  method that checks if this movie object has any available copies, if it
 * does, removes one form inventory
 *
 * @return {bool}  : represents if the movie was able to be returned
 */
bool Movie::borrowMovie() {
    if (m_Inventory > 0) {
        m_Inventory--;
        return true;
    }
    return false;
}
/**-----------------------------returnMovie----------------------------------
 * adds one item to this objects inventory
 */
void Movie::returnMovie() { m_Inventory++; }
/**----------------------------getInventory----------------------------------
 * returns an int representing how many copies this movie object has available
 * @return {int}  : copies of movie available.
 */
int Movie::getInventory() { return m_Inventory; }