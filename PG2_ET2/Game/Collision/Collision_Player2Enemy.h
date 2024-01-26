#pragma once

class Player;
class EnemyManager;
#include <EnemyBody.h>
#include <Bullet.h>

class Collision_Player2Enemy {
public:

	Collision_Player2Enemy(Player* player, EnemyManager* enemyManager);
	~Collision_Player2Enemy();

	void Init(Player* player, EnemyManager* enemyManager);
	void Update();
	//void Draw();
	void Finalize();

private:

	Player* p_player_;
	EnemyManager* p_enemy_;
	Bullet bullet_;
	EnemyBody* enemyBody_;

	bool isCollision_player2enemy_;
	bool preIsCollision_player2enemy_;

	int shakeFrame_;
	int shakeFrameLimit_;

	void Collision_Body();
	void Collision_Bullet();

	bool CheckCollision_Body2Enemy();

};