#pragma once
#include "IScene.h"

#include "NovicePlus.h"

class GameCamera;
class Player;
class EnemyManager;
class Collision_Player2Camera;
class Collision_Player2Enemy;

class Scene_Game final
	: public IScene {
public: // member method

	// Constructor & Desturctor
	Scene_Game();
	~Scene_Game();

	// default method
	void Init() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private: // member object

	// Object
	GameCamera* camera_ = nullptr;

	Player* player_ = nullptr;

	EnemyManager* enemyManager_ = nullptr;


	Collision_Player2Camera* collision_player2camera_ = nullptr;
	Collision_Player2Enemy* collision_player2enemy_ = nullptr;


};

