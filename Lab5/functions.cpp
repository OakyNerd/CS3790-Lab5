#include "functions.hpp"

void dumpVec(intArr v){
    for(int i = 0; i < v.size(); i++) cout << ((i == 0)? "(" + to_string(v[i]): to_string(v[i])) << ((i == v.size()-1)? ")\n": ", ");
}

void dumpMatrix(intMat m){
    for(int i = 0; i < m.size(); i++){
        if(i == 0) cout << "[";
        dumpVec(m[i]);
        if( i == m.size()-1){
            cout << "]\n\n";
        }else{
            cout << ",\n";
        }
    }
}

void dumpData(intMat maxMatrix, intMat allocationMatrix, intMat needMatrix, intArr availableVector){

    cout << "Max Matrix:\n";
    dumpMatrix(maxMatrix);

    cout << "Allocation Matrix:\n";
    dumpMatrix(allocationMatrix);

    cout << "Need Matrix:\n";
    dumpMatrix(needMatrix);

    cout << "Available Vector:\n";
    dumpVec(availableVector);

}

tokenVec seperateTokens(string &s){
    tokenVec tokens;

    for(auto i: s){

    }

}

void bankersAlgorithm(int m, int n, intMat maxMatrix, intArr availableVector){

    /*Create other two vectors*/

    intMat allocationMatrix(m, intArr(n, 0)); //Initialize all to 0 as nothing has been allocated
    intMat needMatrix = maxMatrix; //Creates a copy as resources haven't been allocated yet

    while(true){

        /*Prompt user to select a process*/
        
        int proc;
        intArr reqVec;

        cout << "Enter process number: ";
        cin >> proc;

        if(proc == -1){
            break; /*Break out of the while-loop*/
        }

        /*Prompt user for the request vector for that process*/



        /*Tell the user the request is acceptable/not acceptable*/



        /*If it is acceptable, tell the user if the request is denied (and why) or accepted*/




    }

    dumpData(maxMatrix, allocationMatrix, needMatrix, availableVector);

}