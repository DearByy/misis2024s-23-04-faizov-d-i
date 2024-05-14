#include "complex.hpp"

static const double eps = 2 * std::numeric_limits<double>::epsilon();

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
    return rhs.writeTo(ostrm);
}


std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
    return rhs.readFrom(istrm);
}

bool testParse(const std::string& str)
{
    using namespace std;
    istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << z << endl;

    }
    else {
        cout << "Read error : " << str << " -> " << z << endl;

    }
    return istrm.good();
}

Complex& Complex::operator+=(const Complex& rhs)
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}
Complex& Complex::operator-=(const Complex& rhs)
{
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
Complex& Complex::operator*=(const double& rhs)
{
    re *= rhs;
    im *= rhs;
    return *this;
}
Complex& Complex::operator/=(const Complex& rhs)
{
    double copy = re;
    re = ((re * rhs.re) + (im * rhs.im)) / ((rhs.re * rhs.re) + (rhs.im * rhs.im));
    im = ((rhs.re * im) - (rhs.im * copy)) / ((rhs.re * rhs.re) + (rhs.im * rhs.im));
    return *this;
}
Complex& Complex::operator/=(const double& rhs)
{
    re /= rhs;
    im /= rhs;
    return *this;
}


Complex operator+(const Complex& lhs, const Complex& rhs)
{
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
    return Complex((lhs.re * rhs.re) - (lhs.im * rhs.im), (lhs.re * rhs.im) + (lhs.im * rhs.re));
}

Complex conjugate(const Complex& rhs) {
    return Complex(rhs.re, -rhs.im);
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
    if (std::abs(denominator) > eps) {
        return Complex(((lhs.re * rhs.re) + (lhs.im * rhs.im)) / ((rhs.re * rhs.re) + (rhs.im * rhs.im))
            , ((rhs.re * lhs.im) - (rhs.im * lhs.re)) / ((rhs.re * rhs.re) + (rhs.im * rhs.im)));
    }
    throw std::overflow_error("Divide by zero exception");
}

bool Complex::operator==(const Complex& rhs) {
    return ((std::abs(re - rhs.re) < eps)
        && (std::abs(im - rhs.im) < eps));
}

bool Complex::operator!=(const Complex& rhs) {
    return !operator==(rhs);
}
bool operator==(const double& lhs, const Complex& rhs) { return Complex(lhs) == rhs; }
bool operator==(const Complex& lhs, const double rhs) { return Complex(rhs) == lhs; }
bool operator!=(const double& lhs, const Complex& rhs) { return Complex(lhs) != rhs; }
bool operator!=(const Complex& lhs, const double& rhs) { return Complex(rhs) != lhs; }
Complex operator+(const double& lhs, const Complex& rhs) { return Complex(lhs) + rhs; }
Complex operator+(const Complex& lhs, const double& rhs) { return Complex(rhs) + lhs; }
Complex operator-(const double& lhs, const Complex& rhs) { return Complex(lhs) - rhs; }
Complex operator-(const Complex& lhs, const double& rhs) { return lhs - Complex(rhs); }
Complex operator*(const double& lhs, const Complex& rhs) { return Complex(lhs) * rhs; }
Complex operator*(const Complex& lhs, const double rhs) { return Complex(rhs) * lhs; }
Complex operator/(const double& lhs, const Complex& rhs) { return Complex(lhs) / rhs; }
Complex operator/(const Complex& lhs, const double& rhs) { return lhs / Complex(rhs); }



std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}


std::istream& Complex::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaganary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
            && (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaganary;

        }
        else {
            istrm.setstate(std::ios_base::failbit);

        }

    }
    return istrm;
}


