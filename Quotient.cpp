//
// Created by ryand on 10/15/2020.
//

#include "Quotient.h"
#include <math.h>

typedef Rat::ipair ipair;
size_t Rat::decimals = 3;

Rat::Rat(): fraction(std::pair<int,int>(0,1))
{}

Rat::Rat(double x): fraction(from_double(x))
{}

Rat::Rat(int p, int q): fraction(simplify(p, q))
{}

Rat::Rat(const Rat::ipair &pair): fraction(simplify(pair.first, pair.second))
{}

Rat::Rat(const std::pair<double, double> &pair): fraction(from_double(pair))
{}

const ipair& Rat::get() const {
    return fraction;
}

int Rat::get_p() const {
    return fraction.first;
}

int Rat::get_q() const {
    return fraction.second;
}

const ipair& Rat::set(int p, int q) {
    *this = Rat(p, q);
    return get();
}

const ipair& Rat::set(double x) {
    *this = Rat(x);
    return get();
}

const ipair& Rat::set(const Rat::ipair &pair) {
    *this = Rat(pair);
    return get();
}

const ipair& Rat::set(const std::pair<double, double> &pair) {
    *this = Rat(pair);
    return get();
}

bool Rat::operator==(const Rat &rhs) const {
    return (get_p() == rhs.get_p()) && (get_q() == get_q());
}

bool Rat::operator==(double rhs) const {
    return *this == Rat(rhs);
}

bool Rat::operator==(const Rat::ipair &rhs) const {
    return *this == Rat(rhs);
}

bool Rat::operator==(const std::pair<double, double> &rhs) const {
    return *this == Rat(rhs);
}

bool Rat::operator!=(const Rat &rhs) const {
    return !(*this == rhs);
}

bool Rat::operator!=(double rhs) const {
    return !(*this == rhs);
}

bool Rat::operator!=(const Rat::ipair &rhs) const {
    return !(*this == rhs);
}

bool Rat::operator!=(const std::pair<double, double> &rhs) const {
    return !(*this == rhs);
}

bool Rat::operator<=(const Rat &rhs) const {
    return (get_p() * rhs.get_q() <= get_q() * rhs.get_p());
}

bool Rat::operator<=(double rhs) const {
    return *this <= Rat(rhs);
}

bool Rat::operator<=(const Rat::ipair &rhs) const {
    return *this <= Rat(rhs);
}

bool Rat::operator<=(const std::pair<double, double> &rhs) const {
    return *this <= Rat(rhs);
}

bool Rat::operator>=(const Rat &rhs) const {
    return (get_p() * rhs.get_q() >= get_q() * rhs.get_p());
}

bool Rat::operator>=(double rhs) const {
    return *this >= Rat(rhs);
}

bool Rat::operator>=(const Rat::ipair &rhs) const {
    return *this >= Rat(rhs);
}

bool Rat::operator>=(const std::pair<double, double> &rhs) const {
    return *this >= Rat(rhs);
}

bool Rat::operator<(const Rat &rhs) const {
    return !(*this >= rhs);
}
bool Rat::operator<(double rhs) const {
    return *this < Rat(rhs);
}

bool Rat::operator<(const Rat::ipair &rhs) const {
    return *this < Rat(rhs);
}

bool Rat::operator<(const std::pair<double, double> &rhs) const {
    return *this < Rat(rhs);
}

bool Rat::operator>(const Rat &rhs) const {
    return !(*this <= rhs);
}
bool Rat::operator>(double rhs) const {
    return *this > Rat(rhs);
}

bool Rat::operator>(const Rat::ipair &rhs) const {
    return *this > Rat(rhs);
}

bool Rat::operator>(const std::pair<double, double> &rhs) const {
    return *this > Rat(rhs);
}

Rat Rat::operator+(const Rat &rhs) const {
    int p = get_p() * rhs.get_q() + get_q() * rhs.get_p();
    int q = get_q() * rhs.get_q();
    return Rat(p, q);
}

Rat Rat::operator+(double rhs) const {
    return *this + Rat(rhs);
}

Rat Rat::operator+(const Rat::ipair &rhs) const {
    return *this + Rat(rhs);
}

Rat Rat::operator+(const std::pair<double, double> &rhs) const {
    return *this + Rat(rhs);
}

