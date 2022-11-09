#include "Tree.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;
/*oz asban 207565607
binymin shapira 208965863
data structure 2 exercise 1
class for tree .cpp*/

Tree::Tree(string s) //ctor
{
	this->discussion = new Node(s);
}

Node* Tree::search(string str)//searching string in the tree
{

	if (this->discussion->content == str)//if the root is the wanted str
	{
		return this->discussion;
	}
	if (this->discussion->responses.empty())//if there are no respons return null
	{
		return nullptr;
	}
	else//search in the respons
	{
		//reqursiv search function for node..returns pointer to the node
		return this->discussion->searchRec(this->discussion->responses.begin(), this->discussion->responses.end(), str);
	}
}


void Tree::addResponse(string father, string son)//adding respons (son) to the node that comtent father
{
	Node* dad = this->search(father);//return pointer to the father
	if (dad!=nullptr)//adding the respons
	{
		Node newSon(son);
		dad->responses.push_back(newSon);
	}
}

void Tree::delSubTree(string str)//delete the sub tree with the str content
{
	Node* root = search(str);//search the node withe the wanted content
	if (root!=nullptr)//delete
	{
		root->responses.clear();
		root->content.clear();
	}
}

void Tree::printTree()//print all tree
{
	if (this->discussion->content.empty())//if empty tree
	{
		return;
	}
	else//print the root content
	{
		cout << this->discussion->content<<endl;
	}
	//call riqursive print node func to print all the sub tree
	this->discussion->printNode(this->discussion->responses.begin(), this->discussion->responses.end(), 1);
	return;
}

void Tree::searchPrintRoot(string str)//search title in the tree and print all the way until find it
{
	if (search(str))//check if the node exist
	{
		Node* subtree = search(str);
		cout << subtree->content<<endl;
		subtree->printNode(subtree->responses.begin(), subtree->responses.end(), 1);
	}
}

void Tree::searchPrintLeaf(string str)//print the sub tree of wantwd title
{
	Node* subTree = search(str);//pointer to the wanted tree
	if (subTree)//if the node exist
	{

		if (this->discussion->content == str)//if the root is the wanted str
		{
			cout << str;
			return;
		}
		if (this->discussion->responses.empty())//if there are no respons return null
		{
			return;
		}
		else//search in the respons
		{
			//reqursiv search function for node..returns pointer to the node
			this->discussion->printNodeToRoot(this->discussion->responses.begin(), this->discussion->responses.end(), str);
			cout << this->discussion->content<<endl;
		}
	}
}


Tree::~Tree()//dtor
{
	delete discussion;
}

void Tree::buildNewRoot(string title)//build new root
{
	if (this->discussion->content.empty())//if the root is empty 
		this->discussion->content = title;
	else//if its not empty then delete the subtree andbuild new one
	{
		this->delSubTree(this->discussion->content);
		this->discussion->content = title;
	}
}
