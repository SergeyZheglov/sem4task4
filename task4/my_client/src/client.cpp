#include <ctime>
#include <iostream>
#include <string>
#include <httplib.h>
#include <json.hpp>

void print_help();

int main() {
    httplib::Client cli("127.0.0.1", 8080);
    std::string cmd, name;

    print_help();

    while (std::cin >> cmd) {
        if (cmd == "exit") {
            break;
        }
        else if (cmd == "help") {
            print_help();
        }
        else if (cmd == "generate") {
            auto res = cli.Get("/generate");
            std::cout << std::setw(4) << res->body << std::endl;
        }
        else if (cmd == "print") {
            auto res = cli.Get("/films");
            std::cout << std::setw(4) << res->body << std::endl;
        }
        else if (cmd == "add") {
            std::getline(std::cin, name);
            nlohmann::json content = {{"name", name}};
            cli.Post("/add", content.dump(), "text/plain");
            std::cout << "> Added " << name << std::endl;
        }
        else if (cmd == "delete") {
            std::getline(std::cin, name);
            nlohmann::json content = {{"name", name}};
            cli.Post("/remove", content.dump(), "text/plain");
            std::cout << "> Deleted " << name << std::endl;
        }
        else {
            std::cout << "Unknown command" << std::endl;
        }
    }
    std::cout << "\nFinished" << std::endl;

    return 0;
}

void print_help() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "Commands:" << std::endl;
    std::cout << "  exit - finish the program" << std::endl;
    std::cout << "  help - prints this text" << std::endl;
    std::cout << "  generate - generate random films" << std::endl;
    std::cout << "  print - prints all films" << std::endl;
    std::cout << "  add <name> - adds a random film with this name" << std::endl;
    std::cout << "  delete <name> - removes a film with this name" << std::endl;
    std::cout << "--------------------------" << std::endl;
}
