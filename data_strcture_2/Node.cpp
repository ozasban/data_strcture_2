#include "Node.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;



Node* Node::searchRec(list<Node>::iterator it , string str)
{
	if (it->content.empty())
	{
		return nullptr;
	}
	else
	{
		if (it->content == str)
			return &(*it);

		Node* tNode = searchRec(it->responses.begin(), str);

		if (tNode)
		{
			return tNode;
		}

		//auto it1 =  it->responses.begin();

		return searchRec( it++, str);

	}
}
