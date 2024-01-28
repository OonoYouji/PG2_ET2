#pragma once
#include "MyVector2.h"

enum VERTEX {
	LT, RT,
	LB, RB,
};

class QuadVerf final {
public:

	QuadVerf(const QuadVerf& other);
	QuadVerf(
		const Vec2f& lt,
		const Vec2f& rt,
		const Vec2f& lb,
		const Vec2f& rb
	);
	QuadVerf() = default;
	~QuadVerf() = default;

public:

	Vec2f vertices[4];

public:

	inline Vec2f operator[] (int index) const;
	inline Vec2f operator[] (int index);
	inline QuadVerf& operator= (const QuadVerf& other);
	inline QuadVerf operator+ (const QuadVerf& other) const;
	inline QuadVerf operator- (const QuadVerf& other) const;
	inline QuadVerf operator* (const QuadVerf& other) const;
	inline QuadVerf operator/ (const QuadVerf& other) const;
	inline QuadVerf& operator+= (const QuadVerf& other);
	inline QuadVerf& operator-= (const QuadVerf& other);
	inline QuadVerf& operator*= (const QuadVerf& other);
	inline QuadVerf& operator/= (const QuadVerf& other);

};

inline Vec2f QuadVerf::operator[](int index) const {
	return vertices[index];
}
inline Vec2f QuadVerf::operator[](int index) {
	return vertices[index];
}
inline QuadVerf& QuadVerf::operator=(const QuadVerf& other) {
	this->vertices[LT] = other[LT];
	this->vertices[RT] = other[RT];
	this->vertices[LB] = other[LB];
	this->vertices[RB] = other[RB];
	return *this;
}
inline QuadVerf QuadVerf::operator+(const QuadVerf& other) const {
	return QuadVerf(
		(*this)[LT] + other[LT],
		(*this)[RT] + other[RT],
		(*this)[LB] + other[LB],
		(*this)[RB] + other[RB]
	);
}
inline QuadVerf QuadVerf::operator-(const QuadVerf& other) const {
	return QuadVerf(
		(*this)[LT] - other[LT],
		(*this)[RT] - other[RT],
		(*this)[LB] - other[LB],
		(*this)[RB] - other[RB]
	);
}
inline QuadVerf QuadVerf::operator*(const QuadVerf& other) const {
	return QuadVerf(
		(*this)[LT] * other[LT],
		(*this)[RT] * other[RT],
		(*this)[LB] * other[LB],
		(*this)[RB] * other[RB]
	);
}
inline QuadVerf QuadVerf::operator/(const QuadVerf& other) const {
	return QuadVerf(
		(*this)[LT] / other[LT],
		(*this)[RT] / other[RT],
		(*this)[LB] / other[LB],
		(*this)[RB] / other[RB]
	);
}
inline QuadVerf& QuadVerf::operator+=(const QuadVerf& other) {
	*this = *this + other;
	return *this;
}
inline QuadVerf& QuadVerf::operator-=(const QuadVerf& other) {
	*this = *this - other;
	return *this;
}
inline QuadVerf& QuadVerf::operator*=(const QuadVerf& other) {
	*this = *this * other;
	return *this;
}
inline QuadVerf& QuadVerf::operator/=(const QuadVerf& other) {
	*this = *this / other;
	return *this;
}





class QuadVer final {
public:

	QuadVer(const QuadVer& other);
	QuadVer(
		const Vec2& lt,
		const Vec2& rt,
		const Vec2& lb,
		const Vec2& rb
	);
	QuadVer() = default;
	~QuadVer() = default;

public:

	Vec2 vertices[4];

public:

	inline Vec2 operator[] (int index) const;
	inline Vec2 operator[] (int index);
	inline QuadVer& operator= (const QuadVer& other);
	inline QuadVer operator+ (const QuadVer& other) const;
	inline QuadVer operator- (const QuadVer& other) const;
	inline QuadVer operator* (const QuadVer& other) const;
	inline QuadVer operator/ (const QuadVer& other) const;
	inline QuadVer& operator+= (const QuadVer& other);
	inline QuadVer& operator-= (const QuadVer& other);
	inline QuadVer& operator*= (const QuadVer& other);
	inline QuadVer& operator/= (const QuadVer& other);

};

inline Vec2 QuadVer::operator[](int index) const {
	return vertices[index];
}
inline Vec2 QuadVer::operator[](int index) {
	return vertices[index];
}
inline QuadVer& QuadVer::operator=(const QuadVer& other) {
	this->vertices[LT] = other[LT];
	this->vertices[RT] = other[RT];
	this->vertices[LB] = other[LB];
	this->vertices[RB] = other[RB];
	return *this;
}
inline QuadVer QuadVer::operator+(const QuadVer& other) const {
	return QuadVer(
		(*this)[LT] + other[LT],
		(*this)[RT] + other[RT],
		(*this)[LB] + other[LB],
		(*this)[RB] + other[RB]
	);
}
inline QuadVer QuadVer::operator-(const QuadVer& other) const {
	return QuadVer(
		(*this)[LT] - other[LT],
		(*this)[RT] - other[RT],
		(*this)[LB] - other[LB],
		(*this)[RB] - other[RB]
	);
}
inline QuadVer QuadVer::operator*(const QuadVer& other) const {
	return QuadVer(
		(*this)[LT] * other[LT],
		(*this)[RT] * other[RT],
		(*this)[LB] * other[LB],
		(*this)[RB] * other[RB]
	);
}
inline QuadVer QuadVer::operator/(const QuadVer& other) const {
	return QuadVer(
		(*this)[LT] / other[LT],
		(*this)[RT] / other[RT],
		(*this)[LB] / other[LB],
		(*this)[RB] / other[RB]
	);
}
inline QuadVer& QuadVer::operator+=(const QuadVer& other) {
	*this = *this + other;
	return *this;
}
inline QuadVer& QuadVer::operator-=(const QuadVer& other) {
	*this = *this - other;
	return *this;
}
inline QuadVer& QuadVer::operator*=(const QuadVer& other) {
	*this = *this * other;
	return *this;
}
inline QuadVer& QuadVer::operator/=(const QuadVer& other) {
	*this = *this / other;
	return *this;
}
