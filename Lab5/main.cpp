#include "functions.hpp"

int main(int argc, char** argv){

    /*Read data from a file*/

    int n, m;

    //n = number of processes (rows)
    //m = number of resource types (columns)

    ifstream inputFile(argv[1], ifstream::in);

    if(!inputFile.is_open()){
        cout << "Error opening file.\n";
        return 1;
    }

    string line;
    tokenVec tokens;

    //First line will have our n and m
    getline(inputFile, line);
    //Then we seperate tokens
    tokens = tokenize(line, ' ');

    n = stoi(tokens[0]);
    m = stoi(tokens[1]);

    //Make our matrices and arrays

    intMat maxMatrix(n, intArr(m, 0));
    intArr availableVector(m, 0);

    //We read n rows for our max matrix
    for(int i = 0; i < n; i++){
        getline(inputFile, line);
        //Then we seperate tokens
        tokens = tokenize(line, ' ');
        
        for(int j = 0; j < tokens.size(); j++){
            maxMatrix[i][j] = stoi(tokens[j]);
        }
    }

    //Then our last line is the available vector
    getline(inputFile, line);
    //Then we seperate tokens
    tokens = tokenize(line, ' ');

    inputFile.close(); //Close my file as I'm done reading information

    // if(tokens.size() != m){
    //     return 1;
    // }

    for(int i = 0; i < tokens.size(); i++){
        availableVector[i] = stoi(tokens[i]);
    }

    /*Pass file parameters into main method for bankers algorithm*/

    bankersAlgorithm(m, n, maxMatrix, availableVector);

    return 0;
}