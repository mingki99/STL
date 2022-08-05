
#include <iostream>
#include <vector>


using namespace std;

template<typename T>
class Iterator
{
public:
	Iterator() : _ptr(nullptr)
	{
		
	}

	Iterator(T* ptr) : _ptr(ptr)
	{

	}

	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator temp = *this;
		_ptr++;

		return temp;
		
	}

	Iterator& operator--()
	{
		_ptr--;
		return *this;
	}

	Iterator operator--(int)
	{
		Iterator temp = *this;
		_ptr--;

		return temp;

	}

	Iterator operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}

	Iterator operator-(const int count)
	{
		Iterator temp = *this;
		temp._ptr -= count;
		return temp;
	}

	bool operator==(const Iterator& right)
	{
		return _ptr == right._ptr;
	}


	bool operator!=(const Iterator& right)
	{
		return !(*this == right);
	}

	T& operator*()
	{
		return *_ptr;
	}

	~Iterator()
	{

	}


public:
	T* _ptr;

};

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

	void reserve(int capacity)
	{
		_capacity = capacity;

		T* newData = new T[_capacity];

		// 데이터 복사
		for (int i = 0; i < _size; i++)
			newData[i] = _data[i];

		// 기존 데이터 날리기
		if(_data)
			delete[] _data;

		_data = newData;
	}

	// 레퍼런스로 만든이유
	// 값을 가져올순 있지만 접근하여 값을 넣어주지는 못하기때문에
	T& operator[](const int pos) {return _data[pos];}

	int GetSize() {return _size;}
	int GetCapacity() {return _capacity;}

public:
	typedef Iterator<T> iterator;

	iterator begin() {return iterator(&_data[0]); }
	iterator end() { return begin()+ _size; }


private:
	T* _data;
	int _size;
	int _capacity;

};


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
		cout << v[i] <<endl;
	}

	cout << "-------------------------" <<endl;

	for (Vector<int>::iterator it = v.begin(); it != v.end() ; ++it)
	{
		cout << (*it) << endl;
	}
}
