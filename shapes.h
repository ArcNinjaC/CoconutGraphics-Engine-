#pragma once
#include "vector.h"
#include <vector>

namespace CoconutGraphics {
	struct triangle {

		vector3* p_First, * p_Second, * p_Third = nullptr;
		vector3 color;
		vector3 calculateNormal() const {
			vector3 A = *p_Second - *p_First;
			vector3 B = *p_Third - *p_First;
			vector3 normalVector = A.cross(B);
			normalVector.normalize();
			return normalVector;
		}
		triangle(vector3& first, vector3& second, vector3& third, vector3 col) :
			p_First(&first),
			p_Second(&second),
			p_Third(&third),
			color(col) {}
	};

	struct projected_triangle_data {
		vector2 p1, p2, p3;
		vector3 color;
		double relative_dir_dist;

		projected_triangle_data(vector2 first, vector2 second, vector2 third, double lowest_relative_z, vector3 col) :
			p1(first),
			p2(second),
			p3(third),
			color(col),
			relative_dir_dist(lowest_relative_z)
		{}

		bool operator< (const projected_triangle_data &other) const {
			return (this->relative_dir_dist < other.relative_dir_dist);
		}
	};

	struct mesh {
		// mesh representation is just a list of triangles
		std::vector<triangle> triangles;
		std::vector<vector3>  points;

		mesh() {}

		mesh(std::vector<vector3> pointsObjects, std::vector<triangle> triangleList = {}) :
			triangles(triangleList),
			points(pointsObjects) {}
	};
}