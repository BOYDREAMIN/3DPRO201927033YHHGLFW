#pragma once
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
namespace Math{

	//3X3���
	class mat3{
	public: 	
		//3X3�迭
		float matrix[3][3];

		//�ܼ� �����ϋ�
		mat3(){
			matrix[0][0] = 1;
			matrix[0][1] = 0;
			matrix[0][2] = 0;
			matrix[1][0] = 0;
			matrix[1][1] = 1;
			matrix[1][2] = 0;
			matrix[2][0] = 0;
			matrix[2][1] = 0;
			matrix[2][2] = 1;
		}

		//3X3�迭 �Է� �� �ʱ�ȭ
		mat3(float a, float b, float c,
				float d, float e, float f,
				float g, float h, float i)
		{
			matrix[0][0] = a;
			matrix[0][1] = b;
			matrix[0][2] = c;
			matrix[1][0] = d;
			matrix[1][1] = e;
			matrix[1][2] = f;
			matrix[2][0] = g;
			matrix[2][1] = h;
			matrix[2][2] = i;
		}

		//��ġ
		void Transpose()
		{
			//�����ͼ� �ϵ��ڵ�
			float translate;

			translate = matrix[0][1];
			matrix[0][1] = matrix[1][0];
			matrix[1][0] = translate;

			translate = matrix[0][2];
			matrix[0][2] = matrix[2][0];
			matrix[2][0] = translate;

			translate = matrix[1][2];
			matrix[1][2] = matrix[2][1];
			matrix[2][1] = translate;
		}
		
		//��� 0 ���� �ʱ�ȭ
		void InitMat()
		{
			matrix[0][0] = 0;
			matrix[0][1] = 0;
			matrix[0][2] = 0;
			matrix[1][0] = 0;
			matrix[1][1] = 0;
			matrix[1][2] = 0;
			matrix[2][0] = 0;
			matrix[2][1] = 0;
			matrix[2][2] = 0;
		}

