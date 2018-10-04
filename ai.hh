#if !defined(AILIBRARY_HH)
#define AILIBRARY_HH

/// \file ai.hh
/// \author Egor Starobinskii
/// \date 11 Aug 2018
/// \brief Single-header C++ Library
/// \details This is a single-header C++ Library from Ailurus Studio that 
/// brings you extra time to admire life instead of coding the same functions 
/// again and again.
/// \see https://starobinskii.github.io/AiLibrary
/// \see https://github.com/starobinskii/AiLibrary
/// \see https://snapcraft.io/ailibrary
/// \see https://ailurus.ru/

/// \brief If defined, funstions will be marked as inline. 
/// \details If defined, funstions will be marked as inline. Delete the line 
/// if you want to omit this behavior.
#define INLINE inline

/// \todo add
//#define DIRENT_SUPPORT
//#define SHELL_SUPPORT

#include <array>
#include <cmath>
#include <chrono>
#include <limits>
#include <memory>
#include <random>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sys/stat.h>


#if defined(DIRENT_SUPPORT)
    #include <dirent.h>
    //#include "Include/dirent/dirent.h"
#endif


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
    /// \brief Gets version of the lib
    /// \details This function returns version of the AiLibrary (we use SemVer)
    /// \return Version as a string
    INLINE std::string getVersion(){
        return "1.2.1";
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
        return text.size() >= suffix.size() &&
            text.compare(
                text.size() - suffix.size(), 
                suffix.size(), 
                suffix
            ) == 0;
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

    /// \fn std::string replace(std::string text, const std::string &substring,
    /// const std::string &replacement)
    /// \brief Replaces all occurrences of a substring in a copy of the initial 
    /// string with your text
    /// \details This function replaces all occurrences of a substring in a 
    /// string with your text and return the result. Initial string stays the 
    /// same
    /// \param text Your string to modify
    /// \param substring Your substring to find in the string
    /// \param replacement Replacement for all the substring occurrences
    /// \return Modified copy of the initial string
    INLINE std::string replace(
        std::string text,
        const std::string &substring,
        const std::string &replacement
    ){
        std::size_t position = text.find(substring);
        std::size_t substringSize = substring.size();
        std::size_t replacementSize = replacement.size();
        
        while(std::string::npos != position){
            text.replace(position, substringSize, replacement);
            position = text.find(substring, position + replacementSize);
        }
        return text;
    }

    /// \fn void applyReplace(std::string &text, const std::string 
    /// &substring, const std::string &replacement)
    /// \brief Modifies your string by replacing all occurrences of a substring
    /// string with your text
    /// \details This function replaces all occurrences of a substring in a 
    /// string with your text (modifies the initial string)
    /// \param text Your string to modify
    /// \param substring Your substring to find in the string
    /// \param replacement Replacement for all the substring occurrences
    INLINE void applyReplace(
        std::string &text,
        const std::string &substring,
        const std::string &replacement
    ){
        std::size_t position = text.find(substring);
        std::size_t substringSize = substring.size();
        std::size_t replacementSize = replacement.size();
        
        while(std::string::npos != position){
            text.replace(position, substringSize, replacement);
            position = text.find(substring, position + replacementSize);
        }
    }

    /// \fn bool equal(const char *charString, const std::string string1);
    /// \brief Checks if a char string is equal to a std::string
    /// \details This function compares a char string with a std::string
    /// \param charString Your char string to compare
    /// \param string1 Your std::string to compare
    /// \return True if strings are equal, false otherwise
    INLINE bool equal(const char *charString, const std::string string1){
        const std::string string2(charString);
        
        return string1 == string2;
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
    /// \param value The non-negative  value to which the counter should be 
    /// reset (optional)
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
    /// \param value The non-negative  value to which the counter should be 
    /// reset (optional)
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
    /// \param value The non-negative  value to which the counter should be 
    /// reset (optional)
    INLINE void printMarker(const std::size_t value = 0){
        std::cout << marker(value) << std::endl;
    }

    /// \} End of DebugFunctions Group

    /// \defgroup MathFunctions Math Functions
    /// \brief Functions providing different math methods and checks
    /// \details Group of functions that completes standard C++ mathematical 
    /// methods and helps with matrices and vectors
    /// \{

    /// \fn T sign(const T value);
    /// \brief Returns signum of the value
    /// \details This function returns signum of the number value (usign
    /// copysign())
    /// \param value The number to which signum is applied
    /// \return -1 for negative values, +1 for positive, 0 for zero
    /// \tparam T A number type
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
    /// \param a First number
    /// \param b Second number
    /// \return Minimum of two values
    /// \tparam T A number type
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
    /// \param a First number
    /// \param b Second number
    /// \return Maximum of two values
    /// \tparam T A number type
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
    /// \param input Vector to search for a minimum value
    /// \return Minimum of vector values
    /// \tparam T A number type
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
    /// \param input Vector to search for a maximum value
    /// \return Maximum of vector values
    /// \tparam T A number type
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
    /// \param input Matrix to search for a minimum value
    /// \return Minimum of matrix values
    /// \tparam T A number type
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
    /// \param input Matrix to search for a maximum value
    /// \return Maximum of matrix values
    /// \tparam T A number type
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
    /// \param value Number to test
    /// \return True if number is a square, false otherwise
    /// \tparam T A number type
    /// \todo Add tests
    template<typename T>
    INLINE bool isSquare(const T value){
        if(0 >= value){
            return false;
        }

        T root = (T) round(sqrt(value));

        return value == root * root;
    }

    /// \fn bool isSquare(const std::vector< std::vector<T> > matrix);
    /// \brief Checks if matrix is square
    /// \details This function checks if matrix is square
    /// \param matrix Matrix to test
    /// \return True if matrix is square, false otherwise
    /// \todo Add tests
    template<typename T>
    INLINE bool isSquare(const std::vector< std::vector<T> > matrix){
        return 0 < matrix.size() && matrix.size() == matrix[0].size();
    }

    /// \todo Add description. Add tests. Check for real or int. Change 
    /// srand (ai::time?). Rename max and min
    template<typename T>
    INLINE void generateRandomVector(
        std::vector<T> &vector,
        const std::size_t length,
        const T min = std::numeric_limits<T>::min(),
        const T max = std::numeric_limits<T>::max()
    ){
        std::uniform_real_distribution<T> distribution(min, max);
        std::random_device device;
        srand(device() * time(0));

        vector.resize(length);

        std::generate(
            vector.begin(),
            vector.end(),
            [&device, &distribution](){
                return distribution(device);
            }
        );
    }

    /// \todo Add description. Add tests
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

    /// \todo Add description. Add tests
    template<typename T>
    INLINE void generateRandomMatrix(
        std::vector<T> &vector,
        const std::size_t size,
        const T min = std::numeric_limits<T>::min(),
        const T max = std::numeric_limits<T>::max()
    ){
        generateRandomMatrix(vector, size, size, min, max);
    }

    /// \fn void translateMatrixIntoVector( std::vector< std::vector<T> > 
    /// &matrix, std::vector<T> &vector);
    /// \brief Elongates matrix into a vector
    /// \details This function converts the matrix into a vector, writing each 
    /// row one after another in a line
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
    /// \brief Transform vector in a square matrix (if possible)
    /// \details This function converts the vector into a matrix, if possible. 
    /// Otherwise, an exception will be thrown at runtime
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
                ai::string("Exception while converting vector into the square ")
                + ai::string("matrix: vector size should be square") 
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

    /// \todo add
    void createCirculantMatrix(
        std::vector< std::vector<double> > &matrix,
        std::vector<double> &source,
        const bool moveToTheRight = true
    ){
        if(1 > source.size()){
            throw std::runtime_error(
                ai::string("Exception while creating a circulant: ")
                + ai::string("size of the sources should be at least 1.") 
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

    inline void printDuration(
        const std::chrono::high_resolution_clock::time_point start,
        const std::chrono::high_resolution_clock::time_point finish,
        const std::string scale = std::string("ms"),
        const std::size_t count = 0
    ){
        std::cout << "Timer #" << counter(count) << ": " 
            << ai::duration(start, finish, scale) << scale << std::endl;
    }

    inline void printDuration(
        const std::chrono::high_resolution_clock::time_point start,
        const std::string scale = std::string("ms"),
        const std::size_t count = 0
    ){
        std::chrono::high_resolution_clock::time_point finish = ai::time();

        ai::printDuration(start, ai::time(), scale, count);
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

    /// \fn void print(T income);
    /// \brief Prints variable to the stdout
    /// \details This function prints variable to the stdout with a forwarding
    /// newline symbol
    /// \param income Variable to print
    /// \todo Add tests
    template<typename T>
    INLINE void print(const T income){
        std::cout << ai::string(income) << std::endl;
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
        
        std::cout << "\r" << std::setw(screenWidth) << std::left << line << std::endl;
    }

    /// \} End of InterfaceFunctions Group

    /// \defgroup ReadFunctions Read Functions
    /// \brief Functions providing the ability to read your data
    /// \details Group of functions that reads files and writes its content 
    /// into your variables
    /// \{

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

        for(std::string line; getline(input, line);){
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
    }

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
            for(std::string line; getline(input, line);){
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
    }

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
    }

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

    /// \} End of ReadFunctions Group

    /// \defgroup PrintFunctions Print Functions
    /// \brief Functions providing the ability to print your data
    /// \details Group of functions that prints your data and its parameters 
    /// for quick analysis
    /// \{

    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printMatrix(
        std::vector<std::vector <T> > &matrix,
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

        std::cout << "Matrix[" << matrix.size() << "x" << matrix[0].size() 
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

    /// \todo Add description. Add tests
    template<typename T>
    INLINE void printVector(
        std::vector<T> &vector,
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
        
        std::cout << "Vector[" << vector.size() << "] = {" << std::endl;

        for(std::size_t i = 0; i < lastIndex; ++i){
            std::cout << vector[i] << ", ";
        }
        std::cout << vector[lastIndex] << std::endl;

        std::cout << "}[" << vector.size() << "]" << std::endl;
    }

    /// \} End of PrintFunctions Group

    /// \defgroup SaveFunctions Save Functions
    /// \brief Functions providing the ability to save your data
    /// \details Group of functions that will make saving data much easier 
    /// by supporting various formats and styles
    /// \{

    /// \todo Add description. Add tests
    template<typename T>
    INLINE void saveMatrix(
        const std::string filename,
        std::vector<std::vector <T> > &matrix,
        const bool transpose = false,
        std::string comment = std::string(),
        std::string type = std::string("text"),
        std::string delimiter = std::string(" "),
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

        output << prefix;

        if(transpose){
            for(std::size_t j = 0; j < matrix[0].size(); ++j){
                output << prefix;
            
                const std::size_t lastIndex = matrix.size() - 1;

                for(std::size_t i = 0; i < lastIndex; ++i){
                    output << std::setw(tokenWidth) << matrix[i][j] 
                        << delimiter;
                }

                output << std::setw(tokenWidth) << matrix[lastIndex][j] 
                    << suffix << std::endl;
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
    }

    /// \todo Add description. Add tests
    template<typename T>
    INLINE void saveMatrix(
        const std::string filename,
        std::vector<std::vector <T> > &matrix,
        std::string comment = std::string(),
        std::string type = std::string("text"),
        std::string delimiter = std::string(" "),
        const std::size_t tokenWidth = 14
    ){
        ai::saveMatrix(
            filename,
            matrix,
            false,
            comment,
            type,
            delimiter,
            tokenWidth
        );
    }

    /// \todo Add description. Add tests
    template<typename T>
    INLINE void saveVector(
        const std::string filename,
        const std::vector <T> vector,
        std::string comment = std::string(),
        std::string type = std::string("text"),
        std::string delimiter = std::string("\n")
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

        output << prefix;

        const std::size_t lastIndex = vector.size() - 1;

        for(std::size_t i = 0; i < lastIndex; ++i){
            output << vector[i] << delimiter;
        }

        output << vector[lastIndex] << suffix;
    }

    /// \todo Add description. Add tests
    template<typename T>
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

        output << line;
    }

    /// \todo Add description. Add tests
    template<typename T>
    INLINE bool saveA3R(
        const std::string filename,
        std::vector< std::vector<T> > positions,
        const double radius = 1
    ){
        const std::size_t numberOfParticles = positions.size();

        const int integerNumberOfParticles = (int) numberOfParticles;

        std::ofstream a3r(filename, std::ios::binary | std::ios::out);

        const int startByte = 36;
        const int futureValue = 0;

        const int intSize = 4;
        const int floatSize = 4;
        const int doubleSize = 8;

        if(sizeof(int) != intSize){
            throw std::runtime_error(
                ai::string("int size is ") + ai::string(sizeof(int)) 
                + ai::string(" instead of ") + ai::string(intSize) 
            );
        }
        if(sizeof(float) != floatSize){
            throw std::runtime_error(
                ai::string("float size is ") + ai::string(sizeof(float)) 
                + ai::string(" instead of ") + ai::string(floatSize) 
            );
        }
        if(sizeof(double) != doubleSize){
            throw std::runtime_error(
                ai::string("double size is ") + ai::string(sizeof(double)) 
                + ai::string(" instead of ") + ai::string(doubleSize) 
            );
        }

        a3r.write("a3r\0", 4);
        a3r.write((char*) &integerNumberOfParticles, intSize);
        a3r.write((char*) &startByte, intSize);
        ///\TODO print version
        a3r.write("AiLib 1.1.0\0", 12);
        a3r.write((char*) &radius, doubleSize);
        a3r.write((char*) &futureValue, intSize);

        if(2 == positions[0].size()){
            for(std::size_t i = 0; i < numberOfParticles; ++i){
                float x = (float) positions[i][0];
                float y = (float) positions[i][1];
                float z = 0.;

                a3r.write((char*) &x, floatSize);
                a3r.write((char*) &y, floatSize);
                a3r.write((char*) &z, floatSize);
            }
        }else{
            if(3 == positions[0].size()){
                for(std::size_t i = 0; i < numberOfParticles; ++i){
                    float x = (float) positions[i][0];
                    float y = (float) positions[i][1];
                    float z = (float) positions[i][2];

                    a3r.write((char*) &x, floatSize);
                    a3r.write((char*) &y, floatSize);
                    a3r.write((char*) &z, floatSize);
                }
            }else{
                return false;
            }
        }

        a3r.close();

        return true;
    }

    /// \} End of SaveFunctions Group

    /// \defgroup FileFunctions File Functions
    /// \brief Functions providing the ability to check files and folders
    /// \details Group of functions that checks and analyzes folders and files
    /// \{

    /// \fn bool folderExists(const std::string name);
    /// \brief Checks if folder exists
    /// \details This function checks if the given directory actually 
    /// exists
    /// \param name Path to the folder
    /// \return True if folder exists, false otherwise
    /// \todo Add tests
    INLINE bool folderExists(const std::string name){
        struct stat buffer;

        return 0 == stat(name.c_str(), &buffer);
    }

    /// \todo Add description. Add tests
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

        return count;
    }

    #if defined(DIRENT_SUPPORT)
        /// \todo Add description. Add tests
        INLINE std::vector<std::string> listFilesWithExtension(
            const std::string path,
            const std::string extension,
            const std::string prefix = std::string()
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

            return files;
        }
    #endif

    /// \} End of FileFunctions Group

    #if defined(SHELL_SUPPORT)
        /// \defgroup ShellFunctions Shell Functions
        /// \brief Functions providing shell support
        /// \details Group of functions that will help you to interact with shell
        /// and other programs
        /// \{

        /// \todo Add description. Add tests. Add more options to bufferSize
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
/// \} End of Main Group

#if defined AI_FUTURE
    /// \brief Functions to be added in future releases
    namespace ai{
        inline void getWiseElement2(
            std::vector< std::vector<double> > &a,
            std::vector< std::vector<double> > &b,
            std::vector< std::vector<double> > &c
        ){
            std::size_t length = a.size();
    
            for(std::size_t i = 0; i < length; ++i){
                c[i][0] = a[i][0] * b[i][0] - a[i][1] * b[i][1];
                c[i][1] = a[i][0] * b[i][1] + a[i][1] * b[i][0];
            }
        }

        inline void conjugate2(std::vector< std::vector<double> > &vector){
            std::size_t length = vector.size();
    
            for(std::size_t i = 0; i < length; ++i){
                vector[i][1] = -vector[i][1];
            }
        }

        inline void fft2(std::vector< std::vector<double> > &vector){
            std::size_t k = vector.size();
            std::size_t j = 0;
            std::size_t n = 0;
    
            const double length = (double) k;
    
            double thetaT = 3.14159265358979 / length;
            double swap0 = 0.;
            double swap1 = 0.;
            double T0 = 1.;
            double T1 = 0.;
            double phiT0 = cos(thetaT);
            double phiT1 = -sin(thetaT);
    
            while(1 < k){
                n = k;
        
                k >>= 1;
        
                swap0 = phiT0;
                swap1 = phiT1;
        
                phiT0 = swap0 * swap0 - swap1 * swap1;
                phiT1 = 2. * swap0 * swap1;
        
                T0 = 1.;
                T1 = 0.;
        
                for(std::size_t l = 0; l < k; ++l){
                    for(std::size_t i = l; i < length; i += n){
                        j = i + k;
                
                        swap0 = vector[i][0] - vector[j][0];
                        swap1 = vector[i][1] - vector[j][1];
                
                        vector[i][0] += vector[j][0];
                        vector[i][1] += vector[j][1];
                
                        vector[j][0] = swap0 * T0 - swap1 * T1;
                        vector[j][1] = swap0 * T1 + swap1 * T0;
                    }
            
                    swap0 = T0;
            
                    T0 = swap0 * phiT0 - T1 * phiT1;
                    T1 = swap0 * phiT1 + T1 * phiT0;
                }
            }
    
            std::size_t m = (std::size_t) log2(length);
    
            for(std::size_t i = 0; i < length; ++i){
                j = i;
        
                j = (((j & 0xaaaaaaaa) >> 1) | ((j & 0x55555555) << 1));
                j = (((j & 0xcccccccc) >> 2) | ((j & 0x33333333) << 2));
                j = (((j & 0xf0f0f0f0) >> 4) | ((j & 0x0f0f0f0f) << 4));
                j = (((j & 0xff00ff00) >> 8) | ((j & 0x00ff00ff) << 8));
                j = ((j >> 16) | (j << 16)) >> (32 - m);
        
                if(j > i){
                    swap0 = vector[i][0];
                    swap1 = vector[i][1];
            
                    vector[i][0] = vector[j][0];
                    vector[i][1] = vector[j][1];
            
                    vector[j][0] = swap0;
                    vector[j][1] = swap1;
                }
            }
        }

        inline void ifft2(std::vector< std::vector<double> > &vector){
            const double length = (double) vector.size();
    
            conjugate2(vector);
    
            fft2(vector);
    
            for(std::size_t i = 0; i < length; ++i){
                vector[i][0] /= length;
            }
        }
        
        
        INLINE bool createFolder(const std::string name);

        template<typename T>
        INLINE bool readA3R(
            const std::string filename,
            std::vector< std::vector<T> > &positions,
            double &radius
        );

        template<typename T>
        INLINE bool readA3R(
            const std::string filename,
            std::vector< std::vector<T> > &positions
        );

        template<typename T>
        INLINE bool readXYZ(
            const std::string filename,
            std::vector< std::vector<T> > &positions
        );

        template<typename T>
        INLINE bool saveXYZ(
            const std::string filename,
            std::vector< std::vector<T> > &positions
        );

        INLINE void saveLog(
            const std::string filename,
            std::string &log,
            const bool timestamp = false
        );

        INLINE void saveLog(
            const std::string filename,
            std::vector<std::string> &logs,
            const bool timestamp = false
        );

        template<typename T>
        INLINE void multiplicate(
            std::vector< std::vector<T> > &left,
            std::vector< std::vector<T> > &right,
            std::vector< std::vector<T> > &result,
        );

        template<typename T>
        INLINE void multiplicate(
            std::vector< std::vector<T> > &left,
            std::vector<T> &right,
            std::vector<T> &result,
        );

        template<typename T>
        INLINE void multiplicate(
            std::vector<T> &left,
            std::vector<T> &right,
            std::vector<T> &result,
        );
    }
#endif

#endif