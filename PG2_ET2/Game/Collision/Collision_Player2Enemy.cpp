#include <Collision_Player2Enemy.h>


#include <Player.h>
#include <EnemyManager.h>
#include <EnemyBody.h>
#include <Bullet.h>

Collision_Player2Enemy::Collision_Player2Enemy(Player* player, EnemyManager* enemyManager) {
	Init(player, enemyManager);
}
Collision_Player2Enemy::~Collision_Player2Enemy() { Finalize(); }



void Collision_Player2Enemy::Init(Player* player, EnemyManager* enemyManager) {

	p_player_ = player;
	p_enemy_ = enemyManager;

	shakeFrame_ = 30;
	shakeFrameLimit_ = 30;

}


void Collision_Player2Enemy::Update() {

	preIsCollision_player2enemy_ = isCollision_player2enemy_;
	isCollision_player2enemy_ = false;

	Collision_Body();
	Collision_Bullet();

	if (shakeFrame_ < shakeFrameLimit_) {
		shakeFrame_++;
		p_player_->BodyMakeWorldMatrix(Vec2f(Random::Float(-50, 50), Random::Float(-50, 50)));
	} else {
		p_player_->BodyMakeWorldMatrix(Vec2f(0.0f, 0.0f));
	}

}

void Collision_Player2Enemy::Finalize() {

	p_player_ = nullptr;
	p_enemy_ = nullptr;

}



void Collision_Player2Enemy::Collision_Body() {
	isCollision_player2enemy_ = CheckCollision_Body2Enemy();
	if (!isCollision_player2enemy_) { return; }

	//// ここから衝突時の処理

	/// HPを減らす
	if (isCollision_player2enemy_ && !preIsCollision_player2enemy_) {
		p_player_->SetHP(p_player_->GetHP() - 1);
		shakeFrame_ = 0;
	}

	/// HPがなくなったら死亡
	if (p_player_->GetHP() <= 0) {
		p_player_->SetIsAlive(false);
	}

}

void Collision_Player2Enemy::Collision_Bullet() {

	for (int bi = 0; bi < p_player_->GetBullet().size(); bi++) {
		for (int ei = 0; ei < p_enemy_->GetEnemies().size(); ei++) {

			bullet_ = p_player_->GetBullet()[bi];
			enemyBody_ = p_enemy_->GetEnemies()[ei];
			if (!Collision::Circle::Circle(enemyBody_->GetWorldPos(), bullet_.GetWorldPos(), enemyBody_->GetHitBoxRadius() + bullet_.GetHitBoxRadius())) {
				continue;
			}

			///
			/// ↓当たったときの処理ここから
			///

			enemyBody_->SetIsAlive(false);
			p_player_->SetEnemyKillCount(p_player_->GetEnemyKillCount() + 1);

		}
	}

}

bool Collision_Player2Enemy::CheckCollision_Body2Enemy() {

	for (int ei = 0; ei < p_enemy_->GetEnemies().size(); ei++) {

		enemyBody_ = p_enemy_->GetEnemies()[ei];
		if (Collision::Circle::Circle(enemyBody_->GetWorldPos(), p_player_->GetWorldPos(), enemyBody_->GetHitBoxRadius() + p_player_->GetHitBoxRadius())) {
			return true;
		}
	}

	return false;
}
