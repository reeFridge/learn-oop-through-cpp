#include "vector3d.h"
#include <iostream>
using namespace vector;

#define POINTS_COUNT 2

struct Vector3D::Cheshire {
	// Private fields and methods
	Point3D points[POINTS_COUNT];
};

Vector3D::Vector3D(Point3D a, Point3D b) {
	smile = new Cheshire;
	smile->points[PointId::A] = a;
	smile->points[PointId::B] = b;
}

Vector3D::~Vector3D() {
	delete smile;
}

Point3D Vector3D::getPoint(PointId p) {
	return smile->points[p];
}

void Vector3D::setPoint(PointId p, Point3D newPoint) {
	smile->points[p] = newPoint;
}

double Vector3D::getModule() { 
	double x = smile->points[PointId::B].x - smile->points[PointId::A].x;
	double y = smile->points[PointId::B].y - smile->points[PointId::A].y;
	double z = smile->points[PointId::B].z - smile->points[PointId::A].z;
	x *= x;	y *= y;	z *= z;
	return sqrt(x + y + z);
}

Vector3D Vector3D::getReversed() {
	Point3D resultPoint = {
		smile->points[PointId::A].x - (smile->points[PointId::B].x - smile->points[PointId::A].x),
		smile->points[PointId::A].y - (smile->points[PointId::B].y - smile->points[PointId::A].y),
		smile->points[PointId::A].z - (smile->points[PointId::B].z - smile->points[PointId::A].z)
	};

	return *(new Vector3D(smile->points[PointId::A], resultPoint));
}

Vector3D Vector3D::copy() {
	return *(new Vector3D(smile->points[PointId::A], smile->points[PointId::B]));
}

void Vector3D::multiplyByScalar(const double scalar) {
	for(int i = 0; i < POINTS_COUNT; i++) {
		smile->points[i].x *= scalar;
		smile->points[i].y *= scalar;
		smile->points[i].z *= scalar;
	}
}

void Vector3D::normalize() {
	double module = this->getModule();
	smile->points[PointId::B].x = smile->points[PointId::B].x/module;
	smile->points[PointId::B].y = smile->points[PointId::B].y/module;
	smile->points[PointId::B].z = smile->points[PointId::B].z/module;
	smile->points[PointId::A].x = smile->points[PointId::A].x/module;
	smile->points[PointId::A].y = smile->points[PointId::A].y/module;
	smile->points[PointId::A].z = smile->points[PointId::A].z/module;
}

void Vector3D::print() {
	std::cout 
		<< "Vector: A("
		<< smile->points[PointId::A].x << ", "
		<< smile->points[PointId::A].y << ", "
		<< smile->points[PointId::A].z << "), B("
		<< smile->points[PointId::B].x << ", "
		<< smile->points[PointId::B].y << ", "
		<< smile->points[PointId::B].z << ")" << std::endl;

}

Vector3D Vector3D::add(Vector3D& vectorA, Vector3D& vectorB) {
	Point3D pointAb = vectorA.getPoint(PointId::B);
	Point3D pointBb = vectorB.getPoint(PointId::B);
	Point3D pointBa = vectorB.getPoint(PointId::A);

	Point3D resultPoint = {
		pointBb.x + (pointAb.x - pointBa.x),
		pointBb.y + (pointAb.y - pointBa.y),
		pointBb.z + (pointAb.z - pointBa.z)
	};

	return *(new Vector3D(vectorA.getPoint(PointId::A), resultPoint));
}

Vector3D Vector3D::substract(Vector3D& vectorA, Vector3D& vectorB) {
	Vector3D reversedB = vectorB.getReversed();
	return Vector3D::add(vectorA, reversedB);
}

Vector3D Vector3D::vectorMultiply(Vector3D&, Vector3D&) {
	return *(new Vector3D());
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

