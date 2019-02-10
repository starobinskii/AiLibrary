#include <ai>

/// \file style.cc
/// \author Egor Starobinskii
/// \date 07 Feb 2018
/// \brief A short example of using AiLibrary styling and interface functions
/// \see https://github.com/starobinskii/AiLibrary

int main(){
    ai::clearScreen();
    
    std::cout << "Here are some styles available." << std::endl << std::endl;
    
    ai::printAllStyles();
    
    std::cout << std::endl << "In case styles are not supported, "
        << "just clear 'em! No bad feelings here." << std::endl << std::endl;
    
    ai::clearStyles();
    ai::printAllStyles();
    
    std::cout << std::endl << "Progress bar is here too." << std::endl;
    
    ai::showProgressBar(1.);
    
    std::cout << std::endl;
    
    return 0;
}