#pragma once

//// Include 
#include "NovicePlus.h"


class Bullet {
public: // member method

	// Constructor & Destructor
	Bullet();
	~Bullet();

	// default method
	void Init();
	void Update();
	void Draw();
	void Finalize();

private:

	/*-------------------------
		基礎変数
	-------------------------*/

	Vec2f worldPos_;
	float theta_;
	Vec2f scale_;

	Vec2f size_;

	QuadVerf localVertex_;
	Matrix3x3 worldMatrix_;



	/*-------------------------
		その他
	-------------------------*/

	float hitBoxRadius_;
	Vec2f preWorldPos_;

	Vec2f moveDirection_;
	float speed_;

	Vec2f velocity_;


	int frameCount_;

	QuadVerf shadowLocalVertex_;

public:


	void BeginFrame();


	/// <summary>
	/// world座標系の生成
	/// </summary>
	void MakeWorldMatrix();


	/// <summary>
	/// 弾が撃ち終わったときの条件
	/// </summary>
	/// <returns></returns>
	bool IsEnd();

	/// <summary>
	/// 発射方向を設定する
	/// </summary>
	/// <param name="moveDirection"></param>
	void Shot(const Vec2f& worldPos, const Vec2f& moveDirection);


	/// <summary>
	/// 弾道計算
	/// </summary>
	void Move();


	void DrawShadow();


public:

	Vec2f GetWorldPos() const {
		return worldPos_;
	}

	float GetHitBoxRadius() const {
		return hitBoxRadius_;
	}


};