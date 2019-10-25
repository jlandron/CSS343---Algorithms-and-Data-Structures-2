#include "History.h"

using namespace std;
/**-----------------------------------Borrow::Borrow--------------------------------
 * default no arg constructor
 */
History::History() : Transaction() {}
/**-----------------------------------Borrow::~Borrow------------------------------
 * destrctor to make sure all fields are deleted
 */
History::~History() {}
/**------------------------------------doTransaction-------------------------------
 *
 * @param  map<char, vector<Movie *>> *movies : map containing all of the vector
 *                                              of movies.
 * @param  HashTable *customers               : HashTable containing all of the
 *                                              current customers
 * @param  string line                        : the string containing all of the
 *                                              transaction command
 */
void History::doTransaction(map<char, vector<Movie *>> *movies,
                            HashTable *customers, string line) {
    // put the transaction description in a stringstream to take it apart
    stringstream ss(line);
    // remove the transaction code
    ss >> m_Code;
    // remove the customer ID
    ss >> m_CustomerID;
    // check customer ID and call displayHistory for that customer or throw
    // error message
    if (customers->hasKey(m_CustomerID)) {
        customers->get(m_CustomerID)->desplayHistory();
    } else {
        cerr << "No Customer with ID: " << m_CustomerID << endl;
    }
}