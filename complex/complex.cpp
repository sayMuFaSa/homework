#include "complex.h"
#include <cmath>
#include <iomanip>

complex& complex::operator = (const complex& number){
	this->real = number.real;
	this->imaginary = number.imaginary;

	return *this;
}

complex complex::operator * (const complex& number) const {
	// complex product;
	//
	// product.real = real * number.real - imaginary * number.imaginary;
	//
	// product.imaginary = real * number.imaginary + imaginary * number.real;
	//
	// return product;
	
	return {

		real * number.real - imaginary * number.imaginary,
		
		real * number.imaginary + imaginary * number.real
	};
}

complex complex::operator / (const complex& number) const {
	complex quat;

	complex numerator = (*this) * number.conj();
	
	complex denominator = number * number.conj();

	quat.real =  numerator.real / denominator.real;

	quat.imaginary = numerator.imaginary / denominator.real;

	return quat;
}

complex complex::operator - (const complex& number) const{
	complex diff;

	diff.real = real - number.real;

	diff.imaginary = imaginary - number.imaginary;

	return diff;
}

complex complex::operator + (const complex& number) const {
	complex sum;

	sum.real = real + number.real;

	sum.imaginary = imaginary + number.imaginary;

	return sum;
	
}

complex complex::conj () const {
	return { real, -imaginary };
}

void complex::roots(const int n){
	trig number = this->trout();

	number.radia = std::pow(number.radia, 1.0 / static_cast<double>(n));

	const double teta = number.teta;

	for (int k = 0; k < n; k++){
		number.teta = (teta + 2 * M_PI * static_cast<double>(k)) / static_cast<double>(n);
		complex answer = static_cast<complex> (number);
		std::cout << answer;
		
		if ( k < n - 1){
			std::cout << ",";
		}

		std::cout << std::endl;
	}

}


trig complex::trout(){
	trig value;

	value.radia = sqrt((*this * this->conj()).real);

	value.teta = std::atan2(imaginary, real);

	return value;
}

trig complex::trin(){
	trig value;

	value.ptr = this;
	
	return value;
}

trig::operator complex(){
	complex number;

	number.imaginary = std::sin(teta) * radia;

	number.real = std::cos(teta) * radia;


	return number;
}

std::ostream& operator << (std::ostream& stream, complex& number){
	double imaginary = number.imaginary;
	
	char sign = (number.imaginary >= 0.0) ? '+' : (imaginary = -imaginary, '-');


	stream << number.real << ' ' << sign << ' ' << imaginary << 'i';

	return stream;
}



std::istream& operator >> (std::istream& stream, complex& number){
	std::cout << "Real part: ";
	stream >> number.real;

	std::cout << "Imaginary part: ";
	stream >> number.imaginary;

	return stream;
	

	// Another variant
	
	// std::string my_string;
	// 
	// std::getline (stream, my_string) ;
	//
	// return stream;
}



double complex::abs()	{ return sqrt((*this * this->conj()).real); }

double complex::angle() { return atan(imaginary / real); }



double trig::angle() { return teta; }

double trig::abs() { return radia; }


std::istream& operator >> (std::istream& stream, trig&& number){
	std::cout << "Radia: ";
	stream >> number.radia;

	std::cout << "Angle: ";
	stream >> number.teta;


	number.ptr->real = number.radia * cos(number.teta);

	number.ptr->imaginary = number.radia * sin(number.teta);

	return stream;
}



std::ostream& operator << (std::ostream& stream, trig&& number){
	std::cout << number.radia << " sin( " << number.teta << " ) + "<<  number.radia << " cos( " << number.teta << " )";

	return stream;
}


