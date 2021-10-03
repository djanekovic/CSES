#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>


std::vector<std::uint64_t> two_knights_counter(int n) {
    std::vector<std::uint64_t> counter(n);

    for (int k = n; k >= 0; k--) {
        int traversed = 0;

        for (int col = n-k; col < n; col++) {
            const int current_row = n-k;
            traversed++;

            int possible_jumps = 0;
            if (k > 3) {
                if (col == current_row || col == n-1) {
                    possible_jumps = 2;
                } else if (col == current_row + 1 || col == n-2) {
                    possible_jumps = 3;
                } else {
                    possible_jumps = 4;
                }
            } else if (k == 3) {
                possible_jumps = 2;
            } else {
                possible_jumps = 0;
            }

            counter[k-1] += k*k - possible_jumps - traversed;
        }


        for (int row = n-k+1; row < n; row++) {
            const int current_col = n-k;
            traversed++;
            int possible_jumps = 0;

            if (k > 4) {
                if (row == current_col + 1 || row == n - 1) {
                    possible_jumps = 2;
                } else if (row == current_col + 2 || row == n - 2) {
                    possible_jumps = 3;
                } else {
                    possible_jumps = 4;
                }
            } else if (k == 4) {
                possible_jumps = 2;
            } else if (k == 3) {
                possible_jumps = 1;
            }

            counter[k-1] += k*k - possible_jumps - traversed;
        }
    }

    return counter;
}

int main(void) {
    int n;
    std::cin >> n;

    std::vector<std::uint64_t> counter = two_knights_counter(n);
    std::partial_sum(counter.begin(), counter.end(), counter.begin());

    std::for_each(counter.cbegin(), counter.cend(),
                  [](const auto &c) { std::cout << c << std::endl;});
}
