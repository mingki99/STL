
#include <iostream>

#include <array>

using namespace std;

// ���� 3��
// ���ø����� ������ �������� �޾��ش�.
template<size_t size>
void print(array<int, size> arr)
{
	for (auto ele : arr)
		cout << ele << ", ";
}


int main()
{
	//// ���� 1��
	//array<int, 10> arr1;	// ũ�Ⱑ 10�� int Ÿ�� �迭 ����

	//arr1[0] = 1;	// ù��° ���Ҹ� 1�� ����

	//cout << "arr1�� ù��° ���� " << arr1[0] << endl;


	//array<int, 4> arr2 = {1, 2, 3, 4};

	//cout << "arr2�� ��� ����" ;

	//for (int i = 0; i < arr2.size(); i++)
	//	cout << arr2[i] ;

	//cout << endl;


	//// ���� 2��
	//// .at() �Լ��� �ε����� �Ȱ��� ����Ѵ� index = []
	
	//array<int, 4> arr3 = {1, 2, 3, 4};

	//try
	//{
	//	cout << arr3.at(3) << endl; // ���� �ƴ�
	//	cout << arr3.at(4) << endl; // out_of_range ���� �߻�
	//}
	//catch (const std::out_of_range& ex)
	//{
	//	cerr << ex.what() << endl;
	//}

	// ���� 3��
	// �迭�� �����ϱ�

	array<int, 5> arr = {1, 2, 3, 4, 5};
	// print(arr);
	
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		auto element = (*it);
		cout << element << " ";
	}


	return 0;
}
