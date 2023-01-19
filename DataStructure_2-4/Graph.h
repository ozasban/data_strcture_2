#pragma once
#include "Edge.h"
#include "Vertex.h"
#include <map>
using namespace std;

/*
oz asban 207565607
binymin shapira 208965863
data structure 2 exercise 5
class for Graph .h
*/
class Graph
{
public://data
    map<string, Vertex*> vertices;
    Graph() {};//ctor
    //methods
    void AddVertex(string key);
    void PrintGraph();
    bool DeleteVertex(string key);
    bool AddEdgeSafe(string source, string dest);
    bool DeleteEdge(string source, string dest);
    void PrintOutgoingVertices(string key);
    void PrintIncomingVertices(string key);
    void PrintPathLengthTwoVertices(string key);

};