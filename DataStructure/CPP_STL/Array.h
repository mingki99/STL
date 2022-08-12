#include"pch.h"


// 학생 정보 저장할 구조체 정의
// 학생의 이름, 학급정보를 담고 있다
struct student
{
	string name;
	int standard;
};

// 학생 정보 출력
ostream& operator<<(ostream& os, const student& s)
{
	return (os << "[" << s.name << ", " << s.standard << "]");
}


template<typename T>
class dynamic_array
{
	// array class가 가지고있는 정보
	T* data;
	size_t ArrSize;

public:
	// 크기를 받는 생성자
	dynamic_array(int ArrSize)
	{
		this->ArrSize = ArrSize;
		data = new T[ArrSize];
	}

	// 복사 생성자
	dynamic_array(const dynamic_array<T>& other)
	{
		ArrSize = other.ArrSize;
		data = new T[ArrSize];

		for (int i = 0; i < ArrSize; i++)
			data[i] = other[i];
	}


	~dynamic_array()
	{
		delete[] data;	// 메모리 릭 방지
	}

public:
	
	// at함수 구현 at == []
	T& operator[] (int index) {return data[index];}
	

	const T& operator [](int index) const {return data[index];}

	T& at(int index)
	{
		if (index < ArrSize)
			return data[index];
		else
			throw "Index out of range";

	}

	// 사이즈 반환 함수
	size_t size() const {return ArrSize;}


public:

	// 배열 원소 접근 함수 구현
	T* begin() {return data;}
	const T* begin() const {return data;}
	
	T* end() {return data + ArrSize; }
	const T* end() const {return data + ArrSize; }

public:

	// 두개의 배열을 더하는 연산 정의
	friend dynamic_array<T> operator + (const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
	{
		 dynamic_array<T> result(arr1.size() + arr2.size());
		 copy(arr1.begin(), arr1.end(), result.begin());
		 copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

		 return result;
	}
	
	// 문자열 반환 함수 정의 (기본값 = , (쉼표))
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



