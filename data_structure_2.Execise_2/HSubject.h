#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;
#include "HashTable.h"

/*
oz asban 207565607
binymin shapira 208965863
data structure 2 exercise 2
class for "HSubject" that hirited from class HashTable<list<string>, string>

*/


const int MAX = 1000;



class HSubject :public HashTable<list<string>, string>
{
	//private:
	int key(string s) { return (int)s[0] + (int)s[1] + (int)s[s.length() - 1]; }

public:
	HSubject(int n) :HashTable <list<string>, string>(n) {}
	int h1(string s) { return key(s) % size; }
	int h2(string s) { return (key(s) % (size - 1) + 1) % size; }
	void printS(string ky);
	void printN(string ky, int N);
	void print();
	void startNewTable();
	void addSubjectAndTitle(string s, string t);
};