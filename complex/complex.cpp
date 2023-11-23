#include "complex.h"
#include <cmath>
#include <iomanip>
#include <string>

complex& complex::operator = (const complex& number){
	this->real = number.real;
	this->imaginary = number.imaginary;

	return *this;
}

complex complex::operator * (const complex& number) const {
	complex product;

	product.real = real * number.real - imaginary * number.imaginary;

	product.imaginary = real * number.imaginary + imaginary * number.real;

	return product;
	
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
	return complex( real, -imaginary );
}

void complex::roots(const int n){
	trig number = this->trout();

	number.radia = std::pow(number.radia, 1.0 / static_cast<double>(n));

	const double teta = number.teta;

	for (int k = 0; k < n; k++){
		number.teta = (teta + 2 * M_PI * static_cast<double>(k)) / static_cast<double>(n);
		std::cout << static_cast<complex>(number);
		
		if ( k < n - 1){
			std::cout << ",";
		}

		std::cout << std::endl;
	}

}

void complex::plot() const{
	FILE *pipe = popen("python plot.py", "w"); // change to python3 if needed
	
	fprintf(pipe, "%lf\n", real); // new line will flush the output buffer
	fprintf(pipe, "%lf\n", imaginary); // here also

	pclose(pipe);
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

std::ostream& operator << (std::ostream& stream, const complex& number){
	double imaginary = number.imaginary;

	if (number.imaginary == 0.0){
		std::cout << number.real;
		return stream;
	}

	if (number.real == 0.0){
		std::cout << number.imaginary << 'i';
		return stream;
	}
	
	char sign = (number.imaginary > 0.0) ? '+' : (imaginary = -imaginary, '-');


	stream << number.real << ' ' << sign << ' ' << imaginary << 'i';

	return stream;
}

std::ostream& operator << (std::ostream& stream, complex&& number){
	double imaginary = number.imaginary;

	if (number.imaginary == 0.0){
		std::cout << number.real;
		return stream;
	}

	if (number.real == 0.0){
		std::cout << number.imaginary << 'i';
		return stream;
	}
	
	char sign = (number.imaginary > 0.0) ? '+' : (imaginary = -imaginary, '-');


	stream << number.real << ' ' << sign << ' ' << imaginary << 'i';

	return stream;
}





std::istream& operator >> (std::istream& stream, complex& number){
	// std::cout << "Real part: ";
	// stream >> number.real;
	//
	// std::cout << "Imaginary part: ";
	// stream >> number.imaginary;
	//
	// return stream;
	

	// Another variant
	
	size_t pos;

	std::string input;

	std::getline (stream, input);

	size_t i_pos = input.find('i');

	if (i_pos != std::string::npos){ // if the number has an imaginary part
		input[i_pos] = ' ';
	}else{
		number.real = std::stod(input);	// if it does not, the whole input is real
		number.imaginary = 0.0;
		return stream;
	}

	number.imaginary = std::stod(input, &pos); // let's assume that we have imaginary part only. (for now)

	for (uint64_t i = 0; i < pos; i++){
		input[i] = ' ';
	}

	size_t minus_pos = input.find('-');

	size_t plus_pos = input.find('+');

	if (minus_pos != std::string::npos){
		number.real = number.imaginary; // assumption was incorrect
		input[minus_pos] = ' ';
		number.imaginary = std::stod(input) * -1.0;
		return stream;
	}

	if (plus_pos != std::string::npos){
		number.real = number.imaginary; // assumption was incorrect
		input[plus_pos] = ' ';
		number.imaginary = std::stod(input);
		return stream;
	}

	number.real = 0.0; // assumption succeded (whole number is imaginary)

	return stream;
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
	std::cout << number.radia << "[ sin( " << number.teta << " ) + "
		<< "cos( " << number.teta << " ) ]"; // in radians

	return stream;
}


