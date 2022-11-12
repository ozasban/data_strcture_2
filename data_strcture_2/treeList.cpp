#include "treeList.h"

/*oz asban 207565607
binymin shapira 208965863
data structure 2 exercise 1
class for treeList.cpp*/

treeList::~treeList()
{
	//delete dynamic space
	for (auto it = trees.begin(); it != trees.end(); it++)
	{
		(*it)->~Tree();
		
	}
	//delete the pointer in the list
	trees.erase(trees.begin(), trees.end());
}

void treeList::addNewTree(string s)
{
	//addNewTree
	Tree* t1 = new Tree(s);
	trees.push_front(t1);
}

void treeList::deleteTree(Tree* t)
{
	t->~Tree();
}

void treeList::searchAndPrint(string val)
{
	
	for (auto it = trees.begin(); it != trees.end(); it++)
	{
		if ((*it)->search(val))
		{
			(*it)->searchPrintRoot(val);//print from "val" until leaf
			(*it)->searchPrintLeaf(val);// print until root froom val
		}
		
	} 
}

bool treeList::addResponse(string rt, string prnt, string res)
{
	for (auto it = trees.begin(); it != trees.end(); it++)
	{
		if ((*it)->discussion->content == rt )//if content == "rt"
		{	
			if ((*it)->search(prnt))//if "prnt" found
			{
				(*it)->addResponse(prnt, res);//add response
				return true;
			}
		}
	}
	return false;
}

bool treeList::delResponse(string rt, string res)
{
	for (auto it = trees.begin(); it != trees.end(); it++)//if content == "rt"
	{
		if ((*it)->discussion->content == rt)
		{
			if ((*it)->discussion->content == res)
			{
				this->trees.remove(*it);
				return true;
			}
			else if ((*it)->search(res))//if "res" found
			{
				(*it)->delSubTree(res);
				return true;
			}
		}
	}

	return false;
}

void treeList::printTree(string rt)
{
	for (auto it = trees.begin(); it != trees.end(); it++)
	{
		if ((*it)->discussion->content == rt)//if content == "rt"
		{
			(*it)->printTree();
			return;
		}
	}
}

void treeList::printAllTrees()
{
	int treenum = 1;
	for (auto it = trees.begin(); it != trees.end(); it++)
	{
		cout << "Tree #" << treenum<<endl;
		(*it)->printTree();
		treenum++;
	}
}

void treeList::printSubTree(string rt, string s)
{
	for (auto it = trees.begin(); it != trees.end(); it++)
	{
		if ((*it)->discussion->content == rt)//if content == "rt"
		{
			(*it)->searchPrintRoot(s);
			(*it)->searchPrintLeaf(s);
			return;
		}	
	}

}
