#include "Drama.h"

using namespace std;
/**--------------------------Drama::Drama---------------------------------
 * Default no args constructor.
 */
Drama::Drama() : Movie() {}
/**--------------------------Drama::~Drama--------------------------------
 * Destructor to ensure strings are deleted correctly
 */
Drama::~Drama() {}
/**-----------------------------display-----------------------------------
 * displays all data for this movie object
 */
void Drama::display() const {
    cout << m_Genre << ", " << m_Inventory << ", " << m_Director << ", "
         << m_Title << ", " << m_ReleaseYear << endl;
}
/**--------------------------getDescription-------------------------------
 * returns the formatted description of this movie
 *
 * @return {string}  : returns m_Description for this movie object
 */
string Drama::getDescription() const { return m_Description; }
/**------------------------------setData---------------------------------
 * sets all of the values for this movie object
 *
 * @param  {string} data : complete input string to make a Drama movie
 */
void Drama::setData(string data) {
    stringstream ss(data);
    string tmp;
    m_Genre = data[0];
    ss >> tmp;  // eliminate char,
    getline(ss, tmp, ',');
    m_Inventory = stoi(tmp);
    getline(ss, m_Director, ',');
    m_Director = regex_replace(m_Director, regex("^ +"), "");
    getline(ss, m_Title, ',');
    m_Title = regex_replace(m_Title, regex("^ +"), "");
    ss >> m_ReleaseYear;
    m_Description =
        (string(1, m_Genre) + " " + m_Director + ", " + m_Title + ",");
}
/**---------------------------operator==-------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for equality
 * @return {bool}        : returns true if the movies are the same internally
 */
bool Drama::operator==(const Movie &other) const {
    if (m_Director == other.m_Director && m_Title == other.m_Title) {
        return true;
    }
    return false;
}
/**---------------------------operator!=-------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for inequality
 * @return {bool}        : returns true if the movies are different internally
 */
bool Drama::operator!=(const Movie &other) const { return !(*this == other); }
/**---------------------------operator<--------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for ordering
 * @return {bool}        : returns true if the movie other is larger by
 * definition
 */
bool Drama::operator<(const Movie &other) const {
    if (m_Director < other.m_Director) {
        return true;
    } else if (m_Director == other.m_Director && m_Title < other.m_Title) {
        return true;
    }
    return false;
}
/**----------------------------operator>-------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for ordering
 * @return {bool}        : returns true if the movie other is smaller by
 * definition
 */
bool Drama::operator>(const Movie &other) const { return !(*this < other); }
/**----------------------------operator<=------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for ordering
 * @return {bool}        : returns true if the movie other is larger or the same
 * by definition
 */
bool Drama::operator<=(const Movie &other) const {
    return (*this < other || *this == other);
}
/**----------------------------operator>=-------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for ordering
 * @return {bool}        : returns true if the movie other is smaller or the
 * same by definition
 */
bool Drama::operator>=(const Movie &other) const {
    return (*this > other || *this == other);
}
