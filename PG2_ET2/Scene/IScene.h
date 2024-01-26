#pragma once

class IScene {
public: // member method

	// 仮想デストラクタ
	virtual ~IScene() = default;

	// default method
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Finalize() = 0;

private: // member object

	IScene& operator=(const IScene& other) = delete;
	IScene& operator=(IScene&& other) = delete;

};