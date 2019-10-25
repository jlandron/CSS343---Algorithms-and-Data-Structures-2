#include "Return.h"

using namespace std;
/**--------------------------------Return::Return--------------------------
 * default no arg constructor
 */
Return::Return() : Transaction() {}
/**--------------------------------Return::~Return--------------------------
 * destrctor to make sure all fields are deleted
 */
Return::~Return() {}
/**----------------------------------doTransaction--------------------------
 *
 * @param  map<char, vector<Movie *>> *movies : map containing all of the vector
 *                                              of movies.
 * @param  HashTable *customers               : HashTable containing all of the
 *                                              current customers
 * @param  string line                        : the string containing all of the
 *                                              transaction command
 */
void Return::doTransaction(map<char, vector<Movie *>> *movies,
                           HashTable *customers, string line) {
    // put the transaction description in a stringstream to take it apart
    stringstream ss(line);
    // remove the transaction code
    ss >> m_Code;
    // remove the customer ID
    ss >> m_CustomerID;
    // remove the media type
    ss >> m_MediaType;
    // check the media type
    if (m_MediaType != 'D') {
        cerr << "Transaction not completed due to bad media type code: "
             << m_MediaType << endl;
        return;
    }
    // put the rest of the transaction type in a string
    getline(ss, m_Description);
    // eliminate leading spaces
    m_Description = regex_replace(m_Description, regex("^ +"), "");
    // eliminate control characters if they exist
    m_Description = regex_replace(m_Description, regex("\r\n|\r|\n"), "");

    m_Genre = m_Description[0];
    if (m_Genre == 'F' || m_Genre == 'D' || m_Genre == 'C') {
        Customer *curr = customers->get(m_CustomerID);
        // finding the movie in the vector
        Movie *found = NULL;
        // check if genre vector is empty
        if (movies->at(m_Genre).empty()) {
            cerr << "Transaction not completed due to no movies of Genre: "
                 << m_Genre << endl;
            return;
        }
        for (int i = 0; i < movies->at(m_Genre).size(); i++) {
            if (movies->at(m_Genre).at(i)->getDescription() == m_Description) {
                found = movies->at(m_Genre).at(i);
            }
        }
        if (found != NULL && curr != NULL) {
            // attempt to return the movie in command
            if (curr->removeFromInventory(m_Description)) {
                found->m_Inventory++;
            }  // if remove fails, check if there are equivelent movies in the
               // inventory, and if the customer has one of the equivelent
               // movies, if found, return the equivelent.
            else {
                for (int i = 0; i < movies->at(m_Genre).size(); i++) {
                    if ((*movies->at(m_Genre).at(i) == *found) &&
                        (movies->at(m_Genre).at(i)->getDescription() !=
                         m_Description)) {
                        found = movies->at(m_Genre).at(i);
                        if (curr->removeFromInventory(
                                found->getDescription())) {
                            found->m_Inventory++;
                            return;
                        }
                    }
                }
                cerr << "Transaction not completed due to Customer "
                     << m_CustomerID << " not having Movie: " << m_Description
                     << endl;
            }
        } else if (found == NULL) {
            cerr << "Transaction not completed due to bad Movie request: "
                 << m_Description << endl;
        } else {
            cerr << "Transaction not completed due to bad Customer ID: "
                 << m_Description << endl;
        }
    } else {
        cerr << "Transaction not completed due to bad Genre code: " << m_Genre
             << endl;
    }
}