/**
 *#############################################################################
 *  #---------------------------- Header
 *---------------------------------------# # A Binary Search Tree object that
 *holds strings stored in NodeData			# # Objects.
 *# # @author 	Joshua Landron
 *# # @date 	16Apr2019
 *# # @version	22Apr2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#
 *  #############################################################################
 **/
#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
using namespace std;

/**
 * Binary Search Tree (BST): Data structure defined by a node having no more
 * 2 children, with the left child always being less than it, and the right
 * child always being greater than. The definition of less than and greater than
 * is up to the object type inserted. This BinTree is defined specifically to
 * handle NodeData Objects.
 *
 * Implementation and assumptions:
 * -NodeData Object inserted will not be deleted by the user. The BinTree will
 * handle deletion of newly inserted objects while maintaining its own copies.
 * -NodeData should define what less than and greater than mean using < and >.
 * -------------------------------------------------------------------------------
 **/
#include "nodedata.h"

using namespace std;

class BinTree {
    friend ostream& operator<<(ostream&, const BinTree&);

   public:
    BinTree();                // constructor
    BinTree(const BinTree&);  // copy constructor
    ~BinTree();               // destructor, calls makeEmpty

    bool isEmpty() const;  // true if tree is empty, otherwise false
    void makeEmpty();      // make the tree empty so isEmpty returns true

    BinTree& operator=(
        const BinTree&);  // sets this BinTree equal to other Bintree

    bool operator==(const BinTree&) const;
    bool operator!=(const BinTree&) const;

    int getHeight(const NodeData&);
    void bstreeToArray(NodeData* []);
    void arrayToBSTree(NodeData* []);

    bool insert(NodeData*);
    bool retrieve(const NodeData&, NodeData*&);
    void displaySideways() const;  // provided below, displays the tree sideways

   private:
    //--------------------------- Data Members
    //----------------------------------
    struct Node {
        // These are set to NULL by default for predictability
        NodeData* data;  // pointer to data object
        Node* left;      // left subtree pointer
        Node* right;     // right subtree pointer

        Node() {          // Node constructor
            data = NULL;  // sets all values to NULL by default
            left = NULL;
            right = NULL;
        }
        ~Node() {           // Node destructor
            delete (data);  // calls the NodeData destructor
        }
    };
    Node* root;  // root of the tree

    //------------------------------- utility functions
    //---------------------------
    void copyHelper(Node*);
    void sideways(Node*,
                  int) const;  // provided below, helper for displaySideways()
    Node* traverse(NodeData, Node*&);
    bool equality(Node*, Node*)
        const;  // checks for exact equality including order of contents
    void inorderPrint(Node*, ostream&);  // recursively prints the tree in order
    void inorderHelper(Node* n, NodeData* data[], int& count);
    void buildTree(int, int, NodeData* []);
    int findHeight(
        Node* item);  // determines the max distance to a descendant leaf node
    bool generalFind(Node* left, Node* right, const NodeData&, Node*&);
    void makeEmpty(Node*);
    bool safeInsert(NodeData*);
};
#endif