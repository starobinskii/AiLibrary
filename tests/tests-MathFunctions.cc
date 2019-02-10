#include "catch.hpp"
#include <ai>

TEST_CASE("Return a signum", "[MathFunctions]"){
    REQUIRE(-1 == ai::sign(-10));
    REQUIRE(0 == ai::sign(0));
    REQUIRE(1 == ai::sign(10));
    
    REQUIRE(-1. == ai::sign(-10.));
    REQUIRE(0. == ai::sign(0.));
    REQUIRE(1. == ai::sign(10.));
}

TEST_CASE("Find a minimum", "[MathFunctions]"){
    REQUIRE(1 == ai::min(1, 2));
    REQUIRE(-1 == ai::min(-1, 2));
    REQUIRE(-2 == ai::min(-1, -2));
    
    REQUIRE(1. == ai::min(1., 2.));
    REQUIRE(-1. == ai::min(-1., 2.));
    REQUIRE(-2. == ai::min(-1., -2.));
}

TEST_CASE("Find a maximum", "[MathFunctions]"){
    REQUIRE(2 == ai::max(1, 2));
    REQUIRE(2 == ai::max(-1, 2));
    REQUIRE(-1 == ai::max(-1, -2));
    
    REQUIRE(2. == ai::max(1., 2.));
    REQUIRE(2. == ai::max(-1., 2.));
    REQUIRE(-1. == ai::max(-1., -2.));
}