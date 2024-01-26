#pragma once

#include <NovicePlus.h>

class Target {
	friend class Player;
public: // member method

	// Constructor & Destructor
	Target();
	~Target();

	// default method
	void Init();
	void Update();
	void Draw();
	void Finalize();

private: // member object

	/*-----------------------------
		基礎変数
	-----------------------------*/

	Vec2f worldPos_;
	float theta_;
	Vec2f scale_;

	Vec2f size_;

	QuadVerf localVertex_;
	Matrix3x3 worldMatrix_;


	/*-----------------------------
		その他
	-----------------------------*/


public:

	void BeginFrame();

	void MakeWorldMatrix();

public:

	Vec2f GetWorldPos(void) const { return worldPos_; }


};

