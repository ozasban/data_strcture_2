#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Node
{
	string content;
	list <Node> responses;
};