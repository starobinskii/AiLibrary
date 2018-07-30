#pragma once

#include <array>
#include <cmath>
#include <chrono>
#include <memory>
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

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #include "Include/dirent/dirent.h"
#else
    #include <dirent.h>
#endif

namespace ai{
    /*/ **************************************************************** /*/

    inline std::string getVersion(){
        return "1.1.0";
    }


    /*/ **************************************************************** /*/

    template<typename T>
    std::string string(const T value){
        std::ostringstream stream;

        stream << value;

        return stream.str();
    }

    /*/ **************************************************************** /*/

    inline std::size_t counter(std::size_t value = 0){
        static std::size_t count = 0;

        if(0 != value){
            count = value;
        }

        ++count;

        return count;
    }

    inline std::string marker(std::size_t value = 0){
        static std::size_t count = 0;

        if(0 != value){
            count = value;
        }

        ++count;

        return "Marker #" + ai::string(count);
    }

    inline void printMarker(std::size_t value = 0){
        std::cout << marker(value) << std::endl;
    }

    /*/ **************************************************************** /*/

    template<typename T>
    T sign(const T a){
        if(0 == a){
            return (T) 0;
        }

        return copysign(1, a);
    }

    template<typename T>
    T min(const T a, const T b){
        if(a > b){
            return b;
        }

        return a;
    }

    template<typename T>
    T max(const T a, const T b){
        if(a < b){
            return b;
        }

        return a;
    }

    template<typename T>
    T min(const std::vector<T> input){
        T minimum = input[0];
        
        for(std::size_t i = 1; i < input.size(); ++i){
            minimum = ai::min(minimum, input[i]);
        }
        
        return minimum;
    }

    template<typename T>
    T max(const std::vector<T> input){
        T maximum = input[0];
        
        for(std::size_t i = 1; i < input.size(); ++i){
            maximum = ai::max(maximum, input[i]);
        }
        
        return maximum;
    }

    template<typename T>
    T min(const std::vector< std::vector<T> > input){
        T minimum = input[0][0];

        for(std::size_t i = 0; i < input.size(); ++i){
            for(std::size_t j = 0; j < input[0].size(); ++j){
                minimum = ai::min(minimum, input[i][j]);
            }
        }

        return minimum;
    }

    template<typename T>
    T max(const std::vector< std::vector<T> > input){
        T maximum = input[0][0];

        for(std::size_t i = 0; i < input.size(); ++i){
            for(std::size_t j = 0; j < input[0].size(); ++j){
                maximum = ai::max(maximum, input[i][j]);
            }
        }

        return maximum;
    }

    /*/ **************************************************************** /*/

    inline std::chrono::high_resolution_clock::time_point time(){
        return std::chrono::high_resolution_clock::now();
    }

    inline double duration(
        const std::chrono::high_resolution_clock::time_point start,
        const std::chrono::high_resolution_clock::time_point finish,
        const std::string scale = std::string("ms")
    ){
        if(std::string("s") == scale){
            return (double) std::chrono::duration_cast
                <std::chrono::seconds> (finish - start).count();
        }

        if(std::string("us") == scale){
            return (double) std::chrono::duration_cast
                <std::chrono::microseconds> (finish - start).count();
        }

        return (double) std::chrono::duration_cast
            <std::chrono::milliseconds> (finish - start).count();
    }

    /*/ **************************************************************** /*/

    inline bool hasPrefix(const std::string &str, const std::string &prefix){
        return str.size() >= prefix.size()
            && 0 == str.compare(0, prefix.size(), prefix);
    }

    inline bool hasSuffix(const std::string &str, const std::string &suffix){
        return str.size() >= suffix.size() &&
            str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
    }

   inline bool contains(
       std::string text,
       const std::string &substring
   ){
       return std::string::npos != text.find(substring);
   }

