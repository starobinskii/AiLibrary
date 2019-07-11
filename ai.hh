#if !defined(AILIBRARY_HH)
#define AILIBRARY_HH

/// \file ai.hh
/// \author Egor Starobinskii
/// \date 06 June 2019
/// \brief Single-header C++ Library
/// \details This is a single-header C++ Library from Ailurus Studio that
/// brings you extra time to admire life instead of coding the same functions
/// again and again. Meets the C++11 standard.
/// \see https://starobinskii.github.io/AiLibrary
/// \see https://github.com/starobinskii/AiLibrary
/// \see https://snapcraft.io/ailibrary
/// \see https://ailurus.ru/

/// \brief If defined, funstions will be marked as inline
/// \details If defined, funstions will be marked as inline. Comment the line
/// if you want to omit this behavior
#define INLINE inline

// /// \brief If defined, functions using dirent.h will be included
// /// \details If defined, functions using dirent.h (POSIX) will be included.
// /// Uncomment the line or pass the defined value at compile time if you want
// /// this behavior. Windows users may need to specify the location of the
// /// header below
// #define AI_DIRENT_SUPPORT

// /// \brief If defined, functions requiring GCC v5+ will be included
// /// \details If defined, functions requiring GCC v5+ will be included.
// /// Uncomment the line or pass the defined value at compile time if you want
// /// this behavior. Works for MSVC as well.
// #define AI_GCC5_SUPPORT

// /// \brief If defined, functions requiring UNIX shell will be included
// /// \details If defined, functions requiring UNIX shell will be included.
// /// Uncomment the line or pass the defined value at compile time if you want
// /// this behavior.
// #define AI_SHELL_SUPPORT

// /// \brief If defined, declarations of not yet implemented functions will be
// /// accessible
// /// \details If defined, declarations of not yet implemented functions will
// /// be accessible. Uncomment the line or pass the defined value at compile
// /// time if you want this behavior
// #define AI_FUTURE

#include <array>
#include <cmath>
#include <chrono>
#include <limits>
#include <memory>
#include <random>
#include <string>
#include <thread>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sys/stat.h>

#if defined(AI_DIRENT_SUPPORT)
    /// On Windows, you can use nice dirent.h implementation from Toni Ronkko
    /// (MIT license). Its copy is located at include/dirent.
    /// \see https://github.com/tronkko/dirent
    #include <dirent.h>
    // #include "include/dirent/dirent.h"
#endif

/// \defgroup MacrosGroup Macros Group
/// \brief Some useful macros
/// \details Group of useful macros that cannot be implemented as functions
/// \{

/// \brief Convert a variable name into text
/// \details This macro converts a variable name into text, which is useful
/// for debugging
#define STRINGIFY(x) #x

/// \brief Convert a variable value into text
/// \details This macro converts a variable value into text, so you can access
/// the constants defined at compile time as std::string
#define TO_STRING(x) STRINGIFY(x)

/// \brief Print the line number
/// \details This macro prints the line number on which it was called
#define PRINT_LINE() std::cout << "Line #" << __LINE__ << std::endl

/// \brief Short for-loop
/// \details This macro is the short form for the standard for loop
#define forN(i,n) for(std::size_t i = 0; i < n; ++i)

/// \brief Short for-loop (vector)
/// \details This macro is the short form for the for loop (vector)
#define forS(i,v) for(std::size_t i = 0; i < v.size(); ++i)

/// \} End of Macros Group

/// \namespace ai
/// \brief Main namespace
/// \details Main namespace containing all the functions of AiLibrary
/// \defgroup AiNamespace AiLibrary Namespace
/// \brief Main group
/// \details Main group containing all the functions of AiLibrary
/// \{
namespace ai{
    /// \defgroup LibraryInfo Library Info
    /// \brief Functions providing info about the library
    /// \details Group of functions that provides information about this
    /// library
    /// \{

    /// \fn std::string getVersion();
    /// \brief Get version of the library
    /// \details This function returns version of the AiLibrary (we use SemVer)
    /// \return Version as a string
    /// \see https://semver.org
    INLINE std::string getVersion(){
        return std::string("1.4.0-alpha.1");
    }

    /// \} End of LibraryInfo Group

    /// \defgroup StringFunctions String Functions
    /// \brief Functions providing additional methods to work with strings
    /// \details Group of functions that allows you to freely manipulate and
    /// analyze strings
    /// \{

    /// \fn std::string string(const T value);
    /// \brief Converts input into a string
    /// \details This function converts your variable into std::string using
    /// std::ostringstream
    /// \tparam T Any printable type
    /// \param value Your variable to convert
    /// \return std::string copy of your input
    template<typename T>
    INLINE std::string string(const T value){
        std::ostringstream stream;

        stream << value;

        return stream.str();
    }

    /// \fn bool hasPrefix(const std::string &text, const std::string &prefix);
    /// \brief Checks if a string begins with a substring
    /// \details This function checks if a string begins with a substring
    /// \param text Your string to test
    /// \param prefix Your substring
    /// \return True if string begins with a substring, false otherwise
    INLINE bool hasPrefix(const std::string &text, const std::string &prefix){
        return text.size() >= prefix.size()
            && 0 == text.compare(0, prefix.size(), prefix);
    }

    /// \fn bool hasSuffix(const std::string &text, const std::string &suffix);
    /// \brief Checks if a string ends with a substring
    /// \details This function checks if a string ends with a substring
    /// \param text Your string to test
    /// \param suffix Your substring
    /// \return True if string ends with a substring, false otherwise
    INLINE bool hasSuffix(const std::string &text, const std::string &suffix){
        return text.size() >= suffix.size()
            && 0 == text.compare(
                text.size() - suffix.size(),
                suffix.size(),
                suffix
            );
    }

    /// \fn bool contains(const std::string &text, const std::string
    /// &substring);
    /// \brief Checks if a string contains a substring
    /// \details This function checks if a string contains a substring
    /// \param text Your string to test
    /// \param substring Your substring
    /// \return True if string contains a substring, false otherwise
    INLINE bool contains(
        const std::string &text,
        const std::string &substring
    ){
        return std::string::npos != text.find(substring);
    }

    /// \fn void applyReplace(std::string &text, const std::string
    /// &substring, const std::string &replacement)
    /// \brief Modifies your string by replacing all occurrences of the given
    /// substring with your text
    /// \details This function replaces all occurrences of a substring in a
    /// string with your text (modifies the initial string)
    /// \param text Your string
    /// \param substring Substring for replacement
    /// \param replacement Replacement for all occurrences of the substring
    INLINE void applyReplace(
        std::string &text,
        const std::string substring,
        const std::string replacement
    ){
        std::size_t position = text.find(substring);
        std::size_t substringSize = substring.size();
        std::size_t replacementSize = replacement.size();

        while(std::string::npos != position){
            text.replace(position, substringSize, replacement);
            position = text.find(substring, position + replacementSize);
        }
    }

    /// \fn std::string replace(std::string text, const std::string &substring,
    /// const std::string &replacement)
    /// \brief Replaces all occurrences of the substring in the copy of the 
    /// initial string with your text
    /// \details This function replaces all occurrences of a substring in a
    /// string with your text using applyReplace() and return the result.
    /// Initial string stays the same
    /// \param text Your string
    /// \param substring Substring for replacement
    /// \param replacement Replacement for all occurrences of the substring
    /// \return Modified copy of the initial string
    INLINE std::string replace(
        std::string text,
        const std::string substring,
        const std::string replacement
    ){
        ai::applyReplace(text, substring, replacement);

        return text;
    }

    /// \fn void applyRepeat(std::string &text, const std::size_t counter)
    /// \brief Repeats your string multiple times and returns the result
    /// \details This function repeats your string multiple times and replaces
    /// the given string with the result
    /// \param text String to repeat, will be modified
    /// \param counter Repeat counter
    INLINE void applyRepeat(std::string &text, const std::size_t counter){
        std::string textToRepeat = text;
        
        for(std::size_t i = 0; i < counter; ++i){
            text += textToRepeat;
        }
    }

    /// \fn std::string repeat(std::string text, const std::size_t counter)
    /// \brief Repeats your string multiple times and returns the result
    /// \details This function repeats your string multiple times and returns
    /// the result. Initial string stays the same
    /// \param text String to repeat
    /// \param counter Repeat counter
    /// \return Formed string
    INLINE std::string repeat(
        std::string text,
        const std::size_t counter
    ){
        ai::applyRepeat(text, counter);
        
        return text;
    }
    
    /// \fn void split(const std::string &stringToSplit, const char delimeter,
    /// std::vector<std::string> &splittedStrings)
    /// \brief Splits your string by the given delimeter
    /// \details This function splits your string by the given delimeter and 
    /// stores the result into vector
    /// \param stringToSplit String to split
    /// \param delimeter String delimeter
    /// \param splittedStrings Resulting vector of the substrings
    INLINE void split(
        const std::string &stringToSplit,
        const char delimeter,
        std::vector<std::string> &splittedStrings
    ){
        std::stringstream stream(stringToSplit);
        
        std::string token;
        
        splittedStrings.clear();
        
        while(std::getline(stream, token, delimeter)){
            splittedStrings.push_back(token);
        }
    }

    /// \fn bool equal(const char *charString, const std::string string1)
    /// \brief Checks if a char string is equal to a std::string
    /// \details This function compares a char string with a std::string
    /// \param charString Your char string to compare
    /// \param string1 Your std::string to compare
    /// \return True if strings are equal, false otherwise
    INLINE bool equal(const char *charString, const std::string string1){
        const std::string string2(charString);

        return string1 == string2;
    }

    /// \fn std::string toUpperCase(std::string input)
    /// \brief Converts a string to upper case
    /// \details This function converts the given string to upper case and
    /// returns the result
    /// \param input String to convert
    /// \return Uppercase string
    INLINE std::string toUpperCase(std::string input){
        std::transform(input.begin(), input.end(), input.begin(), ::toupper);

        return input;
    }

    /// \fn std::string toLowerCase(std::string input)
    /// \brief Converts a string to lower case
    /// \details This function converts the given string to lower case and
    /// returns the result
    /// \param input String to convert
    /// \return Lowercase string
    INLINE std::string toLowerCase(std::string input){
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);

