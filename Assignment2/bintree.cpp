/**
 *#############################################################################
 *  #-------------------------- Definitions
 *------------------------------------# # A Binary Search Tree object that holds
 *strings stored in NodeData			# # Objects.
 *# # @author 	Joshua Landron
 *# # @date 	16Apr2019
 *# # @version	25Apr2019
 *# #
 *# # Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *# #
 *#
 *  #############################################################################
 **/
#include "bintree.h"

using namespace std;

//###############################################################################
//#----------------------------- Public methods
//--------------------------------#
//###############################################################################
/**----------------------------- Constructor
 *------------------------------------ Default BinTree
 *
 * creates an empty BinTree object.
 **/
BinTree::BinTree() { root = NULL; }
/**-------------------------- Copy Constructor
 *---------------------------------- Overloaded BinTree
 * @param &other	A reference to the BinTree that will be copied
 *
 * Creates a deep copy of a BinTree object.
 **/
BinTree::BinTree(const BinTree &other) {
    // first check if other is NULL
    root = NULL;
    if (other.root != NULL) {
        copyHelper(other.root);
    }
}
/**------------------------------ Destructor
 *------------------------------------- BinTree Destructor
 *
 * Completely deletes all Nodes and their internal objects
 **/
BinTree::~BinTree() { makeEmpty(); }
/**------------------------------ isEmpty -------------------------------------
 * BinTree Destructor
 * @return	bool	representing if the BinTree is empty.
 *
 * checks if the root of the tree is NULL, or if there is an empty Node with
 * no data. Both situations will be treated as empty.
 **/
bool BinTree::isEmpty() const {
    if (root != NULL) {
        if (root->data == NULL) {
            return true;
        }
    }
    return (root == NULL);
}
/**------------------------------ makeEmpty
 *------------------------------------- BinTree makeEmpty
 *
 * Completely deletes all Nodes and their internal objects, resetting the Root
 * of the tree to be NULL. This is the public facing method that calls the
 *private version of itself.
 **/
void BinTree::makeEmpty() {
    makeEmpty(this->root);
    root = NULL;
}
/**------------------------------ operator =
 *------------------------------------ BinTree operator=
 * @param	&other	a constant reference to another BinTree
 * @return	&BinTree	a reference to this Bintree
 *
 * This method turns this BinTree into a deep copy of the passed BinTree.
 * As a side effect, all contents of this BinTree will be completely deleted.
 **/
BinTree &BinTree::operator=(const BinTree &other) {
    if (this != &other)  // self assignment check
    {
        // need to make this BinTree empty first.
        makeEmpty();
        if (other.root == NULL) {  // if other is empty, return this as empty
            return *this;
        }  // if not empty, create a new Node for Root just in case the tree
           // passed has a root with NULL Data
        root = new Node;
        // first check if other is NULL
        if (other.root->data == NULL) {
            root->data = NULL;
        } else {
            // if the root is not NULL, recursively make copies
            copyHelper(other.root);
        }
    }
    return *this;
}
/**------------------------------ operator ==
 *------------------------------------ BinTree operator==
 * @param	&other	a constant reference to another BinTree
 * @return	bool	representing if two Bintree's are exactly equivalent.
 *
 * This method checks if two BinTree's contain the same items's in the same
 *order.
 **/
bool BinTree::operator==(const BinTree &other) const {
    // calls recursive helper method
    return (equality(this->root, other.root));
}
/**------------------------------ operator !=
 *------------------------------------ BinTree operator!=
 * @param	&other	a constant reference to another BinTree
 * @return	bool	representing if two Bintree's are not exactly
 *equivalent.
 *
 * This method checks if two BinTree's do not contain the same items's in the
 * same order.
 **/
bool BinTree::operator!=(const BinTree &other) const {
    // calls recursive helper method
    return !(*this == other);
}
/**------------------------------ operator <<
 *------------------------------------ BinTree operator<<
 * @param	&out	a reference to the standard outstream
 * @param	&other	a constant reference to another BinTree
 * @return	out		the outstream that has been altered
 *
 * This method ads the nodes of the BinTree to the outstream that is passed.
 * The data in the BinTree will be displayed in-order.
 **/
