cmake_minimum_required(VERSION 3.22)
project(rediPack VERSION 0.0.1 LANGUAGES CXX C ASM_NASM)

# Set C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find NASM
enable_language(ASM_NASM)
if(NOT CMAKE_ASM_NASM_COMPILER_LOADED)
    message(FATAL_ERROR "NASM compiler not found")
endif()

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add NASM source files
file(GLOB_RECURSE ASM_SOURCES "src/*.asm")

# Add source files excluding main.c
file(GLOB_RECURSE SOURCES "src/*.c")
list(FILTER SOURCES EXCLUDE REGEX ".*main\\.c$")

# Add source files excluding main.cpp
file(GLOB_RECURSE CPP_SOURCES "src/*.cpp")
list(FILTER CPP_SOURCES EXCLUDE REGEX ".*main\\.cpp$")

# Option to enable or disable CFLAGS
option(ENABLE_CFLAGS "Enable CFLAGS" OFF)

# Create an object library from the source files
add_library(rediPackObj OBJECT ${ASM_SOURCES} ${CPP_SOURCES} ${SOURCES})

# Find and link hiredis library
find_path(HIREDIS_HEADER hiredis)
message(STATUS "Hiredis header found at: ${HIREDIS_HEADER}")
target_include_directories(rediPackObj PUBLIC ${HIREDIS_HEADER})
find_library(HIREDIS_LIB hiredis)
message(STATUS "Hiredis library found at: ${HIREDIS_LIB}")
target_link_libraries(rediPackObj PRIVATE ${HIREDIS_LIB})

# Find and link redis-plus-plus library //it's placeholder CSV2 will be replaced.
find_package(csv2 REQUIRED)
target_link_libraries(rediPackObj PRIVATE ${CSV2_LIB})

# Find and link nlohmann_json library
find_package(nlohmann_json 3.11.3 REQUIRED)
target_link_libraries(rediPackObj PRIVATE nlohmann_json::nlohmann_json)

if(ENABLE_CFLAGS)
    target_compile_options(rediPackObj PRIVATE 
    $<$<COMPILE_LANGUAGE:C>:-fsanitize=address -Wall -Wextra -Werror>
    $<$<COMPILE_LANGUAGE:CXX>:-fsanitize=address -Wall -Wextra -Werror>
    )
    # Link with sanitizer library for C and C++ targets
    target_link_libraries(rediPackObj PRIVATE -fsanitize=address)
endif()

# Create the main executable with main.cpp
add_executable(rediPack src/main.cpp)
target_link_libraries(rediPack PRIVATE rediPackObj)

# Option to enable or disable GoogleTest
option(ENABLE_GTEST "Enable Google Test" OFF)

if(ENABLE_GTEST)
    enable_testing()
    find_package(GTest REQUIRED)

    # Add test executable
    add_executable(redis_api_test tests/redis_api_test.cc)
    target_link_libraries(redis_api_test PRIVATE GTest::gtest_main rediPackObj)

    include(GoogleTest)
    gtest_discover_tests(redis_api_test)
endif()

# # Install a pkg-config file.
# CONFIGURE_FILE(
#     "${CMAKE_CURRENT_SOURCE_DIR}/cmake/pkg-config.pc.in"
#     "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc"
# )