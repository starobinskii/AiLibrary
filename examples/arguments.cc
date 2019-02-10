#include <ai>

/// \file arguments.cc
/// \author Egor Starobinskii
/// \date 07 Feb 2018
/// \brief A short example of using AiLibrary to read command line parameters
/// \see https://github.com/starobinskii/AiLibrary

void functionToCall(const double parameter){
    std::cout << "Hello from the function! Your parameter is " 
        << parameter << "." << std::endl;
}

int main(const int argc, const char *argv[]){
    double parameter = 0;
    
    for(int i = 1; i < argc; ++i){
        if(
            std::string("-h") == std::string(argv[i])
            || std::string("--help") == std::string(argv[i])
        ){
            std::cout << "usage: arguments [options]"
                << std::endl
                << "    -h  --help                print this usage and exit"
                << std::endl << std::endl
                << "    --parameter=<value>       some parameter value "
                << "[double]"
                << std::endl;
            
            return 0;
        }
        
        if(
            ai::assignParameter(argv[i], "--parameter=", parameter)
        ){
            continue;
        }
    }
    
    functionToCall(parameter);
    
    return 0;
}