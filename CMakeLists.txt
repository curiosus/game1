cmake_minimum_required(VERSION 3.2)
project(phuckman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
set(EXECUTABLE_NAME "phuckman")
add_executable(phuckman ${SOURCE_FILES} Game.cpp Game.h Block.cpp Block.h Player.cpp Player.h Bot.cpp Bot.h)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

