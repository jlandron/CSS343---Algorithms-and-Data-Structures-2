#include "Customer.h"

using namespace std;
/**---------------------------Customer::Customer-------------------------------
 * Default no args constructor.
 */
Customer::Customer() : m_FirstName{""}, m_LastName{""}, m_IDNumber{-1} {}
/**---------------------------Customer::~Customer------------------------------
 * Destructor to ensure strings are deleted correctly
 */
Customer::~Customer() {}
/** --------------------------------Customer-----------------------------------
 * overload constructor that calls setData method to initialize the fields
 *
 * @param {string} data  : string holding the data for this customer object
 */
Customer::Customer(string data) { setData(data); }
/**------------------------------getFirstName---------------------------------
 * returns a copy of this customers first name
 *
 * @return {string} : first name of customer
 */
string Customer::getFirstName() const { return m_FirstName; }
/**-------------------------------getLastName---------------------------------
 * return a copy of this customers last name
 *
 * @return {string}  : last name of customer
 */
string Customer::getLastName() const { return m_LastName; }
/**---------------------------------getID------------------------------------
 * returns the ID of this customer
 *
 * @return {int}  : this customers ID number
 */
int Customer::getID() const { return m_IDNumber; }
/**--------------------------------setData----------------------------------
 * sets the data for this objects fields
 *
 * @param  {string} data : string holding all the customer data in order:
 *                         IDnumber lastName firstName
 */
void Customer::setData(string data) {
    stringstream ss(data);
    ss >> m_IDNumber;
    ss >> m_LastName;
    ss >> m_FirstName;
}
/**-------------------------------toString----------------------------------
 * returns the full name of this customer
 *
 * @return {string}  : the full name of this customer
 */
string Customer::toString() const { return (m_FirstName + " " + m_LastName); }
/**--------------------------removeFromInventory----------------------------
 * checks if the movie is in the inventory of this customer, if it is, remove it
 * from inventory and add a note about the movie being returned, add it to
 * history and return true.
 *
 * @param  {string} desc : formatted description of the movie object to be
 *                         removed from inventory
 * @return {bool}        : returns true if the movie is in this customers
 *                         inventory
 */
bool Customer::removeFromInventory(string desc) {
    // iterate through inventory and remove appropriate item
    for (int i = 0; i < m_CheckedOut.size(); i++) {
        if (m_CheckedOut.at(i) == desc) {
            string res = string("Returned: " + desc);
            m_History.push_back(res);
            m_CheckedOut.erase(m_CheckedOut.begin() + i);
            return true;
        }
    }
    return false;
}
/**------------------------------addToInventory-----------------------------
 * adds the movie to the inventory of this customer as well as adding a note
 * about the movie being checked out to history.
 *
 * @param  {string} desc : formatted description of the movie object to be
 *                         added to the inventory
 */
void Customer::addToInventory(string desc) {
    string res = string("Checked out: " + desc);
    // add desc and res to inventory and history
    m_CheckedOut.push_back(desc);
    m_History.push_back(res);
}
/**-----------------------------displayInventory---------------------------
 * prints the current inventory of this customer object to cout
 */
void Customer::displayInventory() const {
    cout << "\n-------Inventory for customer: " << m_IDNumber << " "
         << toString() << "--------" << endl;
    // iterate through inventory and print each string
    for (int i = m_CheckedOut.size() - 1; i >= 0; i--) {
        cout << m_CheckedOut.at(i) << endl;
    }
    cout << "-------------------End of Inventory------------------\n" << endl;
}
/**-------------------------------desplayHistory---------------------------
 * prints the history of this customer object.
 */
void Customer::desplayHistory() const {
    cout << "\n-----------History for customer: " << m_IDNumber << " "
         << toString() << "--------" << endl;
    // iterate through history and print each string
    for (int i = 0; i < m_History.size(); i++) {
        cout << m_History.at(i) << endl;
    }
    cout << "---------------------End of History-------------------\n" << endl;
}