Rat Rat::operator-(const Rat &rhs) const {
    int p = get_p() * rhs.get_q() - get_q() * rhs.get_p();
    int q = get_q() * rhs.get_q();
    return Rat(p, q);
}

Rat Rat::operator-(double rhs) const {
    return *this - Rat(rhs);
}

Rat Rat::operator-(const Rat::ipair &rhs) const {
    return *this - Rat(rhs);
}

Rat Rat::operator-(const std::pair<double, double> &rhs) const {
    return *this - Rat(rhs);
}

Rat Rat::operator*(const Rat &rhs) const {
    int p = get_p() * rhs.get_p();
    int q = get_q() * rhs.get_q();
    return Rat(p, q);
}

Rat Rat::operator*(double rhs) const {
    return *this * Rat(rhs);
}

Rat Rat::operator*(const Rat::ipair &rhs) const {
    return *this * Rat(rhs);
}

Rat Rat::operator*(const std::pair<double, double> &rhs) const {
    return *this * Rat(rhs);
}

Rat Rat::operator/(const Rat &rhs) const {
    Rat temp(rhs.get_q(), rhs.get_p());
    return *this * temp;
}

Rat Rat::operator/(double rhs) const {
    return *this / Rat(rhs);
}

Rat Rat::operator/(const Rat::ipair &rhs) const {
    return *this / Rat(rhs);
}

Rat Rat::operator/(const std::pair<double, double> &rhs) const {
    return *this / Rat(rhs);
}

Rat Rat::operator%(const Rat &rhs) const {
    Rat temp(*this / rhs);
    int p = temp.get_p() % temp.get_q();
    Rat ret(p, temp.get_q());
    return ret;
}

Rat Rat::operator%(double rhs) const {
    return *this % Rat(rhs);
}

Rat Rat::operator%(const Rat::ipair &rhs) const {
    return *this % Rat(rhs);
}

Rat Rat::operator%(const std::pair<double, double> &rhs) const {
    return *this % Rat(rhs);
}

Rat& Rat::operator+=(const Rat &rhs) {
    *this = *this + rhs;
    return *this;
}

Rat& Rat::operator+=(double rhs) {
    return operator+=(Rat(rhs));
}

Rat& Rat::operator+=(const Rat::ipair &rhs) {
    return operator+=(Rat(rhs));
}

Rat& Rat::operator+=(const std::pair<double, double> &rhs) {
    return operator+=(Rat(rhs));
}

Rat& Rat::operator-=(const Rat &rhs) {
    *this = *this - rhs;
    return *this;
}

Rat& Rat::operator-=(double rhs) {
    return operator-=(Rat(rhs));
}

Rat& Rat::operator-=(const Rat::ipair &rhs) {
    return operator-=(Rat(rhs));
}

Rat& Rat::operator-=(const std::pair<double, double> &rhs) {
    return operator-=(Rat(rhs));
}

Rat& Rat::operator*=(const Rat &rhs) {
    *this = *this * rhs;
    return *this;
}

Rat& Rat::operator*=(double rhs) {
    return operator*=(Rat(rhs));
}

Rat& Rat::operator*=(const Rat::ipair &rhs) {
    return operator*=(Rat(rhs));
}

Rat& Rat::operator*=(const std::pair<double, double> &rhs) {
    return operator*=(Rat(rhs));
}

Rat& Rat::operator/=(const Rat &rhs) {
    *this = *this / rhs;
    return *this;
}

Rat& Rat::operator/=(double rhs) {
    return operator/=(Rat(rhs));
}

Rat& Rat::operator/=(const Rat::ipair &rhs) {
    return operator/=(Rat(rhs));
}

Rat& Rat::operator/=(const std::pair<double, double> &rhs) {
    return operator/=(Rat(rhs));
}

Rat& Rat::operator%=(const Rat &rhs) {
    *this = *this % rhs;
    return *this;
}

Rat& Rat::operator%=(double rhs) {
    return operator%=(Rat(rhs));
}

Rat& Rat::operator%=(const Rat::ipair &rhs) {
    return operator%=(Rat(rhs));
}

Rat& Rat::operator%=(const std::pair<double, double> &rhs) {
    return operator%=(Rat(rhs));
}

int Rat::gcd(int p, int q) const {
    /*if (q == 0) {
        throw std::invalid_argument("Error divide by zero");
    }*/

    if (q == 0) return p;
    int a = p / q;
    int r = p - a * q;
    return gcd(q, r);
}

