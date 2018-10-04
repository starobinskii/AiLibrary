#include "catch.hpp"
#include <ai>

TEST_CASE("Get version of the library", "[LibraryInfo]"){
    REQUIRE(std::string("1.2.1") == ai::getVersion());
}
