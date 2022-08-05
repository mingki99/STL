// #include "Vector.h"
#include "Vector.h"

template<typename T>
void Vector<T>::push_back(const T& val)
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

template<typename T>
void  Vector<T>::reserve(int capacity)
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