ostream &operator<<(ostream &out, const BinTree &other) {
    BinTree temp(other);
    temp.inorderPrint(temp.root, out);

    return (out << endl);
}
/**------------------------------- getHeight
 *------------------------------------- BinTree getHeight
 * @param	&item	a constant reference to a NodeData object
 * @return	int		representing the height of a NodeData item in
 *the BinTree from the lowest point on the branches below it.
 *
 * Returns the max distance from the passed node, if it exists in the tree, to
 * the furthest leaf below it.
 **/
int BinTree::getHeight(const NodeData &item) {
    if (item == *root->data) {  // First find item
        return findHeight(root);
    }
    Node *find = NULL;
    // find while ignoring Binary property
    bool found = generalFind(root->left, root->right, item, find);
    if (find == NULL) {
        return 0;
    }
    return findHeight(find);
}
/**------------------------------ bstreeToArray
 *----------------------------------- BinTree bstreeToArray
 * @param	data[]	a pointer to an array of length 100 containing all
 *NULLs.
 *
 * Copies all NodaData objects in-order from the BinTree to the array.
 * Completely deletes all Nodes and their internal objects in the BinTree
 **/
void BinTree::bstreeToArray(NodeData *data[]) {
    int count = 0;
    inorderHelper(root, data, count);
    makeEmpty();
}
/**------------------------------ arrayToBSTree
 *------------------------------------- BinTree arrayToBSTree
 * @param	data[]	a pointer to an array of length 100 containing 100 or
 *less sorted NodeData items.
 *
 * Copies all NodaData objects in-order from the array to the BinTree.
 * Completely deletes all NodeData object in the array and creates copies for
 *the Nodes in the BinTree that contain them.
 **/
void BinTree::arrayToBSTree(NodeData *data[]) {
    buildTree(0, 99, data);          // build tree first
    for (int i = 0; i < 100; i++) {  // then clear the array
        if (data[i] != NULL) {
            delete (data[i]);
            data[i] = NULL;
        }
    }
}
/**---------------------------------- insert
 *---------------------------------------- BinTree insert
 * @param	*newData	a pointer to a NodaData object to be inserted in
 *the BinTree.
 * @return	bool		representing if the NodeData item was inserted
 *successfully.
 *
 * Attempts to insert the NodeData object in the Bintree. If the NodeData object
 *is already in the BinTree this method will return false and not insert the
 *object. This method will handle deletion of the passed NodeData object.
 **/
bool BinTree::insert(NodeData *newData) {
    NodeData *ptr = new NodeData(*newData);
    if (root == NULL) {   // if this is a new tree
        root = new Node;  // create new NodeData object for this tree
        root->data = ptr;
        delete (newData);
        return true;
    }
    if (root->data == NULL) {  // for reseting the root
        root->data = ptr;
        delete (newData);
        return true;
    }
    Node *temp = NULL;
    Node *curr = traverse(*ptr, temp);  // search for newData
    if (curr != NULL) {  // if newData already exists, return false.
        delete (ptr);
        return false;
    }
    delete (newData);  // temp now has the lowest place for new item
    curr = new Node;   // create a new Node
    curr->data = ptr;
    if (*ptr < *temp->data) {  // choose to place it left or right
        temp->left = curr;
    } else {
        temp->right = curr;
    }
    return true;
}
/**------------------------------ retrieve -------------------------------------
 * BinTree retrieve
 * @param	&nodeSearch		a reference to the NodeData object to be
 *searched for
 * @param	&foundNode		a reference to an external nodeData
 *object that will point directly to the internal object in the Bintree if it is
 *found.
 * @return	bool			representing if the NodeData was found
 *in the BinTree
 *
 * this method searches for the NodeData object and returns a bool if it was
 *found, while assigning the foundNode pointer to the object.
 **/
bool BinTree::retrieve(const NodeData &nodeSearch, NodeData *&foundNode) {
    Node *temp = NULL;                        // make temp as dummy
    Node *find = traverse(nodeSearch, temp);  // search for data using traverse
    if (find == NULL) {
        return false;
    }
    foundNode = find->data;
    return true;
}
//----------------------------- displaySideways
//---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const { sideways(root, 0); }

//###############################################################################
//#----------------------- Private Utility methods
//-----------------------------#
//###############################################################################

//-------------------------------- Sideways
//-------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node *current, int level) const {
    if (current != NULL) {
        level++;
        sideways(current->right, level);

        // indent for readability, 4 spaces per depth level
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }

        cout << *current->data << endl;  // display information of object
        sideways(current->left, level);
    }
}
/**------------------------------- makeEmpty
 *------------------------------------ BinTree makeEmpty
 * @param	*root	a pointer to the Node at the top of the BinTree
 *
 * Completely deletes all Nodes and their internal objects in the tree.
 * This method calls itself recursively deleting the Bintree from the top down.
 **/
