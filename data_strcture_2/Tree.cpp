#include "Tree.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;


Tree::Tree()
{
	this->discussion = new Node();

}

Node* Tree::search(string str)
{

	if (this->discussion->content == str)
	{
		return this->discussion;
	}
	if (this->discussion->responses.empty())
	{
		return nullptr;
	}
	else
	{
		return this->discussion->searchRec(this->discussion->responses.begin(), str);
	}
}
		//if (this->discussion->content == str)
		//	return this->discussion;
		//else
		//{
		//	Auto it1 = this->discussion->responses.begin();
		//	while (it1 != this->discussion->responses.end())
		//	{
		//		it1->
		//	}
		//}
	
		//return null;


Tree::~Tree()
{
	delete discussion;
}

void Tree::buildNewRoot(string title)
{
	if (this->discussion->content.empty())
		this->discussion->content = title;
	else
		this->delSubTree(this->discussion->content);
}
