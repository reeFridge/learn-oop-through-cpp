#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include <math.h>

namespace classes {
	struct Point3D {
		double x, y, z;
	};

	const Point3D NULL_POINT = { 0.0, 0.0, 0.0 };
	
	enum PointId { A, B };

	class Vector3D {
		struct Cheshire;
		Cheshire* smile;
	
		public:
			Vector3D(Point3D a = NULL_POINT, Point3D b = NULL_POINT);
			~Vector3D();
			Point3D		getPoint(PointId);
			void		setPoint(PointId, Point3D);
			double		getModule();
			Vector3D	copy();
			Vector3D	getReversed();
			void		multiplyByScalar(const double);
			void		normalize();
			void		print();

			static		Vector3D	add(Vector3D&, Vector3D&);
			static		Vector3D	substract(Vector3D&, Vector3D&);
			static		Vector3D	vectorMultiply(Vector3D&, Vector3D&);
			static		double		scalarMultiply(Vector3D&, Vector3D&);
			static		double		sin(Vector3D&, Vector3D&);
			static		double		cos(Vector3D&, Vector3D&);
			static		double		angle(Vector3D&, Vector3D&);
	};
}

#endif // VECTOR_3D_H
