#include "EnemyBody.h"



EnemyBody::EnemyBody() { Init(); }
EnemyBody::~EnemyBody() { Finalize(); }



void EnemyBody::Init() {

	worldPos_ = Vec2f(0.0f, 0.0f);
	theta_ = 0.0f;
	scale_ = Vec2f(1.0f, 1.0f);

	size_ = Vec2f(32.0f, 32.0f);

	localVertex_ = MyMath::MakeLocalVertex(size_);
	MakeWorldMatrix();

	isAlive_ = true;

	moveDirection_ = Vec2Method::Normalize(Vec2f(Random::Float(-1.0f,1.0f), Random::Float(-1.0f, 1.0f)));
	speed_ = Random::Float(2.0f, 3.0f);

	velocity_ = moveDirection_ * speed_;

	currentFrame_ = 0;
	limitFrame_ = 60 * 10;

	hitBoxRadius_ = size_.x * scale_.x;

}

void EnemyBody::Update() {

	currentFrame_++;

	worldPos_ += velocity_;
	MakeWorldMatrix();

}

void EnemyBody::Draw() {

	NovicePlus::DrawQuadScreen(
		localVertex_,
		worldMatrix_,
		Vec2f(0.0f, 0.0f),
		Vec2f(32.0f, 32.0f),
		"enemyBody",
		WHITE
	);

	NovicePlus::DrawQuadScreen(
		localVertex_,
		Matrix3x3::MakeAffine(scale_, theta_, worldPos_ + (moveDirection_ * (scale_ * 5.0f))),
		Vec2f(0.0f, 0.0f),
		Vec2f(32.0f, 32.0f),
		"enemyEye",
		WHITE
	);

}

void EnemyBody::Finalize() {
}




void EnemyBody::StartSeting(const Vec2f& worldPos, float scale) {

	worldPos_ = worldPos;
	scale_ = Vec2f(scale, scale);

	hitBoxRadius_ = size_.x * scale_.x;

	MakeWorldMatrix();

}

void EnemyBody::BeginFrame() {
}

void EnemyBody::MakeWorldMatrix() {
	worldMatrix_ = Matrix3x3::MakeAffine(scale_, theta_, worldPos_);
}


