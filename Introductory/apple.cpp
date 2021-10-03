#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>


//TODO: https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
std::int64_t find_smallest_difference_v1(const std::vector<std::int64_t>& a, int i, const std::int64_t total, std::vector<std::int64_t>& subset) {
    if (i == a.size()) {
        return std::labs(2 * std::accumulate(subset.begin(), subset.end(), std::int64_t{}) - total);
    } else {
        auto res = find_smallest_difference_v1(a, i+1, total, subset);
        subset.push_back(a[i]);
        res = std::min(res, find_smallest_difference_v1(a, i+1, total, subset));
        subset.pop_back();
        return res;
    }
}


std::int64_t smallest_difference_v1(const std::vector<std::int64_t>& a) {
    std::int64_t total = std::accumulate(a.begin(), a.end(), std::int64_t{});
    std::vector<std::int64_t> subset;
    return find_smallest_difference_v1(a, 0, total, subset);
}

int main(void) {
    std::int64_t n;
    std::cin >> n;

    std::vector<std::int64_t> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cout << smallest_difference_v1(a) << std::endl;
}
