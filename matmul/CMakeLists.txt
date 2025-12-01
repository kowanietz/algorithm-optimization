cmake_minimum_required(VERSION 3.15)
project(matmul C)

execute_process(
        COMMAND brew --prefix
        OUTPUT_VARIABLE BREW_PREFIX
        OUTPUT_STRIP_TRAILING_WHITESPACE
)
message(STATUS "Using Homebrew prefix: ${BREW_PREFIX}")

set(OPENBLAS_INCLUDE_DIR "${BREW_PREFIX}/opt/openblas/include")
set(OPENBLAS_LIB_DIR "${BREW_PREFIX}/opt/openblas/lib")
set(OPENBLAS_LIB "${OPENBLAS_LIB_DIR}/libopenblas.dylib")

if (NOT EXISTS "${OPENBLAS_LIB}")
    message(FATAL_ERROR "Could not find OpenBLAS at ${OPENBLAS_LIB}.
        Did you run: brew install openblas?")
endif ()

message(STATUS "Using OpenBLAS include: ${OPENBLAS_INCLUDE_DIR}")
message(STATUS "Using OpenBLAS library: ${OPENBLAS_LIB}")

file(GLOB MATMUL_SOURCES "src/*.c")

add_library(matmul SHARED
        ${MATMUL_SOURCES}
)

set_target_properties(matmul PROPERTIES OUTPUT_NAME "matmul")

target_include_directories(matmul PRIVATE
        ${OPENBLAS_INCLUDE_DIR}
        ${BREW_PREFIX}/include
)

target_link_directories(matmul PRIVATE
        ${OPENBLAS_LIB_DIR}
        ${BREW_PREFIX}/lib
)

target_link_libraries(matmul PRIVATE
        ${OPENBLAS_LIB}
)
