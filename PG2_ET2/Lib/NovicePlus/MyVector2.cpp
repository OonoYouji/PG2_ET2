#include "MyVector2.h"

// Include -----
// Math
#include "NovicePlus.h"

/*========================================================
	コンストラクタ
========================================================*/
Vec2f::Vec2f(const Vec2f& v) {
	this->x = v.x;
	this->y = v.y;
}

Vec2f::Vec2f(float x, float y) {
	this->x = x;
	this->y = y;
}

Vec2f Vec2Method::Direction(const Vec2f& pos1, const Vec2f& pos2, bool normalize) {
	if (normalize) { return Normalize(pos2 - pos1); }
	return pos2 - pos1;
}


Vec2f Vec2Method::Normalize(const Vec2f& vector) {
	//vectorの長さを計算
	Vec2f result = vector;
	float length = sqrtf(powf(vector.x, 2.0f) + powf(vector.y, 2.0f));

	//0割り禁止
	if (length != 0) {
		result /= length;
	}

	return result;
}


float Vec2Method::Length(const Vec2f& pos1, const Vec2f& pos2) {
	return sqrtf(powf(pos2.x - pos1.x, 2.0f) + powf(pos2.y - pos1.y, 2.0f));;
}


Vec2f Vec2Method::Distance(const Vec2f& pos1, const Vec2f& pos2) {
	return pos2 - pos1;
}


float Vec2Method::DotProduct(const Vec2f& dir1, const Vec2f& dir2) {
	return ((dir1.x * dir2.x) + (dir1.y * dir2.y));
}


float Vec2Method::CrossProduct(const Vec2f& dir1, const  Vec2f& dir2) {
	return dir1.x * dir2.y - dir1.y * dir2.x;
}

Vec2f Vec2Method::Lerp(const Vec2f& start, const Vec2f& end, float t) {
	return Vec2f(
		MyMath::Lerp(t, start.x, end.x),
		MyMath::Lerp(t, start.y, end.y)
	);
}


/*========================================================
	コンストラクタ
========================================================*/

Vec2::Vec2(const Vec2& v) {
	this->x = v.x;
	this->y = v.y;
}

Vec2::Vec2(int x, int y) {
	this->x = x;
	this->y = y;
}



Vec2f Vec2::castFloat() const {
	return Vec2f(
		static_cast<float>(this->x),
		static_cast<float>(this->y)
	);
}
