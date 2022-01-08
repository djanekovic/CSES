#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
    int n;
    std::cin >> n;

    std::int64_t x;
    std::cin >> x;

    std::vector<std::pair<int, std::int64_t>> a;
    a.reserve(n);
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        a.push_back(std::make_pair(i+1, num));
    }

    std::sort(a.begin(), a.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;
    });

    for (int i = 0; i < n; i++) {
        const auto value = x - a[i].second;
        int lo = 0;
        int hi = a.size() - 1;

        while(lo <= hi) {
            int mid = (hi + lo) / 2;
            if (a[mid].second == value and a[mid].first != a[i].first) {
                std::cout << a[i].first << " " << a[mid].first << std::endl;
                return 0;
            }
            if (a[mid].second > value) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
    }

    std::cout << "IMPOSSIBLE" << std::endl;
}
