#ifndef UFOMAP_MATH_VECTOR3_H
#define UFOMAP_MATH_VECTOR3_H

#include <stddef.h>
#include <algorithm>
#include <cmath>

namespace ufomap_math
{
class Vector3
{
public:
	Vector3() : data_{ 0.0, 0.0, 0.0 }
	{
	}
	Vector3(double x, double y, double z) : data_{ x, y, z }
	{
	}
	Vector3(const Vector3& other) : data_{ other.data_[0], other.data_[1], other.data_[2] }
	{
	}

	Vector3& operator=(const Vector3& other)
	{
		data_[0] = other.data_[0];
		data_[1] = other.data_[1];
		data_[2] = other.data_[2];
		return *this;
	}

	Vector3 cross(const Vector3& other) const
	{
		return cross(*this, other);
	}
	static Vector3 cross(const Vector3& first, const Vector3& second)
	{
		return Vector3(
				(first.data_[1] * second.data_[2]) - (first.data_[2] * second.data_[1]),
				(first.data_[2] * second.data_[0]) - (first.data_[0] * second.data_[2]),
				(first.data_[0] * second.data_[1]) - (first.data_[1] * second.data_[0]));
	}

	double dot(const Vector3& other) const
	{
		return dot(*this, other);
	}
	static double dot(const Vector3& first, const Vector3& second)
	{
		return (first.data_[0] * second.data_[0]) + (first.data_[1] * second.data_[1]) +
					 (first.data_[2] * second.data_[2]);
	}

	double& operator()(size_t idx)
	{
		return data_[idx];
	}

	const double& operator()(size_t idx) const
	{
		return data_[idx];
	}
	double& operator[](size_t idx)
	{
		return data_[idx];
	}
	const double& operator[](size_t idx) const
	{
		return data_[idx];
	}

	double& x()
	{
		return data_[0];
	}
	const double& x() const
	{
		return data_[0];
	}
	double& y()
	{
		return data_[1];
	}
	const double& y() const
	{
		return data_[1];
	}
	double& z()
	{
		return data_[2];
	}
	const double& z() const
	{
		return data_[2];
	}

	double& roll()
	{
		return data_[0];
	}
	const double& roll() const
	{
		return data_[0];
	}
	double& pitch()
	{
		return data_[1];
	}
	const double& pitch() const
	{
		return data_[1];
	}
	double& yaw()
	{
		return data_[2];
	}
	const double& yaw() const
	{
		return data_[2];
	}

	Vector3 operator-() const
	{
		return Vector3(-data_[0], -data_[1], -data_[2]);
	}

	Vector3 operator-(const Vector3& other) const
	{
		return Vector3(data_[0] - other.data_[0], data_[1] - other.data_[1],
									 data_[2] - other.data_[2]);
	}
	Vector3 operator-(double value) const
	{
		return Vector3(data_[0] - value, data_[1] - value, data_[2] - value);
	}
	Vector3 operator+(const Vector3& other) const
	{
		return Vector3(data_[0] + other.data_[0], data_[1] + other.data_[1],
									 data_[2] + other.data_[2]);
	}
	Vector3 operator+(double value) const
	{
		return Vector3(data_[0] + value, data_[1] + value, data_[2] + value);
	}
	Vector3 operator*(const Vector3& other) const
	{
		return Vector3(data_[0] * other.data_[0], data_[1] * other.data_[1],
									 data_[2] * other.data_[2]);
	}
	Vector3 operator*(double value) const
	{
		return Vector3(data_[0] * value, data_[1] * value, data_[2] * value);
	}
	Vector3 operator/(const Vector3& other) const
	{
		return Vector3(data_[0] / other.data_[0], data_[1] / other.data_[1],
									 data_[2] / other.data_[2]);
	}
	Vector3 operator/(double value) const
	{
		return Vector3(data_[0] / value, data_[1] / value, data_[2] / value);
	}

	void operator-=(const Vector3& other)
	{
		data_[0] -= other.data_[0];
		data_[1] -= other.data_[1];
		data_[2] -= other.data_[2];
	}
	void operator+=(const Vector3& other)
	{
		data_[0] += other.data_[0];
		data_[1] += other.data_[1];
		data_[2] += other.data_[2];
	}
	void operator*=(const Vector3& other)
	{
		data_[0] *= other.data_[0];
		data_[1] *= other.data_[1];
		data_[2] *= other.data_[2];
	}
	void operator/=(const Vector3& other)
	{
		data_[0] /= other.data_[0];
		data_[1] /= other.data_[1];
		data_[2] /= other.data_[2];
	}

