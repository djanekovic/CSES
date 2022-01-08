#include <iostream>
#include <vector>
#include <limits>

int main(void) {
    int n;
    std::cin >> n;

    std::vector<std::int64_t> a;
    a.reserve(n);
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        a.push_back(num);
    }

    // I have no idea what is happening and why is this overflowing
    std::int64_t current_sum = 0;
    std::int64_t best_sum = std::numeric_limits<std::int64_t>::min() + 1;
    for (int i = 0; i < n; i++) {
        current_sum = std::max(current_sum + a[i], a[i]);
        best_sum = std::max(current_sum, best_sum);
    }

    std::cout << best_sum << std::endl;
}
