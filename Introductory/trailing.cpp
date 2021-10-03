#include <iostream>
#include <cmath>

int main(void) {
    std::uint64_t n;
    std::cin >> n;

    int k = std::floor(std::log(n) / std::log(5));

    //https://en.wikipedia.org/wiki/Trailing_zero#Factorial
    std::uint64_t num_trailing_zeros = 0;
    for (int i = 1; i <= k; i++) {
        num_trailing_zeros += std::floor(n/std::pow(5, i));
    }

    std::cout << num_trailing_zeros << std::endl;
}
