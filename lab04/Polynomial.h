//
// Created by buksa on 10/8/2025.
//

#ifndef LAB3_POLYNOMIAL_H
#define LAB3_POLYNOMIAL_H
#include <iosfwd>

using namespace std;
class Polynomial {
    // Polinom együtthatói
    double *coefficients;
    // Polinom együtthatóinak a száma
    int capacity;
public:
    Polynomial(int degree, const double coefficients[]);
    Polynomial(const Polynomial &that);
    ~Polynomial();
    // Polinom fokszáma
    int degree() const {return capacity-1;}
    // Polinom értéke a megadott pontban
    double evaluate(double x) const;
    // Polinom deriváltja
    Polynomial derivative() const;
    double operator[](int index) const;
    friend Polynomial operator -(const Polynomial &a);
    friend Polynomial operator +(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator -(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator *(const Polynomial &a, const Polynomial &b);
    friend ostream & operator <<(ostream& out, const Polynomial& what);
    /* copy assignment - mély másolat letiltása értékadásra nézve */
    Polynomial& operator=(const Polynomial&) = delete;
};
#endif //LAB3_POLYNOMIAL_H