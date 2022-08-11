#include "pch.h"

#include <iostream>


#include <array>


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
	

	return 0;
}
