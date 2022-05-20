#include <string>
#include <vector>
#include <json.hpp>

class Film {
private:
    std::string name;
    std::string country;
    int year;
    std::vector<std::string> actors;

public:
    Film();
    Film(std::string name_, std::string country_, int year_, std::vector<std::string> actors_);
    std::string get_name();
    int get_year();
    void from_json(nlohmann::json data);
    nlohmann::json to_json();
    void print_as_json();
};


class FilmContainer {
private:
    std::vector<Film> films;

public:
    ~FilmContainer();
    void add_film(Film film);
    Film get_film(std::string name);
    void remove(std::string name);
    int read(std::string filename);
    nlohmann::json to_json(int after_year = 0);
    void print();
    int execute(std::string filename, int after_year = 0);
};
