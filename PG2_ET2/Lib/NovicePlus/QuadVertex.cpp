#include "QuadVertex.h"

QuadVerf::QuadVerf(const QuadVerf& other) {
	*this = other;
}

QuadVerf::QuadVerf(const Vec2f& lt, const Vec2f& rt, const Vec2f& lb, const Vec2f& rb) {
	this->vertices[LT] = lt;
	this->vertices[RT] = rt;
	this->vertices[LB] = lb;
	this->vertices[RB] = rb;
}



QuadVer::QuadVer(const QuadVer& other) {
	*this = other;
}

QuadVer::QuadVer(const Vec2& lt, const Vec2& rt, const Vec2& lb, const Vec2& rb) {
	this->vertices[LT] = lt;
	this->vertices[RT] = rt;
	this->vertices[LB] = lb;
	this->vertices[RB] = rb;
}


