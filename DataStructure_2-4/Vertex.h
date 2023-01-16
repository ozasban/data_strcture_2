#pragma once
#include <iostream>
#include <iterator>
#include <list>
#include<string>
#include "Edge.h"
using namespace std;

class Edge;

class Vertex
{
public:
    
    string Key;
    list < Edge* > EdgeList;
    double pi;
};



