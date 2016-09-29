#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include <math.h>

class Vector3D {
	struct Cheshire;
	Cheshire* smile;
	
	public:
		double		getElement(int);
		void		setElement(int, double);
		double		getModule();
		Vector3D	copy();
		void		multiplyByScalar(double);
		void		normalize();
		void		print();

		static		Vector3D	add(&Vector3D, &Vector3D);
		static		Vector3D	substruct(&Vector3D, &Vector3D);
		static		Vector3D	vectorMultiply(&Vector3D, &Vector3D);
		static		double		scalarMultiply(&Vector3D, &Vector3D);
		static		double		sin(&Vector3D, &Vector3D);
		static		double		cos(&Vector3D, &Vector3D);
		static		double		angle(&Vector3D, &Vector3D);
}

#endif // VECTOR_H
