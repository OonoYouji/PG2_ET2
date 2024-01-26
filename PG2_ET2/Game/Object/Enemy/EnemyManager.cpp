#include <EnemyManager.h>

#include <GameCamera.h>


EnemyManager::EnemyManager() { Init(); }
EnemyManager::~EnemyManager() { Finalize(); }



void EnemyManager::Init() { }

void EnemyManager::Update() {

	for (auto& enemy : enemies_) {
		enemy->Update();
	}

	int random = Random::Int(1, 5);
	for (int i = 0; i < random; i++) {
		NewEnemy();
	}

	DeleteEnemy();

}

void EnemyManager::Draw() {

	for (auto& enemy : enemies_) {
		enemy->Draw();
	}

}

void EnemyManager::Finalize() {
	enemies_.clear();
	p_camera_ = nullptr;
}



void EnemyManager::DeleteEnemy() {
	for (auto it = enemies_.begin(); it != enemies_.end();) {
		if ((*it)->IsEnd()) {
			it = enemies_.erase(it);
		} else {
			it++;
		}
	}
}

void EnemyManager::NewEnemy() {

	/// 0以外はreturn;
	if (Random::Int(0, 32)) { return; }

	enemies_.push_back(new EnemyBody());

	(*enemies_.rbegin())->StartSeting(
		Vec2f(Random::Float(0.0f, p_camera_->GetWorldPos().x + p_camera_->GetSize().x),
			Random::Float(0.0f, p_camera_->GetWorldPos().y + p_camera_->GetSize().y)),
		Random::Float(1.0f, 1.5f)
	);

}
