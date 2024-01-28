#include "MyMatrix3x3.h"


#include <Novice.h>
#include <assert.h>
#include <cmath>


Matrix3x3::Matrix3x3(const Matrix3x3& m) {
	*this = m;
}

Matrix3x3::Matrix3x3(float value1, float value2, float value3, float value4, float value5, float value6, float value7, float value8, float value9) {
	this->m[0][0] = value1;
	this->m[0][1] = value2;
	this->m[0][2] = value3;
	
	this->m[1][0] = value4;
	this->m[1][1] = value5;
	this->m[1][2] = value6;
	
	this->m[2][0] = value7;
	this->m[2][1] = value8;
	this->m[2][2] = value9;
}

inline Matrix3x3 Matrix3x3::operator+ (const Matrix3x3& other) const {
	Matrix3x3 result;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			result.m[row][col] = this->m[row][col] + other.m[row][col];
		}
	}
	return result;
}

inline Matrix3x3 Matrix3x3::operator- (const Matrix3x3& other) const {
	Matrix3x3 result;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			result.m[row][col] = this->m[row][col] - other.m[row][col];
		}
	}
	return result;
}

inline Matrix3x3 Matrix3x3::operator* (const Matrix3x3& other) const {
	Matrix3x3 result;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			result.m[row][col] =
				this->m[row][0] * other.m[0][col]
				+ this->m[row][1] * other.m[1][col]
				+ this->m[row][2] * other.m[2][col];
		}
	}
	return result;
}

inline Matrix3x3& Matrix3x3::operator+= (const Matrix3x3& other) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			this->m[row][col] += other.m[row][col];
		}
	}
	return *this;
}

inline Matrix3x3& Matrix3x3::operator-= (const Matrix3x3& other) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			this->m[row][col] -= other.m[row][col];
		}
	}
	return *this;
}

inline Matrix3x3& Matrix3x3::operator*= (const Matrix3x3& other) {
	Matrix3x3 result = *this * other;
	*this = result;
	return *this;
}

Matrix3x3 Matrix3x3::MakeIdentity(void) {
	return Matrix3x3(
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	);
}

Matrix3x3 Matrix3x3::MakeAffine(const Vec2f& scale, float rotate, const Vec2f& translate) {
	Matrix3x3 S = Matrix3x3::MakeScale(scale);
	Matrix3x3 R = Matrix3x3::MakeRotate(rotate);
	Matrix3x3 T = Matrix3x3::MakeTranslate(translate);

	/// SRTの順番で計算し行列を変えす
	return S * R * T;
}

Matrix3x3 Matrix3x3::MakeScale(const Vec2f& scale) {
	return Matrix3x3(
		scale.x, 0.0f, 0.0f,
		0.0f, scale.y, 0.0f,
		0.0f, 0.0f, 1.0f
	);
}

Matrix3x3 Matrix3x3::MakeRotate(float rotate) {
	return Matrix3x3(
		std::cosf(rotate), -std::sinf(rotate), 0.0f,
		std::sinf(rotate), std::cosf(rotate), 0.0f,
		0.0, 0.0, 1.0f
	);
}

Matrix3x3 Matrix3x3::MakeRotate(const Vec2f& dir) {
	return Matrix3x3(
		dir.x, -dir.y, 0.0f,
		dir.y, dir.x, 0.0f,
		0.0, 0.0, 1.0f
	);
}

Matrix3x3 Matrix3x3::MakeTranslate(const Vec2f& translate) {
	return Matrix3x3(
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		translate.x, translate.y, 1.0f
	);
}

Matrix3x3 Matrix3x3::MakeInverse(const Matrix3x3& m) {
	Matrix3x3 matrix = m;
	Matrix3x3 result = Matrix3x3::MakeIdentity();

	for (int i = 0; i < 3; ++i) {
		// ピボットが0の場合、行の入れ替えを行う
		if (matrix.m[i][i] == 0.0f) {
			return Matrix3x3::MakeIdentity(); // 単位行列を返す (逆行列が存在しない)
		}

		// ピボットの値を1にする
		float pivot_inverse = 1.0f / matrix.m[i][i];
		for (int j = 0; j < 3; ++j) {
			matrix.m[i][j] *= pivot_inverse;
			result.m[i][j] *= pivot_inverse;
		}

		// 掃き出し法を用いて、他の行を変換
		for (int k = 0; k < 3; ++k) {
			if (k != i) {
				float factor = -matrix.m[k][i];
				for (int j = 0; j < 3; ++j) {
					matrix.m[k][j] += factor * matrix.m[i][j];
					result.m[k][j] += factor * result.m[i][j];
				}
			}
		}
	}

	return result;
}

Vec2f Matrix3x3::Transform(const Vec2f& v, const Matrix3x3& matrix) {
	Vec2f result{ 0.0f,0.0f };

	result.x = v.x * matrix.m[0][0] + v.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	result.y = v.x * matrix.m[0][1] + v.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	float w = v.x * matrix.m[0][2] + v.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];

	assert(w != 0.0f);
	result /= w;

	return result;
}

QuadVerf Matrix3x3::Transform(const QuadVerf& vertex, const Matrix3x3& matrix) {
	return QuadVerf(
		Matrix3x3::Transform(vertex[LT], matrix),
		Matrix3x3::Transform(vertex[RT], matrix),
		Matrix3x3::Transform(vertex[LB], matrix),
		Matrix3x3::Transform(vertex[RB], matrix)
	);
}
