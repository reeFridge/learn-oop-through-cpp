#include "require.h"
using namespace std;
using vector::Vector3D;
using vector::Point3D;
using vector::PointId;

int main(int argc, char** argv) {
	#ifdef DEBUG
		cout << "[DEBUG IS ON]" << endl;
	#endif // DEBUG
	
	Point3D point_a;
	point_a.x = 0;
	point_a.y = 0;
	point_a.z = 0;

	Point3D point_b;
	point_b.x = 3;
	point_b.y = 10.5;
	point_b.z = 0;

	cout << "VectorA:" << endl;
	Vector3D vector_2(point_a, point_b);
	vector_2.print();

	cout << endl << "VectorB:" << endl;
	Vector3D vector_3 = vector_2.copy();
	vector_3.print();
	
	cout << endl << "Reversed VectorB:" << endl;
	vector_3.getReversed().print();

	cout << endl <<"Addition VectorA + VectorB" << endl;
	Vector3D::add(vector_2, vector_3).print();
	
	cout << endl << "Substraction VectorA - VectorB:" << endl;
	Vector3D::substract(vector_2, vector_3).print();
	
	cout << endl << "Point A of VectorB:" << endl;
	Point3D point = vector_3.getPoint(PointId::A);
	cout << point.x << endl << point.y << endl << point.z << endl;
	
	cout << endl <<"Setting point components of VectorB:" << endl;
	point.x = 10;
	point.y = 12;
	point.z = 14;
	vector_3.setPoint(PointId::A, point);
	vector_3.print();
	
	cout << endl << "Multiplying by 10.0 VectorB:" << endl;
	vector_3.multiplyByScalar(10.0);
	vector_3.print();
}
