#include "Scene_Game.h"

/// Include -----
// Manager
#include "GameManager.h"
// Scene/SceneTransition
#include "NormalTransition.h"
#include <Scene_Clear.h>
#include <Scene_GameOver.h>
// Object
#include "GameCamera.h"
#include "Player.h"
#include <EnemyManager.h>
// Collision
#include <Collision_Player2Camera.h>
#include <Collision_Player2Enemy.h>

// Constructor & Desturctor
Scene_Game::Scene_Game() { Init(); }
Scene_Game::~Scene_Game() { Finalize(); }


/*============================================
	初期化関数
============================================*/
void Scene_Game::Init() {

	camera_ = new GameCamera();
	NovicePlus::SetCamera(camera_);

	player_ = new Player();

	enemyManager_ = new EnemyManager();
	enemyManager_->SetCamera(camera_);

	collision_player2camera_ = new Collision_Player2Camera(player_, camera_);
	collision_player2enemy_ = new Collision_Player2Enemy(player_, enemyManager_);


}


/*============================================
	更新処理関数
============================================*/
void Scene_Game::Update() {

	player_->Updata();

	enemyManager_->Update();

	collision_player2camera_->Update();
	collision_player2enemy_->Update();

	/// GameOverの条件
	if (!player_->GetIsAlive()) {
		GameManager::SetNextScene(new Scene_GameOver(), false, new NormalTransition());
		return;
	}

	/// Clearの条件
	if (player_->GetEnemyKillCount() > 50) {
		GameManager::SetNextScene(new Scene_Clear(), false, new NormalTransition());
		return;
	}

}


/*============================================
	描画処理関数
============================================*/
void Scene_Game::Draw() {

	NovicePlus::DrawBox(
		Vec2f(640.0f, 360.0f),
		kWindowSize.castFloat(),
		0x202020ff
	);

	player_->Draw();

	enemyManager_->Draw();

}


/*============================================
	終了処理関数
============================================*/
void Scene_Game::Finalize() {
	SafeDelete(camera_);
	NovicePlus::SetCamera(nullptr);

	SafeDelete(player_);

	SafeDelete(enemyManager_);


	SafeDelete(collision_player2camera_);
	SafeDelete(collision_player2enemy_);

}


/*============================================
	その他メンバ関数
============================================*/