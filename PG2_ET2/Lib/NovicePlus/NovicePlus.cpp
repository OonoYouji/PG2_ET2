#include "NovicePlus.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include "GameTextureManager.h"
#include "GameManager.h"

/*=====================================
	static member object Initialize
=====================================*/
InputManager* NovicePlus::input_;
ICamera* NovicePlus::camera_ = nullptr;
WindowMode NovicePlus::windowMode_;

void NovicePlus::Init(void) {
	input_ = new InputManager();
	windowMode_ = kWindowed;

	GameTextureManager::Init();
	GameManager::Init();

}

void NovicePlus::BeginFrame(void) {
	input_->Update();

	WindowModeChange();

	if (camera_) { camera_->Updata(); }

}

void NovicePlus::Finalize(void) {
	SafeDelete(input_);
}


void NovicePlus::WindowModeChange() {
	if (NovicePlus::IsTriggerKey(DIK_F12)) {
		if (windowMode_ != kWindowed) {
			windowMode_ = kWindowed;
		} else {
			windowMode_ = kFullscreen;
		}
		Novice::SetWindowMode(windowMode_);
	}
}

/*========================================================
	Input --- Keys
========================================================*/

bool NovicePlus::IsTriggerKey(int dik) {
	return input_->IsTriggerKey(dik);
}

bool NovicePlus::IsPressKey(int dik) {
	return input_->IsPressKey(dik);
}

bool NovicePlus::IsReleaseKey(int dik) {
	return input_->IsReleaseKey(dik);
}

/*=======================================================
	Input --- Mouse
=======================================================*/

Vec2f NovicePlus::GetMousePos(void) {
	return input_->GetMousePos().castFloat();
}

bool NovicePlus::IsTriggerMouse(int no) {
	return input_->IsTriggerMouse(no);
}

bool NovicePlus::IsPressMouse(int no) {
	return input_->IsPressMouse(no);
}

bool NovicePlus::IsReleaseMouse(int no) {
	return input_->IsReleaseMouse(no);
}

Vec2f NovicePlus::GetMouseWorldPos(void) {
	return Matrix3x3::Transform(NovicePlus::GetMousePos(), camera_->Screen2WorldMatrix());
}

Vec2f NovicePlus::InputDirection(void) {
	Vec2f dir{ 0.0f,0.0 };

	dir.y += NovicePlus::IsPressKey(DIK_W) or NovicePlus::IsPressKey(DIK_UP);
	dir.x -= NovicePlus::IsPressKey(DIK_A) or NovicePlus::IsPressKey(DIK_LEFT);
	dir.y -= NovicePlus::IsPressKey(DIK_S) or NovicePlus::IsPressKey(DIK_DOWN);
	dir.x += NovicePlus::IsPressKey(DIK_D) or NovicePlus::IsPressKey(DIK_RIGHT);

	return Vec2Method::Normalize(dir);
}

bool NovicePlus::IsDecisionMade(void) {
	return NovicePlus::IsTriggerKey(DIK_SPACE)
		|| NovicePlus::IsTriggerKey(DIK_RETURN);
}


/*=======================================================
	Draw
=======================================================*/


void NovicePlus::DrawBox(const Vec2f& center, const Vec2f& size, uint32_t color, FillMode fillMode) {

	Novice::DrawBox(
		static_cast<int>(center.x - (size.x * 0.5f)),
		static_cast<int>(center.y - (size.y * 0.5f)),
		static_cast<int>(size.x),
		static_cast<int>(size.y),
		0.0f,
		color,
		fillMode
	);;

}

void NovicePlus::DrawCircle(const Vec2f& center, float radius, uint32_t color, FillMode fillMode) {

	Novice::DrawEllipse(
		static_cast<int>(center.x),
		static_cast<int>(center.y),
		static_cast<int>(radius),
		static_cast<int>(radius),
		0.0f,
		color,
		fillMode
	);

}

void NovicePlus::DrawSprite(const Vec2f& pos, const Vec2f& drawSize, const Vec2f& graphSize, const std::string& key, uint32_t color) {

	Novice::DrawSprite(
		static_cast<int>(pos.x - drawSize.x * 0.5f),
		static_cast<int>(pos.y - drawSize.y * 0.5f),
		GameTextureManager::GetGraphHandle(key),
		drawSize.x / graphSize.x,
		drawSize.y / graphSize.y,
		0.0f,
		color
	);

}

void NovicePlus::DrawQuad(const QuadVerf& vertex, const Vec2f& lt, const Vec2f& graphSize, const std::string& key, uint32_t color) {

	Novice::DrawQuad(
		// left top
		static_cast<int>(vertex.lt.x),
		static_cast<int>(vertex.lt.y),
		// right top
		static_cast<int>(vertex.rt.x),
		static_cast<int>(vertex.rt.y),
		// left bottom
		static_cast<int>(vertex.lb.x),
		static_cast<int>(vertex.lb.y),
		// right bottom
		static_cast<int>(vertex.rb.x),
		static_cast<int>(vertex.rb.y),

		static_cast<int>(lt.x),
		static_cast<int>(lt.y),
		static_cast<int>(graphSize.x),
		static_cast<int>(graphSize.y),
		GameTextureManager::GetGraphHandle(key),
		color
	);

}

void NovicePlus::DrawBoxScreen(const Matrix3x3& worldMatrix, const Vec2f& size, uint32_t color, FillMode fillMode) {

	/// screen座標に変換 -----
	Vec2f screenPos = Matrix3x3::Transform({ 0.0f,0.0f }, camera_->MakeWvpVpMatrix(worldMatrix));

	//// 描画 -----
	NovicePlus::DrawBox(
		screenPos,
		size,
		color,
		fillMode
	);

}

void NovicePlus::DrawCircleScreen(const Matrix3x3& worldMatrix, float radius, uint32_t color, FillMode mode) {

	/// screen座標に変換 -----
	Vec2f screenPos = Matrix3x3::Transform({ 0.0f,0.0f }, camera_->MakeWvpVpMatrix(worldMatrix));

	//// 描画 -----
	NovicePlus::DrawCircle(
		screenPos,
		radius,
		color,
		mode
	);

}

void NovicePlus::DrawSpriteScreen(const Matrix3x3& worldMatrix, const Vec2f& drawSize, const Vec2f& graphSize, const std::string key, uint32_t color) {

	/// screen座標に変換 -----
	Vec2f pos = Matrix3x3::Transform({ 0.0f,0.0f }, camera_->MakeWvpVpMatrix(worldMatrix));

	//// 描画 -----
	NovicePlus::DrawSprite(
		pos,
		drawSize,
		graphSize,
		key,
		color
	);

}

void NovicePlus::DrawQuadScreen(const QuadVerf& localVertex, const Matrix3x3& worldMatrix, const Vec2f& lt, const Vec2f& graphSize, const std::string& key, uint32_t color) {

	/// screen座標に変換 -----
	QuadVerf worldVertex = Matrix3x3::Transform(localVertex, camera_->MakeWvpVpMatrix(worldMatrix));

	//// 描画 -----
	NovicePlus::DrawQuad(
		worldVertex,
		lt,
		graphSize,
		key,
		color
	);

}

void NovicePlus::SetCamera(ICamera* newCamera) {
	camera_ = newCamera;
}
