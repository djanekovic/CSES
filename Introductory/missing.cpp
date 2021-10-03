#include <iostream>
#include <iterator>
#include <numeric>

int main(void) {
    std::uint64_t n;
    std::cin >> n;

    const std::uint64_t sum = std::accumulate(std::istream_iterator<int>(std::cin),
                                              std::istream_iterator<int>(), 0UL);

    const std::uint64_t total = n * (n+1) / 2;
    std::cout << total - sum << std::endl;
}
