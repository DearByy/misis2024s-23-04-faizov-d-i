#include "complex.hpp"

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
    return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
    return rhs.readFrom(istrm);
}

bool testparse(const std::string& str) {
    std::istringstream stream(str);
    Complex number;
    stream >> number;

    if(stream.good()) {
        std::cout << "Read success: " << str << " -> " << number << '\n';

    } else {
        std::cout << "Read error: " << str << " -> " << number << '\n';
    }

    return stream.good();

}

Complex& Complex::operator+=(const Complex& rhs) {
    re += rhs.re;
    im += rhs.im;
    return *this;

}
Complex& Complex::operator-=(const Complex& rhs) {
	 re -= rhs.re;
	 im -= rhs.im;
	 return *this;
}
 Complex& Complex::operator*=(const Complex& rhs)
 {
	 double copy = re;
	 re = (re * rhs.re) - (im * rhs.im);
	 im = (copy * rhs.im) + (im * rhs.re);
	 return *this;
 }
Complex& Complex::operator*=(const double& rhs) {
	 re *= rhs;
	 im *= rhs;
	 return *this;
}
Complex& Complex::operator/=(const Complex& rhs) {
	double copy = re;
	re = ((re * rhs.re) + (im * rhs.im)) / ((rhs.re * rhs.re) + (rhs.im * rhs.im));
	im = ((rhs.re * im) - (rhs.im * copy)) / ((rhs.re * rhs.re) + (rhs.im * rhs.im));
	return *this;
}
Complex& Complex::operator/=(const double& rhs) {
    re /= rhs;
	im /= rhs;
	return *this;
}


Complex operator+(const Complex & lhs, const Complex & rhs) {
	 Complex sum(lhs);
	 sum += rhs;
	 return sum;
}

 Complex operator-(const Complex & lhs, const Complex & rhs)
 {
	 return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
	 }

 Complex operator*(const Complex& lhs, const Complex& rhs)
 {
	 return Complex( (lhs.re*rhs.re) - (lhs.im * rhs.im), (lhs.re * rhs.im) + (lhs.im * rhs.re));
	 }
 Complex operator/(const Complex& lhs, const Complex& rhs)
 {
	 return Complex(((lhs.re * rhs.re) + (lhs.im * rhs.im))/((rhs.re * rhs.re) + (rhs.im * rhs.im))
		 , ((rhs.re * lhs.im) - (rhs.im * lhs.re))/ ((rhs.re * rhs.re) + (rhs.im * rhs.im)));
 }
bool operator==(const double& lhs, const Complex& rhs) { 
    return Complex(lhs) == rhs; 
}
bool operator==(const Complex& lhs, const double rhs) { 
    return Complex(rhs) == lhs; 
}
bool operator!=(const double& lhs, const Complex& rhs) { 
    return Complex(lhs) != rhs; 
}
bool operator!=(const Complex& lhs, const double& rhs) { 
    return Complex(rhs) != lhs; 
}
Complex operator+(const double& lhs, const Complex& rhs) { 
    return Complex(lhs) + rhs; 
}
Complex operator+(const Complex& lhs, const double& rhs) { 
    return Complex(rhs) + lhs; 
}
Complex operator-(const double& lhs, const Complex& rhs) { 
    return Complex(lhs) - rhs; 
}
Complex operator-(const Complex& lhs, const double& rhs) { 
    return lhs - Complex(rhs); 
}
Complex operator*(const double& lhs, const Complex& rhs) { 
    return Complex(lhs) * rhs; 
}
Complex operator*(const Complex& lhs, const double rhs) { 
    return Complex(rhs) * lhs; 
}
Complex operator/(const double& lhs, const Complex& rhs) { 
    return Complex(lhs) / rhs; 
}
Complex operator/(const Complex& lhs, const double& rhs) { 
    return lhs / Complex(rhs); 
}

std::ostream & Complex::writeTo(std::ostream & ostrm) const {
	 ostrm << leftBrace << re << separator << im << rightBrace;
	 return ostrm;
}

std::istream& Complex::readFrom(std::istream & istrm) {
	 char leftBrace = 0;
	 double real = 0.0;
	 char comma = 0;
	 double imaginary = 0.0;
	 char rightBrace = 0;
	 istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	 if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace)) {
            re = real;
			im = imaginary;
			
		}
		else {
			istrm.setstate(std::ios_base::failbit);	
		}
		
	}
	return istrm;
}
