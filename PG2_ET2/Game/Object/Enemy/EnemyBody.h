#pragma once

#include "NovicePlus.h"


class EnemyBody {
	friend class EnemyManager;
public:

	EnemyBody();
	~EnemyBody();

	void Init();
	void Update();
	void Draw();
	void Finalize();

private:

	/*--------------------------
		基礎変数
	--------------------------*/

	Vec2f worldPos_;
	float theta_;
	Vec2f scale_;

	Vec2f size_;

	QuadVerf localVertex_;
	Matrix3x3 worldMatrix_;


	/*--------------------------
		その他
	--------------------------*/

	bool isAlive_;


	Vec2f moveDirection_;
	float speed_;

	Vec2f velocity_;

	int currentFrame_;
	int limitFrame_;

	float hitBoxRadius_;


public:

	void StartSeting(const Vec2f& worldPos, float scale);

	void BeginFrame();

	void MakeWorldMatrix();

	/// フラグとは別の寿命
	bool IsEnd() {
		return currentFrame_ >= limitFrame_
			|| !isAlive_;
	}

	bool GetIsAlive() const {
		return isAlive_;
	}

	Vec2f GetWorldPos() const {
		return worldPos_;
	}

	float GetHitBoxRadius() const {
		return hitBoxRadius_;
	}

	void SetIsAlive(bool isAlive) {
		isAlive_ = isAlive;
	}

};