#pragma once

/// Include -----
#include "NovicePlus.h"
#include "PlayerBody.h"
#include "Bullet.h"
#include "Target.h"

class Player final {
public:

	Player();
	~Player();

	// default method
	void Init();
	void Updata();
	void Draw();
	void Finalize();

private:

	PlayerBody* body_ = nullptr;
	std::vector<Bullet> bullets_;
	Target* target_ = nullptr;

	int shotCT_;

	int hp_;
	bool isAlive_;

	int enemyKillCount_;

public:

	void Shot();
	void DeleteBullet();

public:

	Vec2f GetWorldPos() {
		return body_->worldPos_;
	}

	float GetHitBoxRadius() {
		return body_->hitBoxRadius_;
	}

	void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }
	bool GetIsAlive() { return isAlive_; }

	int GetHP() const { return hp_; }
	void SetHP(int hp) { hp_ = hp; }
	
	int GetEnemyKillCount() const { return enemyKillCount_; }
	void SetEnemyKillCount(int enemyKillCount) { enemyKillCount_ = enemyKillCount; }


	std::vector<Bullet> GetBullet() const {
		return bullets_;
	}

	void BodyMakeWorldMatrix(const Vec2f& shakeValue);

};




