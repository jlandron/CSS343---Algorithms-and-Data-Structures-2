#include "TransactionFactory.h"
#include <sstream>
/**-------------------TransactionFactory::TransactionFactory------------------

 * default no arg constructor
 */
TransactionFactory::TransactionFactory() {}
/**-------------------TransactionFactory::~TransactionFactory------------------
 * TransactionFactory::~TransactionFactory
 * destructor to ensure all fields are deleted properly.
 */
TransactionFactory::~TransactionFactory() {}
/**--------------------------------makeTransaction----------------------------
 * makeTransaction
 *builds a new Transaction object on the heap and returns the pointer. returns
 *NULL if the Genre code is incorrect
 *
 * @param  {string} transDescription : Complete description of the transaction
 *                                     to be completed
 */
Transaction *TransactionFactory::makeTransaction(string transDescription) {
    // save the first char, and enter the switch statement
    char transactionCode = transDescription[0];
    Transaction *transaction;
    // checks transaction code and creates correct transaction child type
    switch (transactionCode) {
        case 'I': {
            transaction = new Inventory();
            break;
        }
        case 'H': {
            transaction = new History();
            break;
        }
        case 'B': {
            transaction = new Borrow();
            break;
        }
        case 'R': {
            transaction = new Return();
            break;
        }
        default: {
            cerr << "Error: Transaction type " << transactionCode
                 << " not found" << endl;
            return NULL;
        }
    }
    return transaction;
}