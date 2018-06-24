#pragma once

#include <cmath>
#include <chrono>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <sys/stat.h>

namespace ai{
    /*/ **************************************************************** /*/

    /*/
     * функция, возвращающая версию библиотеки
    /*/
    inline std::string getVersion(){
        return "1.0.0";
    }

    /*/ **************************************************************** /*/

    /*/
     * функция, приводящее значение к типу строки
    /*/
    template<typename T>
    std::string string(const T a){
        std::ostringstream str;

        str << a;

        return str.str();
    }

    /*/
     * функция, возвращающая знак переданного числа (-1, 0, 1)
    /*/
    template<typename T>
    T sign(const T a){
        if(0 == a){
            return (T) 0;
        }

        return copysign(1, a);
    }

    /*/
     * функция, возвращающая максимальное значение в паре
    /*/
    template<typename T>
    T max(const T a, const T b){
        if(a < b){
            return b;
        }

        return a;
    }

    /*/
     * функция, возвращающая максимальное значение в векторе
    /*/
    template<typename T>
    T max(const std::vector<T> input){
        T maximum = input[0];
        
        for(size_t i = 1; i < input.size(); ++i){
            maximum = ai::max(maximum, input[i]);
        }
        
        return maximum;
    }

    /*/
     * функция, возвращающая максимальное значение в матрице
    /*/
    template<typename T>
    T max(const std::vector< std::vector<T> > input){
        T maximum = input[0][0];

        for(size_t i = 0; i < input.size(); ++i){
            for(size_t j = 0; j < input[0].size(); ++j){
                maximum = ai::max(maximum, input[i][j]);
            }
        }

        return maximum;
    }

    /*/ **************************************************************** /*/

    /*/
     * функция, возвращающая текущее время
    /*/
    inline std::chrono::high_resolution_clock::time_point time(){
        return std::chrono::high_resolution_clock::now();
    }

    /*/
     * функция, возвращающая разницу между двумя значениями времени в секундах
    /*/
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

    /*/
     * функция, проверяющая существование директории с указанным адресом
    /*/
    inline bool folderExists(const std::string name){
        struct stat buffer;

        return 0 == stat(name.c_str(), &buffer);
    }

    /*/ **************************************************************** /*/

    /*/
     * функция, проверяющая, начинается ли строка с указанной подстроки
    /*/
    inline bool hasPrefix(const std::string &str, const std::string &prefix){
        return str.size() >= prefix.size()
            && 0 == str.compare(0, prefix.size(), prefix);
    }

   /*/
    * функция, проверяющая, заканчивается ли строка указанной подстрокой
   /*/
    inline bool hasSuffix(const std::string &str, const std::string &suffix){
        return str.size() >= suffix.size() &&
            str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
    }

    /*/
     * функция, присваивающая значение в зависимости от значения указанного
     * параметра
    /*/
    template<typename T>
    inline void assignFromVectorByIntervalCondition(
        T &value,
        const T parameter,
        const std::vector< std::vector<T> > intervals
    ){
        for(size_t i = 0; i < intervals.size(); ++i){
            if(intervals[i][0] <= parameter && parameter <= intervals[i][1]){
                value = intervals[i][2];
                
                return;
            }
        }
    }

    /*/
     * функция, присваивающая пару значений в зависимости от значения указанного
     * параметра
    /*/
    template<typename T>
    inline void assignFromVectorByIntervalCondition(
        T &firstValue,
        T &secondValue,
        const T parameter,
        const std::vector< std::vector<T> > intervals
    ){
        for(size_t i = 0; i < intervals.size(); ++i){
            if(intervals[i][0] <= parameter && parameter <= intervals[i][1]){
                firstValue = intervals[i][1];
                secondValue = intervals[i][2];

                return;
            }
        }
    }

    /*/
     * функция, присваивающая строковое значение в результате парсинга
     * указанного текстового параметра
    /*/
    inline bool assignStringParameter(
        const char *input,
        const std::string name,
        std::string &value
    ){
        std::string parameter = std::string(input);

        if(ai::hasPrefix(parameter, name)){
            parameter = parameter.substr(name.size());
            value = parameter.c_str();

            return true;
        }

        return false;
    }

