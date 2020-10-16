//
// Created by ryand on 10/16/2020.
//

#ifndef QUOTIENT_CLASS_QUOTIENT_H
#define QUOTIENT_CLASS_QUOTIENT_H



#include <stdexcept>
#include <iostream>
#include <utility>

class Rat {
public:
    //pair of integers, is how p and q are held
    typedef std::pair<int,int> ipair;
    //constructors
    Rat();
    Rat(int p, int q);
    Rat(const ipair& pair);
    Rat(const std::pair<double, double>& pair);
    Rat(double x);

    //set and get
    const ipair& get() const;
    int get_p() const;
    int get_q() const;
    //does check for gcd, returns the simplified pair
    const ipair& set(int p, int q);
    const ipair& set(double x);
    const ipair& set(const ipair& pair);
    const ipair& set(const std::pair<double, double>& pair);

    //operators
    bool operator==(const Rat& rhs) const;
    bool operator==(double rhs) const;
    bool operator==(const ipair& rhs) const;
    bool operator==(const std::pair<double,double>& rhs) const;
    friend bool operator==(double lhs, const Rat& rhs);
    friend bool operator==(const ipair& lhs, const Rat& rhs);
    friend bool operator==(const std::pair<double,double>& lhs, const Rat& rhs);

    bool operator!=(const Rat& rhs) const;
    bool operator!=(double rhs) const;
    bool operator!=(const ipair& rhs) const;
    bool operator!=(const std::pair<double,double>& rhs) const;
    friend bool operator!=(double lhs, const Rat& rhs);
    friend bool operator!=(const ipair& lhs, const Rat& rhs);
    friend bool operator!=(const std::pair<double,double>& lhs, const Rat& rhs);

    bool operator<=(const Rat& rhs) const;
    bool operator<=(double rhs) const;
    bool operator<=(const ipair& rhs) const;
    bool operator<=(const std::pair<double,double>& rhs) const;
    friend bool operator<=(double lhs, const Rat& rhs);
    friend bool operator<=(const ipair& lhs, const Rat& rhs);
    friend bool operator<=(const std::pair<double,double>& lhs, const Rat& rhs);

    bool operator>=(const Rat& rhs) const;
    bool operator>=(double rhs) const;
    bool operator>=(const ipair& rhs) const;
    bool operator>=(const std::pair<double,double>& rhs) const;
    friend bool operator>=(double lhs, const Rat& rhs);
    friend bool operator>=(const ipair& lhs, const Rat& rhs);
    friend bool operator>=(const std::pair<double,double>& lhs, const Rat& rhs);

    bool operator<(const Rat& rhs) const;
    bool operator<(double rhs) const;
    bool operator<(const ipair& rhs) const;
    bool operator<(const std::pair<double,double>& rhs) const;
    friend bool operator<(double lhs, const Rat& rhs);
    friend bool operator<(const ipair& lhs, const Rat& rhs);
    friend bool operator<(const std::pair<double,double>& lhs, const Rat& rhs);

    bool operator>(const Rat& rhs) const;
    bool operator>(double rhs) const;
    bool operator>(const ipair& rhs) const;
    bool operator>(const std::pair<double,double>& rhs) const;
    friend bool operator>(double lhs, const Rat& rhs);
    friend bool operator>(const ipair& lhs, const Rat& rhs);
    friend bool operator>(const std::pair<double,double>& lhs, const Rat& rhs);

    Rat operator+(const Rat& rhs) const;
    Rat operator+(double rhs) const;
    Rat operator+(const ipair& rhs) const;
    Rat operator+(const std::pair<double,double>& rhs) const;
    friend Rat operator+(double lhs, const Rat& rhs);
    friend Rat operator+(const ipair& lhs, const Rat& rhs);
    friend Rat operator+(const std::pair<double,double>& lhs, const Rat& rhs);

    Rat operator-(const Rat& rhs) const;
    Rat operator-(double rhs) const;
    Rat operator-(const ipair& rhs) const;
    Rat operator-(const std::pair<double,double>& rhs) const;
    friend Rat operator-(double lhs, const Rat& rhs);
    friend Rat operator-(const ipair& lhs, const Rat& rhs);
    friend Rat operator-(const std::pair<double,double>& lhs, const Rat& rhs);

    Rat operator*(const Rat& rhs) const;
    Rat operator*(double rhs) const;
    Rat operator*(const ipair& rhs) const;
    Rat operator*(const std::pair<double,double>& rhs) const;
    friend Rat operator*(double lhs, const Rat& rhs);
    friend Rat operator*(const ipair& lhs, const Rat& rhs);
    friend Rat operator*(const std::pair<double,double>& lhs, const Rat& rhs);

