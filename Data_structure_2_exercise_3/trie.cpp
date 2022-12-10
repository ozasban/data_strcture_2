#include "trie.h"
#include <iostream>
#include <string>
#include <algorithm>
/// <summary>
/// returns new empty nodetrie
/// </summary>
/// <param name=""></param>
/// <returns></returns>
TrieNode* getNode(void)
{   
    return new TrieNode;
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
            root->children[CHAR_TO_INDEX(key[i])] = new TrieNode;
            root->children[CHAR_TO_INDEX(key[i])] = root;
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
        TrieNode* lastL;//get pointer to the last node in the string
        for (int i = 0; i < key.length(); i++)
        {
            root = root->children[CHAR_TO_INDEX(key[i])];
            if (i == key.length() - 1)
                lastL = root;    
        }
         
       //if the last letter have no childrens delete the node
        if (haveNoChildren(lastL))
        {
            TrieNode* temp = lastL;
            lastL = lastL->parent;
            temp = nullptr;
            //if the parent have no children do the same
            for (int i = 0; i < key.length() - 1; i++)
            {
                if (haveNoChildren(lastL))
                {
                    TrieNode* temp = lastL;
                    lastL = lastL->parent;
                    temp = nullptr;
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

