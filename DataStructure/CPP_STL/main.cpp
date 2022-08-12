#include "pch.h"

#include <iostream>

#include "Array.h"
// #include <array>


int main()
{
	int iStudents;
	cout << "1�� �л� ���� �Է��ϼ��� : ";
	cin >> iStudents;

	// array�迭�� student ������ ���ʷ� ����.
	dynamic_array<student> class1(iStudents);
	for (int i = 0; i < iStudents; i++)
	{
		string name;
		int standard;

		cout << i + 1 << " ���� �л� �̸��� ���̸� �Է��ϼ���: ";
		cin >> name >> standard;
		class1[i] = student{name, standard};
	}
	

	// �迭 ũ�⺸�� ũ�� ���ܹ߻�
	try
	{
		class1.at(iStudents) = student{"John", 8};
	}
	catch (...)
	{
		cout << " ���� �߻�!" << endl;
	}


	// ���� ����
	auto class2 = class1;

	cout << "1���� �����Ͽ� 2�� ���� : " << class2.to_string() << endl;

	// �� �б��� ���ļ� ���ο� ū �б��� ����

	auto class3 = class1 + class2;

	cout << "1�ݰ� 2���� ���� 3�� ����" << class3.to_string() << endl;


	return 0;
}
