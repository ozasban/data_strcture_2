#include <iostream>
#include <iterator>
#include<algorithm>
#include <list>
#include<string>
#include "Graph.h"
#include <map>
using namespace std;

/*
oz asban 207565607
binymin shapira 208965863
data structure 2 exercise 5
class for Graph .cpp
*/

/// <summary>
/// add vertex to graph
/// </summary>
/// <param name="key"></param>
void Graph::AddVertex(string key)
{
    Vertex* newVertex = new Vertex();
    newVertex->Key = key;
    vertices[key] = newVertex;
}
/// <summary>
/// print the graph
/// </summary>
void Graph::PrintGraph()
{
    //for every vertex print his edges
    map<string, Vertex*>::iterator vertexIter;
    list<Edge*>::iterator edgeIter;
    for (vertexIter = vertices.begin(); vertexIter != vertices.end(); ++vertexIter)
    {
        cout << vertexIter->first << ": ";
        for (edgeIter = vertexIter->second->EdgeList.begin(); edgeIter != vertexIter->second->EdgeList.end(); ++edgeIter)
            cout << (*edgeIter)->destination->Key << " ";
        cout << endl;
    }
}
/// <summary>
/// struct for the remove if in the delete method
/// return true if need to delete 
/// </summary>
struct EdgeMatchesKey
{
    EdgeMatchesKey(string key) : key(key) {}
    bool operator()(const Edge* edge) const {
        return edge->destination->Key == key;
    }
    string key;
};
/// <summary>
/// delete vertex to graph
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
bool Graph::DeleteVertex(string key)
{
    map<string, Vertex*>::iterator it;
    it = vertices.find(key);
    if (it == vertices.end())
    {
        return false;
    }
    // Delete the vertex from the map
    vertices.erase(it);

    // Delete all edges that have the vertex as the destination
    for (std::map<string, Vertex*>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        std::pair<string, Vertex*> vertexPair = *it;
        std::list<Edge*>& edges = vertexPair.second->EdgeList;
        edges.remove_if(EdgeMatchesKey(key));
    }
    return true;
}
/// <summary>
/// add edge to the graph if not exist
/// </summary>
/// <param name="source"></param>
/// <param name="dest"></param>
/// <returns></returns>
bool Graph::AddEdgeSafe(string source, string dest)
{
    // Check if the source and destination vertices exist
    if (vertices.find(source) == vertices.end() || vertices.find(dest) == vertices.end())
    {
        return false;
    }

    Vertex* src = vertices[source];
    Vertex* dst = vertices[dest];

    // Check if the edge already exists
    for (std::list<Edge*>::iterator it = src->EdgeList.begin(); it != src->EdgeList.end(); it++)
    {
        Edge* edge = *it;
        if (edge->destination->Key == dest)
        {
            return false;
        }
    }
    //adding edge
    Edge* newEdge = new Edge();
    newEdge->Source = src;
    newEdge->destination = dst;
    src->EdgeList.push_back(newEdge);
    return true;
}


/// <summary>
/// delete edge from graph
/// </summary>
/// <param name="source"></param>
/// <param name="dest"></param>
/// <returns></returns>
bool Graph::DeleteEdge(string source, string dest)
{
    //if source not exist return false
    Vertex* src = vertices[source];
    if (!src)
    {
        return false;
    }

    // Find the edge and delete it
    list<Edge*>::iterator it;
    for (it = src->EdgeList.begin(); it != src->EdgeList.end(); it++)
    {
        if ((*it)->destination->Key == dest)
        {
            break;
        }
    }
    //if dest not exist return false
    if (it == src->EdgeList.end())
    {
        return false;
    }
    src->EdgeList.erase(it);
    return true;
}
/// <summary>
/// print all vertexes that have edge frpm v to them
/// </summary>
/// <param name="key"></param>
void Graph::PrintOutgoingVertices(string key)
{
    ////check if key exist
    if (vertices.find(key) == vertices.end())
    {
        return;
    }
    Vertex* v = vertices[key];
    list<Edge*>::iterator it;
    //print all the detination in v edge list
    for (it = v->EdgeList.begin(); it != v->EdgeList.end(); it++)
    {
        cout << (*it)->destination->Key << " ";
    }
    cout << endl;
}
/// <summary>
///  print all vertexes that have edge frpm them  to v
/// </summary>
/// <param name="key"></param>
void Graph::PrintIncomingVertices(string key)
{
    //check if key exist
    if (vertices.find(key) == vertices.end())
    {
        cout << "ERROR" << endl;
        return;
    }
    map<string, Vertex*>::iterator it;
    //loop the all graph
    for (it = vertices.begin(); it != vertices.end(); it++)
    {
        //if not null
        if (it->second)
        {
            //for every vertex check if if heve edge from them to v and print
            list<Edge*>::iterator it2;
            for (it2 = it->second->EdgeList.begin(); it2 != it->second->EdgeList.end(); it2++)
            {
                if ((*it2)->destination->Key == key)
                {
                    cout << it->first << " ";
                    break;
                }
            }
        }
    }
    cout << endl;
}
/// <summary>
/// print all the vertexes that with distance less then 2 from the aented vertex
/// </summary>
/// <param name="key"></param>
void Graph::PrintPathLengthTwoVertices(string key)
{
    //check if key exist
    if (vertices.find(key) == vertices.end())
    {
        cout << "ERROR" << endl;
        return;
    }
    Vertex* v = vertices[key];
    list<Edge*>::iterator it;
    //run all over the edges of v
    for (it = v->EdgeList.begin(); it != v->EdgeList.end(); it++)
    {
        Vertex* w = (*it)->destination;
        list<Edge*>::iterator it2;
        //for every edge print the vertexes wit distance 1 from the current evertex
        for (it2 = w->EdgeList.begin(); it2 != w->EdgeList.end(); it2++)
        {
            //check if its not our v
            if ((*it2)->destination->Key != key)
            {
                Vertex* x = (*it2)->destination;
                cout << x->Key << " ";
            }
        }
    }
    cout << endl;
}