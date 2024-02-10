#pragma once
#include <sstream>
#include <iostream>

struct Complex {
	double real{ 0.0 };
	double imagine{ 0.0 };
	Complex() = default;
	Complex(const Complex& P2) = default;
	explicit Complex(double nreal)
		:real(nreal)
	{
	}
	Complex(double nreal, double nimagine)
		: real(nreal)
		, imagine(nimagine)
	{
	}
	Complex& operator=(const Complex& P2) = default; //P1 = P2
	~Complex() = default;

	Complex operator-() const;
	Complex operator=(const double& nreal); //P1 = nreal
	bool operator==(const Complex& P2); //P1 == P2
	bool operator==(const double& nreal); //P1 == nreal
	friend bool operator==(const double& nreal, const Complex& P2); //nreal == P2
	bool operator!=(const Complex& P2); //P1 != P2
	bool operator!=(const double& nreal); //P1 != nreal
	friend bool operator!=(const double& nreal, const Complex& P2); //nreal != P2
	Complex operator+=(const Complex& P2);
	Complex operator+=(const double& nreal);
	Complex operator-=(const Complex& P2);
	Complex operator-=(const double& nreal);
	Complex operator*=(const Complex& P2);
	Complex operator*=(const double& nreal);
	Complex operator/=(const Complex& P2);
	Complex operator/=(const double& nreal);
	void operator--();
	void operator++();
	Complex operator+(const Complex& P2);
	Complex operator+(const double& nreal);
	friend Complex operator+(const double& nreal, const Complex& P2);
	Complex operator-(const Complex& P2);
	Complex operator-(const double& nreal);
	friend Complex operator-(const double& nreal, const Complex& P2);
	Complex operator*(const Complex& P2);
	Complex operator*(const double& nreal);
	friend Complex operator*(const double& nreal, const Complex& P2);
	Complex operator/(const Complex& P2);
	Complex operator/(const double& nreal);
	friend Complex operator/(const double& nreal, const Complex& P2);

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	static const char left_brace{ '{' };
	static const char comma{ ',' };
	static const char right_brace{ '}' };
};
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& P2) {
	return P2.writeTo(ostrm);
}
inline std::istream& operator<<(std::istream& istrm, Complex& P2) {
	return P2.readFrom(istrm);
}
