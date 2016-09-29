#include "vector3d.h"

struct Vector3D::Cheshire {
	// Private fields and methods
	double components[6];
};

Vector3D::Vector3D() {
	smile = new Cheshire;
	smile->components[0] = 0;
	smile->components[1] = 0;
	smile->components[2] = 0;
	smile->components[3] = 0;
	smile->components[4] = 0;
	smile->components[5] = 0;
}

Vector3D::~Vector3D() {
	delete smile;
}

double Vector3D::getElement(int i) {
	return smile->components[i];
}

void Vector3D::setElement(int i, double value) {
	smile->components[i] = value;
}

double Vector3D::getModule() { 
	return 0.0;
}

Vector3D* Vector3D::copy() {
	return new Vector3D();
}

void Vector3D::multiplyByScalar(double scalar) {
	smile->components[0] *= scalar;
	smile->components[1] *= scalar;
	smile->components[2] *= scalar;
	smile->components[3] *= scalar;
	smile->components[4] *= scalar;
	smile->components[5] *= scalar;
}

void Vector3D::normalize() {}

void Vector3D::print() {}

Vector3D* Vector3D::add(Vector3D&, Vector3D&) {
	return new Vector3D();
}

Vector3D* Vector3D::substruct(Vector3D&, Vector3D&) {
	return new Vector3D();
}

Vector3D* Vector3D::vectorMultiply(Vector3D&, Vector3D&) {
	return new Vector3D();
}

double Vector3D::scalarMultiply(Vector3D&, Vector3D&) {
	return 0.0;
}

double Vector3D::sin(Vector3D&, Vector3D&) {
	return 0.0;
}

double Vector3D::cos(Vector3D&, Vector3D&) {
	return 0.0;
}

double Vector3D::angle(Vector3D&, Vector3D&) {
	return 0.0;
}

