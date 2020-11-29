cmake_minimum_required (VERSION 3.14)

project (oop1_ex03)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
    add_compile_options (/permissive-)
endif ()

add_executable (oop1_ex03 "")

add_subdirectory (include)
add_subdirectory (src)

set (Catch2_DIR "external/Catch2/lib/cmake/Catch2")
find_package (Catch2 REQUIRED)

add_executable (Tests "")
target_link_libraries (Tests Catch2::Catch2)
add_subdirectory (tests)

set (TARGET_TO_MIMIC oop1_ex03)

get_target_property (Mimic_SOURCES ${TARGET_TO_MIMIC} SOURCES)
get_target_property (Mimic_INCLUDE_DIRECTORIES ${TARGET_TO_MIMIC} INCLUDE_DIRECTORIES)

list (FILTER Mimic_SOURCES EXCLUDE REGEX ".*main.cpp")

target_sources (Tests PRIVATE ${Mimic_SOURCES})
target_include_directories (Tests PRIVATE ${Mimic_INCLUDE_DIRECTORIES})

include (CTest)
include (Catch)
catch_discover_tests (Tests)
