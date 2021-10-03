#include <iostream>

int main(void) {
    int t;
    std::cin >> t;

    while(t--) {
        std::uint64_t a, b;
        std::cin >> a >> b;

        std::uint64_t y = 0;
        if ((2*b - a) % 3 == 0) {
            y = (2*b - a) / 3;

            if (b >= 2 * y) {
                std::cout << "YES" << std::endl;
                continue;
            }
        }

        std::cout << "NO" << std::endl;
    }
}
