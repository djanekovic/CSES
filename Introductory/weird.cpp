#include <iostream>

int main(void) {
    std::uint64_t n;
    std::cin >> n;

    for(; n != 1; ) {
        std::cout << n << " ";

        if (n % 2) {
            n = n * 3 + 1;
        } else {
            n = n / 2;
        }
    }

    std::cout << 1 << std::endl;
}
