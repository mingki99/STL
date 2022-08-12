#include "pch.h"

#include <iostream>

#include "Array.h"
// #include <array>


int main()
{
	int iStudents;
	cout << "1반 학생 수를 입력하세요 : ";
	cin >> iStudents;

	// array배열에 student 정보가 차례로 들어간다.
	dynamic_array<student> class1(iStudents);
	for (int i = 0; i < iStudents; i++)
	{
		string name;
		int standard;

		cout << i + 1 << " 번쨰 학생 이름과 나이를 입력하세요: ";
		cin >> name >> standard;
		class1[i] = student{name, standard};
	}
	

	// 배열 크기보다 크면 예외발생
	try
	{
		class1.at(iStudents) = student{"John", 8};
	}
	catch (...)
	{
		cout << " 예외 발생!" << endl;
	}


	// 깊은 복사
	auto class2 = class1;

	cout << "1반을 복사하여 2반 생성 : " << class2.to_string() << endl;

	// 두 학급을 합쳐서 새로운 큰 학급을 생성

	auto class3 = class1 + class2;

	cout << "1반과 2반을 합쳐 3반 생성" << class3.to_string() << endl;


	return 0;
}
