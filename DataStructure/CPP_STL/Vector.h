#pragma once


#include "Iterator.h"

template<typename T>
class Vector
{
public:
	Vector() : _data(nullptr), _size(0), _capacity(0)
	{

	}

	~Vector()
	{
		if (_data)
			delete[] _data;
	}

public:

	void push_back(const T& val)
	{
		if (_size == _capacity)
		{
			// ���� �۾�
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		// ������ ����
		_data[_size] = val;

		// ������ ���� ����
		_size++;
	}

	

	void reserve(int capacity)
	{
		_capacity = capacity;

		T* newData = new T[_capacity];

		// ������ ����
		for (int i = 0; i < _size; i++)
			newData[i] = _data[i];

		// ���� ������ ������
		if (_data)
			delete[] _data;

		_data = newData;
	}
	
	// ���۷����� ��������
	// ���� �����ü� ������ �����Ͽ� ���� �־������� ���ϱ⶧����
	T& operator[](const int pos) { return _data[pos]; }

	int GetSize() { return _size; }
	int GetCapacity() { return _capacity; }

public:
	typedef Iterator<T> iterator;

	iterator begin() { return iterator(&_data[0]); }
	iterator end() { return begin() + _size; }


private:
	T* _data;
	int _size;
	int _capacity;

};

