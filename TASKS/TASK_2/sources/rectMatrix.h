#ifndef RECT_MATRIX_H
#define RECT_MATRIX_H

namespace classes {
	
	enum ERROR_CODE {
		OUT_OF_ROWS,
		OUT_OF_COLUMNS,
		NOT_VALID_ADD,
		NOT_VALID_MUL
	};

	struct m_size {
		unsigned int columns, rows;
		
		m_size(unsigned int order = 1) : rows(order), columns(order) {};
		m_size(unsigned int rows, unsigned int cols)
		: rows(rows), columns(cols) {};
	};
	
	struct m_proxy {
		m_proxy(double* rowPointer, unsigned int cols)
		: dataRow(rowPointer), colsCount(cols) {};
		double& operator [](unsigned int);
	private:
			double* dataRow;
			unsigned int colsCount;
	};

	class RectMatrix {
		static unsigned int idCounter;

		double* data;
		unsigned int columns, rows, id;

	public:
		RectMatrix(const RectMatrix&);
		RectMatrix(const m_size&, ... );
		RectMatrix(void);
		~RectMatrix(void);
		/*
		 * Setters/getters:
		 * Unlike to math matrix: 
		 * 		Numeration of elements starts at null
		 * Like to math matrix:
		 * 		First argument is row number,
		 * 		Second is column number
		 */
		m_proxy operator [](unsigned int);
		double& operator ()(unsigned int, unsigned int); 
		void operator =(const RectMatrix&);
		void operator +=(const RectMatrix&);
		void operator -=(const RectMatrix&);
		void operator *=(const RectMatrix&);
		void operator *=(double);
		bool isAddValid(const RectMatrix&) const;
		bool isMultiplyValid(const RectMatrix&) const;
		double getMax() const;
		double getMin() const;
		void print() const;
	};
	
	namespace rectMatrixManip {
		RectMatrix operator +(const RectMatrix&, const RectMatrix&);
		RectMatrix operator -(const RectMatrix&, const RectMatrix&);
		RectMatrix operator *(const RectMatrix&, const RectMatrix&);
		RectMatrix operator *(const double, const RectMatrix&);
	}
}

#endif // RECT_MATRIX_H
