#include "Classic.h"

using namespace std;
/**-------------------------------Classic::Classic-------------------------------
 * Default no args constructor.
 */
Classic::Classic() : Movie() {}
/**------------------------------Classic::~Classic-------------------------------
 * Destructor to ensure strings are deleted correctly
 */
Classic::~Classic() {}
/**-----------------------------------display-----------------------------------
 * displays all data for tis movie object
 */
void Classic::display() const {
    cout << m_Genre << ", " << m_Inventory << ", " << m_Director << ", "
         << m_Title << ", " << m_LeadActor << ", " << m_ReleaseMonth << ", "
         << m_ReleaseYear << endl;
}
/**-----------------------------------setData-----------------------------------
 * sets all of the values for this movie object
 *
 * @param  {string} data : complete input string to make a Classic movie
 */
void Classic::setData(string data) {
    stringstream ss(data);
    string tmp;
    m_Genre = data[0];
    ss >> tmp;
    getline(ss, tmp, ',');
    m_Inventory = stoi(tmp);
    getline(ss, m_Director, ',');
    m_Director = regex_replace(m_Director, regex("^ +"), "");
    getline(ss, m_Title, ',');
    m_Title = regex_replace(m_Title, regex("^ +"), "");
    ss >> tmp;
    m_LeadActor = tmp;
    ss >> tmp;
    m_LeadActor += (" " + tmp);
    ss >> m_ReleaseMonth;
    ss >> m_ReleaseYear;
    m_Description =
        string(string(1, m_Genre) + " " + to_string(m_ReleaseMonth) + " " +
               to_string(m_ReleaseYear) + " " + m_LeadActor);
}
/**--------------------------------getDescription------------------------------
 * returns the formatted description of this movie
 *
 * @return {string}  : returns m_Description for this movie object
 */
string Classic::getDescription() const { return (m_Description); }
/**
 * operator==
 *
 * @param  {Movie} other : other movie object to be to be checked for equality
 * @return {bool}        : returns true if the movies are the same internally
 */
bool Classic::operator==(const Movie &other) const {
    if (m_ReleaseYear == other.m_ReleaseYear &&
        m_ReleaseMonth == other.m_ReleaseMonth && m_Title == other.m_Title &&
        m_Director == other.m_Director) {
        return true;
    }
    return false;
}
/**---------------------------------operator!=--------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for inequality
 * @return {bool}        : returns true if the movies are different internally
 */
bool Classic::operator!=(const Movie &other) const { return !(*this == other); }
/**---------------------------------operator<--------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for ordering
 * @return {bool}        : returns true if the movie other is larger by
 * definition
 */
bool Classic::operator<(const Movie &other) const {
    if (m_ReleaseYear < other.m_ReleaseYear) {
        return true;
    } else if (m_ReleaseYear == other.m_ReleaseYear &&
               m_ReleaseMonth < other.m_ReleaseMonth) {
        return true;
    } else if (m_ReleaseYear == other.m_ReleaseYear &&
               m_ReleaseMonth == other.m_ReleaseMonth &&
               m_LeadActor < other.m_LeadActor) {
        return true;
    }
    return false;
}
/**---------------------------------operator>--------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for ordering
 * @return {bool}        : returns true if the movie other is smaller by
 * definition
 */
bool Classic::operator>(const Movie &other) const { return !(*this < other); }
/**---------------------------------operator<=-------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for ordering
 * @return {bool}        : returns true if the movie other is larger or the same
 * by definition
 */
bool Classic::operator<=(const Movie &other) const {
    return (*this < other || *this == other);
}
/**---------------------------------operator>=-------------------------------
 *
 * @param  {Movie} other : other movie object to be to be checked for ordering
 * @return {bool}        : returns true if the movie other is smaller or the
 * same by definition
 */
bool Classic::operator>=(const Movie &other) const {
    return (*this > other || *this == other);
}
