#include <iostream>
#include <cmath>
#include <iomanip>

 
class M_field
{
  private:
	double *M;
  public:
	
	double dimension[3];

	M_field() {
		dimension[0] = dimension[1] = dimension[2] = 0.0; 

		std::cout << "Magnetic Field Created" << std::endl;
		std::cout << "(" << dimension[0] << "," << dimension[1] << "," << dimension[2] << ")" << std::endl;
	}

	M_field (double x, double y, double z) {
		dimension[0] = x;
		dimension[1] = y;
		dimension[2] = z;

		std::cout << "Magnetic field set to\n("
		 << dimension[0] << ", " << dimension[1] << "," << dimension[2] << ")" << std::endl;
	}

	~M_field() {
 
		//std::cout << "Magnetic Field Deleted" << std::endl;
	}
	
	double getX() const {
		return dimension[0];
	}

	double getY() const {
		return dimension[1];
	}

	double getZ() const {
		return dimension[2];
	}

	void setX(double x) {
		dimension[0] = x;
	}

	void setY(double y) {
		dimension[1] = y;
	}

	void setZ(double z) {
		dimension[2] = z;
	}


long double calcVectorMagnitude(double x, double y, double z) {
	
	long double sum =( pow(x, 2) + pow(y, 2) + pow(z, 2) ); 
	
	return std::sqrt(sum);
}


};


class E_field
{
  private:
	double *E;
  public:
	
	double dimension[3];

	void setDimension(double d) {

	}

	E_field() {
		dimension[0] = dimension[1] = dimension[2] = 0.0; 

		std::cout << "Electric Field Created" << std::endl;
		std::cout << "(" << dimension[0] << "," << dimension[1] << "," << dimension[2] << ")" << std::endl;
	}

	E_field (double x, double y, double z) {
		dimension[0] = x;
		dimension[1] = y;
		dimension[2] = z;

		std::cout << "Electric field set to\n("
		 << dimension[0] << ", " << dimension[1] << "," << dimension[2] << ")" << std::endl;
	}

	~E_field() {
 
		//std::cout << "Electric Field Deleted" << std::endl;
	}
	
	double getX() const {
		return dimension[0];
	}

	double getY() const {
		return dimension[1];
	}

	double getZ() const {
		return dimension[2];
	}

	void setX(double x) {
		dimension[0] = x;
	}

	void setY(double y) {
		dimension[1] = y;
	}

	void setZ(double z) {
		dimension[2] = z;
	}


long double calcVectorMagnitude(double x, double y, double z) {
	
	long double sum =( pow(x, 2) + pow(y, 2) + pow(z, 2) ); 
	
	return std::sqrt(sum);
}

long double calcInnerProduct(double x, double y, double z) {

	long double sum = (pow(x, 2) + pow(y, 2) + pow(z, 2));
	return sum;
}


};
	
int main (){

	double x; double y; double z;

	E_field E_default;

	E_field E_coordinates(1e5, 10.9, 1.7e2);
	
	std::cout.precision(10);	
	std::cout << "Vector Magnitude " << E_coordinates.calcVectorMagnitude(1e5, 10.9, 1.7e2) << std::endl;
	
	E_coordinates.setX(12.0);
	E_coordinates.setY(3.0);
	E_coordinates.setZ(4.0);
	
	std::cout << "Electric field set to\n(" << E_coordinates.getX() << ", " << E_coordinates.getY() << "," << E_coordinates.getZ() << ")" << std::endl;
	std::cout.precision(10);	
	std::cout << "Vector Magnitude " << E_coordinates.calcVectorMagnitude(E_coordinates.getX(), E_coordinates.getY(), E_coordinates.getZ()) << std::endl;

	std::cout << "Inner Prodcut " << E_coordinates.calcInnerProduct(E_coordinates.getX(), E_coordinates.getY(), E_coordinates.getZ()) << std::endl;

	M_field M_default;

	M_field M_coordinates(1.5e5, 109, 1.72);
	
	std::cout.precision(10);	
	std::cout << "Vector Magnitude " << M_coordinates.calcVectorMagnitude(1.5e5, 10.9, 1.7e2) << std::endl;
	
	M_coordinates.setX(122.0);
	M_coordinates.setY(33.0);
	M_coordinates.setZ(4.0);

	double vect_mag = M_coordinates.calcVectorMagnitude(M_coordinates.getX(), M_coordinates.getY(), M_coordinates.getZ());;
	
	std::cout << "Magnetic field set to\n(" << M_coordinates.getX() << ", " << M_coordinates.getY() << "," << M_coordinates.getZ() << ")" << std::endl;
	std::cout.precision(10);	
	std::cout << "Vector Magnitude " << M_coordinates.calcVectorMagnitude(M_coordinates.getX(), M_coordinates.getY(), M_coordinates.getZ()) << std::endl;

	std::cout << "Unit Vector " << M_coordinates.getX() / vect_mag << ", " << M_coordinates.getY() / vect_mag << ", " << M_coordinates.getZ() / vect_mag << std::endl;

return 0;
}
