#include <iostream>
#include <cassert>

std::uint64_t even_series(std::uint64_t row_index, std::uint64_t col_index) {
    assert (col_index <= row_index);
    return row_index * row_index - col_index + 1;
}

std::uint64_t odd_series(std::uint64_t row_index, std::uint64_t col_index) {
    assert (col_index <= row_index);
    return (row_index * row_index) - (2 * row_index) + 1 + col_index;
}

int main(void) {
    int t;
    std::cin >> t;

    while(t--) {
        std::uint64_t row, col;
        std::cin >> row >> col;

        if (row == col) {
            std::cout << row * row - row + 1 << std::endl;
            continue;
        }

        if (row > col) {
            if (row % 2) {
                std::cout << odd_series(row, col) << std::endl;
            } else {
                std::cout << even_series(row, col) << std::endl;
            }
        } else {
            if (col % 2) {
                std::cout << even_series(col, row) << std::endl;
            } else {
                std::cout << odd_series(col, row) << std::endl;
            }
        }
    }
}
