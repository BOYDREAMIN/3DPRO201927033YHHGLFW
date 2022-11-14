#pragma once
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
namespace Math{

	//3X3행렬
	class mat3{
	public: 	
		//3X3배열
		float matrix[3][3];

		//단순 선언일떄
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

		//전치
		void Transpose()
		{
			//뇌절와서 하드코딩
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

	};

	//4X4행렬
	class mat4 {
	public :
		
		//4X4배열
		float matrix[4][4];

		//단순 선언일떄 1초기화 
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

		//4X4배열 입력 값 초기화
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

			//뇌절와서 하드코딩
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

		//행렬 0 으로 초기화
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

		//행렬 확인을 위한 출력
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

	//3X1벡터
	class vec3{
	public :

		//3X1배열
		float vector[3][1];

		//단순 선언일떄
		vec3(){
			vector[0][0] = 0.f;
			vector[1][0] = 0.f;
			vector[2][0] = 0.f;
		}

		//3X1배열 입력 값 초기화
		vec3(float a, float b,float c)
		{
			vector[0][0] = a;
			vector[1][0] = b;
			vector[2][0] = c;
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

	//1X3벡터
	class vec1x3 {
	public:

		//3X1배열
		float vector[1][3];

		//단순 선언일떄
		vec1x3() {
			vector[0][0] = 0.f;
			vector[0][1] = 0.f;
			vector[0][2] = 0.f;
		}

		//1X3배열 입력 값 초기화
		vec1x3(float a, float b,float c)
		{
			vector[0][0] = a;
			vector[0][1] = b;
			vector[0][2] = c;
		}

		//벡터 0으로 초기화
		void InitVec()
		{
			vector[0][0] = 0.f;
			vector[0][1] = 0.f;
			vector[0][2] = 0.f;
		}

		//확인을 위한 벡터 프린트
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

	//4X1벡터
	class vec4 {
	public:
		
		//4X1배열
		float vector[4][1];

		//단순 선언일떄
		vec4() {
			vector[0][0] = 0.f;
			vector[1][0] = 0.f;
			vector[2][0] = 0.f;
			vector[3][0] = 0.f;
		}

		//3X1배열 입력 값 초기화
		vec4(float a, float b,float c,float d)
		{
			vector[0][0] = a;
			vector[1][0] = b;
			vector[2][0] = c;
			vector[3][0] = d;
		}

		//벡터 0으로 초기화
		void InitVec()
		{
			vector[0][0] = 0;
			vector[1][0] = 0;
			vector[2][0] = 0;
			vector[3][0] = 0;
		}

		//확인을 위한 벡터 프린트
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

	//1X4벡터
	class vec1x4 {
	public:

		//1X4배열
		float vector[1][4];

		//단순 선언일떄
		vec1x4() {
			vector[0][0] = 0.f;
			vector[0][1] = 0.f;
			vector[0][2] = 0.f;
			vector[0][3] = 0.f;
		}

		//1X4배열 입력 값 초기화
		vec1x4(float a, float b, float c,float d)
		{
			vector[0][0] = a;
			vector[0][1] = b;
			vector[0][2] = c;
			vector[0][3] = d;
		}

		//벡터 0으로 초기화
		void InitVec()
		{
			vector[0][0] = 0.f;
			vector[0][1] = 0.f;
			vector[0][2] = 0.f;
			vector[0][3] = 0.f;
		}

		//확인을 위한 벡터 프린트
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

	//mat3 연산자 ---------------------------------------------
	
	// 행렬(mat3) 더하기 행렬(mat3)
	mat3 operator+(const mat3& origin,const mat3& a)
	{
		//리턴해줄 행렬
		mat3 turnMatrix;

		//초기화를 위해 행렬 0으로 초기화
		turnMatrix.InitMat();

		//계산
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				turnMatrix.matrix[i][j] = origin.matrix[i][j] + a.matrix[i][j];
			}
		}
	
		return turnMatrix;
	}

	// 행렬(mat3) 빼기 행렬(mat3)
	mat3 operator-(const mat3& origin, const mat3& a)
	{
		//리턴해줄 행렬
		mat3 turnMatrix;

		//초기화를 위해 행렬 0으로 초기화
		turnMatrix.InitMat();

		//계산
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				turnMatrix.matrix[i][j] = origin.matrix[i][j] - a.matrix[i][j];
			}
		}

		return turnMatrix;
	}

