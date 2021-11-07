#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
    int number_of_applicants, number_of_apartments, tolerance;
    std::cin >> number_of_applicants;
    std::cin >> number_of_apartments;
    std::cin >> tolerance;

    std::vector<int> desired_apartment_sizes(number_of_applicants);
    for (int i = 0; i < number_of_applicants; i++) {
        std::cin >> desired_apartment_sizes[i];
    }

    std::vector<int> apartment_sizes(number_of_apartments);
    for (int i = 0; i < number_of_apartments; i++) {
        std::cin >> apartment_sizes[i];
    }

    std::sort(std::begin(desired_apartment_sizes), std::end(desired_apartment_sizes));
    std::sort(std::begin(apartment_sizes), std::end(apartment_sizes));

    auto start_it = std::cbegin(desired_apartment_sizes);
    const auto result = std::count_if(std::cbegin(apartment_sizes),
                                      std::cend(apartment_sizes),
                                      [&](const auto apartment_size) {
        // we need -1 since we want *greater_equals* apartment_size - tolerance
        const auto it = std::upper_bound(start_it,
                                         std::cend(desired_apartment_sizes),
                                         apartment_size - tolerance - 1);
        if (it != std::end(desired_apartment_sizes) and
            apartment_size >= *it - tolerance and
            apartment_size <= *it + tolerance) {
            start_it = it+1;
            return true;
        }
        return false;
    });

    std::cout << result << std::endl;
}
