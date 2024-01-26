#pragma once


/// <summary>
/// 二次元ベクトル(float)
/// </summary>
class Vec2f final {
public:

	Vec2f() = default;
	Vec2f(const Vec2f& v);
	Vec2f(float x, float y);

	~Vec2f() = default;

public:

	float x, y;

public:

	/// 四則演算のオペレーター ///

	inline Vec2f operator+ (const Vec2f& other) const;
	inline Vec2f operator- (const Vec2f& other) const;
	inline Vec2f operator* (const Vec2f& other) const;
	inline Vec2f operator/ (const Vec2f& other) const;
	inline Vec2f operator* (float value) const;
	inline Vec2f operator/ (float value) const;

	inline Vec2f& operator+= (const Vec2f& other);
	inline Vec2f& operator-= (const Vec2f& other);
	inline Vec2f& operator*= (const Vec2f& other);
	inline Vec2f& operator/= (const Vec2f& other);
	inline Vec2f& operator*= (float value);
	inline Vec2f& operator/= (float value);

	/// 論理演算子のオペレーター ///

	inline bool operator!= (const Vec2f& other) const;
	inline bool operator== (const Vec2f& other) const;

};





/*========================================================
	四則演算のオペレーター
========================================================*/
inline Vec2f Vec2f::operator+(const Vec2f& other) const {
	return Vec2f(this->x + other.x, this->y + other.y);
}
inline Vec2f Vec2f::operator-(const Vec2f& other) const {
	return Vec2f(this->x - other.x, this->y - other.y);
}
inline Vec2f Vec2f::operator*(const Vec2f& other) const {
	return Vec2f(this->x * other.x, this->y * other.y);
}
inline Vec2f Vec2f::operator/(const Vec2f& other) const {
	return Vec2f(this->x / other.x, this->y / other.y);
}
inline Vec2f Vec2f::operator*(float value) const {
	return Vec2f(this->x * value, this->y * value);
}
inline Vec2f Vec2f::operator/(float value) const {
	return Vec2f(this->x / value, this->y / value);
}

inline Vec2f& Vec2f::operator+=(const Vec2f& other) {
	this->x += other.x;
	this->y += other.y;
	return *this;
}
inline Vec2f& Vec2f::operator-=(const Vec2f& other) {
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}
inline Vec2f& Vec2f::operator*=(const Vec2f& other) {
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}
inline Vec2f& Vec2f::operator/=(const Vec2f& other) {
	this->x /= other.x;
	this->y /= other.y;
	return *this;
}
inline Vec2f& Vec2f::operator*=(float value) {
	this->x *= value;
	this->y *= value;
	return *this;
}
inline Vec2f& Vec2f::operator/=(float value) {
	this->x /= value;
	this->y /= value;
	return *this;
}

inline bool Vec2f::operator!=(const Vec2f& other) const {
	return (this->x != other.x) or (this->y != other.y);
}
inline bool Vec2f::operator==(const Vec2f& other) const {
	return (this->x == other.x) && (this->y == other.y);
}



namespace Vec2Method {

	/// <summary>
	/// pos1からpos2への方向ベクトルを計算
	/// </summary>
	Vec2f Direction(const Vec2f& pos1, const Vec2f& pos2, bool normalize);


	/// <summary>
	/// vectorを正規化する
	/// </summary>
	Vec2f Normalize(const Vec2f& vector);


	/// <summary>
	/// pos1からpos2の長さを計算する
	/// </summary>
	float Length(const Vec2f& pos1, const Vec2f& pos2);


	/// <summary>
	/// pos1->pos2への距離を計算する
	/// </summary>
	Vec2f Distance(const Vec2f& pos1, const Vec2f& pos2);


	/// <summary>
	/// 内積の計算
	/// </summary>
	float DotProduct(const Vec2f& dir1, const Vec2f& dir2);


	/// <summary>
	/// 外積の計算
	/// </summary>
	float CrossProduct(const Vec2f& dir1, const  Vec2f& dir2);


	Vec2f Lerp(const Vec2f& start, const Vec2f& end, float t);

}


/// <summary>
/// 二次元ベクトル(int)
/// </summary>
class Vec2 final {
public:

	Vec2() = default;
	Vec2(const Vec2& v);
	Vec2(int x, int y);

	~Vec2() = default;

public:

	int x, y;

public:

	/// 四則演算のオペレーター ///

	inline Vec2 operator+(const Vec2& other) const;
	inline Vec2 operator-(const Vec2& other) const;
	inline Vec2 operator*(const Vec2& other) const;
	inline Vec2 operator/(const Vec2& other) const;
	inline Vec2 operator*(int value) const;
	inline Vec2 operator/(int value) const;

	inline Vec2& operator+=(const Vec2& other);
	inline Vec2& operator-=(const Vec2& other);
	inline Vec2& operator*=(const Vec2& other);
	inline Vec2& operator/=(const Vec2& other);
	inline Vec2& operator*=(int value);
	inline Vec2& operator/=(int value);

	/// 論理演算子のオペレーター ///

	inline bool operator!=(const Vec2& other) const;
	inline bool operator==(const Vec2& other) const;


public: // user method

	Vec2f castFloat() const;

};


/*========================================================
	四則演算のオペレーター
========================================================*/
inline Vec2 Vec2::operator+(const Vec2& other) const {
	return Vec2(this->x + other.x, this->y + other.y);
}
inline Vec2 Vec2::operator-(const Vec2& other) const {
	return Vec2(this->x - other.x, this->y - other.y);
}
inline Vec2 Vec2::operator*(const Vec2& other) const {
	return Vec2(this->x * other.x, this->y * other.y);
}
inline Vec2 Vec2::operator/(const Vec2& other) const {
	return Vec2(this->x / other.x, this->y / other.y);
}
inline Vec2 Vec2::operator*(int value) const {
	return Vec2(this->x * value, this->y * value);
}
inline Vec2 Vec2::operator/(int value) const {
	return Vec2(this->x / value, this->y / value);
}

inline Vec2& Vec2::operator+=(const Vec2& other) {
	this->x += other.x;
	this->y += other.y;
	return *this;
}
inline Vec2& Vec2::operator-=(const Vec2& other) {
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}
inline Vec2& Vec2::operator*=(const Vec2& other) {
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}
inline Vec2& Vec2::operator/=(const Vec2& other) {
	this->x /= other.x;
	this->y /= other.y;
	return *this;
}
inline Vec2& Vec2::operator*=(int value) {
	this->x /= value;
	this->y /= value;
	return *this;
	// TODO: return ステートメントをここに挿入します
}
inline Vec2& Vec2::operator/=(int value) {
	this->x /= value;
	this->y /= value;
	return *this;
}

inline bool Vec2::operator!=(const Vec2& other) const {
	return (this->x != other.x) or (this->y != other.y);
}
inline bool Vec2::operator==(const Vec2& other) const {
	return (this->x == other.x) && (this->y == other.y);
}