ipair Rat::simplify(int p, int q) const {
    if (q == 0) {
        throw std::invalid_argument("Error: Divide by 0");
    }
    if (q < 0) {
        p *= -1;
        q *= -1;
    }
    int div = gcd(abs(p), abs(q));
    return ipair(p / div, q / div);
}

ipair Rat::from_double(double x) const {
    long q = pow(10, decimals);
    long p = x * q;
    return simplify(p, q);
}

ipair Rat::from_double(const std::pair<double, double> pair) const {
    long p2 = pow(10, decimals);
    long p1 = pair.first * p2;
    long q2 = pow(10, decimals);
    long q1 = pair.second * q2;
    long p = p1 * q2;
    long q = q1 * p2;
    return simplify(p, q);
}

bool operator==(double lhs, const Rat &rhs) {
    return rhs == lhs;
}

bool operator==(const Rat::ipair &lhs, const Rat &rhs) {
    return rhs == lhs;
}

bool operator==(const std::pair<double, double> &lhs, const Rat &rhs) {
    return rhs == lhs;
}

bool operator!=(double lhs, const Rat &rhs) {
    return rhs != lhs;
}

bool operator!=(const Rat::ipair &lhs, const Rat &rhs) {
    return rhs != lhs;
}

bool operator!=(const std::pair<double, double> &lhs, const Rat &rhs) {
    return rhs != lhs;
}

bool operator<=(double lhs, const Rat &rhs) {
    return rhs <= lhs;
}

bool operator<=(const Rat::ipair &lhs, const Rat &rhs) {
    return rhs <= lhs;
}

bool operator<=(const std::pair<double, double> &lhs, const Rat &rhs) {
    return rhs <= lhs;
}

bool operator>=(double lhs, const Rat &rhs) {
    return rhs >= lhs;
}

bool operator>=(const Rat::ipair &lhs, const Rat &rhs) {
    return rhs >= lhs;
}

bool operator>=(const std::pair<double, double> &lhs, const Rat &rhs) {
    return rhs >= lhs;
}

bool operator<(double lhs, const Rat &rhs) {
    return rhs < lhs;
}

bool operator<(const Rat::ipair &lhs, const Rat &rhs) {
    return rhs < lhs;
}

bool operator<(const std::pair<double, double> &lhs, const Rat &rhs) {
    return rhs < lhs;
}

bool operator>(double lhs, const Rat &rhs) {
    return rhs > lhs;
}

bool operator>(const Rat::ipair &lhs, const Rat &rhs) {
    return rhs > lhs;
}

bool operator>(const std::pair<double, double> &lhs, const Rat &rhs) {
    return rhs > lhs;
}

Rat operator+(double lhs, const Rat &rhs) {
    return rhs + lhs;
}
Rat operator+(const Rat::ipair &lhs, const Rat &rhs) {
    return rhs + lhs;
}

Rat operator+(const std::pair<double, double> &lhs, const Rat &rhs) {
    return rhs + lhs;
}

Rat operator-(double lhs, const Rat &rhs) {
    return rhs - lhs;
}
Rat operator-(const Rat::ipair &lhs, const Rat &rhs) {
    return rhs - lhs;
}

Rat operator-(const std::pair<double, double> &lhs, const Rat &rhs) {
    return rhs - lhs;
}

Rat operator*(double lhs, const Rat &rhs) {
    return rhs * lhs;
}
Rat operator*(const Rat::ipair &lhs, const Rat &rhs) {
    return rhs * lhs;
}

Rat operator*(const std::pair<double, double> &lhs, const Rat &rhs) {
    return rhs * lhs;
}

Rat operator/(double lhs, const Rat &rhs) {
    return rhs / lhs;
}
Rat operator/(const Rat::ipair &lhs, const Rat &rhs) {
    return rhs / lhs;
}

Rat operator/(const std::pair<double, double> &lhs, const Rat &rhs) {
    return rhs / lhs;
}

Rat operator%(double lhs, const Rat &rhs) {
    return rhs + lhs;
}
Rat operator%(const Rat::ipair &lhs, const Rat &rhs) {
    return rhs + lhs;
}

Rat operator%(const std::pair<double, double> &lhs, const Rat &rhs) {
    return rhs + lhs;
}

std::ostream& operator<<(std::ostream &os, const Rat &rhs) {
    os << rhs.get_p() << " / " << rhs.get_q();
    return os;
}