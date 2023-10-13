#include <iostream>

class trig;

class complex{
public:
	double imaginary;
	double real;

	complex () { } // Default constructor

	complex (const complex& n) : real(n.real), imaginary(n.imaginary) {}

	complex (double r, double i) : real(r), imaginary (i) {}
	
	complex (const trig& n) : real() {}

	complex& operator = (const complex&);
		
	complex operator * (const complex&) const;

	complex operator / (const complex&) const;

	complex operator - (const complex&) const;

	complex operator + (const complex&) const;

	complex conj () const;

	trig trout();

	trig trin();

	double abs();
	
	double angle();

	void roots(const int n);
};

class trig {
public:
	double teta;
	
	double radia;

	complex* ptr;

	trig () : ptr(nullptr) {}

	trig (const double r, double t) : radia(r), teta(t) {}

	trig (const trig& n) : radia(n.radia), teta(n.teta) {}

	operator complex();

	double angle();

	double abs();
};



extern std::ostream& operator << (std::ostream&, complex&);

extern std::istream& operator >> (std::istream&, complex&);


extern std::ostream& operator << (std::ostream&, trig&&);

extern std::istream& operator >> (std::istream&, trig&&);





