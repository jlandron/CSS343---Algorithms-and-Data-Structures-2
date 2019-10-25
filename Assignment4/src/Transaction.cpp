#include "Transaction.h"

using namespace std;
/**----------------------Transaction::Transaction----------------------------
 * default no arg constructor for general transaction objects.
 */
Transaction::Transaction()
    : m_Code{' '},
      m_Genre{' '},
      m_CustomerID{-1},
      m_MediaType{' '},
      m_Description{""} {}
/**----------------------Transaction::~Transaction--------------------------
 * default destructor for general transactions
 */
Transaction::~Transaction() {}
