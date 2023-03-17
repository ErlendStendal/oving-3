cmake_minimum_required(VERSION 3.22)
project(tcp_server_client)
set(CMAKE_C_STANDARD 11)

add_executable(client client.c)
add_executable(publisher publisher.c)
target_include_directories(client PRIVATE lib/mosquitto/lib
lib/mosquitto/include)
target_include_directories(publisher PRIVATE lib/mosquitto/lib
lib/mosquitto/include)
target_link_libraries(client mosquitto)
target_link_libraries(publisher mosquitto)