		//��� Ȯ���� ���� ���
		void Print()
		{
			cout << " - Matrix3" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << "|";
				for (int j = 0; j < 3; j++)
				{
					cout << matrix[i][j];
					if ((j + 1) / 3 != 1)
						cout << " ";
					else if ((j + 1) / 3 == 1) {
						cout << "|";
						cout << endl;
					}
				}
			}
			cout << endl;
		}

	};

	//4X4���
	class mat4 {
	public :
		
		//4X4�迭
		float matrix[4][4];

		//�ܼ� �����ϋ� 1�ʱ�ȭ 
		mat4() {
			matrix[0][0] = 1;
			matrix[0][1] = 0;
			matrix[0][2] = 0;
			matrix[0][3] = 0;
			matrix[1][0] = 0;
			matrix[1][1] = 1;
			matrix[1][2] = 0;
			matrix[1][3] = 0;
			matrix[2][0] = 0;
			matrix[2][1] = 0;
			matrix[2][2] = 1;
			matrix[2][3] = 0;
			matrix[3][0] = 0;
			matrix[3][1] = 0;
			matrix[3][2] = 0;
			matrix[3][3] = 1;	
		}

		//4X4�迭 �Է� �� �ʱ�ȭ
		mat4(float a, float b, float c, float d, 
			 float e, float f, float g, float h, 
			 float i, float j, float k, float l,
			 float m, float n, float o, float p)
		{
			matrix[0][0] = a;
			matrix[0][1] = b;
			matrix[0][2] = c;
			matrix[0][3] = d;
			matrix[1][0] = e;
			matrix[1][1] = f;
			matrix[1][2] = g;
			matrix[1][3] = h;
			matrix[2][0] = i;
			matrix[2][1] = j;
			matrix[2][2] = k;
			matrix[2][3] = l;
			matrix[3][0] = m;
			matrix[3][1] = n;
			matrix[3][2] = o;
			matrix[3][3] = p;
		}

		void Transpose()
		{
			float translat;

			//�����ͼ� �ϵ��ڵ�
			float translate;

			translate = matrix[0][1];
			matrix[0][1] = matrix[1][0];
			matrix[1][0] = translate;

			translate = matrix[0][2];
			matrix[0][2] = matrix[2][0];
			matrix[2][0] = translate;

			translate = matrix[0][3];
			matrix[0][3] = matrix[3][0];
			matrix[3][0] = translate;

			translate = matrix[1][3];
			matrix[1][3] = matrix[3][1];
			matrix[3][1] = translate;

			translate = matrix[2][3];
			matrix[2][3] = matrix[3][2];
			matrix[3][2] = translate;
		}

		//��� 0 ���� �ʱ�ȭ
		void InitMat()
		{
			matrix[0][0] = 0;
			matrix[0][1] = 0;
			matrix[0][2] = 0;
			matrix[0][3] = 0;
			matrix[1][0] = 0;
			matrix[1][1] = 0;
			matrix[1][2] = 0;
			matrix[1][3] = 0;
			matrix[2][0] = 0;
			matrix[2][1] = 0;
			matrix[2][2] = 0;
			matrix[2][3] = 0;
			matrix[3][0] = 0;
			matrix[3][1] = 0;
			matrix[3][2] = 0;
			matrix[3][3] = 0;
		}

		//��� Ȯ���� ���� ���
		void Print()
		{
			cout << " - Matrix4" << endl;
			for (int i = 0; i < 4; i++)
			{
				cout << "|";
				for (int j = 0; j < 4; j++)
				{
					cout << matrix[i][j];
					if ((j + 1) / 4 != 1)
						cout << " ";
					else if ((j + 1) / 4 == 1) {
						cout << "|";
						cout << endl;
					}
				}
			}
			cout << endl;
		}

	};

	//3X1����
	class vec3{
	public :

		//3X1�迭
		float vector[3][1];

		//�ܼ� �����ϋ�
		vec3(){
			vector[0][0] = 0.f;
			vector[1][0] = 0.f;
			vector[2][0] = 0.f;
		}

		//3X1�迭 �Է� �� �ʱ�ȭ
		vec3(float a, float b,float c)
		{
			vector[0][0] = a;
			vector[1][0] = b;
			vector[2][0] = c;
		}

		//���� 0���� �ʱ�ȭ
		void InitVec()
		{
			vector[0][0] = 0;
			vector[1][0] = 0;
			vector[2][0] = 0;
		}

		//Ȯ���� ���� ���� ����Ʈ
		void Print()
		{
			cout << " - Vector3 " << endl;

			for (int i = 0; i < 3; i++)
			{
				cout << "|";
				for (int j = 0; j < 1; j++)
				{
					cout << vector[i][j];
					cout << "|";
					cout << endl;
				}
			}
			cout << endl;
		}
	};

	//1X3����
	class vec1x3 {
	public:

		//3X1�迭
		float vector[1][3];

		//�ܼ� �����ϋ�
		vec1x3() {
			vector[0][0] = 0.f;
			vector[0][1] = 0.f;
			vector[0][2] = 0.f;
		}

		//1X3�迭 �Է� �� �ʱ�ȭ
		vec1x3(float a, float b,float c)
		{
			vector[0][0] = a;
			vector[0][1] = b;
			vector[0][2] = c;
		}

		//���� 0���� �ʱ�ȭ
		void InitVec()
		{
			vector[0][0] = 0.f;
			vector[0][1] = 0.f;
			vector[0][2] = 0.f;
		}

		//Ȯ���� ���� ���� ����Ʈ
		void Print()
		{
			cout << " - Vector1X3 " << endl;

			for (int i = 0; i < 1; i++)
			{
				cout << "|";
				for (int j = 0; j < 3; j++)
				{
					cout << vector[i][j];
					cout << " ";
				}
			}
			cout << "|";
			cout << endl;
		}
	};

	//4X1����
	class vec4 {
	public:
		
		//4X1�迭
		float vector[4][1];

		//�ܼ� �����ϋ�
		vec4() {
			vector[0][0] = 0.f;
			vector[1][0] = 0.f;
			vector[2][0] = 0.f;
			vector[3][0] = 0.f;
		}

		//3X1�迭 �Է� �� �ʱ�ȭ
		vec4(float a, float b,float c,float d)
		{
			vector[0][0] = a;
			vector[1][0] = b;
			vector[2][0] = c;
			vector[3][0] = d;
		}

		//���� 0���� �ʱ�ȭ
		void InitVec()
		{
			vector[0][0] = 0;
			vector[1][0] = 0;
			vector[2][0] = 0;
			vector[3][0] = 0;
		}

		//Ȯ���� ���� ���� ����Ʈ
		void Print()
		{
			cout << " - Vector4X1 " << endl;

			for (int i = 0; i < 4; i++)
			{
				cout << "|";
				for (int j = 0; j < 1; j++)
				{
					cout << vector[i][j];
					cout << "|";
					cout << endl;
				}
			}
			cout << endl;
		}
	};

	//1X4����
	class vec1x4 {
	public:

		//1X4�迭
		float vector[1][4];

		//�ܼ� �����ϋ�
		vec1x4() {
			vector[0][0] = 0.f;
			vector[0][1] = 0.f;
			vector[0][2] = 0.f;
			vector[0][3] = 0.f;
		}

		//1X4�迭 �Է� �� �ʱ�ȭ
		vec1x4(float a, float b, float c,float d)
		{
			vector[0][0] = a;
			vector[0][1] = b;
			vector[0][2] = c;
			vector[0][3] = d;
		}

		//���� 0���� �ʱ�ȭ
		void InitVec()
		{
			vector[0][0] = 0.f;
			vector[0][1] = 0.f;
			vector[0][2] = 0.f;
			vector[0][3] = 0.f;
		}

		//Ȯ���� ���� ���� ����Ʈ
		void Print()
		{
			cout << " - Vector1X4 " << endl;

			for (int i = 0; i < 1; i++)
			{
				cout << "|";
				for (int j = 0; j < 4; j++)
				{
					cout << vector[i][j];
					cout << " ";
				}
			}
			cout << "|";
			cout << endl;
		}
	};

	//mat3 ������ ---------------------------------------------
	
	// ���(mat3) ���ϱ� ���(mat3)
	mat3 operator+(const mat3& origin,const mat3& a)
	{
		//�������� ���
		mat3 turnMatrix;

		//�ʱ�ȭ�� ���� ��� 0���� �ʱ�ȭ
		turnMatrix.InitMat();

		//���
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				turnMatrix.matrix[i][j] = origin.matrix[i][j] + a.matrix[i][j];
			}
		}
	
		return turnMatrix;
	}

	// ���(mat3) ���� ���(mat3)
	mat3 operator-(const mat3& origin, const mat3& a)
	{
		//�������� ���
		mat3 turnMatrix;

		//�ʱ�ȭ�� ���� ��� 0���� �ʱ�ȭ
		turnMatrix.InitMat();

		//���
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				turnMatrix.matrix[i][j] = origin.matrix[i][j] - a.matrix[i][j];
			}
		}

		return turnMatrix;
	}

	// ���(mat3) ���ϱ� ���(mat3)
	mat3 operator*(const mat3& origin, const mat3& a)
	{
		//�������� ���
		mat3 turnMatrix;

		//�ʱ�ȭ�� ���� ��� 0���� �ʱ�ȭ
		turnMatrix.InitMat();

		//���
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++) {

					turnMatrix.matrix[i][j] += a.matrix[i][k] * origin.matrix[k][j];
				}
			}
		}

		return turnMatrix;
	}

	// ���(mat3) ���ϱ� ����(vec3)
	vec3 operator*(const mat3& origin, const vec3& a)
	{
		//����Ͽ� ��ȯ�� ���
		vec3 turnVector;

		//��� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//��İ� ��� ���
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{	
				turnVector.vector[i][0] += a.vector[j][0] * origin.matrix[j][i];
			}
		}

		//����� ��� ����
		return turnVector;
	}

	// ���(mat3) ���ϱ� ����(vec1x3)
	vec1x3 operator*(const mat3& origin, const vec1x3& a)
	{
		//��ġ�� ���� �Ҵ�
		mat3 transposeMat = origin;
		transposeMat.Transpose();

		//����Ͽ� ��ȯ�� ���
		vec1x3 turnVector;

		//��� 0���� �ʱ�ȭ
		turnVector.InitVec();


		//��İ� ��� ���
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++) {
					turnVector.vector[0][j] += a.vector[0][k] * transposeMat.matrix[j][k];
				}			
			}
		}

		//����� ��� ����
		return turnVector;
	}

	// ���(mat3) ���ϱ� ���
	mat3 operator*(const mat3& origin, const float& a)
	{
		//����Ͽ� ��ȯ�� ���
		mat3 turnMatrix;

		//��� 0���� �ʱ�ȭ
		turnMatrix.InitMat();

		//��İ� ��� ���
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				turnMatrix.matrix[i][j] = origin.matrix[i][j] * a;
			}
		}

		//����� ��� ����
		return turnMatrix;
	}

	// ���(mat3) ������ ���
	mat3 operator/(const mat3& origin, const float& a)
	{
		//����Ͽ� ��ȯ�� ���
		mat3 turnMatrix;

		//��� 0���� �ʱ�ȭ
		turnMatrix.InitMat();

		//��İ� ��� ���
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				turnMatrix.matrix[i][j] = origin.matrix[i][j] / a;
			}
		}

		//����� ��� ����
		return turnMatrix;
	}

	//---------------------------------------------------------

	//mat4 ������ ---------------------------------------------

	// ���(mat4) ���ϱ� ���(mat4)
	mat4 operator+(const mat4 origin,const mat4& a)
	{
		//�������� ���
		mat4 turnMatrix;

		//�ʱ�ȭ�� ���� ��� 0���� �ʱ�ȭ
		turnMatrix.InitMat();

		//���
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				turnMatrix.matrix[i][j] = origin.matrix[i][j] + a.matrix[i][j];
			}
		}

		return turnMatrix;
	}

	// ���(mat4) ���� ���(mat4)
	mat4 operator-(const mat4 origin, const mat4& a)
	{
		//�������� ���
		mat4 turnMatrix;

		//�ʱ�ȭ�� ���� ��� 0���� �ʱ�ȭ
		turnMatrix.InitMat();

		//���
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				turnMatrix.matrix[i][j] = origin.matrix[i][j] - a.matrix[i][j];
			}
		}

		return turnMatrix;
	}

	// ���(mat4) ���ϱ� ���(mat4)
	mat4 operator*(const mat4 origin, const mat4& a)
	{
		//����Ͽ� ��ȯ�� ���
		mat4 turnMatrix;

		//��� 0���� �ʱ�ȭ
		turnMatrix.InitMat();

		//���
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++) {

					turnMatrix.matrix[i][j] += a.matrix[i][k] * origin.matrix[k][j];
				}
			}
		}

		//����� ��� ����
		return turnMatrix;
	}

	// ���(mat4) ���ϱ� ����(vec4)
	vec4 operator*(const mat4& origin, const vec4& a)
	{
		//����Ͽ� ��ȯ�� ���
		vec4 turnVector;

		//��� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//��İ� ��� ���
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				turnVector.vector[i][0] += a.vector[j][0] * origin.matrix[j][i];
			}
		}

		//����� ��� ����
		return turnVector;
	}

	// ���(mat4) ���ϱ� ����(vec1x4)
	vec1x4 operator*(const mat4& origin, const vec1x4& a)
	{
		//��ġ�� ���� �Ҵ�
		mat4 transposeMat = origin;
		transposeMat.Transpose();

		//����Ͽ� ��ȯ�� ���
		vec1x4 turnVector;

		//��� 0���� �ʱ�ȭ
		turnVector.InitVec();


		//��İ� ��� ���
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++) {
					turnVector.vector[0][j] += a.vector[0][k] * transposeMat.matrix[j][k];
				}
			}
		}

		//����� ��� ����
		return turnVector;
	}

	// ���(mat4) ���ϱ� ���
	mat4 operator*(const mat4 origin, const float& a)
	{
		//����Ͽ� ��ȯ�� ���
		mat4 turnMatrix;

		//��� 0���� �ʱ�ȭ
		turnMatrix.InitMat();

		//��İ� ��� ���
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				turnMatrix.matrix[i][j] = origin.matrix[i][j] * a;
			}
		}

		//����� ��� ����
		return turnMatrix;
	}

	// ���(mat4) ������ ���
	mat4 operator/(const mat4 origin, const float& a)
	{
		//����Ͽ� ��ȯ�� ���
		mat4 turnMatrix;

		//��� 0���� �ʱ�ȭ
		turnMatrix.InitMat();

		//��İ� ��� ���
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				turnMatrix.matrix[i][j] =origin.matrix[i][j] / a;
			}
		}

		//����� ��� ����
		return turnMatrix;
	}

	//---------------------------------------------------------

	//vec3 ������ ---------------------------------------------

	// ����(vec3) ���ϱ� ����(vec3)
	vec3 operator+(const vec3 origin,const vec3& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���� �� ��� ���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] + a.vector[i][0];
		}

		//����� ���� ����
		return turnVector;
	}

	// ����(vec3) ���� ����(vec3)
	vec3 operator-(const vec3 origin, const vec3& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] - a.vector[i][0];
		}

		return turnVector;
	}

	// ����(vec3) ���ϱ� ����(vec3)
	vec3 operator*(const vec3 origin, const vec3& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] * a.vector[i][0];
		}

		return turnVector;
	}

	// ����(vec3) ���ϱ� ����(vec1x3)
	vec3 operator+(const vec3 origin, const vec1x3& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] + a.vector[0][i];
		}

		return turnVector;
	}

	// ����(vec3) ���� ����(vec1x3)
	vec3 operator-(const vec3 origin, const vec1x3& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] - a.vector[0][i];
		}

		return turnVector;
	}

	// ����(vec3) ���ϱ� ����(vec1x3)
	vec3 operator*(const vec3 origin, const vec1x3& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] * a.vector[0][i];
		}

		return turnVector;
	}

	// ����(vec3) ���ϱ� ���(mat3)
	vec3 operator*(const vec3 origin, const mat3& a)
	{

		//��ġ�� ���� �Ҵ�
		mat3 transposeMat = a;
		transposeMat.Transpose();

		//����Ͽ� ��ȯ�� ���
		vec3 turnVector;

		//��� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				turnVector.vector[0][i] += transposeMat.matrix[j][i] * origin.vector[j][0];
			}
		}

		return turnVector;
	}

	// ����(vec3) ���ϱ� ���
	vec3 operator*(const vec3 origin, const float& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] * a;
		}

		return turnVector;
	}

	// ����(vec3) ������ ���
	vec3 operator/(const vec3 origin, const float& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] / a;
		}

		return turnVector;
	}


	//---------------------------------------------------------

	//vec1x3 ������ -------------------------------------------
	
	// ����(vec1x3) ���ϱ� ����(vec1x3)
	vec1x3 operator+(const vec1x3 origin,const vec1x3& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] + a.vector[0][i];
		}

		return turnVector;
	}

	// ����(vec1x3) ���� ����(vec1x3)
	vec1x3 operator-(const vec1x3 origin, const vec1x3& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] - a.vector[0][i];
		}

		return turnVector;
	}

	// ����(vec1x3) ���ϱ� ����(vec1x3)
	vec1x3 operator*(const vec1x3 origin, const vec1x3& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] * a.vector[0][i];
		}

		return turnVector;
	}

	// ����(vec1x3) ���ϱ� ����(vec3)
	vec1x3 operator+(const vec1x3 origin, const vec3& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] + a.vector[i][0];
		}

		return turnVector;
	}

	// ����(vec1x3) ���� ����(vec3)
	vec1x3 operator-(const vec1x3 origin, const vec3& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] - a.vector[i][0];
		}

		return turnVector;
	}

	// ����(vec1x3) ���ϱ� ����(vec3)
	vec1x3 operator*(const vec1x3 origin, const vec3& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] * a.vector[i][0];
		}

		return turnVector;
	}

	// ����(vec1x3) ���ϱ� ���(mat3)
	vec1x3 operator*(const vec1x3 origin, const mat3& a)
	{
		//��ġ�� ���� �Ҵ�
		mat3 transposeMat = a;
		transposeMat.Transpose();

		//����Ͽ� ��ȯ�� ���
		vec1x3 turnVector;

		//��� 0���� �ʱ�ȭ
		turnVector.InitVec();


		//���
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				turnVector.vector[0][i] += transposeMat.matrix[j][i] * origin.vector[0][j];
			}
		}

		return turnVector;
	}

	// ����(vec1x3) ���ϱ� ���
	vec1x3 operator*(const vec1x3 origin, const float& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] * a;
		}

		return turnVector;
	}

	// ����(vec1x3) ������ ���
	vec1x3 operator/(const vec1x3 origin, const float& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x3 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] / a;
		}

		return turnVector;
	}

	//---------------------------------------------------------

	//vec4 ������ ---------------------------------------------

	// ����(vec4) ���ϱ� ����(vec4)
	vec4 operator+(const vec4 origin,const vec4& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] + a.vector[i][0];
		}

		return turnVector;
	}

	// ����(vec4) ���� ����(vec4)
	vec4 operator-(const vec4 origin, const vec4& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] - a.vector[i][0];
		}

		return turnVector;
	}

	// ����(vec4) ���ϱ� ����(vec4)
	vec4 operator*(const vec4 origin, const vec4& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] * a.vector[i][0];
		}

		return turnVector;
	}

	// ����(vec4) ���ϱ� ����(vec1x4)
	vec4 operator+(const vec4 origin, const vec1x4& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] + a.vector[0][i];
		}

		return turnVector;
	}

	// ����(vec4) ���� ����(vec1x4)
	vec4 operator-(const vec4 origin, const vec1x4& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] - a.vector[0][i];
		}

		return turnVector;
	}

	// ����(vec4) ���ϱ� ����(vec1x4)
	vec4 operator*(const vec4 origin, const vec1x4& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] * a.vector[0][i];
		}

		return turnVector;
	}

	// ����(vec4) ���ϱ� ���(mat4)
	vec4 operator*(const vec4 origin, const mat4& a)
	{
		//��ġ�� ���� �Ҵ�
		mat4 transposeMat = a;
		transposeMat.Transpose();

		//����Ͽ� ��ȯ�� ���
		vec4 turnVector;

		//��� 0���� �ʱ�ȭ
		turnVector.InitVec();


		//���
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				turnVector.vector[0][i] += transposeMat.matrix[j][i] * origin.vector[j][0];
			}
		}

		return turnVector;
	}

	// ����(vec4) ���ϱ� ���
	vec4 operator*(const vec4 origin, const float& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//��İ� ��� ���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] * a;
		}

		//����� ��� ����
		return turnVector;
	}

	// ����(vec4) ������ ���
	vec4 operator/(const vec4 origin, const float& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] / a;
		}

		return turnVector;
	}

	//---------------------------------------------------------

	//vec1x4 ������ -------------------------------------------

	// ����(vec1x4) ���ϱ� ����(vec1x4)
	vec1x4 operator+(const vec1x4& origin, const vec1x4& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] + a.vector[0][i];
		}

		return turnVector;
	}

	// ����(vec1x4) ���� ����(vec1x4)
	vec1x4 operator-(const vec1x4& origin, const vec1x4& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] - a.vector[0][i];
		}

		return turnVector;
	}

	// ����(vec1x4) ���ϱ� ����(vec1x4)
	vec1x4 operator*(const vec1x4& origin, const vec1x4& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] * a.vector[0][i];
		}

		return turnVector;
	}

	// ����(vec1x4) ���ϱ� ����(vec4)
	vec1x4 operator+(const vec1x4& origin, const vec4& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] + a.vector[i][0];
		}

		return turnVector;
	}

	// ����(vec1x4) ���� ����(vec4)
	vec1x4 operator-(const vec1x4& origin, const vec4& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] - a.vector[i][0];
		}

		return turnVector;
	}

	// ����(vec1x4) ���ϱ� ����(vec4)
	vec1x4 operator*(const vec1x4& origin, const vec4& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] * a.vector[i][0];
		}

		return turnVector;
	}

	// ����(vec1x4) ���ϱ� ���(mat4)
	vec1x4 operator*(const vec1x4& origin, const mat4& a)
	{
		//��ġ�� ���� �Ҵ�
		mat4 transposeMat = a;
		transposeMat.Transpose();

		//����Ͽ� ��ȯ�� ���
		vec1x4 turnVector;

		//��� 0���� �ʱ�ȭ
		turnVector.InitVec();


		//���
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				turnVector.vector[0][i] += transposeMat.matrix[j][i] * origin.vector[0][j];
			}
		}

		return turnVector;
	}

	// ����(vec1x4) ���ϱ� ���
	vec1x4 operator*(const vec1x4& origin, const float& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] * a;
		}

		return turnVector;
	}

	// ����(vec1x4) ������ ���
	vec1x4 operator/(const vec1x4& origin, const float& a)
	{
		//����Ͽ� ��ȯ�� ����
		vec1x4 turnVector;

		//���� 0���� �ʱ�ȭ
		turnVector.InitVec();

		//���
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] / a;
		}

		return turnVector;
	}

	//---------------------------------------------------------
}