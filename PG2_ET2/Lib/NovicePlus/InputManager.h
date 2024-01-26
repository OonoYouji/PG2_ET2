#pragma once
#include <Novice.h>
#include "MyVector2.h"

class InputManager final {
public: // member method

	// constructor & destructor
	InputManager(void);
	~InputManager() = default;

	// default method
	void Update(void);

private: // member object

	// キーの入力状況
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

	// マウスのリリース入力に使う
	bool preMouseBottom_[7] = { 0 };
	// マウスの位置
	Vec2 mousePos_;

	// コントローラーのリリース入力に使用
	//bool preButton

private:

	// copyConstructor 禁止
	InputManager(const InputManager& obj) = delete;
	// 代入演算子の禁止
	InputManager& operator=(const InputManager& obj) = delete;

public: // member method


	// キーボードの入力
	bool IsTriggerKey(int DIK) const;
	bool IsPressKey(int DIK) const;
	bool IsReleaseKey(int DIK) const;

	// マウスの入力; 位置
	bool IsTriggerMouse(int buttonNo) const;
	bool IsPressMouse(int buttonNo) const;
	bool IsReleaseMouse(int buttonNo) const;
	Vec2 GetMousePos(void) { return mousePos_; }
	// ホイールの回転
	int GetWheel(void) const;
	bool IsWheelUP(void) const;
	bool IsWheelDown(void) const;

	// コントローラーの入力;
	bool IsTriggerButton(int stickNo, PadButton button) const;
	bool IsPressButton(int stickNo, PadButton button) const;
	//bool isReleaseButton(int stickNo, PadButton button) const;

};
