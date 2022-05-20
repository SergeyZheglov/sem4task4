#include <string>
#include <vector>
#include <film.h>

class FilmGenerator {
private:
    std::vector<std::string> NAMES = {
        "Mark",
        "Thomas",
        "Andrew",
        "Apollo",
        "Arthur",
        "Michel",
        "Brian",
        "Brandon",
        "James",
        "Antony",
        "Jane",
        "Julia",
        "Katarina",
        "Martha",
        "Jenipher",
        "Bob",
        "Bruce",
        "Hue",
        "Harry"
    };

    std::vector<std::string> FAMILY_NAMES = {
        "Pitt",
        "Brown",
        "Green",
        "Keeper",
        "Williams",
        "Armstrong",
        "Eyecloser",
        "Loudshouter",
        "Walker",
        "Walls",
        "Dooropener",
        "Bloomberg",
        "Lee",
        "Spenser",
        "Bishop",
        "Harrison"
    };

    std::vector<std::string> ADJECTIVES = {
        "Glorious",
        "Frightening",
        "Unavoidable",
        "Triangular",
        "Spinning",
        "Signalling",
        "Screaming",
        "Antipodal"
    };

    std::vector<std::string> NOUNS = {
        "Fear",
        "Paradise",
        "Tennet",
        "Train",
        "House",
        "Square",
        "Death",
        "Cremation",
        "Shining",
        "Apocalypse",
        "Track"
    };

    std::vector<std::string> COUNTRIES = {
        "Russia",
        "USA",
        "North Korea",
        "UK",
        "India",
        "Japan",
        "Italy",
        "Germany",
        "Finland",
        "France",
        "Spain"
    };

public:
    int randint(int a, int b);

    template<typename T>
    T randchoice(std::vector<T> vect);

    std::string actor();

    std::vector<std::string> actors();

    std::string country();

    std::string film_name();

    int year();

    Film film(std::string name = "-");

    FilmContainer films(int _min = 2, int _max = 5);
};
