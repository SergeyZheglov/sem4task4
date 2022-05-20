#include <iostream>
#include <fstream>
#include <film.h>

Film::Film() {}

Film::Film(std::string name_, std::string country_, int year_, std::vector<std::string> actors_) {
    name = name_;
    country = country_;
    year = year_;
    actors = actors_;
}

std::string Film::get_name() {
    return name;
}

int Film::get_year() {
    return year;
}

void Film::from_json(nlohmann::json data) {
    name = data["name"];
    country = data["country"];
    year = data["year"];

    auto data_actors = data["actors"];
    for (auto p = data_actors.begin(); p != data_actors.end(); p++)
        actors.push_back(*p);
}

nlohmann::json Film::to_json() {
    nlohmann::json result = {
        {"name", name},
        {"country", country},
        {"year", year},
        {"actors", actors}
    };
    return result;
}

void Film::print_as_json() {
    std::cout << std::setw(4) << to_json() << std::endl;
}


FilmContainer::~FilmContainer() {
    std::vector<Film>().swap(films);
}

void FilmContainer::add_film(Film film) {
    films.push_back(film);
}

Film FilmContainer::get_film(std::string name) {
    Film empty;
    for (auto p = films.begin(); p != films.end(); p++) {
        if ((*p).get_name() == name) {
            return *p;
        }
    }
    return empty;
}

void FilmContainer::remove(std::string name) {
    for (auto p = films.begin(); p != films.end(); p++) {
        if ((*p).get_name() == name) {
            films.erase(p);
            break;
        }
    }
}

int FilmContainer::read(std::string filename) {
    std::ifstream fp;
    nlohmann::json data;

    fp.open(filename);
    if (!fp)
    {
        std::cout << "Failed to open '" << filename << "'" << std::endl;
        return 0;
    }
    fp >> data;
    fp.close();
    for (auto p = data.begin(); p != data.end(); p++)
    {
        Film new_film;
        new_film.from_json(*p);
        films.push_back(new_film);
    }
    return 1;
}

nlohmann::json FilmContainer::to_json(int after_year) {
    nlohmann::json arr = nlohmann::json::array();
    for (auto p = films.begin(); p != films.end(); p++) {
        if ((*p).get_year() >= after_year)
            arr.push_back((*p).to_json());
    }
    return arr;
}

void FilmContainer::print() {
    std::cout << std::setw(4) << to_json() << std::endl;
}

int FilmContainer::execute(std::string filename, int after_year) {
    std::ofstream fp;

    fp.open(filename);
    if (!fp) {
        std::cout << "Failed to open '" << filename << "'" << std::endl;
        return 0;
    }

    fp << std::setw(4) << to_json(after_year);
    fp.close();
    return 1;
}
