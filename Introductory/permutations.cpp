#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
    int n;
    std::cin >> n;

    if (n > 1 && n < 4) {
        std::cout << "NO SOLUTION" << std::endl;
        return 0;
    }

    for (int i = 1; i <= n/2; i++) {
        std::cout << i * 2 << " ";
    }

    for (int i = 0; i < (n+1)/2; i++) {
        std::cout << i * 2 + 1 << " ";
    }

    std::cout << std::endl;
}
