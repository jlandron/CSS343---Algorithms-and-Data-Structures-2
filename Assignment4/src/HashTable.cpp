#include "HashTable.h"

using namespace std;
/**-------------------------------HashTable::HashTable------------------------------
 * default no arg constructor
 */
HashTable::HashTable() {
    // initialize capacity and size
    m_Size = 0;
    // initialize array of size capacity, set all values to NULL
    arr = new HashNode*[MAX_CAPACITY];
    for (int i = 0; i < MAX_CAPACITY; i++) {
        arr[i] = NULL;
    }
}
/**---------------------------------HashTable::~HashTable---------------------------
 * destructor that deletes all customer objects in the HashTable, then frees the
 * space reserved by the array
 */
HashTable::~HashTable() {
    for (int i = 0; i < MAX_CAPACITY; i++) {
        if (arr[i] != NULL) {
            delete arr[i];
        }
    }
    delete[] arr;
}
/**----------------------------------------hashCode---------------------------------
 * method to calculate he hash of the key passed in
 *
 * @param  {int} key : number to be hashed
 * @return {int}     : the hash value representing index
 */
int HashTable::hashCode(int key) {
    // get code that works with the capacity of this table
    return (key % MAX_CAPACITY);
}
/**---------------------------------------insertNode---------------------------------
 *attempts to insert the node at the calculated hashIndex, if that index is
 *taken it will look for the next available location to insert the node.
 *
 * @param  {int} key         : key for hashTable
 * @param  {Customer*} value : Value that key represents
 */
void HashTable::insertNode(int key, Customer* value) {
    // make new Node
    HashNode* temp = new HashNode(key, value);
    // get initil index
    int hashIndex = hashCode(key);

    while (arr[hashIndex] != NULL && arr[hashIndex]->getKey() != key) {
        hashIndex++;
        hashIndex %= MAX_CAPACITY;
    }
    // check if size needs to be incremented, and insert node
    if (arr[hashIndex] == NULL) {
        m_Size++;
    } else {
        // replacing node, clean up old node
        delete arr[hashIndex];
    }

    arr[hashIndex] = temp;
}
/**------------------------------------get--------------------------------------
 * returns a pointer to the customer object in the HashTable if it exists
 *
 * @param  {int} key    : key to be searched for
 * @return {Customer*}  : customer pointer. changes reflect the customer in the
 * HashTable
 */
Customer* HashTable::get(int key) {
    // get the hashIndex
    int hashIndex = hashCode(key);
    int counter = 0;
    // search for value using key's hashCode
    while (arr[hashIndex] != NULL) {
        // worst case scenario, not found, looked at whole array
        if (counter++ > MAX_CAPACITY) {
            return NULL;
        }
        if (arr[hashIndex]->getKey() == key) {
            return (arr[hashIndex]->getValue());
        }
        hashIndex++;
        hashIndex %= MAX_CAPACITY;
    }
}
/**-----------------------------------hasKey---------------------------------
 * checks if the key provided is in the hash table
 *
 * @param  {int} key : key to search for
 * @return {bool}    : representing if the key is in the hashTable
 */
bool HashTable::hasKey(int key) {
    // get the hashIndex
    int hashIndex = hashCode(key);
    int counter = 0;
    // search for value using key's hashCode
    while (arr[hashIndex] != NULL) {
        // worst case scenario, not found, looked at whole array
        if (counter++ > MAX_CAPACITY) {
            return false;
        }
        if (arr[hashIndex]->getKey() == key) {
            return true;
        }
        hashIndex++;
        hashIndex %= MAX_CAPACITY;
    }
}
/**--------------------------------getSize------------------------------------
 * checks the size of the HashTable, i.e. the number of object in the table.
 *
 * @return {int}  : number fo objects in table
 */
int HashTable::getSize() const { return m_Size; }
/**--------------------------------isEmpty------------------------------------
 * checks if the HashTable is empty
 *
 * @return {bool}      : represents wether of not the HashTable is empty.
 */
bool HashTable::isEmpty() const { return (m_Size == 0); }
/**------------------------------------display---------------------------------
 * displays yhe contents of the hashTable to std out
 */
void HashTable::display() const {
    for (int i = 0; i < MAX_CAPACITY; i++) {
        if (arr[i] != NULL) {
            cout << "key = " << arr[i]->getKey()
                 << " Value = " << arr[i]->getValue()->toString() << endl;
        }
    }
}
