/**
 *#############################################################################
 *#---------------------------- Header---------------------------------------
 *# HashNode class
 *# # @author 	Joshua Landron
 *# # @date     22May2019
 *# # @version  27May2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#############################################################################
 *HashNode to hold customer object and index value
 *Transaction.
 *Assumptions:
 * Used only by the HashTable implemented here.
 **/

#ifndef HASHNODE_H_
#define HASHNODE_H_
#include <string>
#include "Customer.h"

using namespace std;

class HashNode {
   private:
    Customer* m_Value;
    int m_Key;

   public:
    HashNode();
    ~HashNode();
    HashNode(int key, Customer* value);

    int getKey();

    Customer* getValue();
};

#endif /* !HASHNODE_H_ */
