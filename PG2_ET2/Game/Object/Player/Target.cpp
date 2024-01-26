#include "Target.h"



Target::Target() { Init(); }
Target::~Target() { Finalize(); }



void Target::Init() {

	worldPos_ = { 0.0f,0.0f };
	theta_ = 0.0f;
	scale_ = { 1.0f,1.0f };

	size_ = { 16.0f,16.0f };

	localVertex_ = MyMath::MakeLocalVertex(size_);

	MakeWorldMatrix();

}

void Target::Update() {

	BeginFrame();


	MakeWorldMatrix();

}

void Target::Draw() {

	NovicePlus::DrawQuadScreen(
		localVertex_,
		worldMatrix_,
		{ 0.0f,0.0f },
		{ 1.0f,1.0f },
		"white1x1",
		0x00dd0050
	);

}

void Target::Finalize() {
}



void Target::BeginFrame() {

	worldPos_ = NovicePlus::GetMouseWorldPos();

}

void Target::MakeWorldMatrix() {
	worldMatrix_ = Matrix3x3::MakeAffine(scale_, theta_, worldPos_);
}
