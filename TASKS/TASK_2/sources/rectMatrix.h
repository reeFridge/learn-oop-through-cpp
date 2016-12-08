#ifndef RECT_MATRIX_H
#define RECT_MATRIX_H

namespace classes {

	struct m_size {
		unsigned int columns, rows;
		
		m_size(unsigned int order = 1) : columns(order), rows(order) {};
		m_size(unsigned int cols, unsigned int rows)
		: columns(cols), rows(rows) {};
	};
	
	struct m_proxy {
		m_proxy(double*, unsigned int);
		double& operator [](unsigned int)
	private:
			double* dataRow;
			unsigned int targetCol;
	};

	class RectMatrix {
		static unsigned int idCounter;

		double* data;
		unsigned int columns, rows, id;

	public:
		RectMatrix(const RectMatrix&);
		RectMatrix(const m_size& size = m_size(), ... );
		~RectMatrix(void);
		bool isAddValid(const RectMatrix&) const;
		bool isMultiplyValid(const RectMatrix&) const;
		double getMax() const;
		double getMin() const;
		m_proxy operator [](unsigned int);
		double& operator ()(unsigned int, unsigned int);
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