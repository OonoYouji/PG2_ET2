#pragma once
#include "ICamera.h"

/// <summary>
/// scene_gameで使用するカメラ
/// </summary>
class GameCamera final
	: public ICamera {
public: // member method

	// Constructor & Destructor
	GameCamera();
	~GameCamera();

	// default method
	void Init() override;
	void Updata() override;
	//void Init() override;
	void Finalize() override;

private: // member object


public: // user method

	void ResetOrthoMatrix();

};

