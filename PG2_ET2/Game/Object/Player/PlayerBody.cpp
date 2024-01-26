#include "PlayerBody.h"

#include "Target.h"

PlayerBody::PlayerBody(Target* target) { Init(target); }
PlayerBody::~PlayerBody() { Finalize(); }



void PlayerBody::Init(Target* target) {

	worldPos_ = { 640.0f,360.0f };
	theta_ = 0.0f;
	scale_ = { 1.0f,1.0f };

	size_ = { 32.0f,32.0f };

	localVertex_ = MyMath::MakeLocalVertex(size_);

	MakeWorldMatrix();

	color_ = WHITE;

	moveDirection_ = { 0.0f,0.0f };
	speed_ = 8.0f;

	velocity_ = moveDirection_ * speed_;


	isAlive_ = true;

	p_target_ = target;

}

void PlayerBody::Updata() {

	/// 最初
	BeginFrame();

	Move();

	/// 行列に変換
	MakeWorldMatrix();
}

void PlayerBody::Draw() {

	//// ↓↓↓ 影の描画 -----
	Novice::SetBlendMode(kBlendModeAdd);
	NovicePlus::DrawSpriteScreen(
		worldMatrix_,
		size_ * 3.0f,
		Vec2f(128.0f, 128.0f),
		"circle",
		0x40404010
	);
	Novice::SetBlendMode(kBlendModeNormal);
	//// ↑↑↑


	//// 自機の描画 -----
	NovicePlus::DrawQuadScreen(
		localVertex_,
		worldMatrix_,
		{ 0.0f,0.0f, },
		{ 32.0f,32.0f, },
		"playerBody",
		color_
	);

}



void PlayerBody::Finalize() { }

void PlayerBody::BeginFrame() {


	/// 入力処理;
	Input();

	theta_ = MyMath::Theta(Vec2Method::Direction(worldPos_, p_target_->GetWorldPos(), true));

}

void PlayerBody::ImGuiDebug() {
#ifdef _DEBUG
	ImGui::Begin("debug");

	if (ImGui::TreeNode("playerBody")) {

		ImGui::DragFloat2("worldPos", &worldPos_.x, 0.5f);
		ImGui::DragFloat("theta", &theta_, 0.01f);
		ImGui::DragFloat2("scale", &scale_.x, 0.01f);


		ImGui::TreePop();
	}

	ImGui::End();
#endif // _DEBUG
}

void PlayerBody::MakeWorldMatrix() {
	worldMatrix_ = Matrix3x3::MakeAffine(scale_, theta_, worldPos_);
	worldVertex_ = Matrix3x3::Transform(localVertex_, worldMatrix_);
}

void PlayerBody::MakeWorldMatrix(const Vec2f& shakeValue) {
	worldMatrix_ = Matrix3x3::MakeAffine(scale_, theta_, worldPos_ + shakeValue);
}

void PlayerBody::Input() {

	moveDirection_ = NovicePlus::InputDirection();

}

void PlayerBody::Move() {

	velocity_ = moveDirection_ * speed_;

	worldPos_ += velocity_;

}
