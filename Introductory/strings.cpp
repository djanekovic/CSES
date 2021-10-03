#include <set>
#include <iostream>
#include <string>
#include <algorithm>

//https://en.wikipedia.org/wiki/Heap%27s_algorithm
template<typename PermutationsCont>
void generate(int k, std::string& A, PermutationsCont& permutations) {
    if (k == 0) {
        permutations.insert(A);
        return;
    }

    generate(k-1, A, permutations);

    for (int i = 0; i < k-1; i++) {
        if (k % 2 == 0) {
            std::swap(A[i], A[k-1]);
        } else {
            std::swap(A[0], A[k-1]);
        }

        generate(k-1, A, permutations);
    }
}

int main(void) {
    std::string start;
    std::cin >> start;

    std::set<std::string> permutations;
    generate(start.size(), start, permutations);

    std::cout << permutations.size() << std::endl;

    std::for_each(permutations.cbegin(), permutations.cend(),
                [](const auto &s) { std::cout << s << std::endl;});
}
