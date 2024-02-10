#include <iostream>
#include <sstream>
#include "complex.h"

Complex Complex::operator-() const {
	return (Complex(-this->real, -this->imagine));
}
Complex Complex::operator=(const double& nreal) {
	this->real = nreal;
	this->imagine = 0.0;
	return *this;
}
bool Complex::operator==(const Complex& P2) {
	return (this->real == P2.real && this->imagine == P2.imagine);
}
bool Complex::operator==(const double& nreal) {
	return ((this->real == nreal) && (this->imagine == 0.0));
}
bool operator==(const double& nreal, const Complex& P2) {
	return ((P2.real == nreal) && (P2.imagine == 0));
}
bool Complex::operator!=(const Complex& P2) {
	return (!operator==(P2));
}
bool Complex::operator!=(const double& nreal) {
	return (!operator==(nreal));
}
bool operator!=(const double& nreal, const Complex& P2) {
	return (!operator==(nreal, P2));
}
Complex Complex::operator+=(const Complex& P2) {
	this->real += P2.real;
	this->imagine += P2.imagine;
	return *this;
}
Complex Complex::operator+=(const double& nreal) {
	return operator+=(Complex(nreal));
}
Complex Complex::operator-=(const Complex& P2) {
	this->real -= P2.real;
	this->imagine -= P2.imagine;
	return *this;
}
Complex Complex::operator-=(const double& nreal) {
	return operator-=(Complex(nreal));
}
void Complex::operator--() {
	this->real -= 1;
}
void Complex::operator++() {
	this->real += 1;
}
Complex Complex::operator*=(const Complex& P2) {
	double threal(this->real), thimagine(this->imagine);
	this->real = threal * P2.real - thimagine * P2.imagine;
	this->imagine = threal * P2.imagine + thimagine * P2.real;
	return *this;
}
Complex Complex::operator*=(const double& nreal) {
	this->real *= nreal;
	this->imagine *= nreal;
	return *this;
}
Complex Complex::operator/=(const Complex& P2) {
	if ((P2.real * P2.real + P2.imagine * P2.imagine) != 0) {
		double threal(this->real), thimagine(this->imagine);
		this->real = (threal * P2.real + thimagine * P2.imagine) / (P2.real * P2.real + P2.imagine * P2.imagine);
		this->imagine = (thimagine * P2.real - threal * P2.imagine) / (P2.real * P2.real + P2.imagine * P2.imagine);
		return *this;
	}
	throw "DivisionError -> Can not divide by 0";
}
Complex Complex::operator/=(const double& nreal) {
	if (nreal != 0) {
		this->real /= nreal;
		this->imagine /= nreal;
		return *this;
	}
	throw "DivisionError -> Can not divide by 0";
}
Complex Complex::operator+(const Complex& P2) {
	Complex sum(*this);
	sum += P2;
	return sum;
}
Complex Complex::operator+(const double& nreal) {
	return operator+(Complex(nreal));
}
Complex operator+(const double& nreal, const Complex& P2) {
	Complex sum(P2);
	sum += nreal;
	return sum;
}
Complex Complex::operator-(const Complex& P2) {
	Complex diff(*this);
	diff -= P2;
	return diff;
}
Complex Complex::operator-(const double& nreal) {
	return operator-(Complex(nreal));
}
Complex operator-(const double& nreal, const Complex& P2) {
	Complex diff(nreal);
	diff -= P2;
	return diff;
}
Complex Complex::operator*(const Complex& P2) {
	Complex mul(*this);
	mul *= P2;
	return mul;
}
Complex Complex::operator*(const double& nreal) {
	Complex mul(*this);
	mul *= nreal;
	return mul;
}
Complex operator*(const double& nreal, const Complex& P2) {
	Complex mul(P2);
	mul *= nreal;
	return mul;
}
Complex Complex::operator/(const Complex& P2) {
	Complex divi(*this);
	divi /= P2;
	return divi;
}
Complex Complex::operator/(const double& nreal) {
	Complex divi(*this);
	divi /= nreal;
	return divi;
}
Complex operator/(const double& nreal, const Complex& P2) {
	Complex divi(nreal);
	divi /= P2;
	return divi;
}
std::ostream& Complex::writeTo(std::ostream& ostrm) const {
	ostrm << left_brace << real << comma << imagine << right_brace;
	return ostrm;
}
std::istream& Complex::readFrom(std::istream& istrm) {
	char LeftBrace(0);
	double nreal(0.0);
	char Comma(0);
	double nimagine(0.0);
	char RightBrace(0);
	istrm >> LeftBrace >> nreal >> Comma >> nimagine >> RightBrace;
	if (istrm.good()) {
		if ((LeftBrace == Complex::left_brace) && (Comma == Complex::comma) && (RightBrace == Complex::right_brace)) {
			real = nreal;
			imagine = nimagine;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}
