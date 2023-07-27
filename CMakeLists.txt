cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME DFS)
set(CMAKE_CXX_FLAGS "-Wall -o2")
 
set(CMAKE_BUILD_TYPE Release)

project(${PROJECT_NAME})

set(SOURCES /src/*.cpp)
set(HEADERS include/*.hpp)

# file(GLOB 
#     HEADERS "include/*.hpp")
file(GLOB 
        SOURCES "src/*.cpp")

# message()

add_executable(master ${SOURCES} ${HEADERS})
add_executable(minion ${SOURCES} ${HEADERS})

add_library(libdfs SHARED ${SOURCES} ${HEADERS})

target_include_directories(master PRIVATE /include)
target_include_directories(minion PRIVATE /include)

target_link_libraries(master PRIVATE libdfs)
target_link_libraries(minion PRIVATE libdfs)

# include_directories() for all targets

#  install( LIBRARY DESTINATION lib INCLUDE DESTINATION include)