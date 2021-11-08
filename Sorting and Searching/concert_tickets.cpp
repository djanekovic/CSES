#include <algorithm>
#include <iostream>
#include <set>

int main(void) {
    int num_tickets, num_customers;
    std::cin >> num_tickets;
    std::cin >> num_customers;

    std::multiset<int> ticket_prices;
    for(int i = 0; i < num_tickets; ++i) {
        int ticket_price;
        std::cin >> ticket_price;
        ticket_prices.insert(ticket_price);
    }

    for(int i = 0; i < num_customers; ++i) {
        int customer_offer;
        std::cin >> customer_offer;

        const auto it = ticket_prices.upper_bound(customer_offer);

        // it now points to the first element that is bigger than offer
        if (it == std::cbegin(ticket_prices)) {
            // every other ticket is more expensive
            std::cout << -1 << std::endl;
        } else {
            // otherwise we have a value
            std::cout << *std::prev(it) << std::endl;
            ticket_prices.erase(std::prev(it));
        }
    }
}
