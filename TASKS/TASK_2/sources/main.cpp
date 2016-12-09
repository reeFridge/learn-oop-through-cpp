#include "./../../requires.h"
using namespace std;

int main(int argc, char** argv) {
	#ifdef DEBUG
		std::cout << "[DEBUG IS ON]" << std::endl;
	#endif // DEBUG
	
	classes::m_size size(2, 3);
	classes::RectMatrix m(size,
		2.21, 3., 4.,
		9., 8., 5.3
	);
	
	classes::m_size size1(3, 1);
	classes::RectMatrix m1(size1,
		1.,
		1.,
		2.
	);
	
	classes::m_size size2(0, 1);
	classes::RectMatrix m2(size2);
	
	cout << m.isAddValid(m1) << endl;
	cout << m.isMultiplyValid(m1) << endl;
	for (int i = 0; i < size.rows; i++) {
		for (int j = 0; j < size.columns; j++) {
			try {
				cout << (int)(m[i][j]) << " ";
			} catch (classes::ERROR_CODE err) {
				switch(err) {
					case classes::OUT_OF_ROWS:
						cout << " [OOR] ";
						break;
					case classes::OUT_OF_COLUMNS:
						cout << " [OOC] ";
						break;
					default:
						cout << " [OOF] ";
				}
			}
		}
		cout << endl;
	}
	
	cout << (int)m1.getMax() << "|" << (int)m.getMax() << endl << endl;	
	m.print();
	m *= m1;
	m.print();
}
