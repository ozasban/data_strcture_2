#include "HSubject.h"

void HSubject::printS(string ky)
{
	int index = this->search(ky);
	if (index != -1)
	{
		cout << "Subject " << ky << " " << arr[index].data.size() << " topics:" << endl;
		for (auto i = arr[index].data.begin(); i != arr[index].data.end(); i++)
		{
			cout << *i << " ";
		}
		cout << endl;
		///Subject subject1 4 topics:
		///title4 title3 title2 title1

	}
	else
	{
		cout << "ERROR" << endl;
	}
}

void HSubject::printN(string ky, int N)
{
	int index = this->search(ky);
	if (index != -1)
	{
		auto j = arr[index].data.begin();
		for (int i = 0; i < N; i++)
		{
			cout << *j << " " << endl;
		}
		///Subject subject1 4 topics:
		///title4 title3 title2 title1

	}
	else
	{
		cout << "ERROR" << endl;
	}
}

void HSubject::print()
{
	cout << "All subjectsand titles:" << endl;

	list<string> l1;
	for (int i = 0; i < this->size; i++)
	{
		if (arr[i].flag == full)
		{
			l1.push_front(arr[i].key);
			/*cout << arr[i].key << ": ";
			for (auto j = arr[i].data.begin(); j != arr[i].data.end(); i++)
			{
				cout << *j << " " ;
			}
			cout << endl;*/

		}
	}
	l1.sort();
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
	///ואם לא עובד לעשות reverse
}

void HSubject::startNewTable()
{
	for (int i = 0; i < size; i++)
	{
		arr[i].flag = empty;
		arr[i].data.clear();
		arr[i].key.clear();
		
	}
}

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
