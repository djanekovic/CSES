#include <iostream>
#include <algorithm>
#include <vector>

struct Movie {
    std::int64_t start;
    std::int64_t end;
};

int main(void) {
    int n;
    std::cin >> n;

    std::vector<Movie> movies;
    movies.reserve(n);
    for (int i = 0; i < n; i++) {
        std::int64_t start, end;
        std::cin >> start >> end;
        movies.push_back(Movie{start, end});
    }

    std::sort(std::begin(movies), std::end(movies), [](const auto &a, const auto &b) {
        if (a.start == b.start) {
            return a.end > b.end;
        }
        return a.start < b.start;
    });

    //movies are now sorted by start time
    int movies_watched = 0;
    // go over each movies
    for (int i = 0; i < n; ) {
        // check maybe there is some better movie to watch than i-th
        int movie_after_my = n;
        for (int j = i+1; j < n; j++) {
            if (movies[i].end > movies[j].start) {
                if (movies[i].end >= movies[j].end) {
                    // movie j will start sooner and end sooner, it is better, we want to watch that one
                    i = j;
                }
            } else {
                // no movies will be better, we can break
                movie_after_my = j;
                break;
            }
        }

        // watch best movie
        movies_watched++;
        i = movie_after_my;
    }

    std::cout << movies_watched << std::endl;
}
