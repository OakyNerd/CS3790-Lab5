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

tokenVec tokenize(const string &str, char delim){
    tokenVec tokens;
    stringstream ss(str);
    string token;

    while(getline(ss, token, delim)){
        tokens.push_back(token);
    }
    return tokens;
}

void addVectors(intArr &a, intArr &b, bool change){
    //Add vector a to vector b and set a to all 0
    for(int i = 0; i < a.size(); i++){
        b[i] += a[i];
        if(change){
            a[i] = 0;
        }
    }
}

void subtractVectors(intArr &a, intArr &b, bool change){
    //Subtract vector a from vector b and set a to all 0
    for(int i = 0; i < a.size(); i++){
        b[i] -= a[i];
        if(change){
            a[i] = 0;
        }
    }
}

bool compareVectors(intArr a, intArr b){
     //Return true if a < b OR if a == b. false if -1 if a > b

    //This method works under the assumption the vectors are the same length

    for(int i = 0; i < a.size(); i++){
        if(a[i] > b[i]){
            return false;
        }
    }
    return true;
}

bool safetyAlgorithm(intArr available, intMat needMatrix, intMat &allocationMatrix){

    intArr work = available;
    vector<bool> finish(needMatrix.size(), false);

    for(int i = 0; i < needMatrix.size(); i++){
        if(!finish[i] && compareVectors(needMatrix[i], work)){
            //Allocate it's resources to work
            addVectors(allocationMatrix[i], work, false);
            finish[i] = true;
        }
    }

    for(int i = 0; i < finish.size(); i++){
        if(finish[i] == false){
            return false; //Unsafe state
        }
    }

    return true;
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