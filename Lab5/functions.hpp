#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

/*Include statements*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

/*Using statements*/

using namespace std;
using intArr = vector<int>;
using intMat = vector<intArr>;
using tokenVec = vector<string>;

/*Function declarations*/

void dumpVec(intArr v);
void dumpMatrix(intMat m);
void dumpData(intMat maxMatrix, intMat allocationMatrix, intMat needMatrix, intArr availableVector);
void bankersAlgorithm(int m, int n, intMat maxMatrix, intArr availableVector);

#endif