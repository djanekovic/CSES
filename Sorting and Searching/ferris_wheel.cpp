#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
    int num_children, max_weight;

    std::cin >> num_children;
    std::cin >> max_weight;

    std::vector<int> weights(num_children);
    for(int i = 0; i < num_children; i++) {
        std::cin >> weights[i];
    }

    std::sort(std::begin(weights), std::end(weights));

    auto start_it = std::cbegin(weights);
    auto end_it = std::cend(weights) - 1;
    auto result = 0;
    while(std::distance(start_it, end_it) >= 0) {
        if (start_it == end_it) {
            result++;
            break;
        }

        if (*start_it + *end_it > max_weight) {
            end_it--;
        } else {
            start_it++;
            end_it--;
        }
        result++;
    }

    std::cout << result << std::endl;
}
