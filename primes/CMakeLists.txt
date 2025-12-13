cmake_minimum_required(VERSION 3.15)
project(primes C)

file(GLOB PRIMES_SOURCES "src/*.c")

add_library(primes SHARED ${PRIMES_SOURCES}
        src/trial_division_naive.c
        src/trial_division_sqrt.c
        src/trial_division_sqrt_odd.c
        src/trial_division_known_divisors.c
        src/sieve_basic.c
        src/sieve_p2.c
)

set_target_properties(primes PROPERTIES OUTPUT_NAME "primes")
