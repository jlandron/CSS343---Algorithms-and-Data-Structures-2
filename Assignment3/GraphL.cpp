/**
 *#############################################################################
 *#-------------------------- Definitions--------------------------------------
 *#  A Graph that takes information about nodes and edges, and calculates the
 *#  depth first path
 *#  @author 	Joshua Landron
 *#  @date 	    6May2019
 *#  @version	10May2019
 *#
 *#  Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#
 *#############################################################################
 **/
#include "GraphL.h"
#include <fstream>
#if defined(_WIN32) || defined(_WIN64)
#include "vld.h"
#endif
using namespace std;
//#############################################################################
//#----------------------------- Public methods ------------------------------#
//#############################################################################

/**----------------------------Constructor------------------------------------
 * GraphL::GraphL
 * instantiates an empty graph with space for 100 nodes and an arbitrary number
 * of edges
 */
GraphL::GraphL() {
    for (int i = 1; i < MAXNODES; i++) {
        data[i].data = NULL;
        data[i].edgeHead = NULL;
        data[i].visited = false;
    }
}
/**----------------------------Constructor------------------------------------
 * GraphL::GraphL
 * instantiates an empty graph with space for 100 nodes and an arbitrary number
 * of edges followed by calling the buildGraph method with the ifstream
 * reference.
 */
GraphL::GraphL(ifstream &infile) {
    for (int i = 1; i < MAXNODES; i++) {
        data[i].data = NULL;
        data[i].edgeHead = NULL;
        data[i].visited = false;
    }
    buildGraph(infile);
}
/**---------------------destructor--------------------------------------------
 * GraphL::~GraphL
 * deletes all NodeData objects inserted when graph was built
 */
GraphL::~GraphL() {
    for (int i = 1; i < MAXNODES; i++) {
        if (data[i].data != NULL) {
            delete data[i].data;
        }
    }
}
/**-------------------------------buildGraph--------------------------------
 * public method to build a graph from a file to be searched depth first
 * @param  {ifstream} infile : file that must be formatted in a specific way
 */
void GraphL::buildGraph(ifstream &infile) {
    infile >> graphNodes;
    string temp;
    getline(infile, temp);  // dispose of empty line after using >>
    if (infile.eof()) return;
    // cout << graphNodes << " nodes" << endl;
    for (int i = 1; i <= graphNodes; i++) {
        getline(infile, temp);
        // cout << temp << endl;
        data[i].data = new NodeData(temp);
    }
    int from;
    int to;
    while (true) {
        infile >> from;
        infile >> to;
        if (from == 0) {
            break;
        }
        data[from].insert(to);
    }
    getline(infile, temp);  // dispose of empty line after using >>
}
/**------------------------depthFirstSearch----------------------------------
 * public function to conduct depth first search and print the results
 */
void GraphL::depthFirstSearch() {
    for (int i = 1; i <= graphNodes; i++) {
        data[i].visited = false;
    }
    for (int i = 1; i <= graphNodes; i++) {
        if (!data[i].visited) {
            dfs(i);
        }
    }
    cout << endl;
}
//#############################################################################
//#----------------------- Private Utility methods ---------------------------#
//#############################################################################
/**------------------------dfs------------------------------------------------
 * recursive depth first search function called by iterator for each Graph Node
 * @param  {int} currNode : the GraphNode it is working on
 */
void GraphL::dfs(int currNode) {
    data[currNode].visited = true;
    cout << currNode << " ";
    EdgeNode *curr = data[currNode].edgeHead;
    if (curr == NULL) {
        return;
    }
    int loc = curr->adjGraphNode;
    while (curr != NULL) {
        if (!data[loc].visited) {
            dfs(loc);
        }
        curr = curr->nextEdge;
    }
    return;
}
/**-------------------------------displayGraph--------------------------------
 * Iterates through all EdgeNodes printing out the contents of the graph
 */
void GraphL::displayGraph() {
    cout << "Graph:" << endl;
    for (int i = 1; i <= graphNodes; i++) {
        cout << "Node " << i << "\t\t" << *data[i].data << endl;
        displayEdges(i);
    }
}
/**-------------------------------displayEdges----------------------------------
 * prints the edges of a given GraphNode
 * @param  {int} location : number representing the node displayed
 */
void GraphL::displayEdges(int location) {
    EdgeNode *curr = data[location].edgeHead;
    while (curr != NULL) {
        cout << "  edge " << location << " " << curr->adjGraphNode << endl;
        curr = curr->nextEdge;
    }
}
