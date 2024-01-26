#pragma once

#include "MyVector2.h"
#include "QuadVertex.h"
#include <Vector4.h>
#include <cmath>

namespace MyMath {

	/// <summary>
	/// 線形補完
	/// </summary>
	/// <param name="t">	 媒介変数 : 1 ~ 0	 </param>
	/// <param name="start"> 始点			 </param>
	/// <param name="end">	 終点			 </param>
	/// <returns>始点から終点のt分の値</returns>
	float Lerp(float t, float start, float end);


	/// <summary>
	/// 色の線形補完
	/// </summary>
	/// <param name="t">	 媒介変数 : 1 ~ 0	 </param>
	/// <param name="start"> 始点			 </param>
	/// <param name="end">	 終点			 </param>
	/// <returns></returns>
	uint32_t ShiftColor(float t, uint32_t start, uint32_t end);


	/// <summary>
	/// カラーコードをRGBAの4要素に分解して返す関数
	/// </summary>
	/// <param name="color"></param>
	/// <returns></returns>
	Vector4 FloatColor(uint32_t color);

	QuadVerf MakeLocalVertex(const Vec2f& size);


	float Theta(const Vec2f& v);

}