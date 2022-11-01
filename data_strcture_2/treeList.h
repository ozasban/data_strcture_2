#pragma once
#include <iostream>
#include <list>
#include <string>
#include "tree.h"
/*oz asban 207565607
binymin shapira 208965863
data structure 2 exercise 1
class for treeList.h*/

class treeList
{
	list<Tree*> trees;

public:

	treeList() {}//ctor
	~treeList();//detor
	//metods
	void addNewTree(string s);
	void deleteTree(Tree* t);
	void searchAndPrint(string val);
	bool addResponse(string rt, string prnt, string res);
	bool delResponse(string rt, string res);
	void printTree(string rt);
	void printAllTrees();
	void printSubTree(string rt, string s);
};