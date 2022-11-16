#include <stdio.h>
#include <iostream>
#include <math.h>

#include "MuSoenMath.h"

void main() 
{
	Math::mat3 Translate, Scale;
	Math::vec3 v(1, 1, 1);
	Math::vec1x3 vx(1, 1, 1);
	
	Math::mat4 Translatef, Scalef;
	Math::vec4 vf(1, 1, 1, 1);
	Math::vec1x4 vxf(1, 1, 1, 1);

	Translate = Math::mat3(
		1, 0, 3,
		0, 1, 5,
		0, 0, 1
	);

	Scale = Math::mat3(
		2, 0, 0,
		0, 2, 0,
		0, 0, 1
	);

	Translatef = Math::mat4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		3, 5, 2, 1
	);

	Scalef = Math::mat4(
		2, 0, 0, 0,
		0, 2, 0, 0,
		0, 0, 2, 0,
		0, 0, 0, 2
	);

	cout << "mat3 ��" << endl;;

	cout << "��Ÿ�� ���� ��"<<endl;

	cout << "v";
	v = Translate * Scale * v;
	v.Print();

	cout << "vx";
	vx = Translate * Scale * vx;
	vx.Print();
	
	cout << "��Ÿ�� ���� ��" << endl;

	Math::vec3 p(1,1,1);
	p = p * Translate * Scale;
	p.Print();

	Math::vec1x3 px(1,1,1);
	
	px = px * Translate * Scale;
	px.Print();

	cout << endl;

	cout << "mat4 ��" << endl;;

	cout << "��Ÿ�� ���� ��" << endl;

	cout << "vf";
	vf = Translatef * Scalef * vf;
	vf.Print();

	cout << "vxf";
	vxf = Translatef * Scalef * vxf;
	vxf.Print();

	cout << "��Ÿ�� ���� ��" << endl;

	Math::vec4 pf(1,1,1,1);
	pf = pf * Translatef * Scalef;
	pf.Print();

	Math::vec1x4 pxf(1,1,1,1);
	pxf = pxf * Translatef * Scalef;
	pxf.Print();

	cout << endl;

	cout << "vec3 ����" << endl;;

	Math::vec3 vo1(2, 1, 1);

	cout << "vo1 ";
	vo1 = vo1 * 6.f + vo1 / 6.f - vo1;
	vo1.Print();

	cout << "vec4 ����" << endl;;

	Math::vec4 vo1f(2, 1, 1,5);

	cout << "vo1f ";
	vo1f = vo1f * 6.f + vo1f / 6.f - vo1f;
	vo1f.Print();
}