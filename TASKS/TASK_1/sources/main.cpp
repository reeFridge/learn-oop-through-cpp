#include "./../../requires.h"
using namespace std;
using classes::Vector3D;

int main(int argc, char** argv) {
	#ifdef DEBUG
		std::cout << "[DEBUG IS ON]" << std::endl;
	#endif // DEBUG
	
	Vector3D v(1.0);
	Vector3D v1(2.0, 3.0, 1.0);
	Vector3D v2;
    v.print();
	v1.print();
	v2.print();
	Vector3D multi(VectorsManip::add(v, v1));
	multi.print();
}
