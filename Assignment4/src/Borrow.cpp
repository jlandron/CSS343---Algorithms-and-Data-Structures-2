#include "Borrow.h"
/**-------------------------------Borrow::Borrow--------------------------------
 * default no arg constructor
 */
Borrow::Borrow() : Transaction() {}
/**-------------------------------Borrow::~Borrow-------------------------------
 * destrctor to make sure all fields are deleted
 */
Borrow::~Borrow() {}
/**--------------------------------doTransaction-------------------------------
 * compete the transaction that this object represents
 * @param  map<char, vector<Movie *>> *movies : map containing all of the vector
 *                                              of movies.
 * @param  HashTable *customers               : HashTable containing all of the
 *                                              current customers
 * @param  string line                        : the string containing all of the
 *                                              transaction command
 */
void Borrow::doTransaction(map<char, vector<Movie *>> *movies,
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
        // movie either found or not, complete transaction or print error codes
        if (found != NULL && curr != NULL) {
            if (found->getInventory() > 0) {
                curr->addToInventory(m_Description);
                found->m_Inventory--;
            }
            // search for duplicate movies that have inventory, and give the
            // customer one of those
            else {
                for (int i = 0; i < movies->at(m_Genre).size(); i++) {
                    if ((*movies->at(m_Genre).at(i) == *found) &&
                        (movies->at(m_Genre).at(i)->getInventory() > 0)) {
                        found = movies->at(m_Genre).at(i);
                        curr->addToInventory(found->getDescription());
                        found->m_Inventory--;
                        return;
                    }
                }
                cerr << "Transaction not completed due to low inventory for "
                        "Movie: "
                     << m_Description << endl;
            }
        } else if (found == NULL) {
            cerr << "Transaction not completed due to bad Movie request: "
                 << m_Description << endl;
        } else {
            cerr << "Transaction not completed due to bad Customer ID: "
                 << m_CustomerID << endl;
        }
    } else {
        cerr << "Transaction not completed due to bad Genre code: " << m_Genre
             << endl;
    }
}