        return input;
    }

    /// \fn std::string stringToHex(std::string input)
    /// \brief Converts a string to its hexadecimal representation
    /// \details This function converts a string to its hexadecimal 
    /// representation and returns the result
    /// \param input String to convert
    /// \return Hexadecimal string
    INLINE std::string stringToHex(std::string input){
        std::stringstream stream;

        for(std::size_t i = 0; i < input.size(); ++i){
             stream << std::noshowbase << std::setw(2) << std::setfill ('0')
                 << std::hex << (int) input[i];
        }

        return stream.str();
    }
    
    /// \fn std::string stringFromHex(std::string input)
    /// \brief Converts a string from its hexadecimal representation
    /// \details This function converts a string from its hexadecimal 
    /// representation and returns the result
    /// \param input Hexadecimal string to convert
    /// \return Ordinary string
    INLINE std::string stringFromHex(std::string input){
        std::string string;

        for(std::size_t i = 0; i < input.size(); i += 2){
            string.push_back(strtol(input.substr(i, 2).c_str(), NULL, 16));
        }

        return string;
    }


    /// \fn std::string prependNumber(const T value, const std::size_t
    /// digitsBeforePoint, const char symbolToPrepend);
    /// \brief Convert number to counter-like string
    /// \details This function converts number to std::string type and
    /// prepends some zeros (of other given symbol) if needed
    /// \tparam T A number type
    /// \param value Number to style
    /// \param symbolsBeforePoint Minimal required number of symbols before
    /// point
    /// \param symbolToPrepend Prepending symbol, zero by default
    /// \return Styled string
    template<typename T>
    INLINE std::string prependNumber(
        const T value,
        const std::size_t symbolsBeforePoint,
        const char symbolToPrepend = '0'
    ){
        std::string token = ai::string(value);

        const int counter = symbolsBeforePoint 
            - (ai::string((int) value)).size();

        for(int i = 0; i < counter; ++i){
            token = ai::string(symbolToPrepend) + token;
        }
        
        if((T) 0 > value){
            return ai::string("-") 
                + ai::replace(token, "-", ai::string(symbolToPrepend));
        }

        return token;
    }

    /// \} End of StringFunctions Group

    /// \defgroup DebugFunctions Debug Functions
    /// \brief Functions providing some help to debug programs
    /// \details Group of functions that can be useful if you want to debug
    /// your code
    /// \{

    /// \fn std::size_t counter(std::size_t value = 0);
    /// \brief Returns ID starting from zero or the specified value
    /// \details This function returns ID (increases it at each call) starting
    /// from zero or the specified non-negative value
    /// \param value Optional. The non-negative  value to which the counter 
    /// should be reset. Zero by default
    /// \return Counter value
    INLINE std::size_t counter(const std::size_t value = 0){
        static std::size_t count = 0;

        ++count;

        if(0 != value){
            count = value;
        }

        return count;
    }

    /// \fn std::string marker(std::size_t value = 0);
    /// \brief Returns a string containing the word "Marker" and its ID
    /// \details This function returns a string containing the word "marker"
    /// and its ID (increases it at each call). ID specified in the same way
    /// as in the function counter()
    /// \param value Optional. The non-negative  value to which the counter 
    /// should be reset. Zero by default
    /// \return Marker string
    INLINE std::string marker(const std::size_t value = 0){
        static std::size_t count = 0;

        ++count;

        if(0 != value){
            count = value;
        }

        return "Marker #" + ai::string(count);
    }

    /// \fn void printMarker(std::size_t value = 0);
    /// \brief Calls marker() and prints result to stdout
    /// \details This function calls marker() and prints result to stdout
    /// \param value Optional. The non-negative  value to which the counter 
    /// should be reset. Zero by default
    INLINE void printMarker(const std::size_t value = 0){
        std::cout << marker(value) << std::endl;
    }

    /// \} End of DebugFunctions Group

    /// \defgroup MathFunctions Math Functions
    /// \brief Functions providing different math methods and checks
    /// \details Group of functions that completes standard C++ mathematical
    /// methods and helps with matrices and vectors
    /// \{

    /// \brief Mathematical constant 'e'
    /// \details Mathematical constant  \f$e\f$ (20 decimal places)
    static const double e = 2.71828182845904523536;

    /// \brief Mathematical constant 'pi'
    /// \details Mathematical constant \f$\pi\f$ (20 decimal places)
    static const double pi = 3.14159265358979323846;
    
    /// \brief Physical constant 'c'
    /// \details Physical constant \f$c\f$ for the speed of light
    static const double c = 299792458.;

    /// \brief Physical constant 'g'
    /// \details Physical constant \f$g\f$ for the standard gravity of Earth
    static const double g = 9.80665;

    /// \brief Variable for comparing with small values
    /// \details Variable for comparing with small values when the zero check
    /// does not work
    static double epsilon = std::pow(10., -8);

    /// \fn T sign(const T value);
    /// \brief Returns signum of the value
    /// \details This function returns signum of the number value (usign
    /// copysign())
    /// \tparam T A number type
    /// \param value The number to which signum is applied
    /// \return -1 for negative values, +1 for positive, 0 for zero
    template<typename T>
    INLINE T sign(const T value){
        if(0 == value){
            return (T) 0;
        }

        return copysign(1, value);
    }

    /// \fn T min(const T a, const T b);
    /// \brief Returns minimum of two values
    /// \details This function compares two values and returns a minimum
    /// \tparam T A number type
    /// \param a First number
    /// \param b Second number
    /// \return Minimum of two values
    template<typename T>
    INLINE T min(const T a, const T b){
        if(a > b){
            return b;
        }

        return a;
    }

    /// \fn T max(const T a, const T b);
    /// \brief Returns maximum of two values
    /// \details This function compares two values and returns a maximum
    /// \tparam T A number type
    /// \param a First number
    /// \param b Second number
    /// \return Maximum of two values
    template<typename T>
    INLINE T max(const T a, const T b){
        if(a < b){
            return b;
        }

        return a;
    }

    /// \fn T min(const std::vector<T> &input);
    /// \brief Returns minimum of vector values
    /// \details This function compares vector values using min() and returns
    /// a minimum
    /// \tparam T A number type
    /// \param input Vector to search for a minimum value
    /// \return Minimum of vector values
    /// \todo Add tests
    template<typename T>
    INLINE T min(const std::vector<T> &input){
        T minimum = input[0];

        for(std::size_t i = 1; i < input.size(); ++i){
            minimum = ai::min(minimum, input[i]);
        }

        return minimum;
    }

    /// \fn T max(const std::vector<T> &input);
    /// \brief Returns maximum of vector values
    /// \details This function compares vector values using max() and returns
    /// a maximum
    /// \tparam T A number type
    /// \param input Vector to search for a maximum value
    /// \return Maximum of vector values
    /// \todo Add tests
    template<typename T>
    INLINE T max(const std::vector<T> &input){
        T maximum = input[0];

        for(std::size_t i = 1; i < input.size(); ++i){
            maximum = ai::max(maximum, input[i]);
        }

        return maximum;
    }

    /// \fn T min(const std::vector< std::vector<T> > &input);
    /// \brief Returns minimum of matrix values
    /// \details This function compares matrix values using min() and returns
    /// a minimum
    /// \tparam T A number type
    /// \param input Matrix to search for a minimum value
    /// \return Minimum of matrix values
    /// \todo Add tests
    template<typename T>
    INLINE T min(const std::vector< std::vector<T> > &input){
        T minimum = input[0][0];

        for(std::size_t i = 0; i < input.size(); ++i){
            for(std::size_t j = 0; j < input[0].size(); ++j){
                minimum = ai::min(minimum, input[i][j]);
            }
        }

        return minimum;
    }

    /// \fn T max(const std::vector< std::vector<T> > &input);
    /// \brief Returns maximum of matrix values
    /// \details This function compares matrix values using max() and returns
    /// a maximum
    /// \tparam T A number type
    /// \param input Matrix to search for a maximum value
    /// \return Maximum of matrix values
    /// \todo Add tests
    template<typename T>
    INLINE T max(const std::vector< std::vector<T> > &input){
        T maximum = input[0][0];

        for(std::size_t i = 0; i < input.size(); ++i){
            for(std::size_t j = 0; j < input[0].size(); ++j){
                maximum = ai::max(maximum, input[i][j]);
            }
        }

        return maximum;
    }

    /// \fn bool isSquare(const T value);
    /// \brief Checks if number is square
    /// \details This function checks if number is square
    /// \tparam T A number type
    /// \param value Number to test
    /// \return True if number is a square, false otherwise
    /// \todo Add tests
    template<typename T>
    INLINE bool isSquare(const T value){
        if(0 >= value){
            return false;
        }

        T root = (T) round(sqrt(value));

        return value == root * root;
    }

    /// \fn bool isSquare(const std::vector< std::vector<T> > &matrix);
    /// \brief Checks if matrix is square
    /// \details This function checks if matrix is square
    /// \tparam T A number type
    /// \param matrix Matrix to test
    /// \return True if matrix is square, false otherwise
    /// \todo Add tests
    template<typename T>
    INLINE bool isSquare(const std::vector< std::vector<T> > &matrix){
        return 0 < matrix.size() && matrix.size() == matrix[0].size();
    }

    /// \fn void generateRandomVector(std::vector<T> &vector, const
    /// std::size_t length, const T min = std::numeric_limits<T>::min(),
    /// const T max = std::numeric_limits<T>::max());
    /// \brief Fill vector with random values
    /// \details This function fills the vector of given length with random
    /// values using std::mt19937 with std::random_device as seed
    /// \tparam T A number type
    /// \param vector Vector to fill
    /// \param length Required length of the vector
    /// \param min Lower limit of generated values, no limitation by default
    /// \param max Upper limit of generated values, no limitation by default
    /// \todo Add tests
    template<typename T>
    INLINE void generateRandomVector(
        std::vector<T> &vector,
        const std::size_t length,
        const T min = std::numeric_limits<T>::min(),
        const T max = std::numeric_limits<T>::max()
    ){
        std::uniform_real_distribution<T> distribution(min, max);
        std::mt19937 device(std::random_device{}());

        double currentTime =
            (double) (
                    std::chrono::high_resolution_clock::now()
                ).time_since_epoch().count();

        srand(device() * currentTime);

        vector.resize(length);

        std::generate(
            vector.begin(),
            vector.end(),
            [&device, &distribution](){
                return distribution(device);
            }
        );
    }

    /// \fn void generateRandomMatrix(std::vector< std::vector<T> > &matrix,
    /// const std::size_t xSize, const std::size_t ySize, const T min =
    /// std::numeric_limits<T>::min(), const T max =
    /// std::numeric_limits<T>::max());
    /// \brief Fill matrix with random values
    /// \details This function fills the matrix of given sizes with random
    /// values using std::random_device and generateRandomVector()
    /// \tparam T A number type
    /// \param matrix Matrix to fill
    /// \param xSize Required length of the matrix
    /// \param ySize Required height of the matrix
    /// \param min Lower limit of generated values, no limitation by default
    /// \param max Upper limit of generated values, no limitation by default
    /// \todo Add tests
    template<typename T>
    INLINE void  generateRandomMatrix(
        std::vector< std::vector<T> > &matrix,
        const std::size_t xSize,
        const std::size_t ySize,
        const T min = std::numeric_limits<T>::min(),
        const T max = std::numeric_limits<T>::max()
    ){
        matrix.resize(xSize);

        for(size_t i = 0; i < xSize; ++i){
            matrix[i].resize(ySize);

            std::vector<T> row;

            ai::generateRandomVector(row, ySize, min, max);

            matrix[i] = row;
        }
    }

    /// \fn void generateRandomMatrix(std::vector< std::vector<T> > &matrix,
    /// const std::size_t size, const T min = std::numeric_limits<T>::min(),
    /// const T max = std::numeric_limits<T>::max());
    /// \brief Fill matrix with random values
    /// \details This function fills the square matrix of given sizes with
    /// random values using std::random_device and generateRandomVector()
    /// \tparam T A number type
    /// \param matrix Matrix to fill
    /// \param size Required size of the square matrix
    /// \param min Lower limit of generated values, no limitation by default
    /// \param max Upper limit of generated values, no limitation by default
    /// \todo Add tests
    template<typename T>
    INLINE void generateRandomMatrix(
        std::vector< std::vector<T> > &matrix,
        const std::size_t size,
        const T min = std::numeric_limits<T>::min(),
        const T max = std::numeric_limits<T>::max()
    ){
        ai::generateRandomMatrix(matrix, size, size, min, max);
    }

    /// \fn void rotateMatrix(std::vector< std::vector<T> > &matrix, const 
    /// bool rotateClockwise = false);
    /// \brief Rotate square matrix
    /// \details This function rotates the square matrix 90 degrees clockwise
    /// or anticlockwise
    /// \tparam T Any copiable type
    /// \param matrix Matrix to rotate
    /// \param rotateClockwise Optional. If true, rotate clockwise. Otherwise,
    /// rotate anticlockwise (default)
    /// \todo Add tests
    template<typename T>
    void rotateMatrix(
        std::vector< std::vector<T> > &matrix,
        const bool rotateClockwise = false
    ){
        std::size_t length = matrix.size();

        if(rotateClockwise){
            for(std::size_t i = 0; i < length / 2; ++i){ 
                for(std::size_t j = i; j < length - i - 1; ++j){
                    T savedValue = matrix[i][j]; 

                    matrix[i][j] = matrix[length - 1 - j][i]; 
                    matrix[length - 1 - j][i] =
                        matrix[length - 1 - i][length - 1 - j];
                    matrix[length - 1 - i][length - 1 - j] =
                        matrix[j][length - 1 - i];
                    matrix[j][length - 1 - i] = savedValue;   
                } 
            }
        }else{
            for(std::size_t i = 0; i < length / 2; ++i){
                for(std::size_t j = i; j < length - i - 1; ++j){
                    T savedValue = matrix[i][j]; 

                    matrix[i][j] = matrix[j][length - 1 - i]; 
                    matrix[j][length - 1 - i] = 
                        matrix[length - 1 - i][length - 1 - j];
                    matrix[length - 1 - i][length - 1 - j] = 
                        matrix[length - 1 - j][i];
                    matrix[length - 1 - j][i] = savedValue; 
                }
            }
        }
    }

    /// \todo Add description. Add tests
    template<typename T>
    INLINE void inverseMatrix(
        std::vector< std::vector<T> > matrix,
        std::vector< std::vector<T> > &inverse
    ){
        if(!isSquare(matrix)){
            throw std::runtime_error(
                std::string("Exception while inversing: ")
                    + std::string("matrix should be square")
            );
        }

        const std::size_t length = matrix.size();
    
        inverse.clear();
        inverse.resize(length);

        for(std::size_t i = 0; i < length; ++i){
            inverse[i].resize(length);

            inverse[i][i] = (T) 1.;
        }

        T ratio = 0;

        for(std::size_t i = 0; i < length; ++i){
            for(std::size_t j = 0; j < length; ++j){
                if(i != j){
                    ratio = matrix[j][i] / matrix[i][i];

                    for(std::size_t k = 0; k < length; ++k){
                        matrix[j][k] -= ratio * matrix[i][k];
                        inverse[j][k] -= ratio * inverse[i][k];
                    }
                }
            }
        }
        for(std::size_t i = 0; i < length; ++i){
            for(std::size_t j = 0; j < length; ++j){
                inverse[i][j] /= matrix[i][i];
            }
        }
    }

    /// \todo Add description. Add tests
    template<typename T>
    INLINE void inverseMatrix(
        std::vector< std::vector<T> > &matrix
    ){
        ai::inverseMatrix(matrix, matrix);
    }

    /// \fn void translateMatrixIntoVector(std::vector< std::vector<T> >
    /// &matrix, std::vector<T> &vector);
    /// \brief Elongates matrix into a vector
    /// \details This function converts the matrix into a vector, writing each
    /// row one after another in a line
    /// \tparam T A number type
    /// \param matrix Matrix to tranform
    /// \param vector Vector to store the result
    /// \todo Add tests
    template<typename T>
    INLINE void translateMatrixIntoVector(
        std::vector< std::vector<T> > &matrix,
        std::vector<T> &vector
    ){
        for(std::size_t i = 0; i < matrix.size(); ++i){
            for(std::size_t j = 0; j < matrix[i].size(); ++j){
                vector.push_back(matrix[i][j]);
            }
        }
    }

    /// \fn void translateVectorIntoSquareMatrix(std::vector<T> &vector,
    /// std::vector< std::vector<T> > &matrix);
    /// \brief Transform vector into a square matrix (if possible)
    /// \details This function converts the vector into a matrix, if possible.
    /// Otherwise, an exception will be thrown at runtime
    /// \tparam T A number type
    /// \param vector Vector to tranform
    /// \param matrix Matrix to store the result
    /// \exception std::runtime_error If \p matrix is not square
    /// \todo Add tests
    template<typename T>
    INLINE void translateVectorIntoSquareMatrix(
        std::vector<T> &vector,
        std::vector< std::vector<T> > &matrix
    ){
        if(!isSquare(vector.size())){
            throw std::runtime_error(
                ai::string("Exception while converting vector into the ")
                + ai::string("square matrix: vector size should be square")
            );
        }

        std::size_t size = (std::size_t) round(sqrt(vector.size()));

        for(std::size_t i = 0; i < size; ++i){
            std::vector<T> row;

            for(std::size_t j = 0; j < size; ++j){
                row.push_back(vector[i * size + j]);
            }

            matrix.push_back(row);
        }
    }

    /// \fn void generateCirculantMatrix(std::vector< std::vector<double> >
    /// &matrix, std::vector<double> &source, const bool moveToTheRight =
    /// true);
    /// \brief Fill a circulant matrix with values from the input vector
    /// \details This function fills the matrix by rotating the input vector
    /// to the left or right by one value in a row forming a circalunt
    /// \tparam T A number type
    /// \param matrix Matrix to fill
    /// \param source Vector storing the values
    /// \param moveToTheRight If true, shift the vector to the right.
    /// Otherwise to the left. True by default.
    /// \exception std::runtime_error If \p source is an empty vector
    /// \see https://en.wikipedia.org/wiki/Circulant_matrix
    /// \todo Add tests
    template<typename T>
    INLINE void generateCirculantMatrix(
        std::vector< std::vector<T> > &matrix,
        std::vector<T> &source,
        const bool moveToTheRight = true
    ){
        if(1 > source.size()){
            throw std::runtime_error(
                ai::string("Exception while creating a circulant: ")
                + ai::string("size of the source should be at least 1.")
            );
        }

        std::size_t length = source.size();

        std::size_t displacement = 0;

        matrix.clear();
        matrix.resize(length);

        if(moveToTheRight){
            for(std::size_t i = 0; i < length; ++i){
                matrix[i].resize(length);

                std::size_t k = displacement;

                for(std::size_t j = 0; j < length - displacement; ++j){
                    matrix[i][k] = source[j];

                    ++k;
                }

                k = 0;

                for(std::size_t j = length - displacement; j < length; ++j){
                    matrix[i][k] = source[j];

                    ++k;
                }

                ++displacement;
            }
        }else{
            for(std::size_t i = 0; i < length; ++i){
                matrix[i].resize(length);

                std::size_t k = 0;

                for(std::size_t j = displacement; j < length; ++j){
                    matrix[i][k] = source[j];

                    ++k;
                }

                for(std::size_t j = 0; j < displacement; ++j){
                    matrix[i][k] = source[j];

                    ++k;
                }

                ++displacement;
            }
        }
    }

    /// \fn void multiply(const std::vector< std::vector<T> > &left, const
    /// std::vector< std::vector<T> > &right, std::vector< std::vector<T> >
    /// &result);
    /// \brief Calculate matrix-matrix multiplication
    /// \details This function calculates matrix-matrix multiplication
    /// \tparam T A number type
    /// \param left Left matrix to multiply
    /// \param right Right matrix to multiply
    /// \param result Matrix to store result
    /// \exception std::runtime_error If input sizes are inappropriate
    /// \todo Add tests
    template<typename T>
    INLINE void multiply(
        const std::vector< std::vector<T> > &left,
        const std::vector< std::vector<T> > &right,
        std::vector< std::vector<T> > &result
    ){
        if(
            1 > left.size()
            || 1 > right.size()
            || left[0].size() != right.size()
        ){
            throw std::runtime_error(
                "Exception while multiplying: check the sizes of the input."
            );
        }

        std::size_t vLength = left.size();
        std::size_t hLength = right[0].size();
        std::size_t fLength = left[0].size();

        result.resize(vLength);

        for(std::size_t i = 0; i < vLength; ++i){
            result[i].resize(hLength);

            for(std::size_t j = 0; j < hLength; ++j){
                result[i][j] = (T) 0.;
            }
            for(std::size_t k = 0; k < fLength; ++k){
                for(std::size_t j = 0; j < hLength; ++j){
                    result[i][j] += left[i][k] * right[k][j];
                }
            }
        }
    };

    /// \fn void multiply(const std::vector< std::vector<T> > &left, const
    /// std::vector<T> &right, std::vector<T> &result);
    /// \brief Calculate matrix-vector multiplication
    /// \details This function calculates matrix-vector multiplication
    /// \tparam T A number type
    /// \param left Left matrix to multiply
    /// \param right Right vector to multiply
    /// \param result Vector to store result
    /// \exception std::runtime_error If input sizes are inappropriate
    /// \todo Add tests
    template<typename T>
    INLINE void multiply(
        const std::vector< std::vector<T> > &left,
        const std::vector<T> &right,
        std::vector<T> &result
    ){
        if(1 > left.size() || left[0].size() != right.size()){
            throw std::runtime_error(
                "Exception while multiplying: check the sizes of the input."
            );
        }

        std::size_t vLength = left.size();

        int hLength = (int) right.size();
        int j = 0;

        result.resize(vLength);

        for(int i = 0; i < vLength; ++i){
            j = 0;
            result[i] = (T) 0.;

            for(; j <= hLength - 4; j += 4){
                result[i] += left[i][j] * right[j]
                    + left[i][j + 1] * right[j + 1]
                    + left[i][j + 2] * right[j + 2]
                    + left[i][j + 3] * right[j + 3];
            }
            for(; j < hLength; ++j){
                result[i] += left[i][j] * right[j];
            }
        }
    }

    /// \fn void multiply(const std::vector<T> &left, const std::vector<T>
    /// &right, T &result);
    /// \brief Calculate vector-vector multiplication
    /// \details This function calculates vector-vector multiplication
    /// \tparam T A number type
    /// \param left Left vector to multiply
    /// \param right Right vector to multiply
    /// \param result Variable to store result
    /// \exception std::runtime_error If input sizes are inappropriate
    /// \todo Add tests
    template<typename T>
    INLINE void multiply(
        const std::vector<T> &left,
        const std::vector<T> &right,
        T &result
    ){
        if(left.size() != right.size()){
            throw std::runtime_error(
                "Exception while multiplying: check the sizes of the input."
            );
        }

        int length = (int) left.size();
        int i = 0;

        result = (T) 0.;

        for(; i <= length - 4; i += 4){
            result += left[i] * right[i]
                + left[i + 1] * right[i + 1]
                + left[i + 2] * right[i + 2]
                + left[i + 3] * right[i + 3];
        }
        for(; i < length; ++i){
            result += left[i] * right[i];
        }
    }

    /// \fn void multiplyElementWise(const std::vector< std::vector<T> > &left,
    /// const std::vector< std::vector<T> > &right, std::vector< std::vector<T>
    /// > &result);
    /// \brief Calculate matrix-matrix elementwise multiplication
    /// \details This function calculates matrix-matrix elementwise
    /// multiplication
    /// \tparam T A number type
    /// \param left Left matrix to multiply
    /// \param right Right matrix to multiply
    /// \param result Matrix to store result
    /// \exception std::runtime_error If input sizes are inappropriate
    /// \todo Add tests
    template<typename T>
    INLINE void multiplyElementWise(
        const std::vector< std::vector<T> > &left,
        const std::vector< std::vector<T> > &right,
        std::vector< std::vector<T> > &result
    ){
        if(
            1 > left.size()
            || 1 > right.size()
            || left.size() != right.size()
            || left[0].size() != right[0].size()
        ){
            throw std::runtime_error(
                "Exception while multiplying: check the sizes of the input."
            );
        }

        std::size_t vLength = left.size();
        std::size_t hLength = left[0].size();

        result.resize(vLength);

        for(std::size_t i = 0; i < vLength; ++i){
            result[i].resize(hLength);

            for(std::size_t j = 0; j < hLength; ++j){
                result[i][j] = left[i][j] * right[i][j];
            }
        }
    }

    /// \fn void multiplyElementWise(const std::vector<T> &left, const
    /// std::vector<T> &right, std::vector<T> &result);
    /// \brief Calculate vector-vector elementwise multiplication
    /// \details This function calculates vector-vector elementwise
    /// multiplication
    /// \tparam T A number type
    /// \param left Left vector to multiply
    /// \param right Right vector to multiply
    /// \param result Vector to store result
    /// \exception std::runtime_error If input sizes are inappropriate
    /// \todo Add tests
    template<typename T>
    INLINE void multiplyElementWise(
        const std::vector<T> &left,
        const std::vector<T> &right,
        std::vector<T> &result
    ){
        if(left.size() != right.size()){
            throw std::runtime_error(
                "Exception while multiplying: check the sizes of the input."
            );
        }

        int length = (int) left.size();

        result.resize(length);

        for(std::size_t i = 0; i < length; ++i){
            result[i] = left[i] * right[i];
        }
    }

    /// \tparam T A number type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void multiplyComplexElementWise(
        const std::vector< std::vector<T> > &left,
        const std::vector< std::vector<T> > &right,
        std::vector< std::vector<T> > &result
    ){
        if(
            left.size() != right.size()
            || 2 != left[0].size()
            || 2 != right[0].size()
        ){
            throw std::runtime_error(
                "Exception while multiplying: check the sizes of the input."
            );
        }

        const std::size_t length = left.size();

        result.resize(length);

        for(std::size_t i = 0; i < length; ++i){
            result[i].resize(2);

            result[i][0] = left[i][0] * right[i][0]
                - left[i][1] * right[i][1];
            result[i][1] = left[i][0] * right[i][1]
                + left[i][1] * right[i][0];
        }
    }

    /// \tparam T A number type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE std::string complexIntoString(const std::vector<T> complexValue){
        return ai::string(complexValue[0]) + ai::string(" + i")
            + ai::string(complexValue[1]);
    }

    /// \tparam T A number type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void conjugate(std::vector< std::vector<T> > &complexVector){
        const std::size_t length = complexVector.size();

        for(std::size_t i = 0; i < length; ++i){
            complexVector[i][1] = -complexVector[i][1];
        }
    }

    /// \tparam T A number type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void fft(std::vector< std::vector<T> > &complexVector){
        const std::size_t length = complexVector.size();

        if(2 > length || (length & (length - 1)) != 0){
            throw std::runtime_error(
                std::string("Exception while calculating FFT: ")
                    + std::string("vector length must be a power of two.")
            );
        }

        std::size_t j = 0;
        std::size_t k = length;
        std::size_t n = 0;

        const double doubleTypeLength = (double) k;

        double thetaT = ai::pi / doubleTypeLength;
        double swap0 = 0.;
        double swap1 = 0.;
        double T0 = 1.;
        double T1 = 0.;
        double phiT0 = cos(thetaT);
        double phiT1 = -sin(thetaT);

        while(1 < k){
            n = k;
            T0 = 1.;
            T1 = 0.;
            swap0 = phiT0;
            swap1 = phiT1;
            phiT0 = swap0 * swap0 - swap1 * swap1;
            phiT1 = 2. * swap0 * swap1;
            k >>= 1;

            for(std::size_t l = 0; l < k; ++l){
                for(std::size_t i = l; i < length; i += n){
                    j = i + k;
                    swap0 = complexVector[i][0] - complexVector[j][0];
                    swap1 = complexVector[i][1] - complexVector[j][1];
                    complexVector[i][0] += complexVector[j][0];
                    complexVector[i][1] += complexVector[j][1];
                    complexVector[j][0] = swap0 * T0 - swap1 * T1;
                    complexVector[j][1] = swap0 * T1 + swap1 * T0;
                }

                swap0 = T0;
                T0 = swap0 * phiT0 - T1 * phiT1;
                T1 = swap0 * phiT1 + T1 * phiT0;
            }
        }

        std::size_t m = (std::size_t) log2(doubleTypeLength);

        for(std::size_t i = 0; i < length; ++i){
            j = i;
            j = (((j & 0xaaaaaaaa) >> 1) | ((j & 0x55555555) << 1));
            j = (((j & 0xcccccccc) >> 2) | ((j & 0x33333333) << 2));
            j = (((j & 0xf0f0f0f0) >> 4) | ((j & 0x0f0f0f0f) << 4));
            j = (((j & 0xff00ff00) >> 8) | ((j & 0x00ff00ff) << 8));
            j = ((j >> 16) | (j << 16)) >> (32 - m);

            if(j > i){
                swap0 = complexVector[i][0];
                swap1 = complexVector[i][1];
                complexVector[i][0] = complexVector[j][0];
                complexVector[i][1] = complexVector[j][1];
                complexVector[j][0] = swap0;
                complexVector[j][1] = swap1;
            }
        }
    }

    /// \tparam T A number type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void ifft(std::vector< std::vector<T> > &complexVector){
        const std::size_t length = complexVector.size();

        const double doubleTypeLength = (double) length;

        conjugate(complexVector);
        fft(complexVector);
        conjugate(complexVector);

        for(std::size_t i = 0; i < length; ++i){
            complexVector[i][0] /= doubleTypeLength;
            complexVector[i][1] /= doubleTypeLength;
        }
    }

    /// \} End of MathFunctions Group

    /// \defgroup TimeFunctions Time Functions
    /// \brief Functions providing methods to measure time
    /// \details Group of functions that is in help when you need to measure
    /// execution time of some code section
    /// \{

    /// \fn std::chrono::high_resolution_clock::time_point time();
    /// \brief Returns current time point
    /// \details This function returns current time point using std::chrono
    /// \return std::chrono::high_resolution_clock entity
    /// \todo Add tests
    INLINE std::chrono::high_resolution_clock::time_point time(){
        return std::chrono::high_resolution_clock::now();
    }
    
    /// \fn std::chrono::system_clock::time_point systemTime();
    /// \brief Returns current time point
    /// \details This function returns current time point using std::chrono
    /// \return std::chrono::system_clock entity
    /// \todo Add tests
    INLINE std::chrono::system_clock::time_point systemTime(){
        return std::chrono::system_clock::now();
    }

    /// \fn double duration(const
    /// std::chrono::high_resolution_clock::time_point start, const
    /// std::chrono::high_resolution_clock::time_point finish, const
    /// std::string scale = std::string("ms"));
    /// \brief Returns the difference between two time points
    /// \details This function returns the difference between two time points
    /// in hours, minutes, seconds, milliseconds, microseconds or nanoseconds
    /// using std::chrono (handy to measure functions and code blocks)
    /// \param start Time point
    /// \param finish Time point
    /// \param scale Optional. By default function will return difference in
    /// milliseconds. Set \p scale to "h" for hours, "m" for minutes, "s" for
    /// seconds, "us" for microseconds, "ns" for nanoseconds
    /// \return Difference between points
    /// \todo Add tests
    INLINE double duration(
        const std::chrono::high_resolution_clock::time_point start,
        const std::chrono::high_resolution_clock::time_point finish,
        const std::string scale = std::string("ms")
    ){
        if(std::string("h") == scale){
            return (double) std::chrono::duration_cast
                <std::chrono::hours> (finish - start).count();
        }

        if(std::string("m") == scale){
            return (double) std::chrono::duration_cast
                <std::chrono::minutes> (finish - start).count();
        }

        if(std::string("s") == scale){
            return (double) std::chrono::duration_cast
                <std::chrono::seconds> (finish - start).count();
        }

        if(std::string("us") == scale){
            return (double) std::chrono::duration_cast
                <std::chrono::microseconds> (finish - start).count();
        }

        if(std::string("ns") == scale){
            return (double) std::chrono::duration_cast
                <std::chrono::nanoseconds> (finish - start).count();
        }

        return (double) std::chrono::duration_cast
            <std::chrono::milliseconds> (finish - start).count();
    }

    /// \todo Add description. Add tests
    INLINE double duration(
        const std::chrono::high_resolution_clock::time_point start,
        const std::string scale = std::string("ms")
    ){
        return ai::duration(start, ai::time(), scale);
    }

    /// \todo Add description. Add tests
    INLINE void printDuration(
        const std::chrono::high_resolution_clock::time_point start,
        const std::chrono::high_resolution_clock::time_point finish,
        const std::string scale = std::string("ms"),
        const std::size_t count = 0
    ){
        std::cout << "Timer #" << counter(count) << ": "
            << ai::duration(start, finish, scale) << scale << std::endl;
    }

    /// \todo Add description. Add tests
    INLINE void printDuration(
        const std::chrono::high_resolution_clock::time_point start,
        const std::string scale = std::string("ms"),
        const std::size_t count = 0
    ){
        std::chrono::high_resolution_clock::time_point finish = ai::time();

        ai::printDuration(start, finish, scale, count);
    }

    #if defined(AI_GCC5_SUPPORT)
        /// \fn std::string getDateAndTime( 
        /// const std::chrono::system_clock::time_point timePoint =
        /// std::chrono::system_clock::now());
        /// \brief Get date and time
        /// \details This function converts the given moment to std::string
        /// containing the passed date and time 
        /// \param timePoint Optional. The moment on the system clock to be
        /// converted, the current time by default
        /// \return std::string with date and time in the format yyyy.mm.dd 
        /// HH:MM:SS
        /// \todo Add tests
        INLINE std::string getDateAndTime(
            const std::chrono::system_clock::time_point timePoint =
                std::chrono::system_clock::now()
        ){
            std::time_t date = std::chrono::system_clock::to_time_t(timePoint);

            std::ostringstream stream;

            stream << std::put_time(std::localtime(&date), "%F %T");

            return stream.str();
        }

        /// \fn std::string getTimeAndDate( 
        /// const std::chrono::system_clock::time_point timePoint =
        /// std::chrono::system_clock::now());
        /// \brief Get date and time
        /// \details This function converts the given moment to std::string
        /// containing the passed date and time, alias for getDateAndTime()
        /// \param timePoint Optional. The moment on the system clock to be
        /// converted, the current time by default
        /// \return std::string with date and time in the format yyyy.mm.dd 
        /// HH:MM:SS
        /// \todo Add tests
        INLINE std::string getTimeAndDate(
            const std::chrono::system_clock::time_point timePoint =
                std::chrono::system_clock::now()
        ){
            return ai::getDateAndTime(timePoint);
        }

        /// \fn std::string getDate(std::chrono::system_clock::time_point 
        /// timePoint = std::chrono::system_clock::now());
        /// \brief Get date
        /// \details This function converts the given moment to std::string
        /// containing the passed date
        /// \param timePoint Optional. The moment on the system clock to be
        /// converted, the current time by default
        /// \return std::string with date in the format yyyy.mm.dd
        /// \todo Add tests
        INLINE std::string getDate(
            const std::chrono::system_clock::time_point timePoint =
                std::chrono::system_clock::now()
        ){
            std::time_t date = std::chrono::system_clock::to_time_t(timePoint);

            std::ostringstream stream;

            stream << std::put_time(std::localtime(&date), "%F");

            return stream.str();
        }

        /// \fn std::string getTime(std::chrono::system_clock::time_point 
        /// timePoint = std::chrono::system_clock::now());
        /// \brief Get  time
        /// \details This function converts the given moment to std::string
        /// containing the passed time 
        /// \param timePoint Optional. The moment on the system clock to be
        /// converted, the current time by default
        /// \return std::string with date time in the format HH:MM:SS
        /// \todo Add tests
        INLINE std::string getTime(
            const std::chrono::system_clock::time_point timePoint =
                std::chrono::system_clock::now()
        ){
            std::time_t date = std::chrono::system_clock::to_time_t(timePoint);

            std::ostringstream stream;

            stream << std::put_time(std::localtime(&date), "%T");

            return stream.str();
        }

    #endif

    /// \fn double void sleep(const std::size_t ticks, const std::string 
    /// scale = std::string("ms"));
    /// \brief Put the thread to sleep for the specified time
    /// \details This function puts the thread to sleep for the specified time
    /// in hours, minutes, seconds, milliseconds, microseconds or nanoseconds
    /// using std::this_thread::sleep_for and std::chrono
    /// \param ticks Sleep time
    /// \param scale Optional. By default set to milliseconds. Set \p scale 
    /// to "h" for hours, "m" for minutes, "s" for
    /// seconds, "us" for microseconds, "ns" for nanoseconds
    /// \todo Add tests
    INLINE void sleep(
        const std::size_t ticks,
        const std::string scale = std::string("ms")
    ){
        if(std::string("h") == scale){
            return std::this_thread::sleep_for(
                std::chrono::hours(ticks)
            );
        }

        if(std::string("m") == scale){
            return std::this_thread::sleep_for(
                std::chrono::minutes(ticks)
            );
        }

        if(std::string("s") == scale){
            return std::this_thread::sleep_for(
                std::chrono::seconds(ticks)
            );
        }

        if(std::string("us") == scale){
            return std::this_thread::sleep_for(
                std::chrono::microseconds(ticks)
            );
        }

        if(std::string("ns") == scale){
            return std::this_thread::sleep_for(
                std::chrono::nanoseconds(ticks)
            );
        }

        return std::this_thread::sleep_for(
            std::chrono::milliseconds(ticks)
        );
    }

    /// \} End of TimeFunctions Group

    /// \defgroup ParameterFunctions Parameter Functions
    /// \brief Functions providing methods to parse and assign parameters
    /// \details Group of functions that is useful to parse parameters (e.g.,
    /// from command line) and assign its values to your variables
    /// \{

    /// \todo Add description. Add tests
    INLINE std::string parseParameter(
        const char *input,
        const std::string name
    ){
        std::string parameter(input);

        if(hasPrefix(parameter, name)){
            parameter = parameter.substr(name.size());
            return parameter;
        }

        return NULL;
    }

    /// \tparam T Any comparable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void assignFromVectorByIntervalCondition(
        T &value,
        const T parameter,
        const std::vector< std::vector<T> > intervals
    ){
        for(std::size_t i = 0; i < intervals.size(); ++i){
            if(intervals[i][0] <= parameter && parameter <= intervals[i][1]){
                value = intervals[i][2];

                return;
            }
        }
    }

    /// \tparam T Any comparable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void assignFromVectorByIntervalCondition(
        T &firstValue,
        T &secondValue,
        const T parameter,
        const std::vector< std::vector<T> > intervals
    ){
        for(std::size_t i = 0; i < intervals.size(); ++i){
            if(intervals[i][0] <= parameter && parameter <= intervals[i][1]){
                firstValue = intervals[i][1];
                secondValue = intervals[i][2];

                return;
            }
        }
    }

    /// \todo Add description. Add tests
    INLINE bool assignBooleanParameter(
        const char *input,
        const std::string name,
        bool &value
   ){
       if(name == std::string(input)){
           value = true;

           return true;
       }

       return false;
   }

    /// \todo Add description. Add tests
    INLINE bool assignCharParameter(
        const char *input,
        const std::string name,
        char &value
    ){
        std::string parameter = std::string(input);

        if(ai::hasPrefix(parameter, name)){
            parameter = parameter.substr(name.size());

            if(std::string() != parameter){
                value = (char) parameter[0];
            }else{
                value = ' ';
            }

            return true;
        }

        return false;
    }

    /// \todo Add description. Add tests
    INLINE bool assignStringParameter(
        const char *input,
        const std::string name,
        std::string &value
    ){
        std::string parameter = std::string(input);

        if(ai::hasPrefix(parameter, name)){
            value = parameter.substr(name.size());

            return true;
        }

        return false;
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE bool assignParameter(
        const char *input,
        const std::string name,
        T &value
    ){
        std::string parameter = std::string(input);

        if(ai::hasPrefix(parameter, name)){
            parameter = parameter.substr(name.size());

            if(std::istringstream(parameter) >> value){
                return true;
            }
        }

        return false;
    }

    /// \todo Add description. Add tests
    INLINE bool assignAbsDoubleParameter(
        const char *input,
        const std::string name,
        double &value
    ){
        std::string parameter = std::string(input);

        if(ai::hasPrefix(parameter, name)){
            parameter = parameter.substr(name.size());
            value = std::abs(strtod(parameter.c_str(), nullptr));

            return true;
        }

        return false;
    }

    /// \tparam T Any type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE bool assignByCheckingParameter(
        const char *input,
        const std::string parameter,
        T &value,
        const T supposed
    ){
        if(ai::equal(input, parameter)){
            value = supposed;

            return true;
        }

        return false;
    }

    /// \} End of ParameterFunctions Group

    /// \defgroup InterfaceFunctions Interface Functions
    /// \brief Functions providing some style to your console output
    /// \details Group of functions that animate your console with a style-ish
    /// interface
    /// \{

    /// \todo Add description. Add tests
    INLINE void clearScreen(){
        std::cout <<"\033[2J" << "\033[H";
    }

    /// \todo Add description. Add tests
    INLINE void setLocale(const std::string locale){
        if(std::string("en") == ai::toLowerCase(locale)){
            std::locale::global(std::locale("en_US.utf8"));
        }else{
            std::locale::global(
                std::locale(
                    (
                        ai::toLowerCase(locale) + ai::string("_")
                        + ai::toUpperCase(locale) + ai::string(".utf8")
                    ).c_str()
                )
            );
        }
    }

    /// \fn void showProgressBar(double progress, const std::size_t
    /// screenWidth = 80);
    /// \brief Prints a simple progress-bar to stdout
    /// \details This function prints a simple progress-bar to stdout
    /// \param progress Number from 0 to 1 to
    /// \param screenWidth Optional. The maximum length of the progress-bar in
    /// the symbols. Default is 80, should be at least 20
    /// \exception std::runtime_error If \p screenWidth is less than 20
    INLINE void showProgressBar(
        double progress,
        const int screenWidth = 80
    ){
        if(1 < progress){
            progress = 1;
        }

        if(0.01 > progress){
            progress = 0;
        }

        if(20 > screenWidth){
            throw std::runtime_error(
                ai::string("Screen width should be at least 20 (not ")
                + ai::string(screenWidth)
                + ai::string(")")
            );
        }

        const std::size_t barWidth = screenWidth - 7;

        int width = progress * barWidth;

        std::cout << std::fixed;
        std::cout.precision(1);
        std::cout.flush();

        std::cout << "\r" << std::string(width, '=')
            << std::string(barWidth - width, '-')
            << " " << progress * 100. << "%";
    }

    /// \fn void printLine(const std::string line, const std::size_t
    /// screenWidth = 80);
    /// \brief Prints a line with specified width
    /// \details This function prints a line with specified width. Can be
    /// useful to print output when progress-bar is displayed (function
    /// showProgressBar()).
    /// \param line Text to print
    /// \param screenWidth Optional. The maximum length of the progress-bar in
    /// the symbols. Default is 80, should be at least 20
    /// \exception std::runtime_error If \p screenWidth is less than 20
    INLINE void printLine(
        const std::string line,
        const int screenWidth = 80
    ){
        if(20 > screenWidth){
            throw std::runtime_error(
                ai::string("Screen width should be at least 20 (not ")
                + ai::string(screenWidth)
                + ai::string(")")
            );
        }

        std::cout << "\r" << std::setw(screenWidth) << std::left << line
            << std::endl;
    }

    /// \} End of InterfaceFunctions Group

    /// \defgroup ReadFunctions Read Functions
    /// \brief Functions providing the ability to read your data
    /// \details Group of functions that reads files and writes its content
    /// into your variables
    /// \{

    /// \tparam T Any printable type
    /// \exception std::runtime_error If file could not be open
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void parseFileInMatrix(
        const std::string filename,
        const char separator,
        std::vector< std::vector<T> > &matrix
    ){
        std::ifstream input(filename);

        if(!input.good()){
            throw std::runtime_error(
                ai::string("Exception while parsing the file into a matrix: ")
                + filename
            );
        }

        std::string token;

        T value;

        for(std::string line; std::getline(input, line);){
            if('#' == line[0]){
                continue;
            }

            std::istringstream stream(line);

            std::vector<T> row;

            while(std::getline(stream, token, separator)){
                if(std::istringstream(token) >> value){
                    row.push_back(value);
                }
            }

            matrix.push_back(row);
        }

        input.close();
    }

    /// \tparam T Any printable type
    /// \exception std::runtime_error If file could not be open
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void parseFileInVector(
        const std::string filename,
        const char separator,
        std::vector<T> &vector
    ){
        std::ifstream input(filename);

        if(!input.good()){
            throw std::runtime_error(
                ai::string("Exception while parsing the file into a vector: ")
                + filename
            );
        }

        std::string token;

        T value;

        if('\n' == separator){
            for(std::string line; std::getline(input, line);){
                if('#' == line[0]){
                    continue;
                }

                if(std::istringstream(line) >> value){
                    vector.push_back(value);
                }
            }
        }else{
            std::string line;

            std::getline(input, line);

            std::istringstream stream(line);

            while(std::getline(stream, token, separator)){
                if(std::istringstream(token) >> value){
                    vector.push_back(value);
                }
            }
        }

        input.close();
    }

    /// \exception std::runtime_error If file could not be open
    /// \todo Add description. Add tests
    INLINE void parseFileIntoString(
        const std::string filename,
        std::string &content
    ){
        std::ifstream input(filename);

        if(!input.good()){
            throw std::runtime_error(
                ai::string("Exception while parsing the file into a string: ")
                + filename
            );
        }

        std::ostringstream stream;
        stream << input.rdbuf();
        content = stream.str();

        input.close();
    }

    /// \tparam T A number type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void accumulateFileInMatrix(
        const std::string filename,
        const char separator,
        std::vector< std::vector<T> > &matrix
    ){
        std::vector< std::vector<T> > matrixToAdd;

        ai::parseFileInMatrix(filename, separator, matrixToAdd);

        for(std::size_t i = 0; i < matrix.size(); ++i){
            std::transform(
                matrix[i].begin(),
                matrix[i].end(),
                matrixToAdd[i].begin(),
                matrix[i].begin(),
                std::plus<T>()
            );
        }
    }

    /// \tparam T A number type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void accumulateFileInVector(
        const std::string filename,
        const char separator,
        std::vector<T> &vector,
        const bool checkForNaN = false
    ){
        std::vector<T> vectorToAdd;

        ai::parseFileInVector(filename, separator, vectorToAdd);

        std::transform(
            vector.begin(),
            vector.end(),
            vectorToAdd.begin(),
            vector.begin(),
            std::plus<T>()
        );
    }

    /// \tparam T A number type
    /// \exception std::runtime_error If file could not be open
    /// \todo Add description. Add tests
    template<typename T>
    INLINE bool loadA3R(
        const std::string filename,
        std::vector< std::vector<T> > &positions,
        double &radius
    ){
        std::ifstream input(filename, std::ios::binary | std::ios::in);

        if(!input.good()){
            throw std::runtime_error(
                ai::string("Exception while reading positions from the file: ")
                + filename
            );
        }

        char numberOfParticlesValue[4];
        char startByte[4];
        char radiusValue[8];
        char value[4];

        input.seekg(4);
        input.read(numberOfParticlesValue, 4);
        input.read(startByte, 4);
        input.seekg(24);
        input.read(radiusValue, 8);
        input.seekg(reinterpret_cast<int&>(startByte));

        radius = reinterpret_cast<double&>(radiusValue);

        std::size_t numberOfParticles = (std::size_t) reinterpret_cast<int&>(
                numberOfParticlesValue
            );

        positions.resize(numberOfParticles);

        for(std::size_t i = 0; i < numberOfParticles; ++i){
            positions[i].resize(3);

            for(std::size_t j = 0; j < 3; ++j){
                input.read(value, 4);
                positions[i][j] = (T) reinterpret_cast<float&>(value);
            }

            std::cout << std::endl;
        }

        input.close();

        return true;
    }

    /// \tparam T Any printable type
    /// \exception std::runtime_error If file could not be open
    /// \see https://en.wikipedia.org/wiki/XYZ_file_format
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void loadXYZ(
        const std::string filename,
        std::vector< std::vector<T> > &matrix
    ){
        std::ifstream input(filename);

        if(!input.good()){
            throw std::runtime_error(
                ai::string("Exception while reading positions from the file: ")
                + filename
            );
        }

        std::size_t counter = 0;

        std::string token;

        T value;

        for(std::string line; std::getline(input, line);){
            ++counter;

            if(3 > counter){
                continue;
            }

            std::istringstream stream(line);

            std::vector<T> row;

            std::size_t subCounter = 0;

            while(std::getline(stream, token, ' ')){
                ++subCounter;
                if(2 > subCounter){
                    continue;
                }
                if(std::istringstream(token) >> value){
                    row.push_back(value);
                }
            }

            matrix.push_back(row);
        }

        input.close();
    }

    /// \} End of ReadFunctions Group

    /// \defgroup PrintFunctions Print Functions
    /// \brief Functions providing the ability to print your data
    /// \details Group of functions that prints your data and its parameters
    /// for quick analysis
    /// \{

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printMatrix(
        const std::vector<std::vector <T> > &matrix,
        const std::string name = std::string("Matrix"),
        const bool transpose = false,
        const int precision = 5
    ){
        if(1 > matrix.size()){
            throw std::runtime_error(
                ai::string("Exception while printing the matrix: ")
                + ai::string("size should be at least 1.")
            );
        }

        std::cout << std::scientific;
        std::cout.precision(precision);

        std::cout << name << "[" << matrix.size() << "x" << matrix[0].size()
            << "] = {" << std::endl;

        if(transpose){
            for(std::size_t j = 0; j < matrix[0].size(); ++j){
                const std::size_t lastIndex = matrix.size() - 1;

                for(std::size_t i = 0; i < lastIndex; ++i){
                    std::cout << matrix[i][j] << ", ";
                }

                std::cout << matrix[lastIndex][j] << std::endl;
            }
        }else{
            for(std::size_t i = 0; i < matrix.size(); ++i){
                const std::size_t lastIndex = matrix[i].size() - 1;

                for(std::size_t j = 0; j < lastIndex; ++j){
                    std::cout << matrix[i][j] << ", ";
                }

                std::cout << matrix[i][lastIndex] << std::endl;
            }
        }

        std::cout << "}[" << matrix.size() << "x" << matrix[0].size()
            << "]" << std::endl;
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printVector(
        const std::vector<T> &vector,
        const std::string name = std::string("Vector"),
        const int precision = 5
    ){
        if(1 > vector.size()){
            throw std::runtime_error(
                ai::string("Exception while printing the vector: ")
                + ai::string("size should be at least 1.")
            );
        }

        std::size_t lastIndex = vector.size() - 1;

        std::cout << std::scientific;
        std::cout.precision(precision);

        std::cout << name << "[" << vector.size() << "] = {" << std::endl;

        for(std::size_t i = 0; i < lastIndex; ++i){
            std::cout << vector[i] << ", ";
        }
        std::cout << vector[lastIndex] << std::endl;

        std::cout << "}[" << vector.size() << "]" << std::endl;
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void print(
        const std::vector<std::vector <T> > &matrix,
        const std::string name = std::string("Matrix"),
        const bool transpose = false,
        const int precision = 5
    ){
        ai::printMatrix(matrix, name, transpose, precision);
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void print(
        const std::vector<T> &vector,
        const std::string name = std::string("Vector"),
        const int precision = 5
    ){
        ai::printVector(vector, name, precision);
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void print(
        const T value,
        const std::string name = std::string("Value")
    ){
        std::cout << name << " = " << value << std::endl;
    }

    /// \brief Terminal color code for black
    /// \details This terminal control sequences sets black font color
    static std::string black("\033[30m");

    /// \brief Terminal color code for red
    /// \details This terminal control sequences sets red font color
    static std::string red("\033[31m");
    
    /// \brief Terminal color code for green
    /// \details This terminal control sequences sets green font color
    static std::string green("\033[32m");

    /// \brief Terminal color code for yellow
    /// \details This terminal control sequences sets yellow font color
    static std::string yellow("\033[33m");
    
    /// \brief Terminal color code for blue
    /// \details This terminal control sequences sets blue font color
    static std::string blue("\033[34m");

    /// \brief Terminal color code for magenta
    /// \details This terminal control sequences sets magenta font color
    static std::string magenta("\033[35m");

    /// \brief Terminal color code for cyan
    /// \details This terminal control sequences sets cyan font color
    static std::string cyan("\033[36m");
    
    /// \brief Terminal color code for white
    /// \details This terminal control sequences sets white font color
    static std::string white("\033[37m");

    /// \brief Terminal style code for bold
    /// \details This terminal control sequences sets bold font style
    static std::string bold("\033[1m");

    /// \brief Terminal style code for underline
    /// \details This terminal control sequences sets underline font style
    static std::string underline("\033[4m");

    /// \brief Terminal code to reset special formatting
    /// \details This terminal control sequences resets font to the default 
    /// state
    static std::string reset("\033[0m");

    //isatty
    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printStyle(const T income, const std::string style){
        std::cout << style << income << ai::reset << std::endl;
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printBlack(const T income){
        ai::printStyle(income, ai::black);
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printRed(const T income){
        ai::printStyle(income, ai::red);
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printGreen(const T income){
        ai::printStyle(income, ai::green);
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printYellow(const T income){
        ai::printStyle(income, ai::yellow);
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printBlue(const T income){
        ai::printStyle(income, ai::blue);
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printMagenta(const T income){
        ai::printStyle(income, ai::magenta);
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printCyan(const T income){
        ai::printStyle(income, ai::cyan);
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printWhite(const T income){
        ai::printStyle(income, ai::white);
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printBold(const T income){
        ai::printStyle(income, ai::bold);
    }

    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printUnderline(const T income){
        ai::printStyle(income, ai::underline);
    }

    /// \todo Add description. Add tests
    INLINE void printAllStyles(){
        auto printStyleTest = [](
            const std::string color,
            const std::string colorName
        ) -> void{
            std::cout << colorName << ": " << color << "normal, " << ai::bold
                << "bold " << ai::reset
                << color << " and " << ai::underline << "underline"
                << ai::reset
                << color << "." << ai::reset
                << std::endl;
        };

        printStyleTest(ai::black, "Black");
        printStyleTest(ai::red, "Red");
        printStyleTest(ai::green, "Green");
        printStyleTest(ai::yellow, "Yellow");
        printStyleTest(ai::blue, "Blue");
        printStyleTest(ai::magenta, "Magenta");
        printStyleTest(ai::cyan, "Cyan");
        printStyleTest(ai::white, "White");
    }

    /// \todo Add description. Add tests
    INLINE void clearStyles(){
        ai::black = std::string();
        ai::red = std::string();
        ai::green = std::string();
        ai::yellow = std::string();
        ai::blue = std::string();
        ai::magenta = std::string();
        ai::cyan = std::string();
        ai::white = std::string();
        ai::bold = std::string();
        ai::underline = std::string();
        ai::reset = std::string();
    }

    /// \} End of PrintFunctions Group

    /// \defgroup SaveFunctions Save Functions
    /// \brief Functions providing the ability to save your data
    /// \details Group of functions that will make saving data much easier
    /// by supporting various formats and styles
    /// \{

    /// \tparam T Any printable type
    /// \exception std::runtime_error If file could not be open or sizes of 
    /// the input are inappropriate
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void saveMatrix(
        const std::string filename,
        const std::vector<std::vector <T> > &matrix,
        std::string comment = std::string(),
        const bool transpose = false,
        std::string type = std::string("text"),
        std::string delimiter = std::string(" "),
        const std::size_t precision = 6,
        const std::size_t tokenWidth = 14
    ){
        std::string extension("_m.txt");
        std::string prefix("");
        std::string suffix("");

        if(std::string("wolfram") == type){
            extension = std::string("_m.wm");
            prefix = std::string("{");
            delimiter = std::string(", ");
            suffix = std::string("}");
        }

        if(std::string("excel") == type){
            extension = std::string("_m.csv");
            delimiter = std::string("; ");
        }

        if(std::string("data") == type){
            extension = std::string("_m.dat");
            delimiter = std::string("\t");
        }

        std::ofstream output(filename + extension);

        if(!output.good()){
            throw std::runtime_error(
                ai::string("Exception while saving the matrix into the file: ")
                + filename
            );
        }

        if(std::string() != comment){
            output << comment << std::endl;
        }

        output << std::setprecision(precision) << prefix;

        if(transpose){
            std::size_t maximumLength = 0;
            
            for(std::size_t i = 0; i < matrix.size(); ++i){
                maximumLength = ai::max(maximumLength, matrix[i].size());
            }
            for(std::size_t j = 0; j < maximumLength; ++j){
                output << prefix;

                const std::size_t lastIndex = matrix.size() - 1;

                for(std::size_t i = 0; i < lastIndex; ++i){
                    if(matrix[i].size() > j){
                        output << std::setw(tokenWidth) << matrix[i][j]
                            << delimiter;
                    }else{
                        output << std::setw(tokenWidth) << " " << delimiter;
                    }
                }

                if(matrix[lastIndex].size() > j){
                    output << std::setw(tokenWidth) << matrix[lastIndex][j]
                        << suffix;
                }else{
                    output << std::setw(tokenWidth) << " " << suffix;
                }
            }
       }else{
            for(std::size_t i = 0; i < matrix.size(); ++i){
                output << prefix;

                const std::size_t lastIndex = matrix[i].size() - 1;

                for(std::size_t j = 0; j < lastIndex; ++j){
                    output << std::setw(tokenWidth) << matrix[i][j]
                        << delimiter;
                }

                output << std::setw(tokenWidth) << matrix[i][lastIndex]
                    << suffix << std::endl;
            }
        }

        output << suffix;

        output.close();
    }

    /// \tparam T Any printable type
    /// \exception std::runtime_error If file could not be open
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void saveVector(
        const std::string filename,
        const std::vector<T> &vector,
        std::string comment = std::string(),
        std::string type = std::string("text"),
        std::string delimiter = std::string("\n"),
        const std::size_t precision = 6
    ){
        std::string extension("_v.txt");
        std::string prefix("");
        std::string suffix("");

        if(std::string("wolfram") == type){
            extension = std::string("_v.wm");
            prefix = std::string("{");
            delimiter = std::string(", ");
            suffix = std::string("}");
        }

        if(std::string("excel") == type){
            extension = std::string("_v.csv");
            delimiter = std::string("; ");
        }

        if(std::string("data") == type){
            extension = std::string("_v.dat");
            delimiter = std::string("\t");
        }

        std::ofstream output(filename + extension);

        if(!output.good()){
            throw std::runtime_error(
                ai::string("Exception while saving the vector into the file: ")
                + filename
            );
        }

        if(std::string() != comment){
            output << comment << std::endl;
        }

        output << std::setprecision(precision) << prefix;

        if(1 < vector.size()){
            const std::size_t lastIndex = vector.size() - 1;

            for(std::size_t i = 0; i < lastIndex; ++i){
                output << vector[i] << delimiter;
            }

            output << vector[lastIndex];
        }

        output << suffix;

        output.close();
    }

    /// \exception std::runtime_error If file could not be open
    /// \todo Add description. Add tests
    INLINE void saveLine(
        const std::string filename,
        const std::string line,
        std::string comment = std::string()
    ){
        std::ofstream output(filename + "_l.txt");

        if(!output.good()){
            throw std::runtime_error(
                ai::string("Exception while saving the line into the file: ")
                + filename
            );
        }

        if(std::string() != comment){
            output << comment << "\n";
        }

        output << line << std::endl;

        output.close();
    }

    /// \todo Add description. Add tests
    template<typename T>
    INLINE void save(
        const std::string filename,
        const std::vector<std::vector <T> > &matrix,
        std::string comment = std::string()
    ){
        ai::saveMatrix(filename, matrix, comment);
    }

    /// \todo Add description. Add tests
    template<typename T>
    INLINE void save(
        const std::string filename,
        const std::vector<T> &vector,
        std::string comment = std::string()
    ){
        ai::saveVector(filename, vector, comment);
    }

    /// \todo Add description. Add tests
    template<typename T>
    INLINE void save(
        const std::string filename,
        const std::string line,
        std::string comment = std::string()
    ){
        ai::saveLine(filename, line, comment);
    }

    #if defined(AI_GCC5_SUPPORT)
        /// \exception std::runtime_error If file could not be open
        /// \todo Add description. Add tests
        INLINE void saveLog(
            const std::string filename,
            std::string log,
            const bool timestamp = false,
            const std::string stampSeparator = std::string(" ")
        ){
            std::ofstream output(filename, std::ios_base::app);

            if(!output.good()){
                throw std::runtime_error(
                    ai::string("Exception while saving log into the file: ")
                    + filename
                );
            }

            if(timestamp){
                output << ai::getDateAndTime() << stampSeparator;
            }

            output << log << std::endl;

            output.close();
        }

        /// \exception std::runtime_error If file could not be open
        /// \todo Add description. Add tests
        INLINE void saveLog(
            const std::string filename,
            std::vector<std::string> &logs,
            const bool timestamp = false,
            const std::string stampSeparator = std::string(" ")
        ){
            std::ofstream output(filename, std::ios_base::app);

            if(!output.good()){
                throw std::runtime_error(
                    ai::string("Exception while saving log into the file: ")
                    + filename
                );
            }

            std::string prefix("");

            if(timestamp){
                prefix = ai::getDateAndTime() + stampSeparator;
            }

            for(std::size_t i = 0; i < logs.size(); ++i){
                output << prefix << logs[i] << std::endl;
            }

            output.close();
        }

    #endif

    /// \tparam T A number type
    /// \exception std::runtime_error If file could not be open
    /// \todo Add description. Add tests
    template<typename T>
    INLINE bool saveA3R(
        const std::string filename,
        const std::vector< std::vector<T> > &positions,
        const double radius = 1
    ){
        std::ofstream output(
            filename + std::string(".a3r"), std::ios::binary | std::ios::out
        );

        if(!output.good()){
            throw std::runtime_error(
                ai::string("Exception while saving positions into the file: ")
                + filename
            );
        }

        const std::size_t numberOfParticles = positions.size();

        const int integerNumberOfParticles = (int) numberOfParticles;

        const int startByte = 36;
        const int futureValue = 0;

        const int intSize = 4;
        const int floatSize = 4;
        const int doubleSize = 8;

        output.write("a3r\0", 4);
        output.write((char*) &integerNumberOfParticles, intSize);
        output.write((char*) &startByte, intSize);
        output.write("AiLib 1.1.0\0", 12);
        output.write((char*) &radius, doubleSize);
        output.write((char*) &futureValue, intSize);

        if(2 == positions[0].size()){
            for(std::size_t i = 0; i < numberOfParticles; ++i){
                float x = (float) positions[i][0];
                float y = (float) positions[i][1];
                float z = 0.;

                output.write((char*) &x, floatSize);
                output.write((char*) &y, floatSize);
                output.write((char*) &z, floatSize);
            }
        }else{
            if(3 == positions[0].size()){
                for(std::size_t i = 0; i < numberOfParticles; ++i){
                    float x = (float) positions[i][0];
                    float y = (float) positions[i][1];
                    float z = (float) positions[i][2];

                    output.write((char*) &x, floatSize);
                    output.write((char*) &y, floatSize);
                    output.write((char*) &z, floatSize);
                }
            }else{
                return false;
            }
        }

        output.close();

        return true;
    }

    /// \tparam T A number type
    /// \exception std::runtime_error If file could not be open
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void saveXYZ(
        const std::string filename,
        const std::vector< std::vector<T> > &matrix,
        const std::vector<T> &tones,
        std::string elementName = "C"
    ){
        std::ofstream output(filename + std::string(".xyz"));

        if(!output.good()){
            throw std::runtime_error(
                ai::string("Exception while saving positions into the file: ")
                + filename
            );
        }

        const std::size_t numberOfParticles = matrix.size();
        
        bool withColors = (tones.size() == numberOfParticles);

        output << numberOfParticles << std::endl << std::endl;

        for(std::size_t i = 0; i < numberOfParticles; ++i){
            output << elementName;

            for(std::size_t j = 0; j < matrix[i].size(); ++j){
                output << " " << matrix[i][j];
            }
            
            if(withColors){
                double color = 1. - 2. * tones[i];
                
                if(1. < color){
                    color = 1.;
                }else{
                    if(0. > color){
                        color = 0.;
                    }
                }

                output << " " << color;

                color = 1. - std::abs(2. * tones[i] - 1.);

                if(1. < color){
                    color = 1.;
                }else{
                    if(0. > color){
                        color = 0.;
                    }
                }

                output << " " << color;

                color = 2. * tones[i] - 1.;

                if(1. < color){
                    color = 1.;
                }else{
                    if(0. > color){
                        color = 0.;
                    }
                }

                output << " " << color;
            }

            output << std::endl;
        }

        output.close();
    }
    
    /// \tparam T Any printable type
    /// \todo Add description. Add tests
    template<typename T>
    INLINE void saveXYZ(
        const std::string filename,
        const std::vector< std::vector<T> > &matrix,
        std::string elementName = "C"
    ){
        saveXYZ(filename, matrix, std::vector<T>(), elementName);
    }

    /// \} End of SaveFunctions Group

    /// \defgroup FileFunctions File Functions
    /// \brief Functions providing the ability to check files and folders
    /// \details Group of functions that checks and analyzes folders and files
    /// \{

    /// \fn bool fileExists(const std::string name);
    /// \brief Check if file exists
    /// \details This function checks if the given file actually exists 
    /// [POSIX]
    /// \param name Path to the file
    /// \return True if file exists, false otherwise
    /// \todo Add tests
    INLINE bool fileExists(const std::string path){
        struct stat buffer;

        return (0 == stat(path.c_str(), &buffer))
            && (S_IFREG & buffer.st_mode);
    }

    /// \fn bool folderExists(const std::string name);
    /// \brief Check if folder exists
    /// \details This function checks if the given directory actually exists
    /// [POSIX]
    /// \param name Path to the folder
    /// \return True if folder exists, false otherwise
    /// \todo Add tests
    INLINE bool folderExists(const std::string path){
        struct stat buffer;

        return (0 == stat(path.c_str(), &buffer)) 
            && !(S_IFREG & buffer.st_mode);
    }
    
    /// \fn bool exists(const std::string name);
    /// \brief Check if file or folder exists
    /// \details This function checks if the given file or directory actually
    /// exists [POSIX]
    /// \param name Path to the file or folder
    /// \return True if file or folder exists, false otherwise
    /// \todo Add tests
    INLINE bool exists(const std::string path){
        struct stat buffer;

        return 0 == stat(path.c_str(), &buffer);
    }

    /// \fn bool isFile(const std::string name);
    /// \brief Check if the given path leads to a file
    /// \details This function checks if the given path leads to a file
    /// using fileExists() [POSIX]
    /// \param name Path to the file
    /// \return True if is trully a file, false otherwise
    /// \todo Add tests
    INLINE bool isFile(const std::string path){
        return ai::fileExists(path);
    }

    /// \fn bool isFolder(const std::string name);
    /// \brief Check if the given path leads to a folder
    /// \details This function checks if the given path leads to a directory
    /// using folderExists() [POSIX]
    /// \param name Path to the folder
    /// \return True if is trully a folder, false otherwise
    /// \todo Add tests
    INLINE bool isFolder(const std::string path){
        return ai::folderExists(path);
    }

    /// \fn std::size_t countLinesInFile(const std::string filename, const
    /// std::string token = std::string());
    /// \brief Count number of lines in the file
    /// \details This function counts number of lines in the given file (total
    /// or containing the given token)
    /// \param filename Path to the file
    /// \param token Optional. Count only the lines containing the given token.
    /// Count all lines by default
    /// \return Number of lines
    /// \exception std::runtime_error If file could not be open
    /// \todo Add tests
    INLINE std::size_t countLinesInFile(
        const std::string filename,
        const std::string token = std::string()
    ){
        std::ifstream input(filename);

        if(!input.good()){
            throw std::runtime_error(
                ai::string("Exception while counting lines in the file: ")
                + filename
            );
        }

        std::size_t count = 0;

        if(std::string() == token){
            for(std::string line; getline(input, line);){
                ++count;
            }
        }else{
            for(std::string line; getline(input, line);){
                if(std::string::npos != line.find(token)){
                    ++count;
                }
            }
        }

        input.close();

        return count;
    }

    #if defined(AI_DIRENT_SUPPORT)
        /// \todo Add description. Add tests
        INLINE std::vector<std::string> listFilesWithExtension(
            std::string path,
            const std::string extension,
            const std::string prefix = std::string(),
            const bool addPathToFileNames = false
        ){
            DIR *dir;

            struct dirent *ent;

            dir = opendir(path.c_str());

            std::vector<std::string> files;

            if(NULL != dir){
                while(NULL != (ent = readdir (dir))){
                    if(
                        DT_REG == ent->d_type
                        && hasSuffix(ent->d_name, extension)
                    ){
                        files.push_back(prefix + ent->d_name);
                    }
                }

                closedir(dir);
            }

            if(addPathToFileNames){
                path += std::string("/");

                for(std::size_t i = 0; i < files.size(); ++i){
                    files[i] = path + files[i];
                }
            }

            return files;
        }
    #endif

    /// \} End of FileFunctions Group

    #if defined(AI_SHELL_SUPPORT)
        /// \defgroup ShellFunctions Shell Functions
        /// \brief Functions providing shell support
        /// \details Group of functions that will help you to interact with
        /// shell and other programs
        /// \{

        /// \todo Add description. Add tests
        INLINE std::string execute(
            const std::string command
        ){
            const std::size_t bufferSize = 128;

            std::array<char, bufferSize> buffer;

            std::string result;

            std::shared_ptr<FILE> pipe(popen(command.c_str(), "r"), pclose);

            if(!pipe){
                throw std::runtime_error(
                    ai::string("Exception while executing the command: ")
                    + command
                );
            }

            while(!feof(pipe.get())){
                if(nullptr != fgets(buffer.data(), bufferSize, pipe.get())){
                    result += buffer.data();
                }
            }

            return result;
        }
        
        /// \} End of Shell Functions Group
        
    #endif

}

/// \} End of Ai Namespace Group

#if defined(AI_FUTURE)
    /// Functions to be added in future releases
    namespace ai{
        /// Still looking for a good cross-platform solution
        INLINE bool createFolder(const std::string name);
        
        template<typename T>
        INLINE void fill(std::vector< std::vector<T> > &matrix, T value){
            for(std::size_t i = 0; i < matrix.size(); ++i){
                for(std::size_t j = 0; j < matrix[i].size(); ++j){
                    matrix[i][j] = value;
                }
            }
        }
        
        template<typename T>
        INLINE void fill(std::vector<T> &vector, T value){
            for(std::size_t i = 0; i < vector.size(); ++i){
                vector[i] = value;
            }
        }
        
        template<typename T>
        INLINE void sum(
            const std::vector< std::vector<T> > &matrix,
            std::vector<T> &vector
        ){
            vector.clear();
            vector.resize(matrix.size());
            
            for(std::size_t i = 0; i < vector.size(); ++i){
                vector[i] = ai::sum(matrix[i]);
            }
        }
            
        template<typename T>
        INLINE T sum(const std::vector< std::vector<T> > &matrix){
            T sum = (T) 0.;
            
            for(std::size_t i = 0; i < matrix.size(); ++i){
                for(std::size_t j = 0; j < matrix[i].size(); ++j){
                    sum += matrix[i][j];
                }
            }
            
            return sum;
        }
        
        template<typename T>
        INLINE T sum(const std::vector<T> &vector){
            T sum = (T) 0.;
            
            for(std::size_t i = 0; i < vector.size(); ++i){
                sum += vector[i];
            }
            
            return sum;
        }
        
        template<typename T>
        INLINE void sum(
            const std::vector< std::vector<T> > &left,
            const std::vector< std::vector<T> > &right,
            std::vector< std::vector<T> > &result
        ){
            if(
                1 > left.size()
                || left.size() != right.size()
                || left[0].size() != right[0].size()
            ){
                throw std::runtime_error(
                    "Exception while summing: check the sizes of the input."
                );
            }
            
            std::size_t length = left[0].size();
            
            result.clear();
            result.resize(left.size());
            
            for(std::size_t i = 0; i < left.size(); ++i){
                result[i].resize(length);
                
                for(std::size_t j = 0; j < length; ++j){
                    result[i][j] = left[i][j] + right[i][j];
                }
            }
        }
        
        template<typename T>
        INLINE void sum(
            const std::vector<T> &left,
            const std::vector<T> &right,
            std::vector<T> &result
        ){
            if(
                1 > left.size()
                || left.size() != right.size()
            ){
                throw std::runtime_error(
                    "Exception while summing: check the sizes of the input."
                );
            }
            
            result.clear();
            result.resize(left.size());
            
            for(std::size_t i = 0; i < left.size(); ++i){
                result[i] = left[i] + right[i];
            }
        }
        
        template<typename T>
        INLINE void average(
            const std::vector< std::vector<T> > &matrix,
            std::vector<T> &vector
        ){
            vector.clear();
            vector.resize(matrix.size());
            
            for(std::size_t i = 0; i < vector.size(); ++i){
                vector[i] = ai::average(matrix[i]);
            }
        }
            
        template<typename T>
        INLINE T average(const std::vector< std::vector<T> > &matrix){
            T sum = (T) 0.;
            
            std::size_t counter = 0;
            
            for(std::size_t i = 0; i < matrix.size(); ++i){
                for(std::size_t j = 0; j < matrix[i].size(); ++j){
                    sum += matrix[i][j];
                    
                    ++counter;
                }
            }
            
            return sum / ((T) counter);
        }
        
        template<typename T>
        INLINE T average(const std::vector<T> &vector){
            return ai::sum(vector) / ((T) vector.size());
        }
        
        static bool redirectToFiles = false;
        
        INLINE void info(std::string info){
            if(ai::redirectToFiles){
                std::string filename("./info.txt");
                
                std::ofstream output(filename, std::ofstream::app);

                if(!output.good()){
                    throw std::runtime_error(
                        ai::string("Exception while printing to the file: ")
                        + filename
                    );
                }

                output << info << std::endl;
            }else{
                ai::printStyle(info, ai::blue + ai::bold);
            }
        }
        
        INLINE void warning(std::string warning){
            if(ai::redirectToFiles){
                std::string filename("./warnings.txt");

                std::ofstream output(filename, std::ofstream::app);

                if(!output.good()){
                    throw std::runtime_error(
                        ai::string("Exception while printing to the file: ")
                        + filename
                    );
                }

                output << warning << std::endl;
            }else{
                ai::printStyle(warning, ai::yellow + ai::bold);
            }
        }
        
        INLINE void error(std::string error){
            if(ai::redirectToFiles){
                std::string filename("./errors.txt");

                std::ofstream output(filename, std::ofstream::app);

                if(!output.good()){
                    throw std::runtime_error(
                        ai::string("Exception while printing to the file: ")
                        + filename
                    );
                }

                output << error << std::endl;
            }else{
                ai::printStyle(error, ai::red + ai::bold);
            }
        }
        

        
        template<typename T>
        INLINE void negate(std::vector< std::vector<T> > &matrix){
            for(std::size_t i = 0; i < matrix.size(); ++i){
                for(std::size_t j = 0; j < matrix[i].size(); ++j){
                    matrix[i][j] = -matrix[i][j];
                }
            }
        }
        
        template<typename T>
        INLINE void negate(std::vector<T> &vector){
            for(std::size_t i = 0; i < vector.size(); ++i){
                vector[i] = -vector[i];
            }
        }
        
        template<typename T>
        INLINE void multiply(
            std::vector< std::vector<T> > &matrix,
            const T value
        ){
            for(std::size_t i = 0; i < matrix.size(); ++i){
                for(std::size_t j = 0; j < matrix[i].size(); ++j){
                    matrix[i][j] *= value;
                }
            }
        }
        
        template<typename T>
        INLINE void multiply(std::vector<T> &vector, const T value){
            for(std::size_t i = 0; i < vector.size(); ++i){
                vector[i] *= value;
            }
        }
        
        template<typename T>
        INLINE T round(const T value, const std::size_t decimalPlaces = 0){
            T multiplier = (T) std::pow(10., decimalPlaces);
            
            return (T) std::round(value * multiplier) / multiplier;
        }
        
        INLINE std::streambuf* redirectCoutToFile(std::ofstream &file){
            return std::cout.rdbuf(file.rdbuf());
        }

        INLINE std::streambuf* redirectCoutToFile(
            const std::string filename,
            const bool append = true
        ){
            static std::ofstream output;
    
            if(append){
                output.open(filename, std::ios_base::app);
            }else{
                output.open(filename);
            }

            if(!output.good()){
                throw std::runtime_error(
                    ai::string("Exception while redirecting to the file: ")
                    + filename
                );
            }
    
            return ai::redirectCoutToFile(output);
        }

        INLINE void restoreCoutFromFile(std::streambuf *buffer){
            std::cout.rdbuf(buffer);
        }
        
        INLINE void killCout(){
            std::cout.setstate(std::ios::failbit);
        }
        

        
        INLINE void gaussElimination(
            std::vector< std::vector<double> > &matrix,
            std::vector<double> &vector,
            std::vector<double> &result
        ){
            if(
                1 > matrix.size()
                || 1 > matrix.size()
                || matrix.size() != vector.size()
            ){
                throw std::runtime_error(
                    "Exception while eliminating: check the sizes of the input."
                );
            }
            
            const std::size_t length = vector.size();
            
            for(std::size_t i = 0; i < length; ++i){
                if(length != matrix[i].size()){
                    throw std::runtime_error(
                        "Exception while eliminating: check the sizes of the input."
                    );
                }
            }
    
            result.resize(length);
    
            for(std::size_t i = 0; i < length; ++i){
                for(std::size_t k = i + 1; k < length; ++k){
                    if(std::fabs(matrix[i][i]) < std::fabs(matrix[k][i])){
                        double swap = vector[i];
                
                        vector[i] = vector[k];
                        vector[k] = swap;
                
                        for(std::size_t j = 0; j < length; ++j){
                            swap = matrix[i][j];
                            matrix[i][j] = matrix[k][j];
                            matrix[k][j] = swap;
                        }
                    }
                }
            }
            for(std::size_t i = 0; i < length - 1; ++i){
                for(std::size_t k = i + 1; k < length; ++k){
                    double coefficient = matrix[k][i] / matrix[i][i];
            
                    vector[k] = vector[k] - coefficient * vector[i];
            
                    for(std::size_t j = 0; j < length; ++j){
                        matrix[k][j] = matrix[k][j] - coefficient * matrix[i][j];
                    }
                }
            }
            for(int i = (int) length - 1; i >= 0; --i){
                result[i] = vector[i];
        
                for(int j = i + 1; j < length; ++j){
                    if(i != j){
                        result[i] -= matrix[i][j] * result[j];
                    }
                }
        
                result[i] /= matrix[i][i];
            }
        }

        INLINE double randomReal(
            const double min = std::numeric_limits<double>::min(),
            const double max = std::numeric_limits<double>::max()
        ){
            std::uniform_real_distribution<double> distribution(min, max);
        
            std::mt19937 device(std::random_device{}());

            return distribution(device);
        }
        INLINE int randomInteger(
            const int min = std::numeric_limits<int>::min(),
            const int max = std::numeric_limits<int>::max()
        ){
            std::uniform_int_distribution<int> distribution(min, max);
        
            std::mt19937 device(std::random_device{}());

            return distribution(device);
        }

        INLINE std::size_t randomIndex(
            const std::size_t begin,
            const std::size_t end
        ){
            return (std::size_t) ai::randomInteger((int) begin, (int) end);
        }

        INLINE double random(
            const double min = std::numeric_limits<double>::min(),
            const double max = std::numeric_limits<double>::max()
        ){
            return ai::randomReal(min, max);
        }

        template<typename T>
        INLINE std::size_t getRandomIndex(
            const std::vector<T> &vector
        ){
            return ai::randomIndex(0, vector.size() - 1);
        }

        template<typename T>
        INLINE T getRandomElement(
            const std::vector<T> &vector,
            std::size_t begin = 0,
            std::size_t end = std::numeric_limits<std::size_t>::max()
        ){
            if(vector.size() <= begin){
                begin = vector.size() - 1;
            }
            if(vector.size() <= end){
                end = vector.size() - 1;
            }
            if(begin > end){
                throw std::runtime_error("fff");
            }
            std::cout << "[" << begin << "," << end << "]" << std::endl;
            return vector[ai::randomIndex(begin, end)];
        }

        template<typename T>
        INLINE T getRandomElement(
            const std::vector< std::vector<T> > &matrix
        ){
            std::size_t index = ai::getRandomIndex(matrix);

            return matrix[index][ai::getRandomIndex(matrix[index])];
        }
        
        
        // int
        // mkpath(std::string s,mode_t mode)
        // {
        //     size_t pos=0;
        //     std::string dir;
        //     int mdret;
        //
        //     if(s[s.size()-1]!='/'){
        //         // force trailing / so we can handle everything in loop
        //         s+='/';
        //     }
        //
        //     while((pos=s.find_first_of('/',pos))!=std::string::npos){
        //         dir=s.substr(0,pos++);
        //         if(dir.size()==0) continue; // if leading / first time is 0 length
        //         if((mdret=mkdir(dir.c_str(),mode)) && errno!=EEXIST){
        //             return mdret;
        //         }
        //     }
        //     return mdret;
        // }
        //
    }
#endif

#endif