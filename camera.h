#pragma once

#include "vector.h"
#include "angle.h"

namespace CoconutGraphics {

	const double PI = 3.14159;

	class camera {
		angle theta;
		angle phi;
		CoconutGraphics::vector3 direction;
		CoconutGraphics::vector3 directionUp;
		CoconutGraphics::vector3 directionRight;
		CoconutGraphics::vector3 position;
		void updateDirections() {
			direction = vector3::from_spherical(theta, phi);
			directionRight = vector3::from_spherical(theta + angle(PI / 2), phi);
			directionUp = vector3::from_spherical(theta, phi + angle(PI / 2));
		}
	public:
		camera() {}
		camera(CoconutGraphics::vector3 position, angle theta, angle phi) {
			this->position = position;
			this->theta = theta;
			this->phi = phi;
			this->updateDirections();

		}
		angle getTheta() {
			return this->theta;
		}
		void setTheta(angle value) {
			this->theta = value;
			updateDirections();
		}
		void setTheta(double value) {
			this->theta.value = value;
			updateDirections();
		}
		void changeTheta(angle change) {
			this->theta += change;
			updateDirections();
		}
		angle getPhi() {
			return this->phi;
		}
		void setPhi(angle value) {
			this->phi = value;
			updateDirections();
		}
		void setPhi(double value) {
			this->phi.value = value;
			updateDirections();
		}
		void changePhi(angle change) {
			this->phi += change;
			updateDirections();
		}
		vector3 const getPosition() const {
			return this->position;
		}
		void setPosition(vector3 value) {
			this->position = value;
		}
		void changePosition(vector3 change) {
			this->position += change;
		}
		vector3 getDirection() const {
			return this->direction;
		}
		vector3 getRightDirection() const {
			return this->directionRight;
		}
		vector3 getUpDirection() const {
			return this->directionUp;
		}
	};
}
