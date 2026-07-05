#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <vector>


// Define the different types of tokens that can be recognized by the lexer
enum class TokenType {
    _return, 
    int_lit,
    semi   
};

struct Token {
    TokenType type;
    std::optional<std::string> value {};
};


// a function that tokenizes the input string and returns a vector of tokens
std::vector<Token> tokenize(const std::string& input) {
    std::string buf = "";
    std::vector<Token> tokens;

    int i=0;

    for (int i = 0; i < input.size(); i++) {
        char c = input.at(i);
        // std::cout << "Char: " << c << std::endl;

        if(std::isalpha(c)){
            buf.push_back(c);
            i++;

            //  std::cout << "Buf: " << buf << std::endl;
            // std::cout << input.size(); 

            while(i < input.size() && std::isalpha(input.at(i))){
                buf.push_back(input.at(i));
                i++;
                // std::cout << isalpha(input.at(i)) << std::endl; 
            }

            i--;


            if(buf == "return"){
                tokens.push_back({Token{TokenType::_return, std::nullopt}});
                buf.clear();
                continue;
            } else {
                std::cerr << "You messed up mate! Unrecognized token lala1: " << buf << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else if(std::isspace(c)){
            continue;
        }
        else if(std::isdigit(c)){
            buf.push_back(c);
            i++;
            while(std::isdigit(input.at(i))){
                buf.push_back(input.at(i));
                i++;
            }

            i--;
            tokens.push_back({.type = TokenType::int_lit, .value = buf});
            buf.clear();
            continue;
        }
        else if(c == ';'){
            tokens.push_back({.type =TokenType::semi});
        }
        else {
            std::cerr << "You messed up mate! Unrecognized token lala2: " << c << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    return tokens;
}


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
    // std::cout << contents_str << std::endl; 
    
    
    std::vector<Token> tokens = tokenize(contents_str);


    for (const auto& token : tokens) {
        switch (token.type) {
            case TokenType::_return:
                std::cout << "Token: return" << std::endl;
                break;
            case TokenType::int_lit:
                std::cout << "Token: int_lit, Value: " << token.value.value() << std::endl;
                break;
            case TokenType::semi:
                std::cout << "Token: semi" << std::endl;
                break;
            default:
                std::cerr << "Error: Unrecognized token type." << std::endl;
                return EXIT_FAILURE;
        }
    }


    return EXIT_SUCCESS;
}


