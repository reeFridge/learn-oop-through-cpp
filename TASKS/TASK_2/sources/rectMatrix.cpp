#include <cstdarg>
#include <iostream>
#include "rectMatrix.h"

#ifdef DEBUG
#define debugMsg(id, msg) std::cout << "Matrix[" << id << "]:" << msg << std::endl;
#else
#define debugMsg(id, msg) ;
#endif

namespace classes {
	double& m_proxy::operator [](unsigned int column) {
		if (column < colsCount)
			return dataRow[column];
		else
			throw OUT_OF_COLUMNS;
	}
	
	unsigned int RectMatrix::idCounter = 0;
	
	RectMatrix::RectMatrix(const RectMatrix& that)
	: columns(that.columns), rows(that.rows), id(idCounter++) 
	{
		debugMsg(id, "Copy constructor call.")
		unsigned long size = columns*rows;
		data = new double[columns*rows];
		
		for(unsigned int i = 0; i < size; i++)
			data[i] = that.data[i];
	}
	
	RectMatrix::RectMatrix(const m_size& size, ...)
	: columns(size.columns), rows(size.rows), id(idCounter++)
	{
		debugMsg(id, "Custom constructor call.")
		if (!columns || !rows)
			debugMsg(id, "[WARNING]: null-size matrix!")
		
		va_list args;
		va_start(args, size);
		unsigned long lenght = columns*rows;
		data = new double[lenght];
		for (unsigned int i = 0; i < lenght; i++)
			data[i] = va_arg(args, double);
		va_end(args);
	}
	
	RectMatrix::RectMatrix(void)
	: columns(0), rows(0), id(idCounter++)
	{
		debugMsg(id, "Default constructor call.")
		debugMsg(id, "[WARNING]: null-size matrix!")
		unsigned long lenght = columns*rows;
		data = new double[lenght];
		data[0] = 0.;
	}
	
	RectMatrix::~RectMatrix(void) {
		debugMsg(id, "Destructor call.")
		delete [] data;
	}
	
	m_proxy RectMatrix::operator [](unsigned int row) {
		if (row < rows)
			return m_proxy(data+(row*columns), columns);
		else
			throw OUT_OF_ROWS;
	}
	
	double& RectMatrix::operator ()(unsigned int row, unsigned int column) {
		if (row < rows) {
			if (column < columns)
				return data[row*columns+column];
			else
				throw OUT_OF_COLUMNS;
		} else
			throw OUT_OF_ROWS;
	}
	
	void RectMatrix::operator =(const RectMatrix& that) {
		if(isAddValid(that))
			for (int i = 0; i < columns*rows; i++)
				data[i] = that.data[i];
		else
			throw NOT_VALID_ADD;
	}
	
	void RectMatrix::operator +=(const RectMatrix& that) {
		if(isAddValid(that))
			for (int i = 0; i < columns*rows; i++)
				data[i] += that.data[i];
		else
			throw NOT_VALID_ADD;
	}
	
	void RectMatrix::operator -=(const RectMatrix& that) {
		if(isAddValid(that))
			for (int i = 0; i < columns*rows; i++)
				data[i] -= that.data[i];
		else
			throw NOT_VALID_ADD;
	}
	
	void RectMatrix::operator *=(const RectMatrix& that) {
		if(isMultiplyValid(that)) {
			double* temp = new double[that.columns*rows];
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < that.columns; j++)
					for (int r = 0; r < columns; r++)
						temp[i*that.columns + j] += data[i*columns + r]*that.data[r*that.columns + j];
			delete [] data;
			columns = that.columns;
			data = temp;
		} else
			throw NOT_VALID_MUL;
	}
	
	void RectMatrix::operator *=(double scalar) {
		for (int i = 0; i < columns*rows; i++)
			data[i] *= scalar;
	}
	
	bool RectMatrix::isAddValid(const RectMatrix& that) const {
		return columns == that.columns && rows == that.rows;
	}
	
	bool RectMatrix::isMultiplyValid(const RectMatrix& that) const {
		return columns == that.rows;
	}
}

int main() {
	classes::m_size size(2, 3);
	classes::RectMatrix m(size,
		2., 3., 4.,
		9., 8., 5.
	);
	
	classes::m_size size1(3, 1);
	classes::RectMatrix m1(size1,
		1.,
		1.,
		1.
	);
	
	classes::m_size size2(0, 1);
	classes::RectMatrix m2(size2);
	
	std::cout << m.isAddValid(m1) << std::endl;
	std::cout << m.isMultiplyValid(m1) << std::endl;
	for (int i = 0; i < size.rows; i++) {
		for (int j = 0; j < size.columns; j++) {
			try {
				std::cout << (int)(m[i][j]) << " ";
			} catch (classes::ERROR_CODE err) {
				switch(err) {
					case classes::OUT_OF_ROWS:
						std::cout << " [OOR] ";
						break;
					case classes::OUT_OF_COLUMNS:
						std::cout << " [OOC] ";
						break;
					default:
						std::cout << " [OOF] ";
				}
			}
		}
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	
	m *= m1;
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 1; j++) {
			std::cout << (int)m(i, j) << " ";
		}
		std::cout << std::endl;
	}
}