void BinTree::makeEmpty(Node *root) {
    if (root == NULL) {  // dont try and empty a NULL tree
        return;
    }
    if (root->data != NULL) {
        if (root->left != NULL) {
            makeEmpty(root->left);
        }
        if (root->right != NULL) {
            makeEmpty(root->right);
        }
    }
    delete (root);
}
/**-------------------------------- safeInsert
 *-------------------------------------- BinTree safeInsert
 * @param	*newData	a pointer to a NodaData object to be inserted in
 *the BinTree.
 * @return	bool		representing if the NodeData item was inserted
 *successfully.
 *
 * Attempts to insert the NodeData object in the Bintree. If the NodeData object
 *is already in the BinTree this method will return false and not insert the
 *object. This method will only be called externally to allow insertion while
 *maintaining the passed NodeData objects in place.
 **/
bool BinTree::safeInsert(NodeData *newData) {
    NodeData *ptr = new NodeData(*newData);
    if (root == NULL) {   // if this is a new tree
        root = new Node;  // create new NodeData object for this tree
        root->data = ptr;
        return true;
    }
    if (root->data == NULL) {  // for reseting the root
        root->data = ptr;
        return true;
    }
    Node *temp = NULL;
    Node *curr = traverse(*ptr, temp);  // search for newData
    if (curr != NULL) {  // if newData already exists, return false.
        delete (ptr);
        return false;
    }
    curr = new Node;  // create a new Node
    curr->data = ptr;
    if (*newData < *temp->data) {  // choose to place it left or right
        temp->left = curr;
    } else {
        temp->right = curr;
    }
    return true;
}
/**------------------------------- findHeight
 *------------------------------------- BinTree findHeight
 * @param	*item	a pointer to a found NodeData object in the BinTree
 * @return	int		representing the height of a NodeData item in
 *the BinTree from the lowest point on the branches below it.
 *
 * Returns the max distance from the passed node, to the furthest leaf below it.
 * This method calls itself recursively to always find the max hight.
 **/
int BinTree::findHeight(Node *item) {
    if (item == NULL) {
        return 0;
    } else if (item->left == NULL &&
               item->right == NULL) {  // check if leaf node
        return 1;
    } else if (item->left == NULL) {  // check if only has right child
        return (findHeight(item->right) + 1);
    } else if (item->right == NULL) {
        return (findHeight(item->left) + 1);
    }                                   // if its not a leaf, and not single
    int left = findHeight(item->left);  // child, find max between sides
    int right = findHeight(item->right);
    return (left > right ? left + 1 : right + 1);  // turnary check for max
}
/**------------------------------ generalFind---------------------------------
 * BinTree generalFind
 * @param	*left			pointer to the left child
 * @param	*right			pointer to the right child
 * @param	&item			a reference to the NodeData object to be
 *searched for
 * @param	&foundNode		a reference to an external nodeData
 *object that will point directly to the internal object in the Bintree if it is
 *found.
 * @return	bool			representing if the NodeData was found
 *in the BinTree
 *
 * this method searches for the NodeData object and returns a bool if it was
 *found, while assigning the foundNode pointer to the object. This method calls
 *itself recursively while checking all nodes until the node is found.
 **/
bool BinTree::generalFind(Node *left, Node *right, const NodeData &item,
                          Node *&foundNode) {
    if (left != NULL) {             // checks if left has data
        if (*left->data == item) {  // checks if left is the item
            foundNode = left;
            return true;
        }  // if left is not the item, check if its left and right are NULL
        Node *lLeft = left->left == NULL ? NULL : left->left;
        Node *lRight = left->right == NULL ? NULL : left->right;
        generalFind(lLeft, lRight, item, foundNode);  // recursive call
    }
    if (right != NULL) {  // same operations for the right.
        if (*right->data == item) {
            foundNode = right;
            return true;
        }
        Node *rLeft = right->left == NULL ? NULL : right->left;
        Node *rRight = right->right == NULL ? NULL : right->right;
        generalFind(rLeft, rRight, item, foundNode);
    }
    return false;
}
/**-------------------------------copyHelper---------------------------------
 * BinTree 	copyHelper
 * @param	*other		a pointer to a Noda object to be copied from
 *another BinTree.
 *
 * Recursive method that calls itself until it has inserted all nodes from the
 *other BinTree. This method will only be used by the Copy Constructor or
 *operator=
 **/
