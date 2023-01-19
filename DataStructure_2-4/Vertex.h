#pragma once
#include <iostream>
#include <iterator>
#include <list>
#include<string>
#include "Edge.h"
using namespace std;
/*
oz asban 207565607
binymin shapira 208965863
data structure 2 exercise 5
class for vertex
*/
class Edge;

class Vertex
{
public:
   //data 
    string Key;
    list < Edge* > EdgeList;
    double pi;
};



