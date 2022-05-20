#include <ctime>
#include <film_gen.h>
#include <httplib.h>
#include <json.hpp>

int main() {
    httplib::Server svr;
    FilmGenerator gen;
    FilmContainer current_films;

    svr.Get("/generate", [&](const httplib::Request &, httplib::Response &res) {
        std::srand((unsigned)std::time(0));
        current_films = gen.films();
        std::cout << ">> [GET] /generate" << std::endl;
        res.set_content(current_films.to_json().dump(4), "text/plain");
    });

    svr.Get("/films", [&](const httplib::Request &, httplib::Response &res) {
        std::cout << ">> [GET] /films" << std::endl;
        res.set_content(current_films.to_json().dump(4), "text/plain");
    });

    svr.Post("/add", [&](const auto& req, auto& res) {
        std::cout << ">> [POST] /add" << std::endl;
        nlohmann::json j = nlohmann::json::parse(req.body);
        current_films.add_film(gen.film(j["name"]));
		res.set_content(current_films.to_json().dump(4), "text/plain");
	});

    svr.Post("/remove", [&](const auto& req, auto& res) {
        std::cout << ">> [POST] /remove" << std::endl;
        nlohmann::json j = nlohmann::json::parse(req.body);
        current_films.remove(j["name"]);
		res.set_content(current_films.to_json().dump(4), "text/plain");
	});

    svr.listen("127.0.0.1", 8080);

    return 0;
}
