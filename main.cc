#include "ai.hh"

int main(){
    ai::printLine(
        ai::string("This is AiLibrary v")
        + ai::getVersion()
        + ai::string(", welcome!")
    );
    
    return 0;
}