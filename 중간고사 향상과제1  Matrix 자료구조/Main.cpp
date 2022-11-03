#include <stdio.h>
#include <iostream>
#include <math.h>

#include "MuSoenMath.h"

void main() {

	//3X1 ���� v
	Math::vec3 v;

	//  | 2 |
	//	| 1 |
	//	| 1 |
	v = Math::vec3(2, 1);

	cout << "v";
	v.Print();

	Math::mat3 Translate, Rotate, Scale;

	Math::mat3 Result;

	//(3,5) ��ŭ �̵��� �̵� ���
	Translate = Math::mat3(
		1, 0, 3,
		0, 1, 5,
		0, 0, 1
	);

	cout << "Translate";
	Translate.Print();

	//30�� ȸ���� ���� ȸ�� ���
	Rotate = Math::mat3(
		cos(30), -sin(30), 0,
		sin(30), cos(30), 0,
		0, 0, 1
	);

	cout << "Rotate";
	Rotate.Print();

	//2�� Ȯ�븦 ���� Ȯ�� ���
	Scale = Math::mat3(
		2, 0, 0,
		0, 2, 0,
		0, 0, 1
	);

	cout << "Scale";
	Scale.Print();

	//����
	Math::vec3 p = v * Translate * Rotate * Scale;

	//��� ���
	cout << "p";
	p.Print();
}