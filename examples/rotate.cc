#include <ai>

/// \file rotate.cc
/// \author Egor Starobinskii
/// \date 07 Feb 2018
/// \brief A short example of using AiLibrary to rotate square matrix
/// \see https://github.com/starobinskii/AiLibrary

int main(){
    std::vector< std::vector<double> > matrix;
    
    ai::generateRandomMatrix(matrix, 3, 0., 1.);
    
    std::cout << ">> Initial matrix" << std::endl;
    
    ai::printMatrix(matrix);
    
    std::cout << std::endl << ">> Rotate counter-clockwise" << std::endl;
    
    ai::rotateMatrix(matrix);
    
    ai::printMatrix(matrix);
    
    std::cout << std::endl << ">> Rotate back" << std::endl;
    
    ai::rotateMatrix(matrix, true);
    
    ai::printMatrix(matrix);
    
    return 0;
}