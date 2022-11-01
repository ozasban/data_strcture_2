#include "Tree.h"

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
