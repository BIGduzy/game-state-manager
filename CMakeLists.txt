cmake_minimum_required(VERSION 3.6)
project(GSM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES src/main.cpp src/States/state.h src/States/menuState.cpp src/States/menuState.h src/States/playState.cpp src/States/playState.h src/Helpers/gameStateManager.cpp src/Helpers/gameStateManager.h src/Helpers/menu.cpp src/Helpers/menu.h src/Helpers/menuItem.cpp src/Helpers/menuItem.h src/States/splashState.cpp src/States/splashState.h)
add_executable(GSM ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
# set(SFML_ROOT D:/Programming/C++/Libs/SFML-2.4.1_cmake)
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(GSM ${SFML_LIBRARIES})
endif()