void BinTree::copyHelper(Node *other) {
    if (other != NULL) {
        safeInsert(other->data);
        copyHelper(other->left);
        copyHelper(other->right);
    }
}
/**------------------------------ traverse -------------------------------------
 * BinTree traverse
 * @param	n		a NodeData object to be searched for
 * @param	*&temp	a reference to an externally created Node object
 * @return	Node*	a pointer to the node if it is found, if not found,
 *pointer will point to NULL This method searches for the passed NodeData object
 *in this BinTree
 **/
BinTree::Node *BinTree::traverse(NodeData n, Node *&temp) {
    Node *curr = this->root;
    temp = NULL;  // just to be sure it is empty, set it to NULL
    while (curr != NULL &&
           *curr->data !=
               n) {   // traverse through tree looking for the node or the end
        temp = curr;  // assign curr to temp to be passed back
        if (n < *curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return curr;  // will be NULL if the nodeData passed in already exists
}
/**------------------------------ equality -------------------------------------
 * BinTree equality
 * @param	*thisNode	a pointer to the current node in this BinTree
 * @param	*otherNode	a pointer to the current node in the other
 *BinTree
 * @return	bool		represents if the BinTree is exactly to another
 *
 * checks through the the two BinTrees for exact equality using preorder.
 **/
bool BinTree::equality(Node *thisNode, Node *otherNode) const {
    // Check if both the trees are empty
    if (thisNode == NULL && otherNode == NULL) {
        return true;
    }
    // If any one of the tree is non-empty
    // and other is empty, return false
    else if (thisNode != NULL &&
             otherNode != NULL) {  // Check if current data of both trees equal
        // and recursively check for left and right subtrees
        if ((*thisNode->data == *otherNode->data) &&
            (equality(thisNode->left,
                      otherNode->left)) &&  // if false, breaks the check
            (equality(thisNode->right, otherNode->right))) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}
/**------------------------------ inorderPrint--------------------------------
 * BinTree inorderPrint
 * @param	*thisNode	a pointer to the current node in this BinTree
 * @param	&out		a reference to the ostream object passed in.
 *
 * moves through the BinTree recursively adding the NodeData output to the
 *outstream
 **/
void BinTree::inorderPrint(Node *thisNode, ostream &out) {
    if (thisNode != NULL) {  // check if pointer is null
        inorderPrint(thisNode->left, out);
        out << *thisNode->data << " ";
        inorderPrint(thisNode->right, out);
    }
}
/**------------------------------ inorderHelper
 *------------------------------------- BinTree inorderHelper
 * @param	*n			a pointer to the current Node being
 *inserted in the array
 * @param	*data[]		a pointer to the array to be filled with the
 *contents of this BinTree in sorted order.
 * @param	&count		a reference to the externally created counter to
 *keep track of where in the array to place NodeData pointers.
 *
 * Moves through this BinTree creating copies of the NodeData objects to be
 *maintained in the passed array. Calls itself recursively while incrementing
 *the counter for sorted insertion.
 **/
void BinTree::inorderHelper(Node *n, NodeData *data[], int &count) {
    if (n == NULL) {
        return;
    }
    inorderHelper(n->left, data, count);
    NodeData *ptr = new NodeData(*n->data);  // create copy for array
    data[count] = ptr;
    count++;
    inorderHelper(n->right, data, count);
}
/**------------------------------ buildTree
 *------------------------------------- BinTree buildTree
 * @param	left	the index of the left end of the current array portion
 * @param	right	the index of the right end of the current array portion
 *
 * Moves through the passed array creating copies of the NodeData objects to be
 * maintained in this BinTree. Calls itself recursively while inserting Nodes.
 * The NodeData items in the array will be maintained in memory for the BinTree.
 * This method always assumes the NodeData in the array is sorted and start at
 * index 0 of the array. The array may have as many NULL spaces after the last
 * NodeData item that it contains.
 **/
void BinTree::buildTree(int left, int right, NodeData *data[]) {
    while (data[right] == NULL) {  // find the actual last data member location
        right--;
    }
    int root = (left + right) / 2;
    if (left > right) {
        return;
    }
    safeInsert(data[root]);
    buildTree(left, root - 1, data);   // call method for left half
    buildTree(root + 1, right, data);  // call method for right half
}