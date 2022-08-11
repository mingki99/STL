
#include <iostream>

#include <array>

using namespace std;

// 예제 3번
// 템플릿으로 사이즈 동적으로 받아준다.
template<size_t size>
void print(array<int, size> arr)
{
	for (auto ele : arr)
		cout << ele << ", ";
}


int main()
{
	//// 예제 1번
	//array<int, 10> arr1;	// 크기가 10인 int 타입 배열 선언

	//arr1[0] = 1;	// 첫번째 원소를 1로 설정

	//cout << "arr1의 첫번째 원소 " << arr1[0] << endl;


	//array<int, 4> arr2 = {1, 2, 3, 4};

	//cout << "arr2의 모든 원소" ;

	//for (int i = 0; i < arr2.size(); i++)
	//	cout << arr2[i] ;

	//cout << endl;


	//// 예제 2번
	//// .at() 함수는 인덱스와 똑같이 기능한다 index = []
	
	//array<int, 4> arr3 = {1, 2, 3, 4};

	//try
	//{
	//	cout << arr3.at(3) << endl; // 에러 아님
	//	cout << arr3.at(4) << endl; // out_of_range 예외 발생
	//}
	//catch (const std::out_of_range& ex)
	//{
	//	cerr << ex.what() << endl;
	//}

	// 예제 3번
	// 배열값 전달하기

	array<int, 5> arr = {1, 2, 3, 4, 5};
	// print(arr);
	
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		auto element = (*it);
		cout << element << " ";
	}


	return 0;
}
