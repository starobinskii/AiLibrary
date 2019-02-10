#include <ai>

/// \file debug.cc
/// \author Egor Starobinskii
/// \date 07 Feb 2018
/// \brief A short example of using AiLibrary for debugging
/// \see https://github.com/starobinskii/AiLibrary

int main(){
    double testVariable1 = 1.00001;
    double testVariable2 = 0.99999;
    
    std::size_t count = std::pow(10, 6);
    
    ai::printMarker();
    
    for(std::size_t i = 0; i < count; ++i){
        testVariable1 *= 1.00001;
    }
    
    PRINT_LINE();
    
    for(std::size_t i = 0; i < count; ++i){
        testVariable2 *= 0.99999;
    }
    
    ai::printMarker();
    
    std::cout << STRINGIFY(testVariable1) << " = " << testVariable1 << "." 
        << std::endl;
    
    std::cout << STRINGIFY(testVariable2) << " = " << testVariable2 << "." 
        << std::endl;
    
    return 0;
}