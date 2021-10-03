#include <bitset>
#include <iostream>

using Chessboard = std::bitset<64>;

struct QueensSolver {
    Chessboard board_;
    std::bitset<8> columns_;
    std::bitset<8> diag1_;
    std::bitset<8> diag2_;
    int total_count_;

    template<typename T>
    explicit QueensSolver(T&& board):
        board_{std::forward<Chessboard>(board)},
        columns_{}, diag1_{}, diag2_{},
        total_count_{} {}

    bool valid_position(int row, int col) {
        // if all these are false, position is valid
        return !(columns_[col] or diag1_[row + col] or diag2_[col + 8 - row - 1]);
    }

    void set_position(int row, int col, bool value) {
        columns_[col] = diag1_[row + col] = diag2_[col + 8 - row - 1] = value;
    }

    // Backtracking DFS
    void recursive_solution(int row) {
        if (row == 8) {
            total_count_++;
            return;
        }

        // iterate all cols in the row
        for (int i = 0; i < 8; i++) {
            // if the spot is occupied or invalid continue
            if (board_[row * 8 + i] or !valid_position(row, i)) {
                continue;
            }

            // place a queen at this location, we know the location is good
            set_position(row, i, true);

            // this row is fine, try next one, go down the rabbit hole!
            recursive_solution(row+1);

            // reset queen position
            set_position(row, i, false);
        }
    }

    int get_number_of_solutions() {
        total_count_ = 0;
        recursive_solution(0);
        return total_count_;
    }
};

int main(void) {
    Chessboard board;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            std::cin >> c;
            board[i * 8 + j] = c == '*';
        }
    }

    QueensSolver solver(std::move(board));
    std::cout << solver.get_number_of_solutions() << std::endl;
}
