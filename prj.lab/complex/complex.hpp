#ifndef Complex_2024
#define Complex_2024

#include <iostream>
#include <sstream>
#include <limits>
static const double eps = 2 * std::numeric_limits<double>::epsilon();


struct Complex {
    double re{ 0.0 };   //тоже самое, что double re = 0.0;
    double im{ 0.0 };  

    static const char leftBrace{ '{' };  
    static const char separator{ ',' };   
    static const char rightBrace{ '}' };  
  
    Complex() = default;
    Complex(const Complex&) = default;
    explicit Complex(const double real) : re(real) {} //если число имеет только веществ. часть
    Complex(const double real, const double imaginary) : re(real), im(imaginary) {}
    ~Complex() = default;



    bool operator==(const Complex& rhs) {
        return ((std::abs(re - rhs.re) < eps) && (std::abs(im - rhs.im) < eps)); 
    }
    
    
    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs) {
        return operator+=(Complex(rhs));
    }
    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs) {
        return operator-=(Complex(rhs));
    }
    //объявили внутри структуры, опеределим вне
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double& rhs);
    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double& rhs);


    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator+(const double lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator-(const double lhs, const Complex& rhs);

Complex operator*(const Complex& lhs, const Complex& rhs);


Complex operator*(const Complex& lhs, const double rhs);

Complex operator*(const double lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const double rhs);

Complex operator/(const double lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs);
inline std::istream& operator>>(std::istream& istrm, Complex& rhs);
bool testparse(const std::string& str);

#endif