    inline std::string replace(
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

    /*/ **************************************************************** /*/

    inline std::string parseParameter(
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

    template<typename T>
    inline void assignFromVectorByIntervalCondition(
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

    template<typename T>
    inline void assignFromVectorByIntervalCondition(
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

    inline bool assignBooleanParameter(
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

    inline bool assignCharParameter(
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

    inline bool assignStringParameter(
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

    template<typename T>
    inline bool assignParameter(
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

    inline bool assignAbsDoubleParameter(
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

    /*/ **************************************************************** /*/

    inline void showProgressBar(
        double progress,
        const std::size_t screenWidth = 80
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

    inline void printLine(
        const std::string line,
        const std::size_t screenWidth = 80
    ){
        std::cout << "\r" << std::setw(screenWidth) << std::left << line << std::endl;
    }

    /*/ **************************************************************** /*/

    template<typename T>
    inline void parseFileInMatrix(
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

    template<typename T>
    inline void parseFileInVector(
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

    inline void parseFileIntoString(
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

    template<typename T>
    void accumulateFileInMatrix(
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

    template<typename T>
    void accumulateFileInVector(
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

    /*/ **************************************************************** /*/

    template<typename T>
    inline void printMatrix(
        const std::vector<std::vector <T> > matrix,
        const int precision = 5
    ){
        std::cout << std::scientific;
        std::cout.precision(precision);

        if(1 > matrix.size()){
            throw std::runtime_error(
                ai::string("Exception while printing the matrix: ")
                + ai::string("size should be at least 1.") 
            );
        }

        std::cout << "Matrix[" << matrix.size()
            << "x" << matrix[0].size() << "] = {" << std::endl;
        
        for(const std::vector<T> &vector : matrix){
            std::size_t lastIndex = vector.size() - 1;

            for(std::size_t i = 0; i < lastIndex; ++i){
                std::cout << vector[i] << ", ";
            }
            std::cout << vector[lastIndex] << std::endl;
        }

        std::cout << "}[" << matrix.size() 
            << "x" << matrix[0].size() << "]" << std::endl;
    }

    template<typename T>
    inline void printVector(
        const std::vector<T> vector,
        const int precision = 5
    ){
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

    /*/ **************************************************************** /*/

    template<typename T>
    inline void saveMatrix(
        const std::string filename,
        const std::vector<std::vector <T> > matrix,
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

        for(const std::vector<T> &row : matrix){
            output << prefix;
            
            const std::size_t lastIndex = row.size() - 1;

            for(std::size_t i = 0; i < lastIndex; ++i){
                output << std::setw(tokenWidth) << row[i] << delimiter;
            }

            output << std::setw(tokenWidth) << row[lastIndex] << suffix << std::endl;
        }
        
        output << suffix;
    }

    template<typename T>
    inline void saveVector(
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

    template<typename T>
    inline void saveLine(
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

    template<typename T>
    inline bool saveA3R(
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

    /*/ **************************************************************** /*/

    inline bool folderExists(const std::string name){
        struct stat buffer;

        return 0 == stat(name.c_str(), &buffer);
    }

    inline std::size_t countLinesInFile(
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

    inline std::vector<std::string> listFilesWithExtension(
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
                if(DT_REG == ent->d_type && hasSuffix(ent->d_name, extension)){
                    files.push_back(prefix + ent->d_name);
                }
            }

            closedir(dir);
        }

        return files;
    }

    /*/ **************************************************************** /*/

    inline std::string execute(const std::string command){
        std::array<char, 128> buffer;

        std::string result;

        std::shared_ptr<FILE> pipe(popen(command.c_str(), "r"), pclose);

        if(!pipe){
            throw std::runtime_error(
                ai::string("Exception while executing the command: ")
                + command
            );
        }

        while(!feof(pipe.get())){
            if(nullptr != fgets(buffer.data(), 128, pipe.get())){
                result += buffer.data();
            }
        }

        return result;
    }
}