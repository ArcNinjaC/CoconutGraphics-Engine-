#pragma once

namespace CoconutGraphics {
	struct angle {
		double value = 0;
		angle(double angle = 0) : value(angle) {

		}
		angle operator + (angle other) {
			return angle(this->value + other.value);
		}
		angle operator += (angle other) {
			this->value += other.value;
		}
		angle operator - (angle other) {
			return angle(this->value - other.value);
		}
		angle operator * (double factor) {
			return angle(this->value * factor);
		}
		angle operator / (double factor) {
			return angle(this->value / factor);
		}
	};
}