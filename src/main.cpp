#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){

    // just a note that the first argument is the path of the executable itself 
    // we need the name of the file thats passed as the arg `


    if(argc != 2){
        cerr << "Error: Invalid number of arguments." << endl;
        cerr << "Correct Usage: " << argv[0] << " <filename.hy>" << endl;
        return EXIT_FAILURE;
    }


    // cout << "File name: " << argv[1] << endl;


    // great now lets actually read the file

    fstream input(argv[1], ios::in); // ios stands for input/output stream, in this case we are opening the file for reading (input)
    
    stringstream contents;
    contents << input.rdbuf(); // read the file into the stringstream, the entire file is in this now 

    input.close(); // close the file, we have the contents in the stringstream now


    string contents_str = contents.str(); // convert the stringstream to a string

    cout << "Contents of the file: " << endl;
    cout << contents_str << endl; // print the contents of the file



    return EXIT_SUCCESS;
}


