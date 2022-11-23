#include "HSubject.h"
/*
oz asban 207565607
binymin shapira 208965863
data structure 2 exercise 2
class for HSubject .cpp
*/

/// <summary>
/// print one subject 
/// </summary>
/// <param name="ky">string</param>
void HSubject::printS(string ky)
{
	int index = this->search(ky);
	//if found
	if (index != -1)
	{
		cout << "Subject " << ky << " " << arr[index].data.size() << " topics:" << endl;
		//iterator that run about all the array
		for (auto i = arr[index].data.begin(); i != arr[index].data.end(); i++)
		{
			cout << *i << " ";
		}
		cout << endl;

	}
	else//if not found
	{
		cout << "ERROR" << endl;
	}
}
/// <summary>
/// print one subject according "N"
/// </summary>
/// <param name="ky">string </param>
/// <param name="N">int</param>
void HSubject::printN(string ky, int N)
{
	int index = this->search(ky);
	if (index != -1)//if found
	{
		auto j = arr[index].data.begin();
		//iterator that run about part off the array according "N"
		for (int i = 0; i < N && j != arr[index].data.end(); i++)
		{
			cout << *j << " ";
			j++;
		}
		cout << endl;

	}
	else//if not found
	{
		cout << "ERROR" << endl;
	}
}
/// <summary>
/// print all the HSubject
/// </summary>
void HSubject::print()
{
	cout << "All subjects and titles:" << endl;
	//for sort the list
	list<string> l1;
	//if the index isn't empty push it to the list "l1"
	for (int i = 0; i < this->size; i++)
	{
		if (arr[i].flag == full)
		{
			l1.push_front(arr[i].key);
		}
	}
	//sort l1
	l1.sort();
	//print
	for (auto i = l1.begin(); i != l1.end(); i++)
	{
		int index = this->search(*i);
		cout << arr[index].key << ": ";
			for (auto j = arr[index].data.begin(); j != arr[index].data.end(); j++)
			{
				cout << *j << " " ;
			}
			cout << endl;

	}

}
/// <summary>
/// Initializes the array
/// </summary>
void HSubject::startNewTable()
{
	for (int i = 0; i < size; i++)
	{
		arr[i].flag = empty;
		arr[i].data.clear();
		arr[i].key.clear();
		
	}
}
/// <summary>
/// add Subject And Title to HSubject
/// </summary>
/// <param name="s"></param>
/// <param name="t"></param>
void HSubject::addSubjectAndTitle(string s, string t)
{

	int index = this->search(s);
	if (index != -1)
	{
		this->arr[index].data.push_front(t);
	}
	else
	{
		list<string> l1;
		l1.push_front(t);
		this->add(s, l1);
	}
}
