#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

std::int64_t ipow_10(std::int64_t n) {
    if (n == 0) {
        return 1;
    }

    std::int64_t u = ipow_10(n/2);
    u = u*u;

    if (n % 2) {
        u = u * 10;
    }

    return u;
}

char get_digit_from_index(std::int64_t query, const std::vector<std::int64_t>& bounds) {
    const auto [lower_bound, upper_bound] = std::equal_range(bounds.cbegin(), bounds.cend(), query);
    // if lower and upper are the same take upper - 1, otherwise lower is a match, take that
    const auto bound = (lower_bound == upper_bound) ? upper_bound - 1: lower_bound;

    // number we are looking at is n-digit number
    const auto n = std::distance(bounds.cbegin(), bound) + 1;

    // find what number is that
    const auto number = static_cast<std::int64_t>(ipow_10(n-1)) + (query - *bound)/n;
    const auto remainder = (query - *bound) % n;

    //std::cout << "[ " << query << ": " << number << ", " << remainder << " ]" << std::endl;

    return std::to_string(number)[remainder];
}

int main(void) {
    int q;

    std::cin >> q;
    std::vector<std::int64_t> queries(q);

    for (int i = 0; i < q; i++) {
        std::cin >> queries[i];
    }

    const auto max_query_index = *std::max_element(queries.cbegin(), queries.cend());
    std::vector<std::int64_t> bounds;
    bounds.push_back(1);
    do {
        const auto n = bounds.size();
        bounds.push_back(bounds.back() + ipow_10(n-1) * 9 * n);
    } while(bounds.back() < max_query_index);

    std::for_each(queries.cbegin(), queries.cend(),
                  [&](const auto q) {
                      std::cout << get_digit_from_index(q, bounds) << std::endl;
                  });
}
