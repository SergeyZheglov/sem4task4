cmake_minimum_required(VERSION 3.10)

project(task4)

include_directories(my_server/inc my_client/inc ext)

add_executable(client my_client/src/client.cpp)
add_executable(server my_server/src/server.cpp my_server/src/film.cpp my_server/src/film_gen.cpp)

target_link_libraries(client ws2_32)
target_link_libraries(server ws2_32)
