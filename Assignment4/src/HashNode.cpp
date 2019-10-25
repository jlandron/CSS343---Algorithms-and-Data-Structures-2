#include "HashNode.h"

using namespace std;
/**-----------------------------HashNode::HashNode-----------------------------
 * default no arg constructor
 */
HashNode::HashNode() : m_Key{-1}, m_Value{NULL} {}
/**-----------------------------HashNode::~HashNode----------------------------
 * destructor to ensure all fields are deleted
 */
HashNode::~HashNode() { delete m_Value; }
/**-----------------------------HashNode::HashNode-----------------------------
 * overload constructor
 *
 * @param  {int} key         : The key for this HashNode object
 * @param  {Customer*} value : a pointer to this Node's Customer object
 */
HashNode::HashNode(int key, Customer* value) {
    m_Key = key;
    m_Value = value;
}
/**-----------------------------------getKey----------------------------------
 * returns an in representing this objects key
 *
 * @return {int}  : represents this objects Key
 */
int HashNode::getKey() { return m_Key; }
/**----------------------------------getValue--------------------------------
 * returns a pointer to this Node's Customer object
 *
 * @return {Customer*}  : Customer pointer
 */
Customer* HashNode::getValue() { return m_Value; }