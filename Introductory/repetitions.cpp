#include <iostream>
#include <string>
#include <iterator>

int main(void) {
    const std::string input{std::istream_iterator<char>(std::cin),
                            std::istream_iterator<char>()};

    int longest_seq = 0;
    int current_seq_len = 0;
    char current_char = input[0];
    for (auto i = 0u; i < input.size(); i++) {
        if (input[i] == current_char) {
            current_seq_len++;
        } else {
            current_char = input[i];
            longest_seq = std::max(longest_seq, current_seq_len);
            current_seq_len = 1;
        }
    }

    std::cout << std::max(longest_seq, current_seq_len) << std::endl;
}
