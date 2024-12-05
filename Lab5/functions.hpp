#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

/*Include statements*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

/*Using statements*/

using namespace std;
using intArr = vector<int>;
using intMat = vector<intArr>;
using tokenVec = vector<string>;

/*Function declarations*/

tokenVec tokenize(const string &str, char delim); //Generic method for seperating tokens because I don't wanna write mine anymore boss
void dumpVec(intArr v, bool m);
void dumpMatrix(intMat m);
void dumpData(intMat maxMatrix, intMat allocationMatrix, intMat needMatrix, intArr availableVector);
void addVectors(intArr &a, intArr &b);
void subtractVectors(intArr &a, intArr &b);
bool compareVectors(intArr a, intArr b);
bool safetyAlgorithm(intArr work, intMat allocation, intArr request); //Safety algorithm
void bankersAlgorithm(int m, int n, intMat maxMatrix, intArr availableVector); //Rest of the algorithm

#endif