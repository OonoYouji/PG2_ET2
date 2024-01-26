#include <Collision_Player2Camera.h>

#include <Player.h>
#include <GameCamera.h>

Collision_Player2Camera::Collision_Player2Camera(Player* player, GameCamera* camera) {
	Init(player, camera);
}
Collision_Player2Camera::~Collision_Player2Camera() { Finalize(); }



void Collision_Player2Camera::Init(Player* player, GameCamera* camera) {

	p_player_ = player;
	p_camera_ = camera;

	distance_ = p_player_->GetWorldPos() - p_camera_->GetWorldPos();
	scale_ = 1.0f;

}

void Collision_Player2Camera::Update() {

	if (!Collision::Rect::Circle(
		p_camera_->GetWorldVertex(),
		p_player_->GetWorldPos(),
		p_player_->GetHitBoxRadius())) {


		distance_ = p_player_->GetWorldPos() - p_camera_->GetWorldPos();

		distance_ = {
			std::abs(distance_.x),
			std::abs(distance_.y)
		};

		//scale_ = 1.0f;
		if (distance_.x > distance_.y) {
			scale_ = (distance_.x + 300.0f) / (kWindowSize.castFloat().x * 0.5f);
		} else {
			scale_ = (distance_.y + 300.0f) / (kWindowSize.castFloat().y * 0.5f);
		}

		scale_ = std::clamp(scale_, 1.0f, 1.5f);

		p_camera_->SetSize(kWindowSize.castFloat() * scale_);
		p_camera_->ResetOrthoMatrix();

	}

}

void Collision_Player2Camera::Finalize() {

	p_player_ = nullptr;
	p_camera_ = nullptr;

}
