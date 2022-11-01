#pragma once
#include <iostream>
#include <string>
#include <list>
#include"Node.h"
using namespace std;
/*oz asban 207565607
binymin shapira 208965863
data structure 2 exercise 1
class for tree .h*/

class Tree//tree of discussins
{
public:
	Node* discussion;

	//ctor,dtor
	Tree(string s);
	~Tree();
	//functions
	void buildNewRoot(string title);
	Node* search(string str);
	void addResponse( string father, string son);
	void delSubTree(string str);
	void printTree();
	void searchPrintRoot(string str);
	void searchPrintLeaf(string str);
};
