#pragma once
#include <iostream>
#include "angle.h"

namespace CoconutGraphics
{

	struct vector3 {
		double x = 0;
		double y = 0;
		double z = 0;

		static vector3 from_spherical(angle theta, angle phi) {
			return vector3(
				cos(phi.value) * sin(theta.value),
				sin(phi.value),
				cos(phi.value) * cos(theta.value)
			);
		}

		vector3(double i = 0, double j = 0, double k = 0) :x(i), y(j), z(k) {}
		double dot(vector3 other) const {
			return (
				x * other.x +
				y * other.y +
				z * other.z
				);

		}
		vector3 cross(vector3 const other) const {
			return vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
		}
		double length2() {
			return (x * x + y * y + z * z);
		}
		double length() {
			return sqrt(length2());
		}
		void normalize() {
			double length = this->length();
			x, y, z /= length;
		}
		void c_str() {
			std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
		}
		vector3 operator + (vector3 const& other) const {
			return vector3(
				x + other.x,
				y + other.y,
				z + other.z
			);
		}
		void operator += (vector3 const& other) {
			x += other.x;
			y += other.y;
			z += other.z;
		}
		vector3 operator - (vector3 const& other) const {
			return vector3(
				x - other.x,
				y - other.y,
				z - other.z
			);
		}
		void operator -= (vector3 const& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;

		}
		vector3 operator * (double factor) const {
			return vector3(x * factor, y * factor, z * factor);
		}
		void operator *= (double factor) {
			x *= factor;
			y *= factor;
			z *= factor;
		}
		vector3 operator / (double factor) const {
			return vector3(x / factor, y / factor, z / factor);
		}
		void operator /= (double factor) {
			x /= factor;
			y /= factor;
			z /= factor;
		}
	};
	vector3 L = vector3(1.0, 2.0, 3.0) * 4;
	struct vector2 {
		double x = 0;
		double y = 0;

		static vector2 from_circular(angle theta) {
			return vector2(
				cos(theta.value),
				sin(theta.value)
			);
		}
		vector2(double i, double j) :x(i), y(j) {}
		double dot(vector3 other) const {
			return (
				x * other.x +
				y * other.y
				);
		}
		double length2() {
			return (x * x + y * y);
		}
		double length() {
			return sqrt(length2());
		}
		vector2 perpendicular() {
			return vector2(y, -x);
		}
		void output() {
			std::cout << "x : " << x << " y : " << y << std::endl;
		}
		vector2 operator + (vector2 const& other) const {
			return vector2(
				x + other.x,
				y + other.y
			);
		}
		void operator += (vector2 const& other) {
			x += other.x;
			y += other.y;
		}
		vector2 operator - (vector2 const& other) const {
			return vector2(
				x - other.x,
				y - other.y
			);
		}
		vector2 operator * (double factor) {
			return vector2(x * factor, y * factor);
		}
		void operator *= (double factor) {
			x *= factor;
			y *= factor;
		}
		vector2 operator / (double factor) {
			return vector2(x / factor, y / factor);
		}
		void operator /= (double factor) {
			x /= factor;
			y /= factor;
		}
	};
};