    Rat operator/(const Rat& rhs) const;
    Rat operator/(double rhs) const;
    Rat operator/(const ipair& rhs) const;
    Rat operator/(const std::pair<double,double>& rhs) const;
    friend Rat operator/(double lhs, const Rat& rhs);
    friend Rat operator/(const ipair& lhs, const Rat& rhs);
    friend Rat operator/(const std::pair<double,double>& lhs, const Rat& rhs);

    Rat operator%(const Rat& rhs) const;
    Rat operator%(double rhs) const;
    Rat operator%(const ipair& rhs) const;
    Rat operator%(const std::pair<double,double>& rhs) const;
    friend Rat operator%(double lhs, const Rat& rhs);
    friend Rat operator%(const ipair& lhs, const Rat& rhs);
    friend Rat operator%(const std::pair<double,double>& lhs, const Rat& rhs);

    Rat& operator+=(const Rat& rhs);
    Rat& operator+=(double rhs);
    Rat& operator+=(const ipair& rhs);
    Rat& operator+=(const std::pair<double,double>& rhs);

    Rat& operator-=(const Rat& rhs);
    Rat& operator-=(double rhs);
    Rat& operator-=(const ipair& rhs);
    Rat& operator-=(const std::pair<double,double>& rhs);

    Rat& operator*=(const Rat& rhs);
    Rat& operator*=(double rhs);
    Rat& operator*=(const ipair& rhs);
    Rat& operator*=(const std::pair<double,double>& rhs);

    Rat& operator/=(const Rat& rhs);
    Rat& operator/=(double rhs);
    Rat& operator/=(const ipair& rhs);
    Rat& operator/=(const std::pair<double,double>& rhs);

    Rat& operator%=(const Rat& rhs);
    Rat& operator%=(double rhs);
    Rat& operator%=(const ipair& rhs);
    Rat& operator%=(const std::pair<double,double>& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Rat& rhs);

    static size_t decimals;

private:
    ipair from_double(const std::pair<double, double> pair) const;
    ipair from_double(double x) const;
    ipair simplify(int p, int q) const;
    int gcd(int p, int q) const;

    std::pair<int, int> fraction;
};

bool operator==(double lhs, const Rat& rhs);
bool operator==(const Rat::ipair& lhs, const Rat& rhs);
bool operator==(const std::pair<double,double>& lhs, const Rat& rhs);
bool operator!=(double lhs, const Rat& rhs);
bool operator!=(const Rat::ipair& lhs, const Rat& rhs);
bool operator!=(const std::pair<double,double>& lhs, const Rat& rhs);
bool operator<=(double lhs, const Rat& rhs);
bool operator<=(const Rat::ipair& lhs, const Rat& rhs);
bool operator<=(const std::pair<double,double>& lhs, const Rat& rhs);
bool operator>=(double lhs, const Rat& rhs);
bool operator>=(const Rat::ipair& lhs, const Rat& rhs);
bool operator>=(const std::pair<double,double>& lhs, const Rat& rhs);
bool operator<(double lhs, const Rat& rhs);
bool operator<(const Rat::ipair& lhs, const Rat& rhs);
bool operator<(const std::pair<double,double>& lhs, const Rat& rhs);
bool operator>(double lhs, const Rat& rhs);
bool operator>(const Rat::ipair& lhs, const Rat& rhs);
bool operator>(const std::pair<double,double>& lhs, const Rat& rhs);
Rat operator+(double lhs, const Rat& rhs);
Rat operator+(const Rat::ipair& lhs, const Rat& rhs);
Rat operator+(const std::pair<double,double>& lhs, const Rat& rhs);
Rat operator-(double lhs, const Rat& rhs);
Rat operator-(const Rat::ipair& lhs, const Rat& rhs);
Rat operator-(const std::pair<double,double>& lhs, const Rat& rhs);
Rat operator*(double lhs, const Rat& rhs);
Rat operator*(const Rat::ipair& lhs, const Rat& rhs);
Rat operator*(const std::pair<double,double>& lhs, const Rat& rhs);
Rat operator/(double lhs, const Rat& rhs);
Rat operator/(const Rat::ipair& lhs, const Rat& rhs);
Rat operator/(const std::pair<double,double>& lhs, const Rat& rhs);
Rat operator%(double lhs, const Rat& rhs);
Rat operator%(const Rat::ipair& lhs, const Rat& rhs);
Rat operator%(const std::pair<double,double>& lhs, const Rat& rhs);
std::ostream& operator<<(std::ostream& os, const Rat& rhs);


#endif //QUOTIENT_CLASS_QUOTIENT_H