	// 행렬(mat3) 곱하기 행렬(mat3)
	mat3 operator*(const mat3& origin, const mat3& a)
	{
		//리턴해줄 행렬
		mat3 turnMatrix;

		//초기화를 위해 행렬 0으로 초기화
		turnMatrix.InitMat();

		//계산
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

	// 행렬(mat3) 곱하기 벡터(vec3)
	vec3 operator*(const mat3& origin, const vec3& a)
	{
		//계산하여 반환할 행렬
		vec3 turnVector;

		//행렬 0으로 초기화
		turnVector.InitVec();

		//행렬과 행렬 계산
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{	
				turnVector.vector[i][0] += a.vector[j][0] * origin.matrix[j][i];
			}
		}

		//계산한 행렬 리턴
		return turnVector;
	}

	// 행렬(mat3) 곱하기 벡터(vec1x3)
	vec1x3 operator*(const mat3& origin, const vec1x3& a)
	{
		//전치를 위한 할당
		mat3 transposeMat = origin;
		transposeMat.Transpose();

		//계산하여 반환할 행렬
		vec1x3 turnVector;

		//행렬 0으로 초기화
		turnVector.InitVec();


		//행렬과 행렬 계산
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++) {
					turnVector.vector[0][j] += a.vector[0][k] * transposeMat.matrix[j][k];
				}			
			}
		}

		//계산한 행렬 리턴
		return turnVector;
	}

