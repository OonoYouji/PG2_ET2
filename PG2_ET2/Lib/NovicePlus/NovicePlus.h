#pragma once

// Include -----
// Orignal
#include "InputManager.h"
#include "ICamera.h"
#include "Environment.h"
#include "MyMath.h"
#include "MyVector2.h"
#include "QuadVertex.h"
#include "MyMatrix3x3.h"
#include "Collision.h"
#include "Ease.h"
#include "Random.h"
// else
#include <Novice.h>
#include <SafeDelete.h>
#include <imgui.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

class NovicePlus {
public: // member method

	// Constructor & Destructor
	NovicePlus() = default;
	~NovicePlus() = default;

	static void Init(void);
	static void Finalize(void);

	static void BeginFrame(void);


private: // member object

	static InputManager* input_;
	static ICamera* camera_;

	static WindowMode windowMode_;

public: // member method


	static void WindowModeChange();

	/*=================================================
		Input
	=================================================*/

	// Key -----
	static bool IsTriggerKey(int dik);
	static bool IsPressKey(int dik);
	static bool IsReleaseKey(int dik);

	// Mouse -----
	static Vec2f GetMousePos(void);
	static bool IsTriggerMouse(int no);
	static bool IsPressMouse(int no);
	static bool IsReleaseMouse(int no);

	static Vec2f GetMouseWorldPos(void);

	static Vec2f InputDirection(void);

	/// <summary>
	/// 決定ボタンを押したかどうか
	/// </summary>
	static bool IsDecisionMade(void);

	/*================================================
		Draw
	================================================*/

	
	/// <summary>
	/// 矩形を描画する関数
	/// </summary>
	/// <param name="center">矩形の中心</param>
	/// <param name="size">矩形の縦幅、横幅</param>
	/// <param name="color">矩形の色</param>
	/// <param name="fillMode">矩形をぶり潰すか</param>
	static void DrawBox(
		const Vec2f& center,
		const Vec2f& size,
		uint32_t color,
		FillMode fillMode = kFillModeSolid
	);

	/// <summary>
	/// 円を描画するための関数
	/// </summary>
	/// <param name="center">円の中心</param>
	/// <param name="radius">円の半径</param>
	/// <param name="color">円の色</param>
	/// <param name="fillMode">円を塗りつぶすか</param>
	static void DrawCircle(
		const Vec2f& center,
		float radius,
		uint32_t color,
		FillMode fillMode = kFillModeSolid
	);


	static void DrawSprite(
		const Vec2f& pos,
		const Vec2f& drawSize,
		const Vec2f& graphSize,
		const std::string& key,
		uint32_t color
	);

	/// <summary>
	/// 画像込みの矩形を描画する関数
	/// </summary>
	/// <param name="vertex">矩形の4頂点</param>
	/// <param name="lt">画像の描画したい位置の左上座標</param>
	/// <param name="graphSize">画像の大きさ</param>
	/// <param name="key">GameTextureManagerから得る画像のkey</param>
	/// <param name="color">矩形の色</param>
	static void DrawQuad(
		const QuadVerf& vertex,
		const Vec2f& lt,
		const Vec2f& graphSize,
		const std::string& key,
		uint32_t color
	);


	static void DrawBoxScreen(
		const Matrix3x3& worldMatrix,
		const Vec2f& size,
		uint32_t color,
		FillMode fillMode = kFillModeSolid
	);

	static void DrawCircleScreen(
		const Matrix3x3& worldMatrix,
		float radius,
		uint32_t color,
		FillMode mode = kFillModeSolid
	);

	static void DrawSpriteScreen(
		const Matrix3x3& worldMatrix,
		const Vec2f& drawSize,
		const Vec2f& graphSize,
		const std::string key,
		uint32_t color
	);

	static void DrawQuadScreen(
		const QuadVerf& localVertex,
		const Matrix3x3& worldMatrix,
		const Vec2f& lt,
		const Vec2f& graphSize,
		const std::string& key,
		uint32_t color
	);


	/*================================================
		Camera
	================================================*/

	/// <summary>
	/// カメラのセッター
	/// </summary>
	/// <param name="newCamera"></param>
	static void SetCamera(ICamera* newCamera);


};

