#include "Node.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

/*oz asban 207565607
binymin shapira 208965863
data structure 2 exercise 1
class for node .cpp*/


Node::Node(string s)
{
	content = s;
}

Node::~Node()
{

}

//searching title in node
Node* Node::searchRec(list<Node*>::iterator itb , list<Node*>::iterator ite, string str)
{
	if (( * itb)->content.empty())//empty node
	{
		return nullptr;
	}
	else
	{
		if (( * itb)->content == str)//if found return pointer
			return &(**itb);
		//reqursive call to serche in the respons
		Node* tNode = searchRec( ( * itb)->responses.begin(), (*itb)->responses.end(), str);

		if (tNode)//if was found
		{
			return tNode;
		}

		if (itb == ite)//if we are in the end of the list
		{
			return nullptr;
		}

		return searchRec( itb++, ite,str);//searc in the next node

	}
}
//printing the node and his respons in hierarchcal way(tab for the hirarchical)
void Node::printNode(list<Node*>::iterator itb, list<Node*>::iterator ite,int tab)
{
	if (itb==ite)//if empty return
	{
		return ;
	}
	else
	{
		for (int i = 0; i < tab; i++)//print the amount of tubs that needed
		{
			cout << "   ";
		}
		cout << (*itb)->content<<endl;//print the respons
	}
	if(!((*itb)->responses.empty()))//check if there are respons
		printNode((*itb)->responses.begin(), (*itb)->responses.end(), tab + 1);//print the respons for this node

	if (itb == ite)//check that the list didnt over
	{
		return;
	}
	else
	{
		printNode(++itb, ite, tab);//print the next node
	}
}
//the same like print node but with checking condition to stop printing
void Node::printNodeIf(list<Node*>::iterator itb, list<Node*>::iterator ite, int tab, string str)
{
	if (itb == ite || (*itb)->content.empty())
	{
		return;
	}
	else if((*itb)->content==str)//check the condition
	{
		for (int i = 0; i < tab; i++)
		{
			cout << "   ";
		}
		cout << (*itb)->content << endl;
		return;
	}
	else 
	{
		for (int i = 0; i < tab; i++)
		{
			cout << "   ";
		}
		cout << (*itb)->content << endl;
	}
	printNode((*itb)->responses.begin(), ite, tab + 1);

	if (itb == ite)
	{
		return;
	}
	else
	{
		printNode(itb++, ite, tab);
	}
}

void Node::printNodeToRoot(list<Node*>::iterator itb, list<Node*>::iterator ite, string str)
{
	if ((*itb)->content.empty())//empty node
	{
		return;
	}
	else
	{
		if ((*itb)->content == str)//if found return pointer
		{
			cout << str << "=> ";
			return;
		}

		//reqursive call to serche in the respons
		if (!(*itb)->responses.empty())
		{
			printNodeToRoot((*itb)->responses.begin(), (*itb)->responses.end(), str);
			cout << (*itb)->content<< "=> ";
			return;
		}

	}
}

void Node::delsubt(Node n)
{
}
