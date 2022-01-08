#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
    int n;
    std::cin >> n;

    std::vector<std::pair<std::int64_t, bool>> customers;
    customers.reserve(2 * n);
    for (int i = 0; i < n; i++) {
        std::int64_t arrival, leaving;
        std::cin >> arrival >> leaving;
        customers.push_back(std::make_pair(arrival, true));
        customers.emplace_back(std::make_pair(leaving, false));
    }

    std::sort(std::begin(customers), std::end(customers), [](const auto &a, const auto &b) {
        if (a.first == b.first) {
            if (a.second == b.second) {
                return false;
            }
            return a.second;
        }
        return a.first < b.first;
    });


    int max = 0;
    int current_count = 0;
    for (auto i = 0UL; i < customers.size(); i++) {
        if (customers[i].second) {
            current_count++;
        } else {
            current_count--;
        }

        max = std::max(max, current_count);
    }

    std::cout << max << std::endl;
}
