#include "trie.h"
#include <iostream>
#include <string>
#include <algorithm>
/*
oz asban 207565607
binymin shapira 208965863
data structure 2 exercise 3
class for trie  .cpp
*/

/// <summary>
/// returns new empty nodetrie
/// </summary>
/// <param name=""></param>
/// <returns></returns>
TrieNode* getNode(void)
{   
    TrieNode* tr= new TrieNode;
    tr->parent = nullptr;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        tr->children[i] = nullptr;
    tr->isWordEnd = false;
    return tr;
}
/// <summary>
/// return true if node is last letter in woed
/// </summary>
/// <param name="root"></param>
/// <returns></returns>
bool isLastNode(TrieNode* root)
{
    if (root->isWordEnd)
        return true;
    else
        return false;
}
/// <summary>
/// insert new word to the tree
/// </summary>
/// <param name="root"></param>
/// <param name="key"></param>
/// <returns></returns>
bool insertT(TrieNode* root, string key)
{
    //check if its a legal word
    if (!isLowerCase(key))
        return false;
    //run all the chars in key
    for (int i = 0; i < key.length(); i++)
    {
        //if ther is allready a word with this letter continue to next letter
        if (root->children[CHAR_TO_INDEX(key[i])] != nullptr)
        {
            root = root->children[CHAR_TO_INDEX(key[i])];
            if (i == (key.length() - 1))
            {
                root->isWordEnd = true;
                return true;
            }
        }
        //else build the word
        else
        {
            root->children[CHAR_TO_INDEX(key[i])] = getNode();
            root->children[CHAR_TO_INDEX(key[i])]->parent = root;
            root = root->children[CHAR_TO_INDEX(key[i])];
            if (i == (key.length() - 1))
            {
                root->isWordEnd = true;
                return true;
            }
        }
    }
    return false;
}
/// <summary>
/// return true if all letters in string are lowerCase
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
bool isLowerCase(string key)
{
    for (int i = 0; i < key.length(); i++)
    {
        if (!islower(key[i]))
            return false;
    }
    return true;
}
/// <summary>
/// method to delete word
/// </summary>
/// <param name="root"></param>
/// <param name="key"></param>
/// <returns></returns>
bool delT(TrieNode* root, string key)
{
    //if the word is exist delete
    if (searchT(root, key))
    {
        TrieNode* lastL=getNode();//get pointer to the last node in the string
        for (int i = 0; i < key.length(); i++)
        {
            root = root->children[CHAR_TO_INDEX(key[i])];
            if (i == key.length() - 1)
                lastL = root;    
        }
         
       //if the last letter have no childrens delete the node
        if (haveNoChildren(lastL))
        {
           
            lastL = lastL->parent;
            lastL->children[CHAR_TO_INDEX(key[key.length() - 1])] = nullptr;
            
            //if the parent have no children do the same
            for (int i = 0; i < key.length() - 1&&!lastL->isWordEnd; i++)
            {
                if (haveNoChildren(lastL))
                {
                    
                    lastL = lastL->parent;
                    lastL->children[CHAR_TO_INDEX(key[key.length() - i - 2])] = nullptr;
                    
                }
                else
                    break;

            }
        }
        else//just tell that there is no word that end in this node
            lastL->isWordEnd = false;
        return true;
    }
    
}
/// <summary>
/// return true if the word exist in the tree
/// </summary>
/// <param name="root"></param>
/// <param name="key"></param>
/// <returns></returns>
bool searchT(TrieNode* root, string key)
{
    //run on all the word
    for (int i = 0; i < key.length(); i++)
    {
        //if sun exist continue
        if (root->children[CHAR_TO_INDEX(key[i])] != nullptr)
        {
            root = root->children[CHAR_TO_INDEX(key[i])];
            if (i == key.length() - 1)//check if its end of word
                if (!root->isWordEnd)//if there is no such a word
                    return false;
        }
        //if no such a son exist
        else
            return false;
    }
    return true;
}
/// <summary>
/// recursive method to print all the sub trees for preword
/// </summary>
/// <param name="root"></param>
/// <param name="currPrefix"></param>
void suggestionsRec(TrieNode* root, string currPrefix)
{
    //if its a leef print the word and return
    if (haveNoChildren(root)&& root->isWordEnd)
    {
        cout << currPrefix << endl;
        return;
    }
    //if it is and of word but not a leef print and continue
    else if (root->isWordEnd)
    {
        cout << currPrefix << endl;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (root->children[i] != nullptr)
                suggestionsRec(root->children[i], currPrefix + INDEX_TO_CHAR(i));
        }
    }
    //if its a midle of a word continue
    else
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (root->children[i] != nullptr)
                suggestionsRec(root->children[i], currPrefix + INDEX_TO_CHAR(i));
        }
    }
}
/// <summary>
/// get start of a string and compleete it
/// </summary>
/// <param name="root"></param>
/// <param name="query"></param>
/// <returns></returns>
int printAutoSuggestionsT(TrieNode* root, string query)
{
    //find tha last latter to start searching and printing from ther
    for (int i = 0; i < query.length(); i++)
    {
        if (root->children[CHAR_TO_INDEX(query[i])] != nullptr)
            root = root->children[CHAR_TO_INDEX(query[i])];
        else
            return 0;
    }
    suggestionsRec(root, query);
}
/// <summary>
/// print all tree in recursion
/// </summary>
/// <param name="t"></param>
/// <param name="level"></param>
void printT(TrieNode* t, int level)
{
    //print all childrens in orde
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        //if the son exist print and check hus childrens
        if (t->children[i] != nullptr)
        {
            for (int i = 0; i < level; i++)
                cout << " ";
            cout << INDEX_TO_CHAR(i) << ":" << endl;
            printT(t->children[i], level + 1);
        }
    }
    return;
}
/// <summary>
/// return true if have no childrens
/// </summary>
/// <param name="root"></param>
/// <returns></returns>
bool haveNoChildren(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i] != nullptr)
            return false;
    }
    return true;
}

