#include "Tree.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;
/*oz asban 207565607
binymin shapira 208965863
data structure 2 exercise 1
class for tree .cpp*/

Tree::Tree(string s)//ctor
{
	this->discussion->content = s;
	this->discussion = new Node();

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
	if (!dad)//adding the respons
	{
		Node newSon; 
		newSon.content = son;
		dad->responses.push_back(newSon);
	}
}

void Tree::delSubTree(string str)//delete the sub tree with the str content
{
	Node* root = search(str);//search the node withe the wanted content
	if (!root)//delete
	{
		delete root;
		root = nullptr;
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
		if (this->discussion->content.empty())//return if empty
		{
			return;
		}
		else if(this->discussion->content==str)//if the wanted title is in the root
		{
			cout << this->discussion->content<<endl;
			return;
		}
		else//if the title is not in the root, print the root and continue to the respons
		{
			cout << this->discussion->content << endl;
		}
		//reqursive func to print all comments until find the title(include)
		this->discussion->printNodeIf(this->discussion->responses.begin(), this->discussion->responses.end(), 1,str);
	}
}

void Tree::searchPrintLeaf(string str)//print the sub tree of wantwd title
{
	Node* subTree = search(str);//pointer to the wanted tree
	if (subTree)//if the node exist
	{
		cout << subTree->content << endl;//print root
		subTree->printNode(subTree->responses.begin(), subTree->responses.end(), 1);//print sub tree
	}
	return;
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
