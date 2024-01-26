#pragma once

#include "MyVector2.h"
#include "QuadVertex.h"

/// <summary>
/// 3x3の行列
/// </summary>
class Matrix3x3 final {
public: // member method

	Matrix3x3() = default;
	Matrix3x3(const Matrix3x3& m);
	Matrix3x3(
		float value1, float value2, float value3,
		float value4, float value5, float value6,
		float value7, float value8, float value9
	);


	~Matrix3x3() = default;

public:

	// 行列
	float m[3][3];


public:

	/*---------------------------------------
		四則演算のオペレーター
	---------------------------------------*/

	inline Matrix3x3 operator+ (const Matrix3x3& other) const;
	inline Matrix3x3 operator- (const Matrix3x3& other) const;
	inline Matrix3x3 operator* (const Matrix3x3& other) const;
	//inline Matrix3x3 operator/ (const Matrix3x3& other) const;
	inline Matrix3x3& operator+= (const Matrix3x3& other);
	inline Matrix3x3& operator-= (const Matrix3x3& other);
	inline Matrix3x3& operator*= (const Matrix3x3& other);
	//inline Matrix3x3& operator/= (const Matrix3x3& other) const;


public: // user method

	/*---------------------------------------
		各行列の生成関数
		(ここの関数はインスタンスから呼び出さないようにする)
	---------------------------------------*/

	/// <summary>
	/// /// 単位行列を返す関数 ///
	/// </summary>
	static Matrix3x3 MakeIdentity(void);

	/// <summary>
	/// /// アフィン行列を生成 ///
	/// </summary>
	/// <param name="scale">	 S : 拡縮率		 </param>
	/// <param name="rotate">	 R : 回転角		 </param>
	/// <param name="translate"> T : 平行移動量	 </param>
	/// <returns>				 生成したaffine行列</returns>
	static Matrix3x3 MakeAffine(const Vec2f& scale, float rotate, const Vec2f& translate);

	//// SRT -----
	static Matrix3x3 MakeScale(const Vec2f& scale);
	static Matrix3x3 MakeRotate(float rotate);
	static Matrix3x3 MakeRotate(const Vec2f& dir);
	static Matrix3x3 MakeTranslate(const Vec2f& translate);

	/// <summary>
	/// <para> /// 引数の逆行列を生成 /// </para>
	/// 逆行列がないものは単位行列を返す
	/// </summary>
	/// <param name="m"> なにかしらの行列	</param>
	/// <returns>		 引数の逆行列		</returns>
	static Matrix3x3 MakeInverse(const Matrix3x3& m);

	/// <summary>
	/// /// ベクトルと行列の乗算 ///
	/// </summary>
	/// <param name="v">		適当なベクトル		</param>
	/// <param name="matrix">	適当な行列		</param>
	/// <returns>				計算結果			</returns>
	static Vec2f Transform(const Vec2f& v, const Matrix3x3& matrix);

	static QuadVerf Transform(const QuadVerf& vertex, const Matrix3x3& matrix);

};

