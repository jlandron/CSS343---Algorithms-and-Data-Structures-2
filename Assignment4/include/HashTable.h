/**
 *#############################################################################
 *#---------------------------- Header---------------------------------------
 *# Inventory class extending Transaction class
 *# # @author 	Joshua Landron
 *# # @date     22May2019
 *# # @version  27May2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#############################################################################
 *Implements a simple HashTable the holds customerID as key, and Customer* as
 *values.
 * Assumptions: Uses Linear hashing algorithm, so some
 *grouping may occur. The max Size of the HashTable can be changed by editing
 *the constant value MAX_CAPACITY.
 **/
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <string>
#include <vector>
#include "HashNode.h"

using namespace std;

class HashTable {
   private:
    const int MAX_CAPACITY = 101;
    int hashCode(int);
    // array of HashNodes
    HashNode** arr;

    int m_Size;

   public:
    HashTable();
    ~HashTable();
    HashTable(int);
    void insertNode(int, Customer*);
    Customer* get(int key);
    bool hasKey(int key);
    int getSize() const;
    bool isEmpty() const;
    void display() const;
};

#endif /* !HASHLIST_H_ */
