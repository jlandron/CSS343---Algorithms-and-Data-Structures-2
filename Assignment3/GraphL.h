#ifndef GRAPHL_H
#define GRAPHL_H
/**
 *#############################################################################
 *#-------------------------- Header ----------------------------------------
 *#  A Graph that takes information about nodes and edges, and calculates the
 *#  depth first path
 *#  @author 	Joshua Landron
 *#  @date 	    6May2019
 *#  @version	10May2019
 *#
 *#  Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#
 *#############################################################################
 *
 * Depth first search graph: Data structure defined by a node having an
 *arbitrary number of neighbors, This class only contain the minimal amount of
 *structure in order to take in data from a properly formatted file, and have
 *the ability to print the results of the graph and of a depth first search
 *
 * Implementation and assumptions:
 * -NodeData Object inserted will not be inserted by the user. The graph will
 *maintain all of its of data
 * -NodeData should define << for use in this class
 * -Nodes are 1 indexed
 * -User input file should be formatted as such:
 * 3        -the number of nodes
 * aaa      -the names of the nodes
 * bbb
 * ccc
 * 1 2      -directional connections between nodes(edges) in this order
 * 1 3      -from, to
 * 2 3
 * 3 2
 * 0 0      -zeros signify the end of the graph
 * -------------------------------------------------------------------------------
 **/
#include <fstream>
#include <iostream>
#include <sstream>
#include "nodedata.h"
using namespace std;

class GraphL {
    static const int MAXNODES = 101;  // 100 nodes, space 0 is never used
   public:
    GraphL();
    GraphL(ifstream &infile);
    ~GraphL();
    void buildGraph(ifstream &infile);
    void depthFirstSearch();
    void displayGraph();

   private:
    int graphNodes;
    // a much more complicated struct than normal, but much to small for its own
    // class.
    struct EdgeNode {
        int adjGraphNode;
        EdgeNode *nextEdge;
        EdgeNode() { nextEdge = NULL; }
    };
    struct GraphNode {
        EdgeNode *edgeHead;
        NodeData *data;
        bool visited;
        /**--------------constructor--------
         * GraphNode
         * standard constructor sets value of edgehead pointer to NULL
         */
        GraphNode() { edgeHead = NULL; }
        /**-------------destructor----------
         * ~GraphNode
         * iterates through the list of edgeNodes deleating them one at a time
         */
        ~GraphNode() {  // destructor for the mini linked list that will
                        // attached to each graph node
            EdgeNode *curr = edgeHead;
            EdgeNode *next;
            while (curr != NULL) {
                next = curr->nextEdge;
                delete curr;
                curr = next;
            }
        }
        /**--------------insert---------------
         * struct method to deal with front of list insertion
         * @param  {int} id : represeting an adjacent node
         */
        void insert(int id) {
            if (edgeHead == NULL) {
                edgeHead = new EdgeNode;
                edgeHead->adjGraphNode = id;
                edgeHead->nextEdge = NULL;
            } else {
                EdgeNode *tmp = edgeHead;
                edgeHead = new EdgeNode;
                edgeHead->adjGraphNode = id;
                edgeHead->nextEdge = tmp;
            }
        }
    };
    GraphNode data[MAXNODES];
    void displayEdges(int location);
    void dfs(int currNode);
};

#endif