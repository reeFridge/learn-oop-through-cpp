#include "vector3d.h"
#include <iostream>
using namespace classes;
using std::cout;
using std::endl;

inline void debugMsg(const char* msg) {
#ifdef DEBUG
	cout << msg << endl;
#endif
}

struct Vector3D::Cheshire {
	// Private fields and methods
	Point3D point;
	unsigned int id;
};

const Point3D Vector3D::nullPoint = { 0.0, 0.0, 0.0 };
unsigned int Vector3D::idCounter = 0;

//Constructors

//1
Vector3D::Vector3D(Point3D point) {
	debugMsg("Constructor1 was called.");
	smile = new Cheshire;
	smile->point = point;
	smile->id = idCounter++;
	cout << "Vector:" << smile->id << " was created." << endl;
}

//2
Vector3D::Vector3D(double x, double y, double z) {
	debugMsg("Constructor2 was called.");
	smile = new Cheshire;
	smile->point = { x, y, z };
	smile->id = idCounter++;
	cout << "Vector:" << smile->id << " was created." << endl;
}

//Destructor
Vector3D::~Vector3D() {
	debugMsg("Destructor was called.");	
	cout << "Vector:" << smile->id << " now deleting." << endl;
	delete smile;
}

inline double Vector3D::getModule() const { 
	return sqrt(
			smile->point.x*smile->point.x +
			smile->point.y*smile->point.y + 
			smile->point.z*smile->point.z
			);
}

inline void Vector3D::print() const {
	cout << "Vector: "
		 << smile->point.x << ", "
		 << smile->point.y << ", "
		 << smile->point.z << endl;

}

inline const Point3D& Vector3D::getPoint() const {
	return smile->point;
}

Vector3D Vector3D::copy() const {
	return Vector3D(smile->point);
}

void Vector3D::multiplyByScalar(const double scalar) {
	smile->point.x *= scalar;
	smile->point.y *= scalar;
	smile->point.z *= scalar;
}

void Vector3D::normalize() {
	double module = getModule();
	if (module == 0.0) {
		throw "[ERROR] Normalize: dividing on null";
	} else {
		smile->point.x = smile->point.x/module;
		smile->point.y = smile->point.y/module;
		smile->point.z = smile->point.z/module;
	}
}

Vector3D Vector3D::add(Vector3D& vectorA, Vector3D& vectorB) {
	const Point3D& pointA = vectorA.getPoint();
	const Point3D& pointB = vectorB.getPoint();
	Point3D resultPoint = {
		pointA.x + pointB.x,
		pointA.y + pointB.y,
		pointA.z + pointB.z
	};

	return Vector3D(resultPoint);
}

Vector3D Vector3D::substract(Vector3D& vectorA, Vector3D& vectorB) {
	const Point3D& pointB = vectorB.getPoint();
	Vector3D reversedB(-pointB.x, -pointB.y, -pointB.z);
	return Vector3D::add(vectorA, reversedB);
}

Vector3D Vector3D::vectorMultiply(Vector3D& vectorA, Vector3D& vectorB) {
	const Point3D& pointA = vectorA.getPoint();
	const Point3D& pointB = vectorB.getPoint();
	Point3D resultPoint = {
		pointA.y * pointB.z - pointA.z * pointB.y,
		pointA.z * pointB.x - pointA.x * pointB.z,
		pointA.x * pointB.y - pointA.y * pointA.x
	};

	return Vector3D(resultPoint);
}

double Vector3D::scalarMultiply(Vector3D& vectorA, Vector3D& vectorB) {
	const Point3D& pointA = vectorA.getPoint();
	const Point3D& pointB = vectorB.getPoint();
	
	return 
		pointA.x * pointB.x +
		pointA.y * pointB.y +
		pointA.z * pointB.z;
}

double Vector3D::sin(Vector3D&, Vector3D&) {
	return 0.0;
}

double Vector3D::cos(Vector3D& vectorA, Vector3D& vectorB) {
	return 
		Vector3D::scalarMultiply(vectorA, vectorB) /
		(vectorA.getModule() * vectorB.getModule());
}

double Vector3D::angle(Vector3D& vectorA, Vector3D& vectorB) {
	return atan2(
		Vector3D::vectorMultiply(vectorA, vectorB).getModule(),
		Vector3D::scalarMultiply(vectorA, vectorB)
	);
}

