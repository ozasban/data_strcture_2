#pragma once
#include <iostream>
#include <string>
using namespace std;

/*
oz asban 207565607
binymin shapira 208965863
data structure 2 exercise 2
class for tamplate "HashTable"
*/

template <class T, class K>
class HashTable
{
protected:
	//data
	enum state { empty, full, deleted };
	template <class U, class V>
	class Item
	{
	public:
		U data;
		V key;
		state flag;
		Item() {}
		Item(U d, V k, state f) { data = d; key = k; flag = f; }
	};


	int size;
	Item<T, K>* arr;
	//methods
	bool prime(int n);//+
	int hash(K key, int i);
	virtual int h1(K key) = 0;
	virtual int h2(K key) = 0;
public:
	HashTable(int m = 10);//+
	~HashTable();//+
	void add(K& key, T& dat);
	int remove(K key);//+
	int search(K key);
	T* entryData(K i)
	{
		int ind = search(i);
		if (ind == -1)
			return NULL;
		else
			return &(arr[ind].data);
	}
	virtual void print() = 0;
};
/// <summary>
/// returns if n is prime
/// </summary>

template<class T, class K>
bool HashTable<T, K>::prime(int n)
{
	bool is_prime = true;
	if (n == 0 || n == 1) {
		return false;
	}

	// loop to check if n is prime
	for (int i = 2; i <= n / 2; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return is_prime;
}
/// <summary>
/// the hash function
/// </summary>

template<class T, class K>
int HashTable<T, K>::hash(K key, int i)
{
	return (h1(key) + i * h2(key)) % size;

}
/// <summary>
/// build a hashtable with the closest prime num to m
/// </summary>

template<class T, class K>
HashTable<T, K>::HashTable(int m)
{
	//find the closest prime number
	int i;
	for (i = m; !prime(i); i++)
	{
	}
	this->size = i;
	this->arr = new Item<T, K>[size];

}
//dtor
template<class T, class K>
HashTable<T, K>::~HashTable()
{
	delete[] arr;

}
/// <summary>
/// adding organ to the hashTable in the correct place
/// </summary>

template<class T, class K>
void HashTable<T, K>::add(K& key, T& dat)
{
	int i = 0, j = 0;
	while (i < (size))
	{
		j = hash(key, i);
		if (arr[j].flag != full)//do the input only if not full
		{
			arr[j].key = key;
			arr[j].data = dat;
			arr[j].flag = full;
			return;
		}
		else
			i++;

	}
	cout << "hashTable overflow" << endl;
}
/// <summary>
/// searching item in the table return -1 if not found
/// </summary>

template<class T, class K>
int HashTable<T, K>::search(K key)
{
	int i = 0, j = hash(key, i);
	while (i < (size) && arr[j].flag != empty)
	{
		j = hash(key, i);
		if (arr[j].key == key)
		{
			if (arr[j].flag == deleted)
			{
				return -1;
			}
			return j;
		}
		else
		{
			i++;
			j = hash(key, i);
		}

	}
	return -1;
}
/// <summary>
/// remove item from the table
/// </summary>

template<class T, class K>
inline int HashTable<T, K>::remove(K key)
{
	int index = this->search(key);
	if (index != -1)
	{
		arr[index].flag = deleted;
		return 1;
	}

	return -1;
}