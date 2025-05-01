#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <type_traits>

template <class T>
class vec2 {
public:
	T x{}, y{};

	constexpr vec2() = default;
	constexpr vec2(T x, T y) : x(x), y(y) {}
	constexpr vec2(const vec2& v) = default;
	vec2& operator=(const vec2& v) = default;

	constexpr vec2 operator+(const vec2& v) const { return {x + v.x, y + v.y}; }
	constexpr vec2 operator-(const vec2& v) const { return {x - v.x, y - v.y}; }
	constexpr bool operator==(const vec2& v) const { return x == v.x && y == v.y; }
	constexpr bool operator!=(const vec2& v) const { return x != v.x || y != v.y; }

	vec2& operator+=(const vec2& v) { x += v.x; y += v.y; return *this; }
	vec2& operator-=(const vec2& v) { x -= v.x; y -= v.y; return *this; }

	constexpr vec2 operator+(T s) const { return {x + s, y + s}; }
	constexpr vec2 operator-(T s) const { return {x - s, y - s}; }
	constexpr vec2 operator*(T s) const { return {x * s, y * s}; }
	constexpr vec2 operator/(T s) const { return {x / s, y / s}; }

	vec2& operator+=(T s) { x += s; y += s; return *this; }
	vec2& operator-=(T s) { x -= s; y -= s; return *this; }
	vec2& operator*=(T s) { x *= s; y *= s; return *this; }
	vec2& operator/=(T s) { x /= s; y /= s; return *this; }

	void set(T x_, T y_) { x = x_; y = y_; }

	void rotate(T deg) {
		T theta = deg / T(180.0) * T(M_PI);
		T c = std::cos(theta);
		T s = std::sin(theta);
		T tx = x * c - y * s;
		T ty = x * s + y * c;
		x = tx;
		y = ty;
	}

	vec2 moved_at_angle(T angle_deg, T distance) const {
		double angle_rad = angle_deg * M_PI / 180.0;
		T dx = static_cast<T>(std::cos(angle_rad) * distance);
		T dy = static_cast<T>(std::sin(angle_rad) * distance);
		return vec2(x + dx, y + dy);
	}

	vec2 normalize_to(const vec2& target, T distance) const {
		return {(target.x - x) / distance, (target.y - y) / distance};
	}

	T dist(const vec2& v) const {
		T dx = v.x - x;
		T dy = v.y - y;
		return std::sqrt(dx * dx + dy * dy);
	}

	T length() const {
		return std::sqrt(x * x + y * y);
	}

	void truncate(T len) {
		T angle = std::atan2(y, x);
		x = len * std::cos(angle);
		y = len * std::sin(angle);
	}

	vec2 ortho() const {
		return {y, -x};
	}

	static constexpr T dot(const vec2& v1, const vec2& v2) {
		return v1.x * v2.x + v1.y * v2.y;
	}

	static constexpr T cross(const vec2& v1, const vec2& v2) {
		return v1.x * v2.y - v1.y * v2.x;
	}

	vec2 move_towards(const vec2& dest, T speed) const {
		T d = dist(dest);
		if (d > speed) {
			vec2 dir = normalize_to(dest, d);
			return *this + dir * speed;
		} else {
			return dest;
		}
	}
};

using vec2f = vec2<float>;
using vec2d = vec2<double>;
using vec2i = vec2<int>;

#endif // VEC2_H

