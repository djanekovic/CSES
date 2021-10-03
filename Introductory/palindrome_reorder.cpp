#include <iostream>
#include <algorithm>
#include <string>
#include <array>

std::array<int, 26> letter_frequency(const std::string &s) {
    std::array<int, 26> freq;
    freq.fill(0);

    for (auto c: s) {
        freq[c-'A']++;
    }

    return freq;
}

int main(void) {
    std::string a;
    std::cin >> a;

    std::string b(a.size(), '0');

    const auto freq = letter_frequency(a);
    const auto odd_counter = std::count_if(freq.cbegin(), freq.cend(), [](const auto f) { return f % 2; });

    if (odd_counter > 1) {
        std::cout << "NO SOLUTION" << std::endl;
        return 0;
    }

    auto start_b = b.begin();
    auto end_b = b.rbegin();
    for (auto i = 0u; i < freq.size(); i++) {
        if (freq[i] % 2 == 0 && freq[i]) {
            for (int j = 0; j < freq[i]/2; j++) {
                *start_b = i+'A';
                start_b++;
                *end_b = i + 'A';
                end_b++;
            }
        }
    }

    if (odd_counter) {
        const auto odd_freq_it = std::find_if(freq.cbegin(), freq.cend(), [](const auto f) { return f % 2; });
        const auto odd_letter = std::distance(freq.cbegin(), odd_freq_it);

        std::fill_n(start_b, *odd_freq_it, odd_letter+'A');
    }

    std::cout << b << std::endl;
}
