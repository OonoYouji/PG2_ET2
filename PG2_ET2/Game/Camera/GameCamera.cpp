#include "GameCamera.h"

#include "NovicePlus.h"

// Constructor & Destructor
GameCamera::GameCamera() { Init(); }
GameCamera::~GameCamera() { Finalize(); }


/*===========================================
	初期化関数
===========================================*/
void GameCamera::Init() {

	worldPos_ = { 640.0f, 360.0f };
	theta_ = 0.0f;
	scale_ = { 1.0f,1.0f };

	size_ = kWindowSize.castFloat();

	SetOrthoMatrix(
		{ { -size_.x * 0.5f,  size_.y * 0.5f },
		{    size_.x * 0.5f,  size_.y * 0.5f },
		{   -size_.x * 0.5f, -size_.y * 0.5f },
		{    size_.x * 0.5f, -size_.y * 0.5f } }
	);

	SetViewportMatrix({ 0.0f,0.0f }, kWindowSize.castFloat());

	BeginFrame();
	isMove_ = true;
	MakeMatrix();

}


/*===========================================
	更新処理関数
===========================================*/
void GameCamera::Updata() {
	BeginFrame();
	//ImGuiDebug("debug", "gameCamera");
	MakeMatrix();
}


/*===========================================
	終了処理関数
===========================================*/
void GameCamera::Finalize() {
}

void GameCamera::ResetOrthoMatrix() {

	SetOrthoMatrix(
		{ { -size_.x * 0.5f,  size_.y * 0.5f },
		{    size_.x * 0.5f,  size_.y * 0.5f },
		{   -size_.x * 0.5f, -size_.y * 0.5f },
		{    size_.x * 0.5f, -size_.y * 0.5f } }
	);

}
