// #include "Vector.h"
#include "Vector.h"

template<typename T>
void Vector<T>::push_back(const T& val)
{
	if (_size == _capacity)
	{
		// 증설 작업
		int newCapacity = static_cast<int>(_capacity * 1.5);
		if (newCapacity == _capacity)
			newCapacity++;

		reserve(newCapacity);
	}

	// 데이터 저장
	_data[_size] = val;

	// 데이터 개수 증가
	_size++;
}

template<typename T>
void  Vector<T>::reserve(int capacity)
{
	_capacity = capacity;

	T* newData = new T[_capacity];

	// 데이터 복사
	for (int i = 0; i < _size; i++)
		newData[i] = _data[i];

	// 기존 데이터 날리기
	if (_data)
		delete[] _data;

	_data = newData;
}