#include "Bullet.h"



// Constructor & Destructor
Bullet::Bullet() { Init(); }
Bullet::~Bullet() { Finalize(); }



void Bullet::Init() {

	worldPos_ = { 0.0f,0.0f };
	theta_ = 0.0f;
	scale_ = { 1.0f,1.0f };

	size_ = Vec2f(32.0f, 64.0f) / 4.0f;

	localVertex_ = MyMath::MakeLocalVertex(size_);

	MakeWorldMatrix();

	hitBoxRadius_ = size_.y;

	moveDirection_ = { 0.0f,0.0f };
	speed_ = 30.0f;

	velocity_ = moveDirection_ * speed_;

	frameCount_ = 0;

	shadowLocalVertex_ = MyMath::MakeLocalVertex(Vec2f(1.0f, 1.0f) * 64.0f);

}



void Bullet::Update() {

	BeginFrame();


	Move();
	MakeWorldMatrix();

}

void Bullet::Draw() {

	NovicePlus::DrawQuadScreen(
		localVertex_,
		worldMatrix_,
		{ 0.0f,0.0f },
		{ 1.0f,1.0f },
		"white1x1",
		0xd0d0cbff
	);

}

void Bullet::Finalize() { }


void Bullet::BeginFrame() {

	preWorldPos_ = worldPos_;

	frameCount_++;

}

void Bullet::MakeWorldMatrix() {
	worldMatrix_ = Matrix3x3::MakeAffine(scale_, theta_, worldPos_);
}

bool Bullet::IsEnd() {
	return frameCount_ > 180;
}

void Bullet::Shot(const Vec2f& worldPos, const Vec2f& moveDirection) {

	worldPos_ = worldPos;
	moveDirection_ = moveDirection;
	velocity_ = moveDirection_ * speed_;

	theta_ = std::atan2f(-moveDirection_.y, moveDirection_.x) + (1.0f / 2.0f * 3.14f);

}

void Bullet::Move() {
	worldPos_ += velocity_;
}

void Bullet::DrawShadow() {

	NovicePlus::DrawQuadScreen(
		shadowLocalVertex_,
		worldMatrix_,
		Vec2f(0.0f, 0.0f),
		Vec2f(128.0f, 128.0f),
		"circle",
		0x50505030
	);

	Matrix3x3 world = Matrix3x3::MakeAffine({ 1.25f,1.25f }, theta_, worldPos_);
	NovicePlus::DrawQuadScreen(
		localVertex_,
		world,
		{ 0.0f,0.0f },
		{ 1.0f,1.0f },
		"white1x1",
		0xd0d0cb50
	);


}
