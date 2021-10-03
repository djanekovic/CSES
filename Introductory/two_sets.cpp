#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
    std::int64_t n;

    std::cin >> n;

    std::uint64_t total_sum = n * (n+1) / 2;

    if (total_sum % 2) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    std::cout << "YES" << std::endl;

    std::vector<std::uint64_t> a;
    std::vector<std::uint64_t> b;

    while(n > 0) {
        a.push_back(std::max(0L, n));         // 4 - 3 - 2
        b.push_back(std::max(0L, n-1));       // 3 - 2 - 1
        b.push_back(std::max(0L, n-2));       // 2 - 1 - 0

        if (n - 3) {
            a.push_back(std::max(0L, n-3));       // 1 - 0
        }
        n -= 4;
    }

    std::cout << a.size() << std::endl;
    std::for_each(a.begin(), a.end(), [](const auto &a) { std::cout << a << " ";});
    std::cout << std::endl;

    std::cout << b.size() << std::endl;
    std::for_each(b.begin(), b.end(), [](const auto &a) { std::cout << a << " ";});
    std::cout << std::endl;
}
