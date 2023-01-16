#pragma once
#include "Edge.h"
#include "Vertex.h"
#include <map>
using namespace std;
class Graph
{
public:
    map<string, Vertex*> vertices;
    Graph() {};
    void AddVertex(string key);
    void AddEdge(string source, string dest);
    void PrintGraph();
    bool DeleteVertex(string key);
    bool AddEdgeSafe(string source, string dest);
    bool DeleteEdge(string source, string dest);
    void PrintOutgoingVertices(string key);
    void PrintIncomingVertices(string key);
    void PrintPathLengthTwoVertices(string key);

};