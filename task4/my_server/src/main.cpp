#include <ctime>
#include <iostream>
#include <film_gen.h>

int main() {
    FilmGenerator gen;
    FilmContainer my_films;

    srand((unsigned)time(0));

    my_films = gen.films();
    my_films.print();

    return 0;
}
