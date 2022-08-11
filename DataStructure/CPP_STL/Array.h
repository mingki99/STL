#include"pch.h"

template<typename T>
class dynamic_array
{
public:
	// ũ�⸦ �޴� ������
	dynamic_array(int size)
	{
		this->size = size;
		data = new T[size];
	}

	// ���� ������
	dynamic_array(const dynamic_array<T>& other)
	{
		size = other.size;
		data = new T[size];

		for (int i = 0; i < size; i++)
			data[i] = other[i];
	}


	~dynamic_array()
	{
		delete[] data;	// �޸� �� ����
	}

public:
	
	// at�Լ� ���� at == []
	T& operator[] (int index) {return data[index];}
	

	const T& opertor[](int index) const {return data[index];}

	T& at(int index)
	{
		if (index < size)
			return data[index];
		else
			throw "Index out of range";

	}

	// ������ ��ȯ �Լ�
	size_t size() const {return size;}


public:

	// �迭 ���� ���� �Լ� ����
	T* begin() {return data;}
	const T* begin() {return data;}
	
	T* end() {return data + size; }
	const T* end() {return data + size; }

public:

	// �ΰ��� �迭�� ���ϴ� ���� ����
	friend dynamic_array<T> operator + (const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
	{
		 dynamic_array<T> result(add1.size() + add2.size());
		 copy(arr1.begin(), arr1.end(), result.begin());
		 copy(arr1.begin(), arr1.end(), result.begin() + arr1.size());

		 return result;
	}
	
	// ���ڿ� ��ȯ �Լ� ���� (�⺻�� = , (��ǥ))
	string to_string(const string& sep = ", ")
	{
		if (size = 0)
			return "";


		ostringstream os;
		os << data[0];

		for (int i = 0; i < size; i++)
			os << sep << data[i];

		return os.str();
	}


private:
	T* data;
	size_t size;
};



