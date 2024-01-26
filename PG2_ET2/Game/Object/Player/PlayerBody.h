#pragma once

#include "NovicePlus.h"

class Target;

class PlayerBody final {
	friend class Player;
public:

	PlayerBody(Target* target);
	~PlayerBody();

	// default method
	void Init(Target* target);
	void Updata();
	void Draw();
	void Finalize();

private:

	/*--------------------------
		基礎変数
	--------------------------*/

	Vec2f worldPos_;
	float theta_;
	Vec2f scale_;

	Vec2f size_;

	QuadVerf localVertex_;
	Matrix3x3 worldMatrix_;

	uint32_t color_;


	/*--------------------------
		その他
	--------------------------*/

	float hitBoxRadius_;
	QuadVerf worldVertex_;

	Vec2f moveDirection_;
	float speed_;

	Vec2f velocity_;


	/*--------------------------
		フラグ
	--------------------------*/

	bool isAlive_;




	Target* p_target_;


public:


	void BeginFrame();

	void ImGuiDebug();

	void MakeWorldMatrix();
	void MakeWorldMatrix(const Vec2f& shakeValue);

	void Input();

	void Move();


};

