#ifndef GRAPHM_H
#define GRAPHM_H
/**
 *#############################################################################
 *#-------------------------- Header ----------------------------------------
 *#  A Graph that takes information about nodes and edges, and calculates all
 *#  shortest paths using dijkstra's algorithm
 *#  @author 	Joshua Landron
 *#  @date 	    6May2019
 *#  @version	10May2019
 *#
 *#  Built as part of CSS343 with Dr. Min Chen, Spring 2019
 *#
 *#############################################################################
 *
 * dijkstra's algorithm all shortest path graph: Data structure defined by a
 *node having an arbitrary number of neighbors, This class only contain the
 *minimal amount of structure in order to take in data from a properly formatted
 *file, and have the ability to print the results of the graph and of a
 *dijkstra's algorithm all shortest paths search
 *
 * Implementation and assumptions:
 * -NodeData Object inserted will not be inserted by the user. The graph will
 *maintain all of its of data
 * -NodeData should define << for use in this class
 * -nodes are 1 indexed
 * -User input file should be formatted as such:
 * 3        -the number of nodes
 * aaa      -the names of the nodes
 * bbb
 * ccc
 * 1 2 34     -weighted connections between nodes(edges) in this order
 * 1 3 32     -From, to, weight
 * 2 3 10
 * 3 2 5
 * 0 0 0      -zeros signify the end of the graph
 * -------------------------------------------------------------------------------
 **/
#include <fstream>
#include <iostream>
#include "limits.h"
#include "nodedata.h"
using namespace std;

class GraphM {
    static const int MAXNODES = 101;  // 100 nodes, space 0 is never used
    static const int INF = INT_MAX;

   public:
    GraphM();
    GraphM(ifstream &infile);
    ~GraphM();
    void buildGraph(ifstream &infile);
    void insertEdge(int from, int to, int weight);
    void removeEdge(int from, int to);
    void findShortestPath();
    void displayAll();
    void display(int from, int to);

   private:
    /**
     * TableType
     * A struct that holds 3 values to be used in the T matrix
     */
    struct TableType {
        bool visited;
        int dist;
        int path;
    };
    int graphNodes;
    NodeData data[MAXNODES];
    int C[MAXNODES][MAXNODES];
    TableType T[MAXNODES][MAXNODES];
    void allShortestPath();
    void dijkstra(int source);
    int findLowestUnvisited(int source);
    int min(int left, int right);
    string findPath(int from, int to);
};

#endif