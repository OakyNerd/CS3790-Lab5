#include "functions.hpp"

void dumpVec(intArr v, bool m){
    for(int i = 0; i < v.size(); i++) cout << ((i == 0)? "(" + to_string(v[i]): to_string(v[i])) << ((i == v.size()-1)? ")": ", ");
    if(!m) cout << endl;
}

void dumpMatrix(intMat m){
    for(int i = 0; i < m.size(); i++){
        if(i == 0) cout << "[";
        dumpVec(m[i], true);
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
    dumpVec(availableVector, false);

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

void addVectors(intArr &a, intArr &b){
    //Add vector a to vector b
    for(int i = 0; i < a.size(); i++){
        b[i] += a[i];
    }
}

void subtractVectors(intArr &a, intArr &b){
    //Subtract vector a from vector b
    for(int i = 0; i < a.size(); i++){
        b[i] -= a[i];
    }
}

bool vectorIsZero(intArr v){
    for(int i = 0; i < v.size(); i++){
        if(v[i] != 0){
            return false;
        }
    }
    return true;
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

bool safetyAlgorithm(intArr work, intMat allocation, intArr request){

    //Let work and finish be vectors of size m and n respectively
    //We pass in a copy of available to be our work vector
    vector<bool> finish(allocation.size(), false);
    for(int i = 0; i < finish.size(); i++){
        if(vectorIsZero(allocation[i])){
            finish[i] = true;
        }
    }

    for(int i = 0; i < finish.size(); i++){
        if(!finish[i] && compareVectors(request, work)){
            addVectors(allocation[i], work); //Add allocation to work
            finish[i] = true;
        }
    }

    for(int i = 0; i < finish.size(); i++){
        if(!finish[i]) return false;
    }

    return true;
    
}

void bankersAlgorithm(int m, int n, intMat maxMatrix, intArr availableVector){

    /*Create other two vectors*/

    intMat allocationMatrix(n, intArr(m, 0)); //Initialize all to 0 as nothing has been allocated
    intMat needMatrix = maxMatrix; //Creates a copy as resources haven't been allocated yet

    while(true){

        /*Prompt user to select a process*/
        
        int proc;
        intArr reqVec;

        while(true){

            cout << "Enter process number: ";
            cin >> proc;

            if(proc > n){
                cout << "Invalid process. Try again.\n";
            }else{
                break;
            }

            cin.clear();
            while (cin.get() != '\n') 
            {
                continue;
            }

        }

        if(proc < 0){
            break;
        }

        cin.clear();
        while (cin.get() != '\n') 
        {
            continue;
        }

        intArr requestVector;
        int num;

        cout << "Enter request vector: ";
        for(int i = 0; i < m; i++){
            cin >> num;
            requestVector.push_back(num);
        }

        cout << "Process " << proc << " with request vector ";
        dumpVec(requestVector, false);

        //Now the fun begins

        //Check if Request <= Need[i]
            //If not then DENY - Exceeded maximum claim
        //Check if Request <= Available
            //If not then DENY - Not enough resources available

        if(!compareVectors(requestVector, needMatrix[proc])){
            cout << "Denied - Exceeded Maximum Claim\n";
            //dumpData(maxMatrix, allocationMatrix, needMatrix, availableVector);
        }else if(!compareVectors(requestVector, availableVector)){
            cout << "Denied - Not Enough Resources Available\n";
            //dumpData(maxMatrix, allocationMatrix, needMatrix, availableVector);
        }else{

            //If both are true SIMULATE granting the request

            //Available = Available - Request
            //Allocation[i] = Allocation[i] + Request
            //Need[i] = Need[i] - Request

            subtractVectors(requestVector, availableVector);
            addVectors(requestVector, allocationMatrix[proc]);
            subtractVectors(requestVector, needMatrix[proc]);

            //dumpData(maxMatrix, allocationMatrix, needMatrix, availableVector);

            //If the system remains in a safe state, grant. Else, revert and deny.

            if(safetyAlgorithm(availableVector, allocationMatrix, requestVector)){
                //Keep the changes and grant
                cout << "Granted\n";
            }else{
                //Revert the changes and Deny - System Left In Unsafe State
                addVectors(requestVector, availableVector);
                subtractVectors(requestVector, allocationMatrix[proc]);
                addVectors(requestVector, needMatrix[proc]);
                cout << "Denied - System Left In Unsafe State\n";
            }

        }

        dumpData(maxMatrix, allocationMatrix, needMatrix, availableVector);


    }

    dumpData(maxMatrix, allocationMatrix, needMatrix, availableVector);

}