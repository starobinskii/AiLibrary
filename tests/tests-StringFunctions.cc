#include "catch.hpp"
#include <ai>

TEST_CASE("Cast parameter into a std::string", "[StringFunctions]"){
    REQUIRE(std::string("1.2") == ai::string((float) 1.2));
    REQUIRE(std::string("-1.2") == ai::string((float) -1.2));
    REQUIRE(std::string("1.2") == ai::string((double) 1.2));
    REQUIRE(std::string("-1.2") == ai::string((double) -1.2));
    REQUIRE(std::string("1") == ai::string((int) 1));
    REQUIRE(std::string("-1") == ai::string((int) -1));
    REQUIRE(std::string("1") == ai::string((std::size_t) 1));
    REQUIRE(std::string("o") == ai::string('o'));
    REQUIRE(std::string("one") == ai::string("one"));
}

TEST_CASE("Check if string has a given prefix", "[StringFunctions]"){
    REQUIRE(true == ai::hasPrefix("text with a prefix", "text with"));
    REQUIRE(false == ai::hasPrefix("text without a prefix", "text w/o"));
}

TEST_CASE("Check if string has a given suffix", "[StringFunctions]"){
    REQUIRE(true == ai::hasSuffix("text with a suffix", "a suffix"));
    REQUIRE(false == ai::hasSuffix("text without a suffix", "no suffix"));
}

TEST_CASE("Check if string has a given substring", "[StringFunctions]"){
    REQUIRE(true == ai::contains("text with a substring", "with a sub"));
    REQUIRE(false == ai::contains("text without a substring", "with no sub"));
}

TEST_CASE("Replace part of the string", "[StringFunctions]"){
    REQUIRE(std::string("text with a replace") == ai::replace("text without a replace", "without", "with"));
    REQUIRE(std::string("text without a replace") == ai::replace("text without a replace", "no", "with"));
}

TEST_CASE("Modify string by replacing a part of it", "[StringFunctions]"){
    std::string stringWithAReplace("text without a replace");
    std::string stringWithoutAReplace("text without a replace");
    
    ai::applyReplace(stringWithAReplace, "without", "with");
    ai::applyReplace(stringWithoutAReplace, "no", "with");
    
    REQUIRE(std::string("text with a replace") == stringWithAReplace);
    REQUIRE(std::string("text without a replace") == stringWithoutAReplace);
}

TEST_CASE("Check if char array and std::string are equal", "[StringFunctions]"){
    char charLine[] = {'l', 'i', 'n', 'e', ' ', 't', 'o', ' ', 't', 'e', 's', 't', '\0'};
    std::string stringLine("line to test");
    std::string wrongStringLine("line not to test");
    
    REQUIRE(true == ai::equal(charLine, stringLine));
    REQUIRE(false == ai::equal(charLine, wrongStringLine));
}

TEST_CASE("Transform string to upper case", "[StringFunctions]"){
    REQUIRE(std::string("UPPER CASE!") == ai::toUpperCase("Upper cAse!"));
}

TEST_CASE("Transform string to lower case", "[StringFunctions]"){
    REQUIRE(std::string("lower case!") == ai::toUpperCase("Lower cAse!"));
}

TEST_CASE("Convert number to counter-like string", "[StringFunctions]"){
    REQUIRE(std::string("0003") == ai::prependNumber(3, 4));
    REQUIRE(std::string("3") == ai::prependNumber(3, -4));
    REQUIRE(std::string("###3") == ai::prependNumber(3, 4, '#'));
    REQUIRE(std::string("300") == ai::prependNumber(300, 2));
    REQUIRE(std::string("-00.3") == ai::prependNumber(-0.3, 5));
}