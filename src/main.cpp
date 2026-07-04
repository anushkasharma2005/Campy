#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>


// Define the different types of tokens that can be recognized by the lexer
enum class TokenType {
    _return, 
    int_lit,
    semi   
};

struct Token {
    TokenType type;
    std::optional<std::string> value;
};



int main(int argc, char* argv[]){

    // just a note that the first argument is the path of the executable itself 
    // we need the name of the file thats passed as the arg `
    if(argc != 2){
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Correct Usage: " << argv[0] << " <filename.hy>" << std::endl;
        return EXIT_FAILURE;
    }


    // cout << "File name: " << argv[1] << endl;
    // great now lets actually read the file
    // ios stands for input/output stream, in this case we are opening the file for reading (input)
    std::fstream input(argv[1], std::ios::in); 
    std::stringstream contents;
    // read the file into the stringstream, the entire file is in this now 
    contents << input.rdbuf();

    input.close();

    // convert the stringstream to a string
    std::string contents_str = contents.str(); 

    std::cout << "Contents of the file: " << std::endl;
    std::cout << contents_str << std::endl; 


    return EXIT_SUCCESS;
}


