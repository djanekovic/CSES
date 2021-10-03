#include <iostream>

/**
 * Fast computation of x^n % mod
 */
std::uint64_t fast_modpow(const std::uint64_t x, const std::uint64_t n, const std::uint64_t mod) {
    if (n == 0) {
        return 1;
    }

    std::uint64_t u = fast_modpow(x, n/2, mod);

    u = (u * u)  % mod;
    if (n % 2) {
        u = (u * x) % mod;
    }

    return u;
}

int main(void) {
    constexpr std::uint64_t mod = 1000000007;
    std::uint64_t n;
    std::cin >> n;

    std::cout << fast_modpow(2, n, mod) << std::endl;
}
