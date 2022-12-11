#pragma once
// C++ program to demonstrate auto-complete feature 
// using Trie data ure. 
#include <iostream>
#include <string>
using namespace std;
/*
oz asban 207565607
binymin shapira 208965863
data structure 2 exercise 3
class for trie  .h
*/

// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (26) 

// Converts key current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
// Converts childrens current index into character
// use only 'a' through 'z' and lower case 
#define INDEX_TO_CHAR(c) ((char)((int)c + (int)'a')) 

// trie node 
struct TrieNode
{
	TrieNode* children[ALPHABET_SIZE];
	TrieNode* parent;

	// isWordEnd is true if the node represents 
	// end of a word 
	bool isWordEnd;
};


TrieNode* getNode(void);
bool isLastNode(TrieNode* Root);
bool insertT(TrieNode* Root, string key);
bool isLowerCase(string key);
bool delT(TrieNode* Root, string key);
//bool delR(TrieNode* prev, TrieNode* root, string key, int ind);
bool searchT(TrieNode* Root, string key);
void suggestionsRec(TrieNode* Root, string currPrefix);
int printAutoSuggestionsT(TrieNode* Root, string query);
void printT(TrieNode* t, int level);
bool haveNoChildren(TrieNode* Root);



class Trie
{
	TrieNode* root;

public:
	Trie() { root = getNode(); }
	bool insert(string wrd) { return insertT(root, wrd); }
	bool delW(string wrd) { return delT(root, wrd); }
	int printAutoSuggestions(string wrd) { return printAutoSuggestionsT(root, wrd); }
	bool search(string key) { return searchT(root, key); }
	void printTrie() { printT(root, 0); }

};