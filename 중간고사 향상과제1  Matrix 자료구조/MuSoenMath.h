#pragma once
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
namespace Math{

	//3X3행렬
	class mat3 {
	public: 	
		//3X3배열
		float matrix[3][3];

		//단순 선언일떄
		mat3(){}

		//3X3배열 입력 값 초기화
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
		
		// 덜하기 +(a.matrix) = turnMatrix
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

		// 빼기 -(a.matrix) = turnMatrix
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

		//행렬 끼리 곱하기 *(a.matrix) = turnMatrix
		mat3 operator*(const mat3& a)
		{
			//계산하여 반환할 행렬
			mat3 turnMatrix;

			//행렬 0으로 초기화
			turnMatrix.InitMat();

			//행렬과 행렬 계산
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++) {
						turnMatrix.matrix[i][j] += matrix[i][k] * a.matrix[k][j];
					}
				}
			}

			//계산한 행렬 리턴
			return turnMatrix;
		}

		//행렬 확인을 위한 출력
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

		//행렬 0 으로 초기화
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

	//3X1벡터
	class vec3 {
	public :

		//3X1배열
		float vector[3][1];

		//단순 선언일떄
		vec3(){}

		//3X1배열 입력 값 초기화
		vec3(float a, float b)
		{
			vector[0][0] = a;
			vector[1][0] = b;
			vector[2][0] = 1.f;
		}

		// 벡터와 행렬 곱하기 *(a.matrix) = turnVector
		vec3 operator*(const mat3& a)
		{
			//계산하여 반환할 벡터
			vec3 turnVector;

			//벡터 0으로 초기화
			turnVector.InitVec();

			//벡터 와 행렬 계산
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					turnVector.vector[0][i] += vector[0][j] * a.matrix[i][j];
				}
			}

			//계산한 벡터 리턴
			return turnVector;
		}

		//벡터 0으로 초기화
		void InitVec()
		{
			vector[0][0] = 0;
			vector[1][0] = 0;
			vector[2][0] = 0;
		}

		//확인을 위한 벡터 프린트
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








