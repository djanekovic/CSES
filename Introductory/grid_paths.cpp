#include <iostream>
#include <cassert>
#include <bitset>
#include <algorithm>
#include <array>
#include <vector>
#include <string>

enum class Move {
    UP, DOWN, LEFT, RIGHT, ANY
};

using Path = std::array<Move, 48>;

Move char_to_move(char c) {
    switch(c) {
        case 'U': return Move::UP;
        case 'D': return Move::DOWN;
        case 'L': return Move::LEFT;
        case 'R': return Move::RIGHT;
        case '?': return Move::ANY;
    }
    __builtin_unreachable();
}

Path read_path() {
    std::string p;
    std::cin >> p;

    Path path;
    std::transform(p.begin(), p.end(), path.begin(), [](const auto c) { return char_to_move(c); });

    return path;
}

struct GridPathGenerator {
    static constexpr auto n = 7;
    std::vector<Path> paths_;
    std::bitset<n*n> visited_;
    Path current_path_;
    std::size_t current_index_;
    int goal_row_;
    int goal_col_;

    GridPathGenerator():
        paths_{},
        visited_{},
        current_path_{},
        current_index_{},
        goal_row_{n-1},
        goal_col_{0} {}

    bool is_left_move_legal(const int row, const int col) const {
        const auto new_col = col - 1;
        return new_col >= 0 && !visited_.test(row * n + new_col);
    }

    bool is_right_move_legal(const int row, const int col) const {
        const auto new_col = col + 1;
        return new_col < n && !visited_.test(row * n + new_col);
    }

    bool is_up_move_legal(int row, int col) const {
        const auto new_row = row - 1;
        return new_row >= 0 && !visited_.test(new_row * n + col);
    }

    bool is_down_move_legal(const int row, const int col) const {
        const auto new_row = row + 1;
        return new_row < n && !visited_.test(new_row * n + col);
    }

    void recusively_generate_paths(int row=0, int col=0) {
        visited_.set(row * n + col);

        // if goal reached we are done
        if (row == goal_row_ and col == goal_col_) {
            // check if the current path is valid, ie all fields are covered
            if (visited_.all()) {
                paths_.push_back(current_path_);
            }

            return;
        }

        // short circuit checks
        if (is_left_move_legal(row, col) and is_right_move_legal(row, col)) {
            if (!is_up_move_legal(row, col) and !is_down_move_legal(row, col)) {
                // Looking at the wall, we can terminate the search here
                return;
            }
        }

        if (is_up_move_legal(row, col) and is_down_move_legal(row, col)) {
            if (!is_left_move_legal(row, col) and !is_right_move_legal(row, col)) {
                // Looking at the wall, we can terminate the search here
                return;
            }
        }

        // check the legal moves
        if (is_left_move_legal(row, col)) {
            current_path_[current_index_] = Move::LEFT;
            current_index_++;
            const auto new_row = row;
            const auto new_col = col - 1;

            recusively_generate_paths(new_row, new_col);
            visited_.reset(new_row * n + new_col);
            current_index_--;
        }

        if (is_right_move_legal(row, col)) {
            current_path_[current_index_] = Move::RIGHT;
            current_index_++;
            const auto new_row = row;
            const auto new_col = col + 1;

            recusively_generate_paths(new_row, new_col);
            visited_.reset(new_row * n + new_col);
            current_index_--;
        }

        if (is_up_move_legal(row, col)) {
            current_path_[current_index_] = Move::UP;
            current_index_++;
            const auto new_col = col;
            const auto new_row = row - 1;

            recusively_generate_paths(new_row, new_col);
            visited_.reset(new_row * n + new_col);
            current_index_--;
        }

        if (is_down_move_legal(row, col)) {
            current_path_[current_index_] = Move::DOWN;
            current_index_++;
            const auto new_col = col;
            const auto new_row = row + 1;

            recusively_generate_paths(new_row, new_col);
            visited_.reset(new_row * n + new_col);
            current_index_--;
        }
    }
};

std::vector<Path> generate_all_paths() {
    GridPathGenerator g;
    // set start
    g.recusively_generate_paths(0, 0);
    return g.paths_;
}

bool compare_paths(const Path& a, const Path& b) {
    const auto [it1, it2] = std::mismatch(std::cbegin(a), std::cend(a),
        std::cbegin(b), std::cend(b),
        [](const auto& move_a, const auto& move_b) {
            return move_a == Move::ANY or move_b == Move::ANY or move_a == move_b;
        });
    return it1 == std::cend(a) and it2 == std::cend(b);
}

int main(void) {
    Path path = read_path();
    auto paths = generate_all_paths();

    const auto cnt = std::count_if(std::cbegin(paths), std::cend(paths),
            [&](const auto p) { return compare_paths(p, path); });
    std::cout << cnt << std::endl;
}
