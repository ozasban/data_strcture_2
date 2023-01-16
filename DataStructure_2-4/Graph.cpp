#include "Graph.h"
#include <iostream>
#include <iterator>
#include<algorithm>
#include <list>
#include<string>
#include <map>
using namespace std;
void Graph::AddVertex(string key)
{
    Vertex* newVertex = new Vertex();
    newVertex->Key = key;
    vertices[key] = newVertex;
}

void Graph::PrintGraph()
{
    map<string, Vertex*>::iterator vertexIter;
    list<Edge*>::iterator edgeIter;
    for (vertexIter = vertices.begin(); vertexIter != vertices.end(); ++vertexIter)
    {
        cout << vertexIter->first << " --> ";
        for (edgeIter = vertexIter->second->EdgeList.begin(); edgeIter != vertexIter->second->EdgeList.end(); ++edgeIter)
            cout << (*edgeIter)->destination->Key << " ";
        cout << endl;
    }
}

bool Graph::DeleteVertex(string key)
{
    auto it = vertices.find(key);
    if (it == vertices.end())
    {
        cout << "Vertex not found" << endl;
        return false;
    }
    // Delete the vertex from the map
    vertices.erase(it);

    // Delete all edges that have the vertex as the destination
    for (auto const& vertexPair : vertices)
    {
        list<Edge*>& edges = vertexPair.second->EdgeList;
        edges.remove_if([key](const Edge* edge) { return edge->destination->Key == key; });
    }
    return true;
}

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
    Edge* newEdge = new Edge();
    newEdge->Source = src;
    newEdge->destination = dst;
    src->EdgeList.push_back(newEdge);
    return true;
}



bool Graph::DeleteEdge(string source, string dest)
{
    Vertex* src = vertices[source];
    if (!src)
    {
        cout << "Source vertex does not exist." << endl;
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
    if (it == src->EdgeList.end())
    {
        cout << "Edge does not exist." << endl;
        return false;
    }
    src->EdgeList.erase(it);
    return true;
}

void Graph::PrintOutgoingVertices(string key)
{
    Vertex* v = vertices[key];
    cout << "Outgoing vertices from " << key << ": ";
    list<Edge*>::iterator it;
    for (it = v->EdgeList.begin(); it != v->EdgeList.end(); it++)
    {
        cout << (*it)->destination->Key << " ";
    }
    cout << endl;
}

void Graph::PrintIncomingVertices(string key)
{
    cout << "Incoming vertices to " << key << ": ";
    map<string, Vertex*>::iterator it;
    for (it = vertices.begin(); it != vertices.end(); it++)
    {
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
    cout << endl;
}

void Graph::PrintPathLengthTwoVertices(string key)
{
    cout << "Vertices with path of length 2 from " << key << ": ";
    Vertex* v = vertices[key];
    list<Edge*>::iterator it;
    for (it = v->EdgeList.begin(); it != v->EdgeList.end(); it++)
    {
        Vertex* w = (*it)->destination;
        list<Edge*>::iterator it2;
        for (it2 = w->EdgeList.begin(); it2 != w->EdgeList.end(); it2++)
        {
            Vertex* x = (*it2)->destination;
            cout << x->Key << " ";
        }
    }
    cout << endl;
}