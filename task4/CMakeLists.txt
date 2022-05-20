cmake_minimum_required(VERSION 3.10)
# set(CMAKE_CXX_FLAGS "-fmax-errors=5")

project(task4)

set(CLIENT_SRC my_client/src/client.cpp)
set(SERVER_SRC my_server/src/server.cpp my_server/src/film.cpp my_server/src/film_gen.cpp)

set(INCLUDE_DIR my_server/inc ext)

include_directories(${INCLUDE_DIR})

add_executable(client ${CLIENT_SRC})
add_executable(server ${SERVER_SRC})

target_link_libraries(client ws2_32)
target_link_libraries(server ws2_32)
