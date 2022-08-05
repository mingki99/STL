
#include <iostream>
#include "Vector.h"


using namespace std;


int main()
{
	Vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v.GetSize() << " " << v.GetCapacity() << endl;
	}

	for (int i = 0; i < v.GetSize(); i++)
	{
		cout << v[i] << endl;
	}

	cout << "-------------------------" << endl;

	for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << endl;
	}
}