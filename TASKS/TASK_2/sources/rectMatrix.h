#ifndef RECT_MATRIX_H
#define RECT_MATRIX_H

#include <iostream>

namespace classes {
	class RectMatrix {
		
	static unsigned int idCounter;
	
	double *data;
	unsigned int columns, rows, id;
	
	public:
		RectMatrix(const RectMatrix&);
		RectMatrix;
		//need find the way to initialize elements of matrix in this Constructor
		RectMatrix(unsigned int columns, unsigned int rows = 0, ... );
		~RectMatrix();
		bool isAddValid(const RectMatrix&) const;
		bool isMultiplyValid(const RectMatrix&) const;
		double getMax() const;
		double getMin() const;
		double& operator [](unsigned int);
		std::ostream& operator <<(std::ostream&) const;
		void operator =(const RectMatrix&);
		void operator +(const RectMatrix&);
		void operator -(const RectMatrix&);
		void operator *(const RectMatrix&);
		void operator *(double);
	};
	
	namespace rectMatrixManip {
		RectMatrix operator +(const RectMatrix&, const RectMatrix&);
		RectMatrix operator -(const RectMatrix&, const RectMatrix&);
		RectMatrix operator *(const RectMatrix&, const RectMatrix&);
		RectMatrix operator *(const double, const RectMatrix&);
	}
}

#endif // RECT_MATRIX_H