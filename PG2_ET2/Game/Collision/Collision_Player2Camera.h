#pragma once

#include <NovicePlus.h>
class Player;
class GameCamera;

class Collision_Player2Camera final {
public: /// member method

	Collision_Player2Camera(Player* player, GameCamera* camera);
	~Collision_Player2Camera();

	void Init(Player* player, GameCamera* camera);
	void Update();
	//void Draw();
	void Finalize();

private:

	Player* p_player_;
	GameCamera* p_camera_;

	Vec2f distance_;
	float scale_;

};