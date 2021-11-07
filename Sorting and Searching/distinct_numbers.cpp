#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main(void) {
    int n;
    std::cin >> n;

    std::vector<std::int64_t> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    /*
    std::copy_n(std::istream_iterator<std::int64_t>(std::cin), n, std::begin(a));
    */

    std::sort(std::begin(a), std::end(a));
    const auto dist = std::distance(std::begin(a), std::unique(std::begin(a), std::end(a)));
    std::cout << dist << std::endl;
}