	// 행렬(mat3) 곱하기 상수
	mat3 operator*(const mat3& origin, const float& a)
	{
		//계산하여 반환할 행렬
		mat3 turnMatrix;

		//행렬 0으로 초기화
		turnMatrix.InitMat();

		//행렬과 상수 계산
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				turnMatrix.matrix[i][j] = origin.matrix[i][j] * a;
			}
		}

		//계산한 행렬 리턴
		return turnMatrix;
	}

	// 행렬(mat3) 나누기 상수
	mat3 operator/(const mat3& origin, const float& a)
	{
		//계산하여 반환할 행렬
		mat3 turnMatrix;

		//행렬 0으로 초기화
		turnMatrix.InitMat();

		//행렬과 상수 계산
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				turnMatrix.matrix[i][j] = origin.matrix[i][j] / a;
			}
		}

		//계산한 행렬 리턴
		return turnMatrix;
	}

	//---------------------------------------------------------

	//mat4 연산자 ---------------------------------------------

	// 행렬(mat4) 더하기 행렬(mat4)
	mat4 operator+(const mat4 origin,const mat4& a)
	{
		//리턴해줄 행렬
		mat4 turnMatrix;

		//초기화를 위해 행렬 0으로 초기화
		turnMatrix.InitMat();

		//계산
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				turnMatrix.matrix[i][j] = origin.matrix[i][j] + a.matrix[i][j];
			}
		}

		return turnMatrix;
	}

	// 행렬(mat4) 빼기 행렬(mat4)
	mat4 operator-(const mat4 origin, const mat4& a)
	{
		//리턴해줄 행렬
		mat4 turnMatrix;

		//초기화를 위해 행렬 0으로 초기화
		turnMatrix.InitMat();

		//계산
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				turnMatrix.matrix[i][j] = origin.matrix[i][j] - a.matrix[i][j];
			}
		}

		return turnMatrix;
	}

	// 행렬(mat4) 곱하기 행렬(mat4)
	mat4 operator*(const mat4 origin, const mat4& a)
	{
		//계산하여 반환할 행렬
		mat4 turnMatrix;

		//행렬 0으로 초기화
		turnMatrix.InitMat();

		//계산
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++) {

					turnMatrix.matrix[i][j] += a.matrix[i][k] * origin.matrix[k][j];
				}
			}
		}

		//계산한 행렬 리턴
		return turnMatrix;
	}

	// 행렬(mat4) 곱하기 벡터(vec4)
	vec4 operator*(const mat4& origin, const vec4& a)
	{
		//계산하여 반환할 행렬
		vec4 turnVector;

		//행렬 0으로 초기화
		turnVector.InitVec();

		//행렬과 행렬 계산
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				turnVector.vector[i][0] += a.vector[j][0] * origin.matrix[j][i];
			}
		}

		//계산한 행렬 리턴
		return turnVector;
	}

	// 행렬(mat4) 곱하기 벡터(vec1x4)
	vec1x4 operator*(const mat4& origin, const vec1x4& a)
	{
		//전치를 위한 할당
		mat4 transposeMat = origin;
		transposeMat.Transpose();

		//계산하여 반환할 행렬
		vec1x4 turnVector;

		//행렬 0으로 초기화
		turnVector.InitVec();


		//행렬과 행렬 계산
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++) {
					turnVector.vector[0][j] += a.vector[0][k] * transposeMat.matrix[j][k];
				}
			}
		}

		//계산한 행렬 리턴
		return turnVector;
	}

	// 행렬(mat4) 곱하기 상수
	mat4 operator*(const mat4 origin, const float& a)
	{
		//계산하여 반환할 행렬
		mat4 turnMatrix;

		//행렬 0으로 초기화
		turnMatrix.InitMat();

		//행렬과 상수 계산
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				turnMatrix.matrix[i][j] = origin.matrix[i][j] * a;
			}
		}

		//계산한 행렬 리턴
		return turnMatrix;
	}

	// 행렬(mat4) 나누기 상수
	mat4 operator/(const mat4 origin, const float& a)
	{
		//계산하여 반환할 행렬
		mat4 turnMatrix;

		//행렬 0으로 초기화
		turnMatrix.InitMat();

		//행렬과 상수 계산
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				turnMatrix.matrix[i][j] =origin.matrix[i][j] / a;
			}
		}

		//계산한 행렬 리턴
		return turnMatrix;
	}

	//---------------------------------------------------------

	//vec3 연산자 ---------------------------------------------

	// 벡터(vec3) 더하기 벡터(vec3)
	vec3 operator+(const vec3 origin,const vec3& a)
	{
		//계산하여 반환할 벡터
		vec3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//벡터 와 행렬 계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] + a.vector[i][0];
		}

		//계산한 벡터 리턴
		return turnVector;
	}

	// 벡터(vec3) 빼기 벡터(vec3)
	vec3 operator-(const vec3 origin, const vec3& a)
	{
		//계산하여 반환할 벡터
		vec3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] - a.vector[i][0];
		}

		return turnVector;
	}

	// 벡터(vec3) 곱하기 벡터(vec3)
	vec3 operator*(const vec3 origin, const vec3& a)
	{
		//계산하여 반환할 벡터
		vec3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] * a.vector[i][0];
		}

		return turnVector;
	}

	// 벡터(vec3) 더하기 벡터(vec1x3)
	vec3 operator+(const vec3 origin, const vec1x3& a)
	{
		//계산하여 반환할 벡터
		vec3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] + a.vector[0][i];
		}

		return turnVector;
	}

	// 벡터(vec3) 빼기 벡터(vec1x3)
	vec3 operator-(const vec3 origin, const vec1x3& a)
	{
		//계산하여 반환할 벡터
		vec3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] - a.vector[0][i];
		}

		return turnVector;
	}

	// 벡터(vec3) 곱하기 벡터(vec1x3)
	vec3 operator*(const vec3 origin, const vec1x3& a)
	{
		//계산하여 반환할 벡터
		vec3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] * a.vector[0][i];
		}

		return turnVector;
	}

	// 벡터(vec3) 곱하기 행렬(mat3)
	vec3 operator*(const vec3 origin, const mat3& a)
	{

		//전치를 위한 할당
		mat3 transposeMat = a;
		transposeMat.Transpose();

		//계산하여 반환할 행렬
		vec3 turnVector;

		//행렬 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				turnVector.vector[0][i] += transposeMat.matrix[j][i] * origin.vector[j][0];
			}
		}

		return turnVector;
	}

	// 벡터(vec3) 곱하기 상수
	vec3 operator*(const vec3 origin, const float& a)
	{
		//계산하여 반환할 벡터
		vec3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] * a;
		}

		return turnVector;
	}

	// 벡터(vec3) 나누기 상수
	vec3 operator/(const vec3 origin, const float& a)
	{
		//계산하여 반환할 벡터
		vec3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] / a;
		}

		return turnVector;
	}


	//---------------------------------------------------------

	//vec1x3 연산자 -------------------------------------------
	
	// 벡터(vec1x3) 더하기 벡터(vec1x3)
	vec1x3 operator+(const vec1x3 origin,const vec1x3& a)
	{
		//계산하여 반환할 벡터
		vec1x3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] + a.vector[0][i];
		}

		return turnVector;
	}

	// 벡터(vec1x3) 빼기 벡터(vec1x3)
	vec1x3 operator-(const vec1x3 origin, const vec1x3& a)
	{
		//계산하여 반환할 벡터
		vec1x3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] - a.vector[0][i];
		}

		return turnVector;
	}

	// 벡터(vec1x3) 곱하기 벡터(vec1x3)
	vec1x3 operator*(const vec1x3 origin, const vec1x3& a)
	{
		//계산하여 반환할 벡터
		vec1x3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] * a.vector[0][i];
		}

		return turnVector;
	}

	// 벡터(vec1x3) 더하기 벡터(vec3)
	vec1x3 operator+(const vec1x3 origin, const vec3& a)
	{
		//계산하여 반환할 벡터
		vec1x3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] + a.vector[i][0];
		}

		return turnVector;
	}

	// 벡터(vec1x3) 빼기 벡터(vec3)
	vec1x3 operator-(const vec1x3 origin, const vec3& a)
	{
		//계산하여 반환할 벡터
		vec1x3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] - a.vector[i][0];
		}

		return turnVector;
	}

	// 벡터(vec1x3) 곱하기 벡터(vec3)
	vec1x3 operator*(const vec1x3 origin, const vec3& a)
	{
		//계산하여 반환할 벡터
		vec1x3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] * a.vector[i][0];
		}

		return turnVector;
	}

	// 벡터(vec1x3) 곱하기 행렬(mat3)
	vec1x3 operator*(const vec1x3 origin, const mat3& a)
	{
		//전치를 위한 할당
		mat3 transposeMat = a;
		transposeMat.Transpose();

		//계산하여 반환할 행렬
		vec1x3 turnVector;

		//행렬 0으로 초기화
		turnVector.InitVec();


		//계산
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				turnVector.vector[0][i] += transposeMat.matrix[j][i] * origin.vector[0][j];
			}
		}

		return turnVector;
	}

	// 벡터(vec1x3) 곱하기 상수
	vec1x3 operator*(const vec1x3 origin, const float& a)
	{
		//계산하여 반환할 벡터
		vec1x3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] * a;
		}

		return turnVector;
	}

	// 벡터(vec1x3) 나누기 상수
	vec1x3 operator/(const vec1x3 origin, const float& a)
	{
		//계산하여 반환할 벡터
		vec1x3 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 3; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] / a;
		}

		return turnVector;
	}

	//---------------------------------------------------------

	//vec4 연산자 ---------------------------------------------

	// 벡터(vec4) 더하기 벡터(vec4)
	vec4 operator+(const vec4 origin,const vec4& a)
	{
		//계산하여 반환할 벡터
		vec4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] + a.vector[i][0];
		}

		return turnVector;
	}

	// 벡터(vec4) 빼기 벡터(vec4)
	vec4 operator-(const vec4 origin, const vec4& a)
	{
		//계산하여 반환할 벡터
		vec4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] - a.vector[i][0];
		}

		return turnVector;
	}

	// 벡터(vec4) 곱하기 벡터(vec4)
	vec4 operator*(const vec4 origin, const vec4& a)
	{
		//계산하여 반환할 벡터
		vec4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] * a.vector[i][0];
		}

		return turnVector;
	}

	// 벡터(vec4) 더하기 벡터(vec1x4)
	vec4 operator+(const vec4 origin, const vec1x4& a)
	{
		//계산하여 반환할 벡터
		vec4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] + a.vector[0][i];
		}

		return turnVector;
	}

	// 벡터(vec4) 빼기 벡터(vec1x4)
	vec4 operator-(const vec4 origin, const vec1x4& a)
	{
		//계산하여 반환할 벡터
		vec4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] - a.vector[0][i];
		}

		return turnVector;
	}

	// 벡터(vec4) 곱하기 벡터(vec1x4)
	vec4 operator*(const vec4 origin, const vec1x4& a)
	{
		//계산하여 반환할 벡터
		vec4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] * a.vector[0][i];
		}

		return turnVector;
	}

	// 벡터(vec4) 곱하기 행렬(mat4)
	vec4 operator*(const vec4 origin, const mat4& a)
	{
		//전치를 위한 할당
		mat4 transposeMat = a;
		transposeMat.Transpose();

		//계산하여 반환할 행렬
		vec4 turnVector;

		//행렬 0으로 초기화
		turnVector.InitVec();


		//계산
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				turnVector.vector[0][i] += transposeMat.matrix[j][i] * origin.vector[j][0];
			}
		}

		return turnVector;
	}

	// 벡터(vec4) 곱하기 상수
	vec4 operator*(const vec4 origin, const float& a)
	{
		//계산하여 반환할 벡터
		vec4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//행렬과 상수 계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] * a;
		}

		//계산한 행렬 리턴
		return turnVector;
	}

	// 벡터(vec4) 나누기 상수
	vec4 operator/(const vec4 origin, const float& a)
	{
		//계산하여 반환할 벡터
		vec4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[i][0] = origin.vector[i][0] / a;
		}

		return turnVector;
	}

	//---------------------------------------------------------

	//vec1x4 연산자 -------------------------------------------

	// 벡터(vec1x4) 더하기 벡터(vec1x4)
	vec1x4 operator+(const vec1x4& origin, const vec1x4& a)
	{
		//계산하여 반환할 벡터
		vec1x4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] + a.vector[0][i];
		}

		return turnVector;
	}

	// 벡터(vec1x4) 빼기 벡터(vec1x4)
	vec1x4 operator-(const vec1x4& origin, const vec1x4& a)
	{
		//계산하여 반환할 벡터
		vec1x4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] - a.vector[0][i];
		}

		return turnVector;
	}

	// 벡터(vec1x4) 곱하기 벡터(vec1x4)
	vec1x4 operator*(const vec1x4& origin, const vec1x4& a)
	{
		//계산하여 반환할 벡터
		vec1x4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] * a.vector[0][i];
		}

		return turnVector;
	}

	// 벡터(vec1x4) 더하기 벡터(vec4)
	vec1x4 operator+(const vec1x4& origin, const vec4& a)
	{
		//계산하여 반환할 벡터
		vec1x4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] + a.vector[i][0];
		}

		return turnVector;
	}

	// 벡터(vec1x4) 빼기 벡터(vec4)
	vec1x4 operator-(const vec1x4& origin, const vec4& a)
	{
		//계산하여 반환할 벡터
		vec1x4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] - a.vector[i][0];
		}

		return turnVector;
	}

	// 벡터(vec1x4) 곱하기 벡터(vec4)
	vec1x4 operator*(const vec1x4& origin, const vec4& a)
	{
		//계산하여 반환할 벡터
		vec1x4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] * a.vector[i][0];
		}

		return turnVector;
	}

	// 벡터(vec1x4) 곱하기 행렬(mat4)
	vec1x4 operator*(const vec1x4& origin, const mat4& a)
	{
		//전치를 위한 할당
		mat4 transposeMat = a;
		transposeMat.Transpose();

		//계산하여 반환할 행렬
		vec1x4 turnVector;

		//행렬 0으로 초기화
		turnVector.InitVec();


		//계산
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				turnVector.vector[0][i] += transposeMat.matrix[j][i] * origin.vector[0][j];
			}
		}

		return turnVector;
	}

	// 벡터(vec1x4) 곱하기 상수
	vec1x4 operator*(const vec1x4& origin, const float& a)
	{
		//계산하여 반환할 벡터
		vec1x4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] * a;
		}

		return turnVector;
	}

	// 벡터(vec1x4) 나누기 상수
	vec1x4 operator/(const vec1x4& origin, const float& a)
	{
		//계산하여 반환할 벡터
		vec1x4 turnVector;

		//벡터 0으로 초기화
		turnVector.InitVec();

		//계산
		for (int i = 0; i < 4; i++)
		{
			turnVector.vector[0][i] = origin.vector[0][i] / a;
		}

		return turnVector;
	}

	//---------------------------------------------------------
}