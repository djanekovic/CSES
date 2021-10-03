#include <iostream>
#include <cmath>

int get_spare_peg(int src, int dst) {
    return 6 - src - dst;
}

void solve(int n, int src, int dst) {
    if (n == 0) {
        return;
    }

    solve(n-1, src, get_spare_peg(src, dst));
    std::cout << src << " " << dst << std::endl;
    solve(n-1, get_spare_peg(src, dst), dst);
}

int main(void) {
    int n;
    std::cin >> n;

    std::cout << std::exp2(n) - 1 << std::endl;
    solve(n, 1, 3);
}
