#include "Comedy.h"

using namespace std;
/**-----------------------------Comedy::Comedy----------------------------------
 * Default no args constructor.
 */
Comedy::Comedy() : Movie() {}
/**-----------------------------Comedy::~Comedy--------------------------------
 * Destructor to ensure strings are deleted correctly
 */
Comedy::~Comedy() {}
/**---------------------------------display-----------------------------------
 * displays all data for tis movie object
 */
void Comedy::display() const {
    cout << m_Genre << ", " << m_Inventory << ", " << m_Director << ", "
         << m_Title << ", " << m_ReleaseYear << endl;
}
/**---------------------------------setData----------------------------------
 * sets all of the values for this movie object
 *
 * @param  {string} data : complete input string to make a Comedy movie
 */
void Comedy::setData(string data) {
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
        (string(1, m_Genre) + " " + m_Title + ", " + to_string(m_ReleaseYear));
}
/**-----------------------------getDescription-------------------------------
 * returns the formatted description of this movie
 *
 * @return {string}  : returns m_Description for this movie object
 */
string Comedy::getDescription() const { return m_Description; }
/**-------------------------------operator==---------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for equality
 * @return {bool}        : returns true if the movies are the same internally
 */
bool Comedy::operator==(const Movie &other) const {
    if (m_Title == other.m_Title && m_ReleaseYear == other.m_ReleaseYear) {
        return true;
    }
    return false;
}
/**--------------------------------operator!=-------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for inequality
 * @return {bool}        : returns true if the movies are different internally
 */
bool Comedy::operator!=(const Movie &other) const { return !(*this == other); }
/**--------------------------------operator<--------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for ordering
 * @return {bool}        : returns true if the movie other is larger by
 * definition
 */
bool Comedy::operator<(const Movie &other) const {
    // compare titles first
    if (m_Title < other.m_Title) {
        return true;
    } else if (m_Title == other.m_Title &&
               m_ReleaseYear < other.m_ReleaseYear) {
        return true;
    }
    return false;
}
/**---------------------------------operator>------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for ordering
 * @return {bool}        : returns true if the movie other is smaller by
 * definition
 */
bool Comedy::operator>(const Movie &other) const { return !(*this < other); }
/**---------------------------------operator<=----------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for ordering
 * @return {bool}        : returns true if the movie other is larger or the same
 * by definition
 */
bool Comedy::operator<=(const Movie &other) const {
    return (*this < other || *this == other);
}
/**---------------------------------operator>=-----------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for ordering
 * @return {bool}        : returns true if the movie other is smaller or the
 * same by definition
 */
bool Comedy::operator>=(const Movie &other) const {
    return (*this > other || *this == other);
}
