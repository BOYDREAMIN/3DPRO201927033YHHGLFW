#pragma once
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
namespace Math{

	//3X3���
	class mat3 {
	public: 	
		//3X3�迭
		float matrix[3][3];

		//�ܼ� �����ϋ�
		mat3(){}

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
		
		// ���ϱ� +(a.matrix) = turnMatrix
		mat3 operator+(const mat3& a)
		{
			mat3 turnMatrix;
			turnMatrix.InitMat();

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					turnMatrix.matrix[i][j] = matrix[i][j] + a.matrix[i][j];
				}
			}

			return turnMatrix;
		}

		// ���� -(a.matrix) = turnMatrix
		mat3 operator-(const mat3& a)
		{
			mat3 turnMatrix;
			turnMatrix.InitMat();

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					turnMatrix.matrix[i][j] = matrix[i][j] - a.matrix[i][j];
				}
			}

			return turnMatrix;
		}

		//��� ���� ���ϱ� *(a.matrix) = turnMatrix
		mat3 operator*(const mat3& a)
		{
			//����Ͽ� ��ȯ�� ���
			mat3 turnMatrix;

			//��� 0���� �ʱ�ȭ
			turnMatrix.InitMat();

			//��İ� ��� ���
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++) {
						turnMatrix.matrix[i][j] += matrix[i][k] * a.matrix[k][j];
					}
				}
			}

			//����� ��� ����
			return turnMatrix;
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
	};

	//3X1����
	class vec3 {
	public :

		//3X1�迭
		float vector[3][1];

		//�ܼ� �����ϋ�
		vec3(){}

		//3X1�迭 �Է� �� �ʱ�ȭ
		vec3(float a, float b)
		{
			vector[0][0] = a;
			vector[1][0] = b;
			vector[2][0] = 1.f;
		}

		// ���Ϳ� ��� ���ϱ� *(a.matrix) = turnVector
		vec3 operator*(const mat3& a)
		{
			//����Ͽ� ��ȯ�� ����
			vec3 turnVector;

			//���� 0���� �ʱ�ȭ
			turnVector.InitVec();

			//���� �� ��� ���
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					turnVector.vector[0][i] += vector[0][j] * a.matrix[i][j];
				}
			}

			//����� ���� ����
			return turnVector;
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
}








