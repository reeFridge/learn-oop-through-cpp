#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include <math.h>

namespace classes {
	struct Point3D {
		double x, y, z;
	};

	typedef const char* err;

	class Vector3D {
		struct Cheshire;
		Cheshire* smile;

		static const Point3D nullPoint;
		static unsigned int idCounter;
	
		public:
			Vector3D(Point3D point = nullPoint);
			Vector3D(double x, double y = 0.0, double z = 0.0);
			~Vector3D();
			double			getModule() const;
			void			print()		const;
			const Point3D&	getPoint()	const;
			Vector3D		copy()		const;
			void			multiplyByScalar(const double);
			void			normalize();

	};
	
	namespace VectorsManip {
		Vector3D	add(Vector3D&, Vector3D&);
		Vector3D	substract(Vector3D&, Vector3D&);
		Vector3D	vectorMultiply(Vector3D&, Vector3D&) ;
		double		scalarMultiply(Vector3D&, Vector3D&);
		double		sin(Vector3D&, Vector3D&);
		double		cos(Vector3D&, Vector3D&);
		double		angle(Vector3D&, Vector3D&);
	}
}

#endif // VECTOR_3D_H
