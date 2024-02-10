#pragma once
#include <iostream>
#include <sstream>

class rational {
private:
	int64_t num{ 0 };
	int64_t den{ 1 };
public:
	rational() = default;
	rational(const rational& P2) = default;
	explicit rational(const int64_t& nnum)
		: rational(nnum, 1)
	{
	}
	rational(const int64_t& nnum, const int64_t& nden)
		: num((nnum* (nden > 0 ? 1 : -1)))
		, den(std::abs(nden))
	{
		if (den == 0) {
			throw;
		}
	}
	rational& operator=(const rational& P2) = default;
	rational operator-() const;

	bool operator==(const rational& P2) const;
	bool operator==(const int64_t& nnum) const;
	friend bool operator==(const int64_t& num, const rational& P2);
	bool operator!=(const rational& P2) const;
	bool operator!=(const int64_t& nnum) const;
	friend bool operator!=(const int64_t& num, const rational& P2);
	bool operator>(const rational& P2) const;
	bool operator>(const int64_t& nnum) const;
	friend bool operator>(const int64_t& nnum, const rational& P2);
	bool operator>=(const rational& P2) const;
	bool operator>=(const int64_t& nnum) const;
	friend bool operator>=(const int64_t& nnum, const rational& P2);
	bool operator<(const rational& P2) const;
	bool operator<(const int64_t& nnum) const;
	friend bool operator<(const int64_t& nnum, const rational& P2);
	bool operator<=(const rational& P2) const;
	bool operator<=(const int64_t& nnum) const;
	friend bool operator<=(const int64_t& nnum, const rational& P2);

	rational operator=(const int64_t& nnum);
	operator int64_t() const;
	operator double() const;
	//friend int64_t operator=(int64_t nnum, const rational& p2);
	rational operator+=(const rational& P2);
	rational operator+=(const int64_t& nnum);
	rational operator-=(const rational& P2);
	rational operator-=(const int64_t& nnum);
	rational operator*=(const rational& P2);
	rational operator*=(const int64_t& nnum);
	rational operator/=(const rational& P2);
	rational operator/=(const int64_t& nnum);
	rational operator+(const rational& P2) const;
	rational operator+(const int64_t& nnum) const;
	friend rational operator+(const int64_t& nnum, const rational& P2);
	rational operator-(const rational& P2) const;
	rational operator-(const int64_t& nnum) const;
	friend rational operator-(const int64_t& nnum, const rational& P2);
	rational operator*(const rational& P2) const;
	rational operator*(const int64_t& nnum) const;
	friend rational operator*(const int64_t& nnum, const rational& P2);
	rational operator/(const rational& P2) const;
	rational operator/(const int64_t& nnum) const;
	friend rational operator/(const int64_t& nnum, const rational& P2);
	rational operator++();
	rational operator++(int k);
	rational operator--();
	rational operator--(int k);

	static const char slash{ '/' };

	std::ostream& writeto(std::ostream& ostr) const;
	std::istream& readfrom(std::istream& istrm);

	int64_t gcd() const;
	int64_t lcm(int64_t nnum, int64_t nden) const;
};
inline std::ostream& operator<<(std::ostream& ostrm, const rational& P2) {
	return P2.writeto(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, rational& P2) {
	return P2.readfrom(istrm);
}
