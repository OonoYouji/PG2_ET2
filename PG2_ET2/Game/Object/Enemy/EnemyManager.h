#pragma once 

#include <EnemyBody.h>
#include <NovicePlus.h>
class GameCamera;

class EnemyManager final {
public: /// member method

	EnemyManager();
	~EnemyManager();

	void Init();
	void Update();
	void Draw();
	void Finalize();

private: /// member object

	std::vector<EnemyBody*> enemies_;

	GameCamera* p_camera_;

	void DeleteEnemy();
	void NewEnemy();

public:

	void SetCamera(GameCamera* camera) {
		p_camera_ = camera;
	}

	std::vector<EnemyBody*> GetEnemies() const {
		return enemies_;
	}

	/*Vec2f GetEnemyWorldPos(int index) const {
		return enemies_[index].worldPos_;
	}*/

};