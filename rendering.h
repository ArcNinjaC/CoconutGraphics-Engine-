#pragma once
#include <iostream>
#include <algorithm>
#include "shapes.h"
#include "scene.h"



namespace CoconutGraphics {
	vector3 relative_dir_coordinates(const camera& camera, const vector3& point)
	{
		vector3 relative_obs_point = point - camera.getPosition();

		vector3 relative_x_dir = camera.getRightDirection();
		double relative_x = relative_obs_point.dot(relative_x_dir);

		vector3 relative_y_dir = camera.getUpDirection();
		double relative_y = relative_obs_point.dot(relative_y_dir);

		// vector3 relative_z_dir = camera.getDirection();
		double relative_z = relative_obs_point.dot(camera.getDirection());

		return vector3(relative_x, relative_y, relative_z);
	}

	vector2 perspective(const vector3& relative_coordinates, double close_up_factor) {
		double projection_factor = close_up_factor / relative_coordinates.z;
		double projected_x = relative_coordinates.x * projection_factor;
		double projected_y = relative_coordinates.y * projection_factor;
		vector2 projection = vector2(projected_x, projected_y);
		return projection;
	}
	double getIllumination(const vector3& normal, const vector3& light_direction) {
		return (normal.dot(light_direction) + 1.0) / 2.0;
	}
	projected_triangle_data render_triangle(const triangle& triangle, const scene_data& scene_data_obj) {
		vector3 relative_first = relative_dir_coordinates(scene_data_obj.camera, *triangle.p_First);
		vector3 relative_second = relative_dir_coordinates(scene_data_obj.camera, *triangle.p_Second);
		vector3 relative_third = relative_dir_coordinates(scene_data_obj.camera, *triangle.p_Third);
		vector2 projected_first = perspective(relative_first, scene_data_obj.CLOSE_UP);
		vector2 projected_second = perspective(relative_second, scene_data_obj.CLOSE_UP);
		vector2 projected_third = perspective(relative_third, scene_data_obj.CLOSE_UP);
		vector3 color = triangle.color * getIllumination(triangle.calculateNormal(), scene_data_obj.light_dir);
		double lowest_relative_z = std::min(std::min(relative_first.z, relative_second.z), relative_third.z);
		return projected_triangle_data(projected_first, projected_second, projected_third, lowest_relative_z, color);
	}

	std::vector<projected_triangle_data> getSceneProjectedTriangleData(const scene_data& scene_data_obj) {

		std::vector<projected_triangle_data> triangleData;

		for (const mesh& meshObject : scene_data_obj.objects) {
			for (const triangle& triangleOjbect : meshObject.triangles) {

				triangleData.push_back(render_triangle(triangleOjbect, scene_data_obj));

			}
		}
		sortTriangleData(triangleData);
		return triangleData;
	}

	void sortTriangleData(std::vector<projected_triangle_data> &triangle_data) {
		std::sort(triangle_data.begin(), triangle_data.end());
	}
}
