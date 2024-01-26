#include "MyMath.h"
#include <Novice.h>
#include <math.h>


/*=============================================================

=============================================================*/

float MyMath::Lerp(float t, float start, float end) {
	return (1.0f - t) * start + t * end;
}

uint32_t MyMath::ShiftColor(float t, uint32_t start, uint32_t end) {
	Vector4 sColor = MyMath::FloatColor(start);
	Vector4 eColor = MyMath::FloatColor(end);

	Vector4 lerp = Vector4(
		MyMath::Lerp(t, sColor.x, eColor.x),
		MyMath::Lerp(t, sColor.y, eColor.y),
		MyMath::Lerp(t, sColor.z, eColor.z),
		MyMath::Lerp(t, sColor.w, eColor.w)
	);

	uint32_t result =
		static_cast<int>(lerp.x) << 24 |
		static_cast<int>(lerp.y) << 16 |
		static_cast<int>(lerp.z) << 8 |
		static_cast<int>(lerp.w) << 0;

	return result;
}

Vector4 MyMath::FloatColor(uint32_t color) {
	return Vector4(
		static_cast<float>(color >> 24 & 0xFF),
		static_cast<float>(color >> 16 & 0xFF),
		static_cast<float>(color >> 8 & 0xFF),
		static_cast<float>(color >> 0 & 0xFF)
	);
}


QuadVerf MyMath::MakeLocalVertex(const Vec2f& size) {
	return {
		{ -size.x * 0.5f,  size.y * 0.5f },
		{  size.x * 0.5f,  size.y * 0.5f },
		{ -size.x * 0.5f, -size.y * 0.5f },
		{  size.x * 0.5f, -size.y * 0.5f }
	};
}

float MyMath::Theta(const Vec2f& v) {
	Vec2f tmp = Vec2Method::Normalize(v);
	return std::atan2f(-tmp.y, tmp.x);
}
