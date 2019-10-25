/**
 *#############################################################################
 *#-------------------------- Definitions--------------------------------------
 *#  A Graph that takes information about nodes and edges, and calculates all
 *#  shortest paths using Dijkstra's algorithm
 *#
 *#  @author 	Joshua Landron
 *#  @date 	    5May2019
 *#  @version	10May2019
 *#
 *#  Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#
 *#############################################################################
 **/
#include "GraphM.h"
#include "sstream"
using namespace std;
//#############################################################################
//#----------------------------- Public methods ------------------------------#
//#############################################################################
/**-------------------Constructor------------------
 * GraphM::GraphM
 *  Constructor that initializes a 100 by 100 grid for calculating
 *  all distances and paths for up to 100 nodes in a graph.
 */
GraphM::GraphM() {
    //          [from][to]
    //   int C[MAXNODES][MAXNODES];
    // initializing all paths to INF to indicate no path
    // between nodes
    for (int i = 0; i < MAXNODES; i++) {
        for (int j = 0; j < MAXNODES; j++) {
            C[i][j] = INF;
        }
        C[i][i] = 0;
    }
    //   TableType T[MAXNODES][MAXNODES];
    for (int i = 1; i < MAXNODES; i++) {
        for (int j = 0; j < MAXNODES; j++) {
            T[i][j].visited = false;
            T[i][j].dist = INF;
            T[i][j].path = 0;
        }
    }
}
/**-------------------Constructor------------------
 * overloaded GraphM
 *  This constructor takes a reference to an ifstream to be passed to buildGraph
 *  Constructor first initializes a 100 by 100 grid for calculating
 *  all distances and paths for up to 100 nodes in a graph, followed by calling
 *  the buildGraph method with the ifstream reference. 
 */
GraphM::GraphM(ifstream &infile) {
    // initializing all paths to INF to indicate no path
    // between nodes
    for (int i = 0; i < MAXNODES; i++) {
        for (int j = 0; j < MAXNODES; j++) {
            C[i][j] = INF;
        }
        C[i][i] = 0;
    }
    //   TableType T[MAXNODES][MAXNODES];
    for (int i = 1; i < MAXNODES; i++) {
        for (int j = 0; j < MAXNODES; j++) {
            T[i][j].visited = false;
            T[i][j].dist = INF;
            T[i][j].path = 0;
        }
    }
    buildGraph(infile);
}
/**-----------------------------Destructor-----------------------------
 * no internal objects to destroy, so just the default destructor
 */
GraphM::~GraphM() {}
/**-----------------------------buildGraph-----------------------------
 *
 * @param  {ifstream} infile :
 */
void GraphM::buildGraph(ifstream &infile) {
    infile >> graphNodes;
    string temp;
    getline(infile, temp);  // dispose of empty line after using >>
    if (infile.eof()) return;
    // cout << numNodes << " nodes" << endl;
    for (int i = 1; i <= graphNodes; i++) {
        getline(infile, temp);
        // cout << temp << endl;
        data[i] = NodeData(temp);
    }
    int from;
    int to;
    int weight;
    while (true) {
        infile >> from;
        infile >> to;
        infile >> weight;
        if (from == 0) {
            break;
        }
        C[from][to] = weight;
    }
    getline(infile, temp);  // dispose of empty line after using >>
}
/**-----------------------------------insertEdge------------------------------
 * inserts an edge from one node to another, overwrites the weight if there is
 * an existing edge
 *
 * @param  {int} from   :   node edge should start at
 * @param  {int} to     :   node edge should end at
 * @param  {int} weight :   weight of edge
 */
void GraphM::insertEdge(int from, int to, int weight) { C[from][to] = weight; }
/**------------------------------------removeEdge------------------------------
 * removes an edge between two nodes if it exists, resets and automatically
 * recalculates all shortest paths in grid after removal
 *
 * @param  {int} from : node edge starts at
 * @param  {int} to   : node edge ends at
 */
void GraphM::removeEdge(int from, int to) {
    C[from][to] = INF;
    for (int i = 1; i < MAXNODES; i++) {
        for (int j = 0; j < MAXNODES; j++) {
            T[i][j].visited = false;
            T[i][j].dist = INF;
            T[i][j].path = 0;
        }
    }
}
/**-----------------------------findShortestPath--------------------------------
 * public method to calculate all shortest paths of the Graph, iterates though
 * all nodes calling its utility method dijkstra to calculate all shortest path
 * -This method should be called again if there are any changes to the graph
 * such as adding or removing edges
 *
 */
