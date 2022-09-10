cmake_minimum_required(VERSION 3.15)

# # Uncomment this line below and supply a toolchain.cmake file
# #
# set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/toolchain.cmake)
project(main VERSION 0.0.1 LANGUAGES CXX)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

find_package(libbasis REQUIRED CONFIG)

set(LINKER_SCRIPT_PATHS ${CMAKE_SOURCE_DIR}/linker)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
target_compile_options(${PROJECT_NAME} PRIVATE ${CORTEX_M4_FLAGS})
target_link_options(${PROJECT_NAME} PRIVATE ${CORTEX_M4_FLAGS}
    -L${LINKER_SCRIPT_PATHS} -T${LINKER_SCRIPT_PATHS}/lpc4078.ld
    -Wl,-Map=${PROJECT_NAME}.map,--cref -Wl,--gc-sections
    -Wl,--print-memory-usage)
target_link_libraries(${PROJECT_NAME} PRIVATE libbasis::libbasis)
arm_post_build(${PROJECT_NAME})