	void operator-=(double value)
	{
		data_[0] -= value;
		data_[1] -= value;
		data_[2] -= value;
	}
	void operator+=(double value)
	{
		data_[0] += value;
		data_[1] += value;
		data_[2] += value;
	}
	void operator*=(double value)
	{
		data_[0] *= value;
		data_[1] *= value;
		data_[2] *= value;
	}
	void operator/=(double value)
	{
		data_[0] /= value;
		data_[1] /= value;
		data_[2] /= value;
	}

	bool operator==(const Vector3& other) const
	{
		return data_[0] == other.data_[0] && data_[1] == other.data_[1] &&
					 data_[2] == other.data_[2];
	}
	bool operator!=(const Vector3& other) const
	{
		return data_[0] != other.data_[0] || data_[1] != other.data_[1] ||
					 data_[2] != other.data_[2];
	}

	double norm() const
	{
		return std::sqrt(squaredNorm());
	}
	double squaredNorm() const
	{
		return (data_[0] * data_[0]) + (data_[1] * data_[1]) + (data_[2] * data_[2]);
	}

	Vector3& normalize()
	{
		*this /= norm();
		return *this;
	}
	Vector3 normalized() const
	{
		Vector3 temp(*this);
		return temp.normalize();
	}

	double angleTo(const Vector3& other) const
	{
		return std::acos(dot(other) / (norm() * other.norm()));
	}

	double distance(const Vector3& other) const
	{
		double x = data_[0] - other.data_[0];
		double y = data_[1] - other.data_[1];
		double z = data_[2] - other.data_[2];
		return sqrt((x * x) + (y * y) + (z * z));
	}
	double distanceXY(const Vector3& other) const
	{
		double x = data_[0] - other.data_[0];
		double y = data_[1] - other.data_[1];
		return sqrt((x * x) + (y * y));
	}

	size_t size() const
	{
		return 3;
	}

	double min() const
	{
		return std::min(std::min(data_[0], data_[1]), data_[2]);
	}
	double max() const
	{
		return std::max(std::max(data_[0], data_[1]), data_[2]);
	}

	size_t minElementIndex() const
	{
		if (data_[0] <= data_[1])
		{
			return data_[0] <= data_[2] ? 0 : 2;
		}
		else
		{
			return data_[1] <= data_[2] ? 1 : 2;
		}
	}
	size_t maxElementIndex() const
	{
		if (data_[0] >= data_[1])
		{
			return data_[0] >= data_[2] ? 0 : 2;
		}
		else
		{
			return data_[1] >= data_[2] ? 1 : 2;
		}
	}

	Vector3& ceil()
	{
		for (int i = 0; i < 3; ++i)
		{
			data_[i] = std::ceil(data_[i]);
		}
		return *this;
	}
	Vector3 ceil() const
	{
		return Vector3(std::ceil(data_[0]), std::ceil(data_[1]), std::ceil(data_[2]));
	}
	Vector3& floor()
	{
		for (int i = 0; i < 3; ++i)
		{
			data_[i] = std::floor(data_[i]);
		}
		return *this;
	}
	Vector3 floor() const
	{
		return Vector3(std::floor(data_[0]), std::floor(data_[1]), std::floor(data_[2]));
	}
	Vector3& trunc()
	{
		for (int i = 0; i < 3; ++i)
		{
			data_[i] = std::trunc(data_[i]);
		}
		return *this;
	}
	Vector3 trunc() const
	{
		return Vector3(std::trunc(data_[0]), std::trunc(data_[1]), std::trunc(data_[2]));
	}
	Vector3& round()
	{
		for (int i = 0; i < 3; ++i)
		{
			data_[i] = std::round(data_[i]);
		}
		return *this;
	}
	Vector3 round() const
	{
		return Vector3(std::round(data_[0]), std::round(data_[1]), std::round(data_[2]));
	}

	Vector3& clamp(const Vector3& min, const Vector3& max)
	{
		for (int i = 0; i < 3; ++i)
		{
			data_[i] = std::clamp(data_[i], min[i], max[i]);
		}
		return *this;
	}

	Vector3 clamp(const Vector3& min, const Vector3& max) const
	{
		return clamp(*this, min, max);
	}

	static Vector3 clamp(const Vector3& value, const Vector3& min, const Vector3& max)
	{
		return Vector3(std::clamp(value[0], min[0], max[0]),
									 std::clamp(value[1], min[1], max[1]),
									 std::clamp(value[2], min[2], max[2]));
	}

protected:
	double data_[3];
};
}  // namespace ufomap_math

#endif  // UFOMAP_MATH_VECTOR3_H