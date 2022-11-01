#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;
/*oz asban 207565607
binymin shapira
data structure 2 exercise 1
class for node .h*/

class Node//discussion
{
public:
	//data
	string content;
	list <Node> responses;
	//functions
	Node* searchRec(list<Node>::iterator itb, list<Node>::iterator ite,string str);
	void printNode(list<Node>::iterator itb, list<Node>::iterator ite,int tab);
	void printNodeIf(list<Node>::iterator itb, list<Node>::iterator ite, int tab, string str);
};