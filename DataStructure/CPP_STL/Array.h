#include"pch.h"


// �л� ���� ������ ����ü ����
// �л��� �̸�, �б������� ��� �ִ�
struct student
{
	string name;
	int standard;
};

// �л� ���� ���
ostream& operator<<(ostream& os, const student& s)
{
	return (os << "[" << s.name << ", " << s.standard << "]");
}


template<typename T>
class dynamic_array
{
	// array class�� �������ִ� ����
	T* data;
	size_t ArrSize;

public:
	// ũ�⸦ �޴� ������
	dynamic_array(int ArrSize)
	{
		this->ArrSize = ArrSize;
		data = new T[ArrSize];
	}

	// ���� ������
	dynamic_array(const dynamic_array<T>& other)
	{
		ArrSize = other.ArrSize;
		data = new T[ArrSize];

		for (int i = 0; i < ArrSize; i++)
			data[i] = other[i];
	}


	~dynamic_array()
	{
		delete[] data;	// �޸� �� ����
	}

public:
	
	// at�Լ� ���� at == []
	T& operator[] (int index) {return data[index];}
	

	const T& operator [](int index) const {return data[index];}

	T& at(int index)
	{
		if (index < ArrSize)
			return data[index];
		else
			throw "Index out of range";

	}

	// ������ ��ȯ �Լ�
	size_t size() const {return ArrSize;}


public:

	// �迭 ���� ���� �Լ� ����
	T* begin() {return data;}
	const T* begin() const {return data;}
	
	T* end() {return data + ArrSize; }
	const T* end() const {return data + ArrSize; }

public:

	// �ΰ��� �迭�� ���ϴ� ���� ����
	friend dynamic_array<T> operator + (const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
	{
		 dynamic_array<T> result(arr1.size() + arr2.size());
		 copy(arr1.begin(), arr1.end(), result.begin());
		 copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

		 return result;
	}
	
	// ���ڿ� ��ȯ �Լ� ���� (�⺻�� = , (��ǥ))
	string to_string(const string& sep = ", ")
	{
		if (ArrSize = 0)
			return "";


		ostringstream os;
		os << data[0];

		for (int i = 0; i < ArrSize; i++)
			os << sep << data[i];

		return os.str();
	}


private:

	
};



