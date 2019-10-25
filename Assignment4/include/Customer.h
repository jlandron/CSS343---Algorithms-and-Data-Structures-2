/**
 *#############################################################################
 *#---------------------------- Header---------------------------------------
 *# Customer class
 *# # @author 	Joshua Landron
 *# # @date     22May2019
 *# # @version  27May2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#############################################################################
 *Transaction.
 *Assumptions:
 * Customers should only have first and last names, and have a unique ID number.
 * The customer input should be formatted as such:
 * customerID LastName firstName
 **/

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Customer {
   public:
    Customer();
    ~Customer();
    Customer(string data);
    string getFirstName() const;
    string getLastName() const;
    int getID() const;
    void setData(string data);
    string toString() const;
    bool removeFromInventory(string desc);
    void addToInventory(string desc);
    void displayInventory() const;
    void desplayHistory() const;

   private:
    string m_FirstName;
    string m_LastName;
    int m_IDNumber;
    // list of currently checked out movies
    vector<string> m_CheckedOut;
    // list of all previous movie activity for this customer
    vector<string> m_History;
};

#endif /* !CUSTOMER_H_ */