void GraphM::findShortestPath() {
    for (int source = 1; source <= graphNodes; source++) {
        // distance from node to itself is 0;
        T[source][source].dist = 0;
        dijkstra(source);
        // reset viseted tags for next pass
        for (int i = 1; i <= graphNodes; i++) {
            for (int j = 1; j <= graphNodes; j++) {
                T[i][j].visited = false;
            }
        }
    }
}
//#############################################################################
//#----------------------- Private Utility methods ---------------------------#
//#############################################################################
/**--------------------------------dijkstra------------------------------------
 * utility method to conduct the standard dijkstra algorithm from a starting
 * node
 * @param  {int} source : The node that we are treating as the head for this
 * pass
 */
void GraphM::dijkstra(int source) {
    // finds the shortest distance from source to all other nodes
    for (int i = 1; i <= graphNodes; i++) {
        // find v //not visited, shortest distance at this point
        int v = findLowestUnvisited(source);
        // mark v visited
        T[source][v].visited = true;
        // for each w adjacent to v
        for (int w = 1; w <= graphNodes; w++) {
            // if (w is not visited)
            if (C[v][w] < INF) {
                if (!T[source][w].visited) {
                    if (T[source][v].dist + C[v][w] < T[source][w].dist) {
                        T[source][w].dist = T[source][v].dist + C[v][w];
                        T[source][w].path = v;
                    }
                }
            }
        }
    }
}
/**---------------------------------displayAll--------------------------------
 * prints the graph to cout in a formatted manner
 */
void GraphM::displayAll() {
    cout << "Description \t    From node  to node  Dijkstra's\tPath" << endl;
    for (int i = 1; i <= graphNodes; i++) {
        cout << data[i] << endl;
        for (int j = 1; j <= graphNodes; j++) {
            if (i != j) {
                if (T[i][j].dist == INF) {
                    cout << "\t\t\t" << i << "\t" << j << "\t---" << endl;
                } else {
                    cout << "\t\t\t" << i << "\t" << j << "\t" << T[i][j].dist
                         << "\t\t" << findPath(i, j) << endl;
                }
            }
        }
    }
}
/**---------------------------------display----------------------------------
 * displays a songle shortest path to cout
 * @param  {int} from : begginging node
 * @param  {int} to   : ending node
 */
void GraphM::display(int from, int to) {
    if (T[from][to].dist == INF) {
        cout << "No Path from " << from << " to " << to << endl;
        return;
    }
    cout << from << "\t" << to << "\t" << T[from][to].dist << "\t\t"
         << findPath(from, to) << endl;
    stringstream ss;
    int location;
    ss << findPath(from, to);
    while (ss >> location) {
        cout << data[location] << endl;
    }
    cout << endl;
}
/**---------------------------findLowestUnvisited---------------------------
 * private method to find the lowest connected, unvisited node
 * @param  {int} source :
 * @return {int}        :
 */
int GraphM::findLowestUnvisited(int source) {
    int min = INF;
    int min_index = source;
    for (int v = 1; v <= graphNodes; v++) {
        if (T[source][v].visited == false && C[source][v] < min) {
            min = C[source][v], min_index = v;
        }
    }
    return min_index;
}
/**-----------------------------------min----------------------------------
 * finds the smaller of two passed int values
 *
 * @param  {int} left   : first int
 * @param  {int} right  : second int
 * @return {int} result : smaller int
 */
int GraphM::min(int left, int right) { return (left < right ? left : right); }
/**--------------------------------findPath---------------------------------
 * finds the complete path as determined by the shortest path algorithm
 * and returns it as a string
 *
 * @param  {int} from : graph node to start
 * @param  {int} to   : graph node to end
 * @return {string}   : output of path from start to end
 */
string GraphM::findPath(int from, int to) {
    string result = "";
    int path[100];    // array to store path
    int pathLen = 0;  // keeps track of how many ints were inserted into path
    stringstream ss;
    if (T[from][to].dist == INF) {
        return result;
    }
    while (to != from) {
        path[pathLen] = to;
        to = T[from][to].path;
        pathLen++;
    }
    path[pathLen] = from;
    pathLen++;
    for (int i = pathLen - 1; i >= 0; i--) {
        ss << path[i] << " ";
    }
    result = ss.str();
    return result;
}
