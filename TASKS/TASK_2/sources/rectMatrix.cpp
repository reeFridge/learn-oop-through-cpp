#include <cstdarg>
#include "rectMatrix.h"

namespace classes {
	unsigned int RectMatrix::idCounter = 0;
	
	RectMatrix::RectMatrix(const RectMatrix& that)
	: columns(that.columns), rows(that.rows), id(idCounter++) 
	{
		unsigned long size = columns*rows;
		data = new double[columns*rows];
		
		for(unsigned int i = 0; i < size; i++)
			data[i] = that.data[i];
	}
	
	RectMatrix::RectMatrix(const m_size& size, ...)
	: columns(size.columns), rows(size.rows), id(idCounter++)
	{
		va_list args;
		va_start(args, size);
		unsigned long lenght = columns*rows;
		data = new double[lenght];
		for (unsigned int i = 0; i < lenght; i++)
			data[i] = va_arg(args, double);
		va_end(args);
	}
	
	RectMatrix::~RectMatrix(void) {
		delete [] data;
	}
}