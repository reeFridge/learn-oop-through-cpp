#include "./../../requires.h"
using namespace std;
using classes::Vector3D;

int main(int argc, char** argv) {
	#ifdef DEBUG
		cout << "[DEBUG IS ON]" << endl;
	#endif // DEBUG
	
	Vector3D v(1.0);
	Vector3D v1(2.0, 3.0, 1.0);
	Vector3D v2;
    v.print();
	v1.print();
	v2.print();
}
