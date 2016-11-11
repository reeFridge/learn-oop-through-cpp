#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include <math.h>

namespace classes {
	struct Point3D {
		double x, y, z;
	};

	class Vector3D {
		struct Cheshire;
		Cheshire* smile;

		static const Point3D nullPoint = { 0.0, 0.0, 0.0 };
	
		public:
			Vector3D();
			Vector3D(Point3D point = nullPoint);
			Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);
			~Vector3D();
			double		getModule() const;
			Vector3D	copy() const;
			Vector3D	getReversed() const;
			void		multiplyByScalar(const double);
			void		normalize();
			void		print() const;

			static		Vector3D	add(Vector3D&, Vector3D&);
			static		Vector3D	substract(Vector3D&, Vector3D&);
			static		Vector3D	vectorMultiply(Vector3D&, Vector3D&) ;
			static		double		scalarMultiply(Vector3D&, Vector3D&);
			static		double		sin(Vector3D&, Vector3D&);
			static		double		cos(Vector3D&, Vector3D&);
			static		double		angle(Vector3D&, Vector3D&);
	};
}

#endif // VECTOR_3D_H
