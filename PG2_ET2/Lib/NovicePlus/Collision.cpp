#include "Collision.h"
#include <cmath>
#include <Novice.h>



bool Collision::CheckLR(const Vec2f& pos1, const Vec2f& pos2, const Vec2f& pos2Dir) {
	enum DIR {
		RIGHT,
		LEFT
	};

	if (Vec2Method::CrossProduct(pos2Dir, Vec2Method::Direction(pos1, pos2, true)) > 0) {
		return RIGHT;
	}
	return LEFT;
}



/*================================================================================
		矩形
================================================================================*/


bool Collision::Rect::Rect(const QuadVerf& ver1, const QuadVerf& ver2) {
	if (Collision::Rect::Point(ver2, ver1[LT])) { return true; }
	if (Collision::Rect::Point(ver2, ver1[RT])) { return true; }
	if (Collision::Rect::Point(ver2, ver1[LB])) { return true; }
	if (Collision::Rect::Point(ver2, ver1[RB])) { return true; }

	if (Collision::Rect::Point(ver1, ver2[LT])) { return true; }
	if (Collision::Rect::Point(ver1, ver2[RT])) { return true; }
	if (Collision::Rect::Point(ver1, ver2[LB])) { return true; }
	if (Collision::Rect::Point(ver1, ver2[RB])) { return true; }

	return false;
}

bool Collision::Rect::Circle(const QuadVerf& ver, const Vec2f center, float distance) {
	// 点と矩形の当たり判定
	if (Collision::Rect::Point(ver, center)) { return true; }

	// 円と線の当たり判定
	if (Collision::Circle::Line(center, ver[LT], ver[LB], distance)) { return true; }
	if (Collision::Circle::Line(center, ver[LB], ver[RB], distance)) { return true; }
	if (Collision::Circle::Line(center, ver[RB], ver[RT], distance)) { return true; }
	if (Collision::Circle::Line(center, ver[RT], ver[LT], distance)) { return true; }

	return false;
}


bool Collision::Rect::Point(const QuadVerf& ver, const Vec2f& point) {
	//外積の計算をしPointがRectの外側にいた場合falseを返す;
	if (Vec2Method::CrossProduct(Vec2Method::Direction(ver[LT], point, true), Vec2Method::Direction(ver[LT], ver[LB], true)) < 0) { return false; }
	if (Vec2Method::CrossProduct(Vec2Method::Direction(ver[RT], point, true), Vec2Method::Direction(ver[RT], ver[LT], true)) < 0) { return false; }
	if (Vec2Method::CrossProduct(Vec2Method::Direction(ver[LB], point, true), Vec2Method::Direction(ver[LB], ver[RB], true)) < 0) { return false; }
	if (Vec2Method::CrossProduct(Vec2Method::Direction(ver[RB], point, true), Vec2Method::Direction(ver[RB], ver[RT], true)) < 0) { return false; }

	return true;
}


/*================================================================================
		円
================================================================================*/


bool Collision::Circle::Rect(const Vec2f center, const QuadVerf& ver, float distance) {
	// 点と矩形の当たり判定
	if (Collision::Rect::Point(ver, center)) { return true; }

	// 円と線の当たり判定
	if (Collision::Circle::Line(center, ver[LT], ver[LB], distance)) { return true; }
	if (Collision::Circle::Line(center, ver[LB], ver[RB], distance)) { return true; }
	if (Collision::Circle::Line(center, ver[RB], ver[RT], distance)) { return true; }
	if (Collision::Circle::Line(center, ver[RT], ver[LT], distance)) { return true; }

	return false;
}

bool Collision::Circle::Circle(const Vec2f& center1, const Vec2f& center2, float distance) {
	return Vec2Method::Length(center1, center2) < distance;
}

bool Collision::Circle::Line(const Vec2f& center, const Vec2f& start, const Vec2f& end, float distance) {
	float dot = Vec2Method::DotProduct(Vec2Method::Direction(start, end, true), Vec2Method::Direction(start, center, false));
	Vec2f tmp;
	if (dot > 0 && dot < Vec2Method::Length(start, end)) { //最近傍点が線上にあるとき
		tmp.x = start.x + Vec2Method::Direction(start, end, true).x * dot;
		tmp.y = start.y + Vec2Method::Direction(start, end, true).y * dot;
		if (Vec2Method::Length(center, tmp) < distance) { return true; }
	} else if (dot < 0) { //startより後ろのとき
		if (Collision::Circle::Point(center, start, distance)) { return true; }
	} else if (dot > Vec2Method::Length(start, end)) { //endを超えているとき
		if (Collision::Circle::Point(center, end, distance)) { return true; }
	}
	return false;
}

bool Collision::Circle::Point(const Vec2f& center, const Vec2f& point, float distance) {
	return Vec2Method::Length(center, point) < distance;
}


/*================================================================================
		線
================================================================================*/

bool Collision::Line::Line(const Vec2f& start1, const Vec2f& end1, const Vec2f& start2, const Vec2f& end2) {
	int trueCount = 0;
	if (Collision::CheckLR(start1, start2, Vec2Method::Direction(start2, end2, true)) == 0) {
		if (Collision::CheckLR(end1, start2, Vec2Method::Direction(start2, end2, true)) == 1) {
			trueCount++;
		}
	} else {
		if (Collision::CheckLR(end1, start2, Vec2Method::Direction(start2, end2, true)) == 0) {
			trueCount++;
		}
	}

	if (Collision::CheckLR(start2, start1, Vec2Method::Direction(start1, end1, true)) == 0) {
		if (Collision::CheckLR(end2, start1, Vec2Method::Direction(start1, end1, true)) == 1) {
			trueCount++;
		}
	} else {
		if (Collision::CheckLR(end2, start1, Vec2Method::Direction(start1, end1, true)) == 0) {
			trueCount++;
		}
	}

	if (trueCount == 2) { return true; }

	return false;
}
