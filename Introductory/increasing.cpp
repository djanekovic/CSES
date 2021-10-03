#include <iostream>
#include <vector>
#include <iterator>

int main(void) {
    int n;
    std::cin >> n;

    std::vector<std::uint64_t> a;
    a.reserve(n);
    std::copy(std::istream_iterator<std::uint64_t>(std::cin),
              std::istream_iterator<std::uint64_t>(),
              std::back_inserter(a));

    std::uint64_t step = 0;
    for (auto i = 1u; i < a.size(); i++) {
        if (a[i] < a[i-1]) {
            step = step + a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }

    std::cout << step << std::endl;
}