    /*/
     * функция, присваивающая вещественное значение по модулю в результате
     * парсинга указанного текстового параметра
    /*/
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

    /*/
     * функция, выводящая текстовый индикатор прогресса шириной в 80 символов
    /*/
    inline void showProgressBar(double progress){
        if(1 < progress){
            progress = 1;
        }

        if(0.01 > progress){
            progress = 0;
        }

        int width = progress * 73;

        std::cout << std::fixed;
        std::cout.precision(1);
        std::cout.flush();

        std::cout << "\r" << std::string(width, '=')
            << std::string(73 - width, '-')
            << " " << progress * 100. << "%";
    }

    /*/ **************************************************************** /*/

    /*/
     * функция, выводящая значения строки на экран
    /*/
    inline void printLine(const std::string line){
        std::cout << std::setw(80) << std::left << line << std::endl;
    }

    /*/ **************************************************************** /*/

    /*/
     * функция, считывающая значения из текстового файла в матрицу
    /*/
    template<typename T>
    inline void parseFileInMatrix(
        const std::string filename,
        const char separator,
        std::vector<std::vector <T> > &matrix
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

            std::vector<double> row;

            while(std::getline(stream, token, separator)){
                if(std::istringstream(token) >> value){
                    row.push_back(value);
                }
            }

            matrix.push_back(row);
        }
    }

    /*/
     * функция, считывающая значения из текстового файла в вектор
    /*/
    template<typename T>
    inline void parseFileInVector(
        const std::string filename,
        const char separator,
        std::vector <T> &vector
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

    /*/
     * функция, выводящая значения матрицы на экран
    /*/
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

        std::cout << "Matrix[ " << matrix.size()
            << "x" << matrix[0].size() << "] = {" << std::endl;
        
        for(const std::vector<T> &vector : matrix){
            size_t lastIndex = vector.size() - 1;

            for(size_t i = 0; i < lastIndex; ++i){
                std::cout << vector[i] << ", ";
            }
            std::cout << vector[lastIndex] << std::endl;
        }

        std::cout << "}" << std::endl;
    }

    /*/
     * функция, выводящая значения вектора на экран
    /*/
    template<typename T>
    inline void printVector(
        const std::vector<T> vector,
        const int precision = 5
    ){
        size_t lastIndex = vector.size() - 1;

        std::cout << std::scientific;
        std::cout.precision(precision);
        
        std::cout << "Vector[ " << vector.size() << "] = {" << std::endl;

        for(size_t i = 0; i < lastIndex; ++i){
            std::cout << vector[i] << ", ";
        }
        std::cout << vector[lastIndex] << std::endl;

        std::cout << "}" << std::endl;
    }

    /*/
     * функция, сохраняющая значения матрицы в текстовый файл
    /*/
    template<typename T>
    inline void saveMatrix(
        const std::string filename,
        const std::vector<std::vector <T> > matrix,
        std::string comment = std::string()
    ){
        std::ofstream output(filename + "_m.txt");

        if(!output.good()){
            throw std::runtime_error(
                ai::string("Exception while saving the matrix into the file: ") 
                + filename
            );
        }

        if(std::string() != comment){
            output << comment << "\n";
        }

        for(const std::vector<T> &row : matrix){
            const size_t lastIndex = row.size() - 1;

            for(size_t i = 0; i < lastIndex; ++i){
                output << std::setw(14) << row[i] << "\t";
            }

            output << std::setw(14) << row[lastIndex] << std::endl;
        }
    }

    /*/
     * функция, сохраняющая значения вектора в текстовый файл
    /*/
    template<typename T>
    inline void saveVector(
        const std::string filename,
        const std::vector <T> vector,
        std::string comment = std::string()
    ){
        std::ofstream output(filename + "_v.txt");

        if(!output.good()){
            throw std::runtime_error(
                ai::string("Exception while saving the vector into the file: ") 
                + filename
            );
        }

        if(std::string() != comment){
            output << comment << "\n";
        }

        const size_t lastIndex = vector.size() - 1;

        for(size_t i = 0; i < lastIndex; ++i){
            output << vector[i] << "\n";
        }

        output << vector[lastIndex];
    }

    /*/
     * функция, сохраняющая значения текстовой строки в текстовый файл
    /*/
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
}