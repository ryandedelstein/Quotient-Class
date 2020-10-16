#include <iostream>
#include <stdexcept>
#include "Quotient.h"

int main() {
    Rat i(3.985);
    Rat k = -2.3;
    Rat j = i + k;
    k = - 2.5 + j;
    std::pair<double,double> p(3.2, -8.991);
    j += p;
    std::cout << i << std::endl;
    std::cout << k << std::endl;
    std::cout << j << std::endl;
    std::cout << (i <= k) << std::endl;
    std::cout << (i != k) << std::endl;
    std::cout << (i >= k) << std::endl;
    std::cout << (i < k) << std::endl;
    return 0;
}

