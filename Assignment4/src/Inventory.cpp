#include "Inventory.h"

using namespace std;
/**------------------------------------Inventory::Inventory-----------------------------
 * default no arg constructor
 */
Inventory::Inventory() : Transaction() {}
/**------------------------------------Inventory::~Inventory---------------------------
 * destrctor to make sure all fields are deleted
 */
Inventory::~Inventory() {}
/**----------------------------------------doTransaction-------------------------------
 * completes the inventory transaction for the movie store, displaying all
 * movies in order
 *
 * @param  map<char, vector<Movie *>> *movies : map containing all of the vector
 *                                              of movies.
 * @param  HashTable *customers               : HashTable containing all of the
 *                                              current customers
 * @param  string line                        : the string containing all of the
 *                                              transaction command
 */
void Inventory::doTransaction(map<char, vector<Movie *>> *movies,
                              HashTable *customers, string line) {
    cout << "\n-----------------------Inventory--------------------------"
         << endl;
    // prints comedies first
    cout << "----Printing all Movies in Genre: Comedy----" << endl;
    for (int i = 0; i < movies->at('F').size(); i++) {
        movies->at('F').at(i)->display();
    }
    // prints Dramas next
    cout << "----Printing all Movies in Genre: Drama----" << endl;
    for (int i = 0; i < movies->at('D').size(); i++) {
        movies->at('D').at(i)->display();
    }
    // prints Classics last
    cout << "----Printing all Movies in Genre: Classic----" << endl;
    for (int i = 0; i < movies->at('C').size(); i++) {
        movies->at('C').at(i)->display();
    }
    cout << "--------------------End of Inventory--------------------------\n"
         << endl;
}
