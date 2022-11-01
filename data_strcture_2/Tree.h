#pragma once
#include <iostream>
#include <string>
#include <list>
#include"Node.h"
using namespace std;

class Tree
{
	Node* discussion;
public:
	Tree();
	~Tree();
	void buildNewRoot(string title);
	Node* search(string str);
	void addResponse( string father, string son);
	void delSubTree(string str);
	void printTree();
	void searchPrintRoot(string str);
	void searchPrintLeaf(string str);
};
