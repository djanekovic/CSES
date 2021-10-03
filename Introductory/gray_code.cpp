#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>


std::string to_string(int i, int n) {
    std::string a;
    a.reserve(n);

    for (int j = n-1; j >= 0; j--) {
        a.push_back((1 << j & i) ? '1' : '0');
    }

    return a;
}

int main(void) {
    int n;
    std::cin >> n;

    std::vector<int> gray{0, 1};

    for (int i = 2; i <= n; i++) {
        int number_of_codes = std::exp2(i);
        gray.reserve(number_of_codes);
        const auto tmp = gray;
        gray.clear();
        for (int j = 0; j < number_of_codes; j++) {
            if (j < number_of_codes/2) {
                gray.push_back(0 + tmp[j]);
            } else {
                gray.push_back(number_of_codes/2 + tmp[-j - 1 + number_of_codes]);
            }
        }
    }

    std::for_each(gray.cbegin(), gray.cend(),
                  [n](const auto i) { std::cout << to_string(i, n) << std::endl; });
}
