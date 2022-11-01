#include "Tree.h"

Tree::Tree()
{
	this->discussion = new Node();

}

Node* Tree::search(string str)
{
	while()
	return null;
}
void Tree::addResponse(string father, string son)
{
	while()
}
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
