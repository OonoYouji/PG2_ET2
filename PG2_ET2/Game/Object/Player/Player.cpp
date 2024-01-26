#include "Player.h"

#include "NovicePlus.h"

Player::Player() { Init(); }
Player::~Player() { Finalize(); }



void Player::Init() {

	target_ = new Target();
	body_ = new PlayerBody(target_);

	shotCT_ = 0;

	hp_ = 10;
	isAlive_ = true;

	enemyKillCount_ = 0;

}

void Player::Updata() {

	body_->Updata();

	target_->Update();

	Shot();
	DeleteBullet();

	for (auto& bullet : bullets_) {
		bullet.Update();
	}

}

void Player::Draw() {

	Novice::SetBlendMode(kBlendModeAdd);
	for (auto& bullet : bullets_) {
		bullet.DrawShadow();
	}
	Novice::SetBlendMode(kBlendModeNormal);
	for (auto& bullet : bullets_) {
		bullet.Draw();
	}

	body_->Draw();

	target_->Draw();

}

void Player::Finalize() {
	SafeDelete(body_);
	bullets_.clear();
	SafeDelete(target_);
}

void Player::Shot() {

	shotCT_--;
	if (shotCT_ > 0) { return; }

	if (!NovicePlus::IsPressMouse(0)) { return; }

	/// ↓↓↓ ここから先は撃たれたときの処理

	bullets_.push_back(Bullet());

	/// end()の一個前がpush_back()したBullet;
	auto bulletItr = bullets_.end();
	bulletItr--;

	bulletItr->Shot(
		body_->worldPos_,
		Vec2Method::Direction(
			body_->worldPos_,
			target_->worldPos_ /*+ Vec2f(Random::Float(-10, 10), Random::Float(-10, 10))*/,
			true
		)
	);

	shotCT_ = 3;

}

void Player::DeleteBullet() {

	for (auto it = bullets_.begin(); it != bullets_.end();) {
		if (it->IsEnd()) {
			it = bullets_.erase(it);
		} else {
			it++;
		}
	}

}

void Player::BodyMakeWorldMatrix(const Vec2f& shakeValue) {
	body_->MakeWorldMatrix(shakeValue);
}
