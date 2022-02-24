#include "clause.h"

// DFS, the sub-function of Calculate Cn_k
void dfs(int n, int k, int index, vector<int>& path, vector <vector <int> >& res) {
    if (path.size() == k) {
        res.push_back(path);
        return;
    }
    for (unsigned int i = index; i <= n - (k - path.size()) + 1; ++i) {
        path.push_back(i);
        dfs(n, k, i + 1, path, res);
        path.pop_back();
    }
}

// Calculate Cn_k
vector <vector <int> > combine(int n, int k) {
    vector <vector <int> > res;
    if (k <= 0 || n < k) {
        return res;
    }
    vector<int> path;
    dfs(n, k, 1, path, res);
    return res;
}

// Convert four binary values to a decimal value
int Bin_To_Dec(int b, int c, int d, int e) {
    return b * (int)pow(2, 3) + c * (int)pow(2, 2) + d * (int)pow(2, 1) + e * (int)pow(2, 0);
}

vector <vector <int>> ProduceBinComb(int n, int k){
    vector< vector<int> > comb;
    comb = combine(n, k);
    for (auto p = 0; p < int(comb.size()); p++) {
        for (auto q = 0; q < int(comb[p].size()); q++) {
            comb[p][q] -= 1;
            //            cout << comb[p][q] << " ";
        }
        //        cout << endl;
    }

    //    cout << "The number of different combinations for combYi: " << comb.size() << endl;

    vector <int> sizeN(n);
    for (auto p = 0; p < n; p++) {
        sizeN[p] = p;
    }


    // Determine the SOP matrix for combinations
    vector <vector <int>> SOPMat(comb.size(), vector <int>(n, 0));
    for (auto p = 0; p < int(comb.size()); p++) {
        for (auto q = 0; q < int(comb[p].size()); q++) {
            auto findRes = find(sizeN.begin(), sizeN.end(), comb[p][q]);
            int index = findRes - sizeN.begin();
            SOPMat[p][index] = 1;
        }
    }

    // Output the pla format of SOP matrix
    //    cout << "The PLA format of SOP matrix:" << endl;
    //    for (auto p = 0; p < int(SOPMat.size()); p++) {
    //        for (auto q = 0; q < int(SOPMat[p].size()); q++) {
    //            cout << SOPMat[p][q];
    //        }
    //        cout << endl;
    //    }
    //    cout << endl << endl;

    return SOPMat;
}

vector < vector <int> > fenceFamily;
vector <int> path;
//Use an array to record the previous values that need to be output repeatedly during the recursion process
int set[100];

vector < vector <int> > GenerateFence(int gateNum) {

    // Used to determine whether to recurse to the deepest point in the recursion process
    int depth = gateNum, colMax = gateNum, level = gateNum;

    q(gateNum, colMax, 0, level, depth);
    return fenceFamily;
}

//This function represents the use of an integer not greater than m to split n, i is used to represent the length of
// the number of records that already exist in the set array
void q(int n, int m, int i, int level, int k)
{
    if (n == k && n != m)
    {
        //At this time, the recursive stack has returned to the top level of a branch
        //Reset the counter i to 0
        // cout << endl;
        //        for(int j = i; j < level-1; j++){
        //            path.push_back(0);
        //        }
        if (!path.empty()) {
            std::sort(path.begin(), path.end());
            //            featureVecPartition.push_back(path);
            do
            {
                if(path.back() == 1){
                    int flag = 1;
                    for(auto x = 0; x < int(path.size()) - 1; x++){
                        int sum = 0;
                        //                        if(path[x] > 3){
                        //                            flag = 0;
                        //                            break;
                        //                        }
                        for(auto y = x+1; y < int(path.size()); y++){
                            sum = sum + path[y];
                        }
                        if(path[x] > 2 * sum){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 1){
                        fenceFamily.push_back(path);
                    }
                }
            } while (next_permutation(path.begin(), path.end()));
        }
        path.clear();
        i = 0;
    }
    if (n == 1)
    {
        path.push_back(1);
        //        for(int j = i; j < level-1; j++){
        //            path.push_back(0);
        //        }
        // printf("1 ");

        if (!path.empty()) {
            std::sort(path.begin(), path.end());
            //            featureVecPartition.push_back(path);
            do
            {
                if(path.back() == 1){
                    int flag = 1;
                    for(auto x = 0; x < int(path.size()) - 1; x++){
                        int sum = 0;
                        //                        if(path[x] > 3){
                        //                            flag = 0;
                        //                            break;
                        //                        }
                        for(auto y = x+1; y < int(path.size()); y++){
                            sum = sum + path[y];
                        }
                        if(path[x] > 2 * sum){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 1){
                        fenceFamily.push_back(path);
                    }
                }
            } while (next_permutation(path.begin(), path.end()));
        }
        path.clear();
        return;
    }
    else if (m == 1)
    {
        // When m is 1, it means to output n 1s
        for (int i = 0; i < n - 1; i++) {
            // printf("1+");
            path.push_back(1);
        }
        // printf("1 ");
        path.push_back(1);
        //        for(int j = i; j < level-1; j++){
        //            path.push_back(0);
        //        }

        if (!path.empty()) {
            std::sort(path.begin(), path.end());
            //featureVecPartition.push_back(path);
            do
            {
                if(path.back() == 1){
                    int flag = 1;
                    for(auto x = 0; x < int(path.size()) - 1; x++){
                        int sum = 0;
                        //                        if(path[x] > 3){
                        //                            flag = 0;
                        //                            break;
                        //                        }
                        for(auto y = x+1; y < int(path.size()); y++){
                            sum = sum + path[y];
                        }
                        if(path[x] > 2 * sum){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 1){
                        fenceFamily.push_back(path);
                    }
                }
            } while (next_permutation(path.begin(), path.end()));
        }
        path.clear();
        return;
    }
    if (n < m)
    {
        q(n, n, i, level, k);
    }
    if (n == m)
    {
        //When n is equal to m, it reaches a leaf of this recursive summation. At this time,
        // it needs to output one more space, which means the next output is another leaf
        // printf("%d ", n);
        path.push_back(n);
        //        for(int j = i; j < level-1; j++){
        //            path.push_back(0);
        //        }

        if (!path.empty()) {
            std::sort(path.begin(), path.end());
            // featureVecPartition.push_back(path);
            do
            {
                if(path.back() == 1){
                    int flag = 1;
                    for(auto x = 0; x < int(path.size()) - 1; x++){
                        int sum = 0;
                        //                        if(path[x] > 3){
                        //                            flag = 0;
                        //                            break;
                        //                        }
                        for(auto y = x+1; y < int(path.size()); y++){
                            sum = sum + path[y];
                        }
                        if(path[x] > 2 * sum){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 1){
                        fenceFamily.push_back(path);
                    }
                }
            } while (next_permutation(path.begin(), path.end()));
        }
        path.clear();

        //Before outputting another leaf recursively, output the previously recorded numbers on the leaf together
        for(int j = 0; j < i; j++) {
            // printf("%d+", set[j]);
            path.push_back(set[j]);
        }
        q(n, m - 1, i, level, k);

    }
    if (n > m)
    {
        //If n is greater than m, use m as the decomposition
        // printf("%d+", m);
        path.push_back(m);
        //Record the value of m as the trunk node and increase i
        set[i++] = m;
        //Recursively output the decomposition after m
        q(n - m, m, i, level, k);
        //After the recursion is completed, the array record needs to be backed up by one and back to the previous node
        i--;
        //Execute another branch and output the recorded data before the next recursion
        for (int j = 0; j < i; j++) {
            // printf("%d+", set[j]);
            path.push_back(set[j]);
        }
        //Recursively output another branch situation
        q(n, m - 1, i, level, k);
    }
}


ConstructClause::ConstructClause(int _variableNumber, int _accuracy, int _gate, int _gateCate, int _gateKind, int _N, int _maxFanout, vector <int> _featureVector, vector <vector <vector <int> >> _gateTruthTable, context& c, map <vector <string>, string> _gateLibrary) {
    variableNumber = _variableNumber;
    accuracy = _accuracy;
    gate = _gate;
    gateCate = _gateCate;
    gateKind = _gateKind;
    featureVector = _featureVector;
    N = _N;
    gateTruthTable = _gateTruthTable;
    gateLibrary = _gateLibrary;
    maxFanout = _maxFanout;

    // determine m_i
    maximumfanout = vector <int> (_variableNumber + _accuracy + _gate, 0);
    for(auto i = 0; i < _variableNumber + _accuracy + _gate; i++){
        if(i < _variableNumber + _accuracy){
            maximumfanout[i] = 1;
        }
        else{
            maximumfanout[i] = maxFanout;
        }
    }

    // Determine the values in the truth table for the input variables and input constant coefficients
    X_known = vector < vector < vector <int> > > (_variableNumber + _accuracy, vector <vector <int> > (1, vector <int>((int)pow(2, _variableNumber + _accuracy))));

    // Transform the t-th bit in the truth table into binary values, and assign them to the input variables
    //and input constant coefficients
    for (auto t = 0; t < pow(2, variableNumber + accuracy); t++) {
        auto j = t;
        for (auto i = variableNumber + accuracy - 1; i >= 0; i--) {
            for(auto k = 0; k < 1; k++){
                X_known[i][k][t] = j % 2;
            }
            // X_known[i][1][t] = j % 2;
            //cout << X_known[i][t] << " ";
            j /= 2;
        }
        //cout << endl;
    }

//     // Define the values in the truth table for each gate，and number them sequentially.
    X_unknown = vector < vector <int> >(_gate, vector <int>((int)pow(2, _variableNumber + _accuracy)));
    int Number = 1;
//    cout << "The X_unknown matrix:" << endl;
    for (unsigned int i = 0; i < X_unknown.size(); i++) {
        for (unsigned int j = 0; j < X_unknown[0].size(); j++) {
            X_unknown[i][j] = Number;
//            cout << X_unknown[i][j] << " ";
            Number++;
        }
//        cout << endl;
    }

    // x_iat
    for (unsigned int i = 0; i < gate; i++) {
    	vector < vector <expr> > temp0;
    	temp0.clear();
		for (unsigned int j = 0; j < maxFanout; j++) {
            vector <expr> temp1;
            temp1.clear();
            for(unsigned int k = 0; k < (int)pow(2, variableNumber + accuracy); k++){
                temp1.push_back(c.bool_const(("XUnknown" + std::to_string(i) + "," + std::to_string(j) + "," + std::to_string(k)).c_str()));
            }
			temp0.push_back(temp1);
		}
		X_Unknown_Z3.push_back(temp0);
    }

    // Add output gate index variables, g_hia
    for (unsigned int i = 0; i < variableNumber; i++) {
    	vector < vector <expr> > temp0;
    	temp0.clear();

        vector < vector <expr> > temp0INT;
    	temp0INT.clear();

		for (unsigned int j = 0; j < variableNumber + accuracy + gate; j++) {
            vector <expr> temp1;
            temp1.clear();

            vector <expr> temp1INT;
            temp1INT.clear();

            for(unsigned int k = 0; k < maximumfanout[j]; k++){
                temp1.push_back(c.bool_const(("outputGateIndex" + std::to_string(i) + "," + std::to_string(j)+ "," + std::to_string(k)).c_str()));
                temp1INT.push_back(c.int_const(("outputGateIndex" + std::to_string(i) + "," + std::to_string(j)+ "," + std::to_string(k)).c_str()));
            }
            temp0.push_back(temp1);
            temp0INT.push_back(temp1INT);

		}
		outputGateIndex.push_back(temp0);
        outputGateIndex_INT.push_back(temp0INT);
    }

    // Add output truth table variables, o_ht
    for (unsigned int i = 0; i < variableNumber; i++) {
    	vector <expr> temp;
    	temp.clear();
		for (unsigned int j = 0; j < (int)pow(2, variableNumber + accuracy); j++) {
			temp.push_back(c.bool_const(("outputTB" + std::to_string(i) + "," + std::to_string(j)).c_str()));
		}
		outputTruthTable.push_back(temp);
    }

    for (unsigned int i = 0; i < variableNumber; i++) {
		vector <expr> temp;
		temp.clear();
		for (unsigned int j = 0; j < (int)pow(2, variableNumber + accuracy); j++) {
			temp.push_back(c.int_const(("outputTBInt" + std::to_string(i) + "," + std::to_string(j)).c_str()));
		}
		outputTruthTable_Z3_INT.push_back(temp);
	}

    // Obtain the current largest index
//    cout << "The number of X_unknown:" << Number - 1 << endl;
//    cout << endl << endl;

    AssMatrix = vector < vector <int> >(int(pow(2, _accuracy)), vector <int>((int)pow(2, _variableNumber), -1));

    // Define the selection variables s_ij
    S = vector < vector <int> >(gate, vector<int>(0));
    for (auto i = 0; i < gate; i++) {
        S[i].resize(variableNumber + accuracy + i);
    }

    // Number s_ij sequentially
//    cout << "The S matrix:" << endl;
    for (unsigned int i = 0; i < S.size(); i++) {
        for (unsigned int j = 0; j < S[i].size(); j++) {
            S[i][j] = Number;
//            cout << S[i][j] << " ";
            Number++;
        }
//        cout << endl;
    }

    // s_ija
    for (unsigned int i = 0; i < S.size(); i++) {
    	vector < vector <expr> > temp0;
    	temp0.clear();

        vector < vector <expr> > temp0INT;
    	temp0INT.clear();

		for (unsigned int j = 0; j < S[i].size(); j++) {
            vector <expr> temp1;
            temp1.clear();

            vector <expr> temp1INT;
            temp1INT.clear();

            for(unsigned int k = 0; k < maximumfanout[j]; k++){
                temp1.push_back(c.bool_const(("S" + std::to_string(i) + "," +std::to_string(j)+ "," +std::to_string(k)).c_str()));
                temp1INT.push_back(c.int_const(("S_INT" + std::to_string(i) + "," +std::to_string(j)+ "," +std::to_string(k)).c_str()));
            }
			temp0.push_back(temp1);
            temp0INT.push_back(temp1INT);
		}
		S_Z3.push_back(temp0);
        S_Z3_INT.push_back(temp0INT);
    }

    // Define the local truth table for each gate operator and number them sequentially
    f = vector < vector <int> >(gate, vector <int>((int)pow(2, N)));
//    cout << "The f matrix:" << endl;
    for (unsigned int i = 0; i < f.size(); i++) {
        for (unsigned int j = 0; j < f[i].size(); j++) {
            f[i][j] = Number;
//            cout << f[i][j] << " ";
            Number++;
        }
//        cout << endl;
    }

    // f_iapquv
    for (unsigned int i = 0; i < f.size(); i++) {
    	vector < vector <expr> > temp0;
    	temp0.clear();
		for (unsigned int j = 0; j < maxFanout; j++) {
            vector <expr> temp1;
            temp1.clear();
            for (unsigned int k = 0; k < f[i].size(); k++) {
                temp1.push_back(c.bool_const(("f" + std::to_string(i) + "," + std::to_string(j)+ "," + std::to_string(k)).c_str()));
            }
            temp0.push_back(temp1);
		}
		f_Z3.push_back(temp0);
	}


//     // Define the gate index for each gate and number them sequentially
//     GateIndex = vector < vector <int> >(gate, vector <int>(gateCate));
// //    cout << "The GateIndex matrix:" << endl;
//     for (unsigned int i = 0; i < GateIndex.size(); i++) {
//         for (unsigned int j = 0; j < GateIndex[i].size(); j++) {
//             GateIndex[i][j] = Number;
// //            cout << GateIndex[i][j] << " ";
//             Number++;
//         }
// //        cout << endl;
//     }

    // v_il
    for (unsigned int i = 0; i < gate; i++) {
    	vector <expr> temp;
        temp.clear();

        vector <expr> temp_INT;
    	temp_INT.clear();

		for (unsigned int j = 0; j < gateKind; j++) {
			temp.push_back(c.bool_const(("GateIndex" + std::to_string(i) + "," + std::to_string(j)).c_str()));
            temp_INT.push_back(c.int_const(("GateIndexInt" + std::to_string(i) + "," + std::to_string(j)).c_str()));
		}
		GateIndex_Z3.push_back(temp);
        GateIndex_Z3_INT.push_back(temp_INT);
	}

    // for (unsigned int i = 0; i < gate; i++) {
	// 	vector <expr> temp;
	// 	temp.clear();
	// 	for (unsigned int j = 0; j < gateKind; j++) {
	// 		temp.push_back(c.int_const(("GateIndexInt" + std::to_string(i) + "," + std::to_string(j)).c_str()));
	// 	}
	// 	GateIndex_Z3_INT.push_back(temp);
	// }

    probabilityVec.push_back(81);
    probabilityVec.push_back(27);
    probabilityVec.push_back(27);
    probabilityVec.push_back(9);
    probabilityVec.push_back(27);
    probabilityVec.push_back(9);
    probabilityVec.push_back(9);
    probabilityVec.push_back(3);
    probabilityVec.push_back(27);
    probabilityVec.push_back(9);
    probabilityVec.push_back(9);
    probabilityVec.push_back(3);
    probabilityVec.push_back(9);
    probabilityVec.push_back(3);
    probabilityVec.push_back(3);
    probabilityVec.push_back(1);

//    cout << "The sum number of X_unknown and S and f and GateIndex:" << Number - 1 << endl;
//    cout << endl << endl;
}

// vector <vector <IndexRelation> > ConstructClause::AddAdditionalVariable(context& c, MatInfo IndexMatrix, vector <int> largestCubeVector, vector <int> featureVector, vector <int> toBeAssignedCV1, int coarseGrain1, vector <int> toBeAssignedCV2, int coarseGrain2){

//     vector <vector <IndexRelation> > AllVarRelation;
// //    cout << "Add Y Variables:" << endl;
//     vector <IndexRelation> AllVarRelationYX;

//     // Determine the index of first Y_variable.
//     int p = int(GateIndex.size());
//     int q = int(GateIndex[0].size());
//     int YVarNum = GateIndex[p-1][q-1] + 1;
//     int AddYVarNum = 0;
//     int AddZVarNum = 0;

//     // Traverse Assignment matrix to find the relationship between X_variables and Y_variables.
//     for(auto i = 0; i < int(AssMatrix[0].size()); i++){
//         for(auto j = 0; j < int(AssMatrix.size()); j=j+coarseGrain2){
//             //            if(AssMat[j][i] == -1){
//             vector <int> YvarIndex;

//             // Find the location i in G[i] of columns
//             int columnInGLoc = -1;
//             for(auto p = 0; p < int(IndexMatrix.first.size()); p++){
//                 for(auto q = 0; q < int(IndexMatrix.first[p].size()); q++){
//                     if(IndexMatrix.first[p][q] == i){
//                         columnInGLoc = p;
//                         break;
//                     }
//                 }
//                 if(columnInGLoc == p){
//                     break;
//                 }
//             }

//             // Store the index of Y_variable and its location in G
//             YvarIndex.push_back(YVarNum);
//             YvarIndex.push_back(columnInGLoc);

//             YVariable.push_back(YVarNum);
// //            cout << YVarNum << " ";

//             Y_Variable_Z3.push_back(c.bool_const(("YVariable" + std::to_string(AddYVarNum)).c_str()));

//             // Store corresponding indexes of X_variables
//             vector <int> XVarIndex;
//             for(auto k = i*int(pow(2,accuracy))+j; k < i * int(pow(2,accuracy))+j+coarseGrain2; k++){
//                 int Xindex = X_unknown[gate-1][k];
//                 //                int Xindex = k;
//                 XVarIndex.push_back(Xindex);
//             }

//             IndexRelation RelationYX(YvarIndex, XVarIndex);
//             AllVarRelationYX.push_back(RelationYX);
//             YVarNum++;
//             AddYVarNum++;

//             XVarIndex.clear();
//             YvarIndex.clear();
//             //            }
//         }
//     }

// //    cout << endl << endl;
// //    cout << "Add Z Variables:" << endl;
//     vector <IndexRelation> AllVarRelationZY;
//     vector <IndexRelation> AllVarRelationZX;

//     int ZVarNum = GateIndex[p-1][q-1] + int(YVariable.size()) + 1;
//     // Traverse Assignment matrix to find the relationship between Z_variables and Y_variables.
//     for(auto i = 0; i < int(AssMatrix[0].size()); i++){
//         for(auto j = 0; j < int(AssMatrix.size()); j=j+coarseGrain1){

//             vector <int> ZvarIndex;

//             // Find the location i in G[i] of columns for z variables
//             int columnInGLoc = -1;
//             for(auto p = 0; p < int(IndexMatrix.first.size()); p++){
//                 for(auto q = 0; q < int(IndexMatrix.first[p].size()); q++){
//                     if(IndexMatrix.first[p][q] == i){
//                         columnInGLoc = p;
//                         break;
//                     }
//                 }
//                 if(columnInGLoc == p){
//                     break;
//                 }
//             }

//             // Store the index of Y_variable and its location in G
//             ZvarIndex.push_back(ZVarNum);
//             ZvarIndex.push_back(columnInGLoc);

//             ZVariable.push_back(ZVarNum);
// //            cout << ZVarNum << " ";

//             Z_Variable_Z3.push_back(c.bool_const(("ZVariable" + std::to_string(AddZVarNum)).c_str()));

//             // Store corresponding indexes of Y_variables
//             vector <int> YVarIndex;
//             for(auto k = i*int(pow(2,accuracy))+j; k < i * int(pow(2,accuracy))+j+coarseGrain1; k++){
//                 if(k % coarseGrain2 == 0){
//                     int Yindex = YVariable[k/coarseGrain2];
//                     YVarIndex.push_back(Yindex);
//                 }
//             }


//             // Store corresponding indexes of X_variables
//             vector <int> XVarIndex;
//             for(auto k = i*int(pow(2,accuracy))+j; k < i * int(pow(2,accuracy))+j+coarseGrain1; k++){
//                 int Xindex = X_unknown[gate-1][k];
//                 XVarIndex.push_back(Xindex);
//             }

//             IndexRelation RelationZY(ZvarIndex, YVarIndex);
//             AllVarRelationZY.push_back(RelationZY);

//             IndexRelation RelationZX(ZvarIndex, XVarIndex);
//             AllVarRelationZX.push_back(RelationZX);

//             ZVarNum++;
//             AddZVarNum++;

//             ZvarIndex.clear();
//             YVarIndex.clear();
//             XVarIndex.clear();
//             //                        }
//         }
//     }

//     AllVarRelation.push_back(AllVarRelationZY);
//     AllVarRelation.push_back(AllVarRelationYX);
//     AllVarRelation.push_back(AllVarRelationZX);


// //    cout << endl << endl;

//     return AllVarRelation;
// }

// Construct main clause
void ConstructClause::ConstructMainClause(ofstream& outputfile, context& c1, solver& s) {
    int mainClauseNum = 0;
    for (auto i = variableNumber + accuracy + 1; i <= variableNumber + accuracy + gate; i++) {
		// int n0 = i - 1, j0 = N;
        // int n0 = (i - 1) * maxFanout, j0 = N;
        int n0 = variableNumber + accuracy + (i - 1 - variableNumber - accuracy) * maxFanout, j0 = N;
		// vector<vector<int> > InputComb;
		vector<vector<int> > GateInputComb;
		// Calculate C(i-1)_N, Mat stores different combinations in C(i-1)_N, where each combination is represented as a row

		//cout << "The different input combinations for gate" << i << ":" << endl;
		GateInputComb = combine(n0, j0);
//		cout << "The number of different input combinations for gate" << i << ": " << GateInputComb.size() << endl;

		// // If gate i (at level t) has two fains j and k (j < k), gate k should be on level t−1. Otherwise, delete this combination
		int q = i - (variableNumber + accuracy + 1);  // The gate index in S_ij matrix and X_unknown matrix
		// for(auto x = 0; x < int(InputComb.size()); x++){
		//     if((InputComb[x][N-1] >= minIndex[q] + 1) && (InputComb[x][N-1] <= maxIndex[q] + 1)){
		//         GateInputComb.push_back(InputComb[x]);
		//     }
		// }
		// cout << "The number of different input combinations for gate" << i << ": " << GateInputComb.size() << endl;


		for (unsigned int p = 0; p < GateInputComb.size(); p++) { // Traverse each input combination
			// int j = GateInputComb[p][0], k = GateInputComb[p][1], m = GateInputComb[p][2], n = GateInputComb[p][3]; // Obtain each element in the input combination
            int j, k, m, n; // Obtain each element in the input combination

            if(GateInputComb[p][0] <= variableNumber + accuracy)
                j = GateInputComb[p][0];
            else 
                j = ceil((GateInputComb[p][0]- variableNumber - accuracy)/2.0) + variableNumber + accuracy;
            
            if(GateInputComb[p][1] <= variableNumber + accuracy)
                k = GateInputComb[p][1];
            else 
            	k = ceil((GateInputComb[p][1]- variableNumber - accuracy)/2.0) + variableNumber + accuracy;
            
            if(GateInputComb[p][2] <= variableNumber + accuracy)
                m = GateInputComb[p][2];
            else 
            	m = ceil((GateInputComb[p][2]- variableNumber - accuracy)/2.0) + variableNumber + accuracy;
            
            if(GateInputComb[p][3] <= variableNumber + accuracy)
                n = GateInputComb[p][3];
            else 
            	n = ceil((GateInputComb[p][3]- variableNumber - accuracy)/2.0) + variableNumber + accuracy;


			if ((j <= variableNumber + accuracy) && (k <= variableNumber + accuracy) && (m <= variableNumber + accuracy) && (n <= variableNumber + accuracy)) {  // If the elements both are input variables or constant coefficients
				for (int t = 0; t < (int)pow(2, variableNumber + accuracy); t++) {  // Traverse each bit in the truth table
					
                    for(auto index0 = 0; index0 < maximumfanout[j-1]; index0++){
                        for(auto index1 = 0; index1 < maximumfanout[k-1]; index1++){
                            for(auto index2 = 0; index2 < maximumfanout[m-1]; index2++){
                                for(auto index3 = 0; index3 < maximumfanout[n-1]; index3++){

                                    int b = X_known[j - 1][index0][t], c = X_known[k - 1][index1][t], d = X_known[m - 1][index2][t], e = X_known[n - 1][index3][t]; // Obtain the values of t-th bit in the truth table for two elements
                                    int h = Bin_To_Dec(b, c, d, e); // Convert binary values to a decimal value
                                    
                                    for (int a = 0; a <= 1; a++) {  // Traverse on a and a1
                                        for(int a1 = 0; a1 <=1; a1++){
                                        	expr tmpa = c1.bool_const("tmpa");
                                            expr tmpa1 = c1.bool_const("tmpa1");
                                        	
                                            if( a == 0 ){
                                                tmpa = c1.bool_val(false);
                                            }
                                            else if(a == 1){
                                                tmpa = c1.bool_val(true);
                                            }

                                            if( a1 == 0 ){
                                                tmpa1 = c1.bool_val(false);
                                            }
                                            else if(a1 == 1){
                                                tmpa1 = c1.bool_val(true);
                                            }
                                        	

                                            s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (X_Unknown_Z3[q][0][t] ^ tmpa) || (f_Z3[q][0][h] ^ (!tmpa)));

                                            s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (X_Unknown_Z3[q][1][t] ^ tmpa1) || (f_Z3[q][1][h] ^ (!tmpa1)));
                                            
                                        }
                                    }
                                }
                            }
                        }
                    }
					
				}
			}

			if ((j <= variableNumber + accuracy) && (k <= variableNumber + accuracy) && (m <= variableNumber + accuracy) && (n > variableNumber + accuracy)) { // If 1st element both is input variable or constant coefficient, the 2nd element is a gate.
				for (int t = 0; t < pow(2, variableNumber + accuracy); t++) { // Traverse each bit in the truth table
					
                    for(auto index0 = 0; index0 < maximumfanout[j-1]; index0++){
                        for(auto index1 = 0; index1 < maximumfanout[k-1]; index1++){
                            for(auto index2 = 0; index2 < maximumfanout[m-1]; index2++){
                                for(auto index3 = 0; index3 < maximumfanout[n-1]; index3++){
                                    int b = X_known[j - 1][index0][t], c = X_known[k - 1][index1][t], d = X_known[m - 1][index2][t]; // Obtain the values of t-th bit in the truth table for 1st element
                                    int g = n - (variableNumber + accuracy + 1); // Calculate 2nd gate index in S_ij matrix
                                    for (auto e = 0; e <= 1; e++) {  // Traverse on e
                                        for (auto a = 0; a <= 1; a++) {  // Traverse on a
                                            for(int a1 = 0; a1 <=1; a1++){
                                                
                                                 int h = Bin_To_Dec(b, c, d, e); // Convert binary values to a decimal value

                                                expr tmpa = c1.bool_const("tmpa");
                                                expr tmpa1 = c1.bool_const("tmpa1");
                                                expr tmpe = c1.bool_const("tmpe");
                                                
                                                if( a == 0 ){
                                                    tmpa = c1.bool_val(false);
                                                }
                                                else if(a == 1){
                                                    tmpa = c1.bool_val(true);
                                                }

                                                if( a1 == 0 ){
                                                    tmpa1 = c1.bool_val(false);
                                                }
                                                else if(a1 == 1){
                                                    tmpa1 = c1.bool_val(true);
                                                }

                                                if(e == 0){
                                                    tmpe = c1.bool_val(false);
                                                }
                                                else if(e == 1){
                                                    tmpe = c1.bool_val(true);
                                                }

                                            //    s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (tmp5)|| (tmp1) || (tmp2) || (tmp3)|| (tmp4));
                                                //  s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (X_Unknown_Z3[g][index3][t] ^ tmpe)|| (X_Unknown_Z3[q][0][t] ^ tmpa) || (X_Unknown_Z3[q][1][t] ^ tmpa1) || (f_Z3[q][0][h] ^ (!tmpa))|| (f_Z3[q][1][h] ^ (!tmpa1)));
                                                 s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (X_Unknown_Z3[g][index3][t] ^ tmpe)|| (X_Unknown_Z3[q][0][t] ^ tmpa) || (f_Z3[q][0][h] ^ (!tmpa)));
                                                 s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (X_Unknown_Z3[g][index3][t] ^ tmpe)|| (X_Unknown_Z3[q][1][t] ^ tmpa1) || (f_Z3[q][1][h] ^ (!tmpa1)));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
					
				}
			}

			if ((j <= variableNumber + accuracy) && (k <= variableNumber + accuracy) && (m > variableNumber + accuracy) && (n > variableNumber + accuracy)) {
				for (int t = 0; t < pow(2, variableNumber + accuracy); t++) {
                    for(auto index0 = 0; index0 < maximumfanout[j-1]; index0++){
                        for(auto index1 = 0; index1 < maximumfanout[k-1]; index1++){
                            for(auto index2 = 0; index2 < maximumfanout[m-1]; index2++){
                                for(auto index3 = 0; index3 < maximumfanout[n-1]; index3++){

                                    if((m == n) && (index2 == index3))
                                        continue;

                                    int b = X_known[j - 1][index0][t], c = X_known[k - 1][index1][t];
                                    int x = m - (variableNumber + accuracy + 1);
                                    int y = n - (variableNumber + accuracy + 1);
                                    for (auto d = 0; d <= 1; d++) {
                                        for (auto e = 0; e <= 1; e++) {
                                            for (auto a = 0; a <= 1; a++) {
                                                for(int a1 = 0; a1 <=1; a1++){

                                                    int h = Bin_To_Dec(b, c, d, e); // Convert binary values to a decimal value
                                                    expr tmpa = c1.bool_const("tmpa");
                                                    expr tmpa1 = c1.bool_const("tmpa1");
                                                    expr tmpe = c1.bool_const("tmpe");
                                                    expr tmpd = c1.bool_const("tmpd");
                                                    
                                                    if( a == 0 ){
                                                        tmpa = c1.bool_val(false);
                                                    }
                                                    else if(a == 1){
                                                        tmpa = c1.bool_val(true);
                                                    }

                                                    if( a1 == 0 ){
                                                        tmpa1 = c1.bool_val(false);
                                                    }
                                                    else if(a1 == 1){
                                                        tmpa1 = c1.bool_val(true);
                                                    }

                                                    if(e == 0){
                                                        tmpe = c1.bool_val(false);
                                                    }
                                                    else if(e == 1){
                                                        tmpe = c1.bool_val(true);
                                                    }

                                                    if(d == 0){
                                                        tmpd = c1.bool_val(false);
                                                    }
                                                    else if(d == 1){
                                                        tmpd = c1.bool_val(true);
                                                    }

                                                    // s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (X_Unknown_Z3[x][index2][t] ^ tmpd) || (X_Unknown_Z3[y][index3][t] ^ tmpe) || (X_Unknown_Z3[q][0][t] ^ tmpa) || (X_Unknown_Z3[q][1][t] ^ tmpa1) || (f_Z3[q][0][h] ^ (!tmpa))|| (f_Z3[q][1][h] ^ (!tmpa1)));
                                                    s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (X_Unknown_Z3[x][index2][t] ^ tmpd) || (X_Unknown_Z3[y][index3][t] ^ tmpe) || (X_Unknown_Z3[q][0][t] ^ tmpa) || (f_Z3[q][0][h] ^ (!tmpa)));
                                                    s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (X_Unknown_Z3[x][index2][t] ^ tmpd) || (X_Unknown_Z3[y][index3][t] ^ tmpe) || (X_Unknown_Z3[q][1][t] ^ tmpa1) || (f_Z3[q][1][h] ^ (!tmpa1)));
//                                                    s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (tmp6) || (tmp5) || (tmp1) || (tmp2) || (tmp3)|| (tmp4));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        
                    }
				}
			}

			if ((j <= variableNumber + accuracy) && (k > variableNumber + accuracy) && (m > variableNumber + accuracy) && (n > variableNumber + accuracy)) {
				for (int t = 0; t < pow(2, variableNumber + accuracy); t++) {
                    for (int t = 0; t < pow(2, variableNumber + accuracy); t++) {

                        for(auto index0 = 0; index0 < maximumfanout[j-1]; index0++){
                            for(auto index1 = 0; index1 < maximumfanout[k-1]; index1++){
                                for(auto index2 = 0; index2 < maximumfanout[m-1]; index2++){
                                    for(auto index3 = 0; index3 < maximumfanout[n-1]; index3++){

                                        if(((m == n) && (index2 == index3)) || ((k == m) && (index1 == index2)))
                                            continue;

                                        int b = X_known[j - 1][index0][t];
                                        int v = k - (variableNumber + accuracy + 1);
                                        int x = m - (variableNumber + accuracy + 1);
                                        int y = n - (variableNumber + accuracy + 1);
                                        for(auto c = 0; c <= 1; c++){
                                            for (auto d = 0; d <= 1; d++) {
                                                for (auto e = 0; e <= 1; e++) {
                                                    for (auto a = 0; a <= 1; a++) {
                                                        for(int a1 = 0; a1 <=1; a1++){

                                                            int h = Bin_To_Dec(b, c, d, e); // Convert binary values to a decimal value

                                                            expr tmpa = c1.bool_const("tmpa");
                                                            expr tmpa1 = c1.bool_const("tmpa1");
                                                            expr tmpe = c1.bool_const("tmpe");
                                                            expr tmpd = c1.bool_const("tmpd");
                                                            expr tmpc = c1.bool_const("tmpc");

                                                            
                                                            if( a == 0 ){
                                                                tmpa = c1.bool_val(false);
                                                            }
                                                            else if(a == 1){
                                                                tmpa = c1.bool_val(true);
                                                            }

                                                            if( a1 == 0 ){
                                                                tmpa1 = c1.bool_val(false);
                                                            }
                                                            else if(a1 == 1){
                                                                tmpa1 = c1.bool_val(true);
                                                            }

                                                            if(e == 0){
                                                                tmpe = c1.bool_val(false);
                                                            }
                                                            else if(e == 1){
                                                                tmpe = c1.bool_val(true);
                                                            }

                                                            if(d == 0){
                                                                tmpd = c1.bool_val(false);
                                                            }
                                                            else if(d == 1){
                                                                tmpd = c1.bool_val(true);
                                                            }

                                                            if(c == 0){
                                                                tmpc = c1.bool_val(false);
                                                            }
                                                            else if(c == 1){
                                                                tmpc = c1.bool_val(true);
                                                            }

                                                            // s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (X_Unknown_Z3[v][index1][t] ^ tmpc)|| (X_Unknown_Z3[x][index2][t] ^ tmpd) || (X_Unknown_Z3[y][index3][t] ^ tmpe) || (X_Unknown_Z3[q][0][t] ^ tmpa) || (X_Unknown_Z3[q][1][t] ^ tmpa1) || (f_Z3[q][0][h] ^ (!tmpa))|| (f_Z3[q][1][h] ^ (!tmpa1)));
                                                             s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (X_Unknown_Z3[v][index1][t] ^ tmpc)|| (X_Unknown_Z3[x][index2][t] ^ tmpd) || (X_Unknown_Z3[y][index3][t] ^ tmpe) || (X_Unknown_Z3[q][0][t] ^ tmpa) || (f_Z3[q][0][h] ^ (!tmpa)));
                                                              s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (X_Unknown_Z3[v][index1][t] ^ tmpc)|| (X_Unknown_Z3[x][index2][t] ^ tmpd) || (X_Unknown_Z3[y][index3][t] ^ tmpe) || (X_Unknown_Z3[q][1][t] ^ tmpa1) || (f_Z3[q][1][h] ^ (!tmpa1)));
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
				}
			}

			if ((j > variableNumber + accuracy) && (k > variableNumber + accuracy) && (m > variableNumber + accuracy) && (n > variableNumber + accuracy)) {
				for (int t = 0; t < pow(2, variableNumber + accuracy); t++) {
                    for(auto index0 = 0; index0 < maximumfanout[j-1]; index0++){
                        for(auto index1 = 0; index1 < maximumfanout[k-1]; index1++){
                            for(auto index2 = 0; index2 < maximumfanout[m-1]; index2++){
                                for(auto index3 = 0; index3 < maximumfanout[n-1]; index3++){

                                    if(((m == n) && (index2 == index3)) || ((k == m) && (index1 == index2)) || ((j == k) && (index0 == index1)))
                                        continue;
                                    int u = j - (variableNumber + accuracy + 1);
                                    int v = k - (variableNumber + accuracy + 1);
                                    int x = m - (variableNumber + accuracy + 1);
                                    int y = n - (variableNumber + accuracy + 1);
                                    for(auto b = 0; b <= 1; b++){
                                        for(auto c = 0; c <= 1; c++){
                                            for (auto d = 0; d <= 1; d++) {
                                                for (auto e = 0; e <= 1; e++) {
                                                    for (auto a = 0; a <= 1; a++) {
                                                        for(int a1 = 0; a1 <=1; a1++){

                                                            int h = Bin_To_Dec(b, c, d, e); // Convert binary values to a decimal value

                                                            expr tmpa = c1.bool_const("tmpa");
                                                            expr tmpa1 = c1.bool_const("tmpa1");
                                                            expr tmpe = c1.bool_const("tmpe");
                                                            expr tmpd = c1.bool_const("tmpd");
                                                            expr tmpc = c1.bool_const("tmpc");
                                                            expr tmpb = c1.bool_const("tmpb");

                                                            if( a == 0 ){
                                                                tmpa = c1.bool_val(false);
                                                            }
                                                            else if(a == 1){
                                                                tmpa = c1.bool_val(true);
                                                            }

                                                            if( a1 == 0 ){
                                                                tmpa1 = c1.bool_val(false);
                                                            }
                                                            else if(a1 == 1){
                                                                tmpa1 = c1.bool_val(true);
                                                            }

                                                            if(e == 0){
                                                                tmpe = c1.bool_val(false);
                                                            }
                                                            else if(e == 1){
                                                                tmpe = c1.bool_val(true);
                                                            }

                                                            if(d == 0){
                                                                tmpd = c1.bool_val(false);
                                                            }
                                                            else if(d == 1){
                                                                tmpd = c1.bool_val(true);
                                                            }

                                                            if(c == 0){
                                                                tmpc = c1.bool_val(false);
                                                            }
                                                            else if(c == 1){
                                                                tmpc = c1.bool_val(true);
                                                            }

                                                            if(b == 0){
                                                                tmpb = c1.bool_val(false);
                                                            }
                                                            else if(b == 1){
                                                                tmpb = c1.bool_val(true);
                                                            }

                                                            // s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (X_Unknown_Z3[u][index0][t] ^ tmpb) || (X_Unknown_Z3[v][index1][t] ^ tmpc) || (X_Unknown_Z3[x][index2][t] ^ tmpd) || (X_Unknown_Z3[y][index3][t] ^ tmpe) || (X_Unknown_Z3[q][0][t] ^ tmpa) || (X_Unknown_Z3[q][1][t] ^ tmpa1) || (f_Z3[q][0][h] ^ (!tmpa))|| (f_Z3[q][1][h] ^ (!tmpa1)));
                                                            s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (X_Unknown_Z3[u][index0][t] ^ tmpb) || (X_Unknown_Z3[v][index1][t] ^ tmpc) || (X_Unknown_Z3[x][index2][t] ^ tmpd) || (X_Unknown_Z3[y][index3][t] ^ tmpe) || (X_Unknown_Z3[q][0][t] ^ tmpa) || (f_Z3[q][0][h] ^ (!tmpa)));
                                                            s.add(!S_Z3[q][j-1][index0] || !S_Z3[q][k-1][index1] || !S_Z3[q][m-1][index2] || !S_Z3[q][n-1][index3] || (X_Unknown_Z3[u][index0][t] ^ tmpb) || (X_Unknown_Z3[v][index1][t] ^ tmpc) || (X_Unknown_Z3[x][index2][t] ^ tmpd) || (X_Unknown_Z3[y][index3][t] ^ tmpe) || (X_Unknown_Z3[q][1][t] ^ tmpa1) || (f_Z3[q][1][h] ^ (!tmpa1)));
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
				}
			}
		}

	}

//    cout << "The number of main clauses:" << mainClauseNum << endl;
}


// Construct 1st contraint clause: the operator has 2-input fanins.
void ConstructClause::Construct1stClause(ofstream& outputfile, context& c, solver& s) {
    int firststClauseNum = 0;

   for(auto i = 0; i < gate; i++){
        expr tmp = c.int_const("tmp");
        tmp = c.int_val(0);
        for(auto j = 0; j < S[i].size(); j++){
            for(auto k = 0; k < maximumfanout[j]; k++){
                tmp = tmp + S_Z3_INT[i][j][k];
            }
            // cout << S_Z3[i][j] << endl;
        }
        s.add(tmp == N);
    }
}


void ConstructClause::ConstructOutputConstraint(ofstream& outputfile, context& c, solver& s){
    int outputConsNum = 0;

    // Each output points to a node in the Boolean chain.
    for(auto i = 0; i < variableNumber; i++){
        expr tmp = c.int_const("tmp");
        tmp = c.int_val(0);
        for(auto j = 0; j < variableNumber + accuracy + gate; j++){
            for(auto k = 0; k < maximumfanout[j]; k++){
                tmp = tmp + outputGateIndex_INT[i][j][k];

                s.add(!outputGateIndex[i][j][k] || (outputGateIndex_INT[i][j][k] == 1));
                s.add(outputGateIndex[i][j][k] || (outputGateIndex_INT[i][j][k] == 0));
            }
            
        }
        s.add(tmp == 1);


        // The relationship between outputGateIndex and outputGateIndex_INT
        for(auto j = 0; j < int(pow(2, variableNumber+accuracy)); j++){
            s.add(!outputTruthTable[i][j] || (outputTruthTable_Z3_INT[i][j] == 1));
            s.add(outputTruthTable[i][j] || (outputTruthTable_Z3_INT[i][j] == 0));
        }

    }

    // The relationship between the truth table of gate x_i and each output
    for(auto h = 0; h < variableNumber; h++){
        for(auto i = 0; i < variableNumber + accuracy + gate; i++){
            for(auto t = 0; t < int(pow(2, variableNumber+accuracy)); t++){
                if(i < variableNumber + accuracy){
                	expr X_known_Z30 = c.bool_const("X_known_Z30");
                    if(X_known[i][0][t] == 0){
                        X_known_Z30 = c.bool_val(false);
                    }
                    else if(X_known[i][0][t] == 1){
                        X_known_Z30 = c.bool_val(true);
                    }
                    expr tmp1 = !outputGateIndex[h][i][0] || (!X_known_Z30 ^ outputTruthTable[h][t]);
                    s.add(tmp1);

                    // expr X_known_Z31 = c.bool_const("X_known_Z31");
                    // if(X_known[i][1][t] == 0){
                    //     X_known_Z31 = c.bool_val(false);
                    // }
                    // else if(X_known[i][1][t] == 1){
                    //     X_known_Z31 = c.bool_val(true);
                    // }
                    // expr tmp2 = !outputGateIndex[h][i][1] || (!X_known_Z31 ^ outputTruthTable[h][t]);
                    // s.add(tmp2);

                    outputConsNum++;
                }
                else{
                    for(auto k = 0; k < maxFanout; k++){
                        expr tmp = !outputGateIndex[h][i][k] || (!X_Unknown_Z3[i-variableNumber-accuracy][k][t] ^ outputTruthTable[h][t]);
                        s.add(tmp);
                        outputConsNum++;
                    }
                }
            }
         }
     }


    // cout << "The number of output clauses:" << outputConsNum << endl;
}


void ConstructClause::GateIndexConstraintZ3(ofstream& outputfile, int gateKind, vector <double> gateArea, context& c, solver& s){
	int gateIndexClauseNum = 0;
	for(auto i = 0; i < gate; i++){
		//Add gate index constraints

		//Each gate has exactly one kind of gate.
		//At least 1
		expr tmp = c.bool_const("tmp");
		tmp = c.bool_val(false);
		for(auto k = 0; k < gateKind; k++){
			tmp = tmp || GateIndex_Z3[i][k];
		}
		s.add(tmp);
		gateIndexClauseNum++;

		//At most 1
		int n1 = gateKind, j1 = 2;
		vector< vector<int> > combAtMost1;
		// Calculate Cn_(G[i]+1), Mat7 stores different combinations in Cn_(G[i]+1), where each combination is represented as a row.
		combAtMost1 = combine(n1, j1);

		// cout << "The number of different combinations in combAtMostXi for G[" << i << "]: " << combAtMostGi.size() << endl;

		//At most 1
		for (unsigned int p = 0; p < combAtMost1.size(); p++) {
			expr tmp = c.bool_const("tmp");
			tmp = c.bool_val(false);
			for (unsigned int q = 0; q < combAtMost1[p].size(); q++) {
				int x = combAtMost1[p][q]-1;
//				outputfile << -trueGateCate[x] << " ";
				tmp = tmp || (!GateIndex_Z3[i][x]);
			}
//			outputfile << 0 << endl;
			s.add(tmp);
			gateIndexClauseNum++;
		}

		// The relationship between f_ipquv and gateIndex_ik
		for(auto j = 0; j < gateKind; j++){
			// First implication
			vector <expr> temp1;
			for(auto k = 0; k < gateTruthTable[0][0].size(); k++){
				if(gateTruthTable[j][0][k] == 0){
					temp1.push_back(f_Z3[i][0][k]);
				}
				else if(gateTruthTable[j][0][k] == 1){
					temp1.push_back(!f_Z3[i][0][k]);
				}

                if(gateTruthTable[j][1][k] == 0){
					temp1.push_back(f_Z3[i][1][k]);
				}
				else if(gateTruthTable[j][1][k] == 1){
					temp1.push_back(!f_Z3[i][1][k]);
				}
			}

			expr tmp = c.bool_const("tmp");
			tmp = c.bool_val(false);
			for(auto m = 0; m < temp1.size(); m++){
//				outputfile << temp1[m] << " ";
				tmp = tmp || temp1[m];
			}
			tmp = tmp || GateIndex_Z3[i][j];
			s.add(tmp);
//			outputfile << trueGateCate[j] << " " << 0 << endl;
			gateIndexClauseNum++;

			// Second implication
			vector <expr> temp2;
			for(auto k = 0; k < gateTruthTable[0][0].size(); k++){
				if(gateTruthTable[j][0][k] == 0){
					temp2.push_back(!f_Z3[i][0][k]);
				}
				else if(gateTruthTable[j][0][k] == 1){
					temp2.push_back(f_Z3[i][0][k]);
				}
                if(gateTruthTable[j][1][k] == 0){
					temp2.push_back(!f_Z3[i][1][k]);
				}
				else if(gateTruthTable[j][1][k] == 1){
					temp2.push_back(f_Z3[i][1][k]);
				}
			}

			for(auto m = 0; m < temp2.size(); m++){
				s.add(!GateIndex_Z3[i][j] || temp2[m]);
//				outputfile << -trueGateCate[j] << " " << temp2[m] << " " << 0 << endl;
				gateIndexClauseNum++;
			}
		}

		// The relationship between GateIndex_Z3 and GateIndex_Z3_INT
		for(auto j = 0; j < gateKind; j++){
			s.add(!GateIndex_Z3[i][j] || (GateIndex_Z3_INT[i][j] == 1));
			s.add( GateIndex_Z3[i][j] || (GateIndex_Z3_INT[i][j] == 0));
		}

        // The relationship between S_Z3 and S_Z3_INT
		for(auto j = 0; j < S[i].size(); j++){
            for(auto k = 0; k < maximumfanout[j]; k++){
                s.add(!S_Z3[i][j][k] || (S_Z3_INT[i][j][k] == 1));
			    s.add(S_Z3[i][j][k] || (S_Z3_INT[i][j][k] == 0));
            }
		}

	}
}


void ConstructClause::errorConstraint(ofstream& outputfile, context& c, solver& s, int errorBound){
     // MED constraint
    expr consMED = c.int_const("tmp");
 	consMED = c.int_val(0);
     for(auto t = 0; t < int(pow(2, variableNumber+accuracy)); t++){
         expr tmp = c.int_const("tmp");
 	     tmp = c.int_val(0);

 //        // 5-3 compressor
 //        tmp = tmp + int(pow(2,0)) * outputTruthTable_Z3_INT[0][t] + int(pow(2,1)) * outputTruthTable_Z3_INT[1][t] + int(pow(2,1)) * outputTruthTable_Z3_INT[2][t];

 //       // 4-2 compressor with equal weight
 //       tmp = tmp + int(pow(2,0)) * outputTruthTable_Z3_INT[0][t] + int(pow(2,0)) * outputTruthTable_Z3_INT[1][t];

           // conventional compressors
           for(auto h = 0; h < variableNumber; h++){
               tmp = tmp + int(pow(2,h)) * outputTruthTable_Z3_INT[h][t];
           }

           consMED = consMED + abs(tmp - featureVector[t]) * probabilityVec[t];

     }
     s.add(consMED <= errorBound);

}

void ConstructClause::areaConstraintZ3(ofstream& outputfile, int gateKind, vector <double> gateArea, double maxArea, context& c, solver& s){
//	int gateAreaClauseNum = 0;
	// Area constraint
//    cout << "max area: " << maxArea << endl;
	expr tmp = c.int_const("tmp");
	tmp = c.int_val(0);
	for(auto i = 0; i < gate; i++){
		for(auto j = 0; j < gateKind; j++){
			tmp = tmp + gateArea[j] * (GateIndex_Z3_INT[i][j]);
		}
	}
	s.add(tmp <= maxArea);
}


int ConstructClause::SMTSolverSingleSol(context& c, solver& s, int maxIterationPerRun){
	int runNum = 0;
	auto result = sat;
	while(runNum == 0 || result == sat){
	        runNum++;
	        if(runNum == maxIterationPerRun+1){
	            break;
	        }

	        params p(c);
            if(gate == 4){
                p.set(":timeout", 700000u);
            }
            else if(gate == 5){
                p.set(":timeout", 25252000u);
            }

			s.set(p);

//           auto start = chrono::system_clock::now();

	        result = s.check();
	        cout << result << endl;

//           auto end1 = chrono::system_clock::now();
//           auto duration1 = chrono::duration_cast<std::chrono::milliseconds>(end1 - start);
//           auto milliseconds1 = duration1.count();
//           cout << "runtime: " << milliseconds1 << endl;
//	        model m = s.get_model();
	        // cout << m << "\n";
//	        PrintVerifyCircuitZ3(m, indexOfXn_mInG, gateArea);
//	        cout << endl << endl;
//
//        	expr tmp = c.bool_const("tmp");
//        	tmp = c.bool_val(false);
//
////			        for(auto i = 0; i < m.size(); i++){
////			        	func_decl v = m[i];
////			        	tmp = tmp || (v != m.get_const_interp(v));
////			        }
//
//	        for(auto i = 0; i < X_Unknown_Z3.size(); i++){
//	        	for(auto j = 0; j < X_Unknown_Z3[i].size(); j++){
//
//					tmp = tmp || (X_Unknown_Z3[i][j] != m.eval(X_Unknown_Z3[i][j]));
//	        	}
//	        }
//	        s.add(tmp);
	}
	if(result == sat){
		return 1;
	}
	else{
		return 0;
	}
}


double ConstructClause::PrintVerifyCircuitZ3WithoutXor(char* outputDir, model& m, vector <double> gateArea, vector <double> gateAreaTrue, int errorBound, int solutionNum, vector <double>& areaSet, vector <int>& gateNumSet){
    // 	Verify Circuit
    vector <int> calOutput(int(pow(2, variableNumber+accuracy)), -1);

    int error = 0;
    int med = 0;
    for(auto t = 0; t < int(pow(2, variableNumber+accuracy)); t++){
        int tmp = 0;

//		 // 5-3 compressor
//		 tmp = tmp + int(pow(2,0)) * m.eval(outputTruthTable_Z3_INT[0][t]).get_numeral_int() + int(pow(2,1)) * m.eval(outputTruthTable_Z3_INT[1][t]).get_numeral_int() + int(pow(2,1)) * m.eval(outputTruthTable_Z3_INT[2][t]).get_numeral_int();

         // conventional compressor
         for(auto h = 0; h < variableNumber; h++){
             auto item = outputTruthTable_Z3_INT[h][t];
             tmp = tmp + int(pow(2,h)) * m.eval(item).get_numeral_int();
         }

//        // 4-2 compressor with equal weight
//        tmp = tmp + int(pow(2,0)) * m.eval(outputTruthTable_Z3_INT[0][t]).get_numeral_int() + int(pow(2,0))* m.eval(outputTruthTable_Z3_INT[1][t]).get_numeral_int();

        calOutput[t] = tmp;

        // error = error + abs(calOutput[t]-featureVector[t]);

        if(abs(calOutput[t]-featureVector[t]) != 0){
           error = error + 1;
        //    cout << t << " ";
       }
       
       
       
       med = med + abs(calOutput[t]-featureVector[t])*probabilityVec[t];
    }
    // cout << endl;

	// int flag = 1;
	// for(auto i = 0; i < int(pow(2, variableNumber+accuracy)); i++){
	// 	if(calOutput[i] != featureVector[i]){
	// 		flag = 0;
	// 	}
	// }

	// if(flag == 1){
//    int difference = errorBound - error;
    if(error <= errorBound){
        cout << "Real error rate: " << error << ", ";
        cout << "Real med: " << med << ", ";
		cout << "Verify successfully!" << endl;
		cout << endl;
	}
	else{
        cout << "Real error distance: " << error << ", ";
		cout << "Verify failed! The feature vector is: ";
		for(auto i = 0; i < int(pow(2, variableNumber+accuracy)); i++){
			cout << calOutput[i] << " ";
		}
		cout << endl;
	}

    // // Observe outputs
    // cout << "outputGateIndex" << endl;
    // for(auto i = 0; i < outputGateIndex.size(); i++){
    //     for(auto j = 0; j < outputGateIndex[i].size(); j++){
    //         for(auto k = 0; k < outputGateIndex[i][j].size(); k++){
    //             auto item = outputGateIndex[i][j][k];
    //             if(m.eval(item).is_true()){
    //                 cout << i << "-" << j << "-" << k << "th" << " ";
    //             }
    //         }
    //     }
    // }
    // cout << endl << endl;

    // cout << "X_Unknown_Z3" << endl;
    // for(auto j = 0; j < maxFanout; j++){
    //     for(auto k = 0; k < int(pow(2, variableNumber+accuracy)); k++){
    //         auto item = X_Unknown_Z3[gate-1][j][k];
    //         if(m.eval(item).is_true()){
    //             cout << j << "-" << k << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // cout << "S_Z3" << endl;
    // for(auto j = 0; j < gate; j++){
    //     for(auto k = 0; k < S_Z3[j].size(); k++){
    //         for(auto l = 0; l < maximumfanout[k]; l++){
    //             auto item = S_Z3[j][k][l];
    //             if(m.eval(item).is_true()){
    //                 cout << j << "-" << k << "-" << l << " ";
    //             }
    //         }
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // cout << "S_Z3_INT" << endl;
    // for(auto j = 0; j < gate; j++){
    //     for(auto k = 0; k < S_Z3_INT[j].size(); k++){
    //         for(auto l = 0; l < maximumfanout[k]; l++){
    //             auto item = S_Z3_INT[j][k][l];
    //             if((m.eval(item)).get_numeral_int() == 1){
    //                 cout << j << "-" << k << "-" << l << " ";
    //             }
    //         }
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // cout << "GateIndex_Z3" << endl;
    // for(auto j = 0; j < gate; j++){
    //     for(auto k = 0; k < gateKind; k++){
    //         auto item = GateIndex_Z3[j][k];
    //         if(m.eval(item).is_true()){
    //             cout << j << "-" << k << " ";
    //             cout << "gate area: " << gateArea[k] << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // int tmp1 = 0;
    // cout << "GateIndex_Z3_INT" << endl;
    // for(auto j = 0; j < gate; j++){
    //     for(auto k = 0; k < gateKind; k++){
    //         auto item = GateIndex_Z3_INT[j][k];
    //         if(m.eval(item).get_numeral_int() == 1){
    //             cout << j << "-" << k << " ";
    //             // cout << "gate area: " << gateArea[k] << endl;
    //             tmp1 = tmp1 + gateArea[k];
    //         }
    //     }
    //     cout << endl;
    // }
    // cout << "total area: " << tmp1 << endl;
    // cout << endl;
	

    // cout << "f_Z3" << endl;
    // for(auto j = 0; j < maxFanout; j++){
    //     for(auto k = 0; k < int(pow(2, variableNumber+accuracy)); k++){
    //         auto item = f_Z3[gate-1][j][k];
    //         if(m.eval(item).is_true()){
    //             cout << j << "-" << k << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    // cout << endl;


    // cout << "o_ht" << endl;
    // for(auto j = 0; j < variableNumber; j++){
    //     for(auto k = 0; k < int(pow(2, variableNumber+accuracy)); k++){
    //         auto item = outputTruthTable[j][k];
    //         if(m.eval(item).is_true()){
    //             cout << j << "-" << k << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    // cout << endl;


	//Print Circuit
	vector < vector <string> > circuitRes (gate, vector <string>(N+2));
	vector <int> circuitIndex(gate, -1);

	for(auto i = 0; i < int(S_Z3.size()); i++){
		cout << "For gate " << variableNumber + accuracy + i << ":" << endl;
		cout << "The four fanins are: ";
		circuitRes[i][5] = std::to_string(variableNumber + accuracy + i);

//		auto k = S[i][0];
		auto count = 0;
		for(auto j = 0; j < S_Z3[i].size(); j++){
            for(auto k = 0; k < maximumfanout[j]; k++){
                auto item = S_Z3[i][j][k];
                if(m.eval(item).is_true()){
                    count++;
                    cout << j << "-" << k << "th" << " ";
                    if(count == 1){
                        circuitRes[i][1] = std::to_string(j) + std::to_string(k);
                    }
                    else if(count == 2){
                        circuitRes[i][2] = std::to_string(j) + std::to_string(k);
                    }
                    else if(count == 3){
                        circuitRes[i][3] = std::to_string(j) + std::to_string(k);
                    }
                    else if(count == 4){
                        circuitRes[i][4] = std::to_string(j) + std::to_string(k);
                    }
                }
            }
		}
		cout << ",the operator is: ";
//		auto p = f[i][0];
		// auto gateIndex = string();
        vector <string> gateIndex;
        gateIndex.clear();

        auto tmp1 = string();
        auto tmp2 = string();

		for(auto q = 0; q < int(f_Z3[i][0].size()); q++){
			auto item1 = f_Z3[i][0][q];
            auto item2 = f_Z3[i][1][q];

			if(m.eval(item1).is_true()){
				tmp1.push_back('1');
				//cout << 1 << " ";
			}
			else{
				tmp1.push_back('0');
				//cout << 0 << " ";
			}

            if(m.eval(item2).is_true()){
				tmp2.push_back('1');
				//cout << 1 << " ";
			}
			else{
				tmp2.push_back('0');
				//cout << 0 << " ";
			}
		}
		//cout << gateIndex << " ";
        gateIndex.push_back(tmp1);
        gateIndex.push_back(tmp2);

		// cout << gateIndex << endl;
		auto iter = gateLibrary.find(gateIndex);
		cout << iter->second << ", ";
//		gateType.push_back(iter->second);
		circuitRes[i][0] = iter->second;

		cout << "the gate index is: ";

		for(auto k = 0; k < GateIndex_Z3[i].size(); k++){
			auto item  = GateIndex_Z3[i][k];
			if(m.eval(item).is_true()){
				cout << k << endl;
				circuitIndex[i] = k;
//				circuitRes[i][0] = k;
				//cout << 1 << " ";
			}

//			auto item1  = GateIndex_Z3_INT[i][k];
//			if(m.eval(item1).get_numeral_int()> 0){
//				cout << k << " " << m.eval(item1).get_numeral_int() << endl;
//				//cout << 1 << " ";
//			}
		}

	}

    char sol[1000];
    strcpy(sol, outputDir);
    strcat(sol, "summary");
    strcat(sol, std::to_string(solutionNum).data());
    strcat(sol, ".txt");
    ofstream out(sol);
    // Print the truth table of outputs
    out << "Real error rate: " << error << ", ";
    out << "Real med: " << med << endl;
    // cout << "The truth table of the approximate 4-2 compressor: " << endl;
    out << "The truth table of the approximate 4-2 compressor: " << endl;
   for(auto t = 0; t < (int)pow(2, variableNumber + accuracy); t++){
    //    cout << t << "-th bit:";
       out << "\"";
       for(auto i = variableNumber - 1; i >= 0; i--){
           auto item  = outputTruthTable[i][t];
           if(m.eval(item).is_true()){
            //    cout << "1";
               out << "1";
           }
           else{
            //    cout << "0";
               out << "0";
           }
       }
    //    cout << endl;
       out << "\"" << ", ";
   }

   vector <int> outputIndex(variableNumber, -1);
   vector <int> outputIndexTrue(variableNumber, -1);
   for(auto i = 0; i < variableNumber; i++){
       for(auto k = 0; k < outputGateIndex[i].size(); k++){
           for(auto l = 0; l < maximumfanout[k]; l++){
               auto item = outputGateIndex[i][k][l];
                if(m.eval(item).is_true()){
                    outputIndexTrue[i] = k;
                    if( (k >= variableNumber + accuracy) && (circuitIndex[k - variableNumber - accuracy] >= 96))
                        outputIndex[i] = k * 10 + l;
                    else
                        outputIndex[i] = k;
                }
           }
       }
   }

//    std::sort(outputIndex.begin(), outputIndex.end());
	cout << endl;

	double area = 0;
    double areaTrue = 0;
	for(auto i = 0; i < gate; i++){
		int index = circuitIndex[i];
		area = area + gateArea[index];
        areaTrue = areaTrue + gateAreaTrue[index];
	}

    // There exists a buffer in the circuit.
    for(auto i = 0; i < variableNumber; i++){
        if(outputIndex[i] < variableNumber + accuracy){
            areaTrue = areaTrue + gateAreaTrue[4];
        }
    }
    areaSet[solutionNum] = areaTrue;
    gateNumSet[solutionNum] = gate;
    
	cout << "The real area of circuit is: " << areaTrue << endl;
    cout << "The corresponding integer area of circuit is: " << area << endl << endl;


    // change circuitRes
    for(auto p = 0; p < circuitRes.size(); p++){
        for(auto q = 1; q <=4 ; q++){
            if(int(circuitRes[p][q][0] - '0') < variableNumber+accuracy){
                circuitRes[p][q] = circuitRes[p][q][0];
            }
            else if(circuitIndex[int(circuitRes[p][q][0] - '0') - variableNumber - accuracy] < 96){
                circuitRes[p][q] = circuitRes[p][q][0];
            }
        }
    }


    // create a temporary .v file
	// Output the first three lines for .v file
    char sol1[1000];
    strcpy(sol1, outputDir);
    strcat(sol1, "solution");
    strcat(sol1, std::to_string(solutionNum).data());
    strcat(sol1, ".v");
	ofstream ofs(sol1);
	ofs << "module \\solution-0 ("<< endl;
	ofs << "  ";
	for(int i = 0; i < variableNumber+accuracy; i++){
		if(i == variableNumber+accuracy-1){
			ofs << "x" << i << "," << endl;
		}
		else{
			ofs << "x" << i << ", ";
		}
	}

    ofs << "  ";
//    for(int i = 0; i < outputIndex.size(); i++){
//		if(i == outputIndex.size()-1){
//			ofs << "z" << outputIndex[i] << " );" << endl;
//		}
//		else{
//			ofs << "z" << outputIndex[i] << ", ";
//		}
//	}

    for(int i = 0; i < outputIndex.size(); i++){
		if(i == outputIndex.size()-1){
			ofs << "out" << i << " );" << endl;
		}
		else{
			ofs << "out" << i << ", ";
		}
	}

	// ofs << "  z0 );" << endl;

	ofs << "  input" << " ";
	for(int i = 0; i < variableNumber+accuracy; i++){
		if(i == variableNumber+accuracy-1){
			ofs << "x" << i << ";" << endl;
		}
		else{
			ofs << "x" << i << ", ";
		}
	}

	ofs << "  output" << " ";
//	for(int i = 0; i < outputIndex.size(); i++){
//		if(i == outputIndex.size()-1){
//			ofs << "z" << outputIndex[i] << ";" << endl;
//		}
//		else{
//			ofs << "z" << outputIndex[i] << ", ";
//		}
//	}

	for(int i = 0; i < outputIndex.size(); i++){
		if(i == outputIndex.size()-1){
			ofs << "out" << i << ";" << endl;
		}
		else{
			ofs << "out" << i << ", ";
		}
	}
//	ofs << "  output z0;" << endl;

    int count = 0;
    for(int i = variableNumber+accuracy; i < variableNumber+accuracy+gate; i++){
        auto it = find(outputIndexTrue.begin(), outputIndexTrue.end(), i);
        if(it != outputIndexTrue.end()){
            count++;
        }
    }

    vector <int> tmp;
    int number = 0;
    for(auto h = 0; h < outputIndex.size(); h++){
        if(outputIndexTrue[h] > variableNumber + accuracy-1){
            auto iter = find(tmp.begin(), tmp.end(), outputIndexTrue[h]);
            if(iter == tmp.end()){
                tmp.push_back(outputIndexTrue[h]);
                number++;
            }
        }
    }

    for(int i = variableNumber+accuracy; i < variableNumber+accuracy+gate; i++){
        auto it1 = outputIndex.begin();
        auto it2 = outputIndex.begin();

        if((circuitIndex[i - variableNumber - accuracy] >= 96)){
            it1 = find(outputIndex.begin(), outputIndex.end(), i*10);
            it2 = find(outputIndex.begin(), outputIndex.end(), i*10+1);

            if((((it1 == outputIndex.end()) && (it2 != outputIndex.end()))) || ((it1 != outputIndex.end()) && (it2 == outputIndex.end()))){
                count--;
                number--;
            }
        }
    }

    if(number < gate){
		ofs << "  wire" << " ";
        int num = 0;

		for(int i = variableNumber+accuracy; i < variableNumber+accuracy+gate; i++){

            auto it1 = outputIndex.begin();
            auto it2 = outputIndex.begin();
            auto it = outputIndex.begin();

            if((circuitIndex[i - variableNumber - accuracy] >= 96)){
                it1 = find(outputIndex.begin(), outputIndex.end(), i*10);
                it2 = find(outputIndex.begin(), outputIndex.end(), i*10+1);
            }
            else{
                it = find(outputIndex.begin(), outputIndex.end(), i);
            }
            
            if((circuitIndex[i - variableNumber - accuracy] >= 96)){
            	if(((it1 != outputIndex.end()) && (it2 != outputIndex.end()))){
					continue;
				}
            }
            else{
            	if((it != outputIndex.end())){
					continue;
				}
            }

            // if((((it1 == outputIndex.end()) && (it2 != outputIndex.end()))) || ((it1 != outputIndex.end()) && (it2 == outputIndex.end())))
            //     count--;
            

            if(num == gate-count-1){
                if((circuitIndex[i - variableNumber - accuracy] >= 96)){
                    if(((it1 == outputIndex.end()) && (it2 != outputIndex.end())))
                        ofs << "new_n" << i*10 << "_;" << endl;
                    else if(((it1 != outputIndex.end()) && (it2 == outputIndex.end())))
                        ofs << "new_n" << i*10+1 << "_;" << endl;
                    else{
                        ofs << "new_n" << i*10 << "_, ";
                        ofs << "new_n" << i*10+1 << "_;" << endl;
                    }
                }
                else 
                    ofs << "new_n" << i << "_;" << endl;
            }
            else{
                if((circuitIndex[i - variableNumber - accuracy] >= 96)){
                    if(((it1 == outputIndex.end()) && (it2 != outputIndex.end())))
                        ofs << "new_n" << i*10 << "_, ";
                    else if(((it1 != outputIndex.end()) && (it2 == outputIndex.end())))
                        ofs << "new_n" << i*10+1 << "_, ";
                    else{
                        ofs << "new_n" << i*10 << "_, ";
                        ofs << "new_n" << i*10+1 << "_, ";
                    }
                }
                else 
                    ofs << "new_n" << i << "_, ";
            }
            num++;
        }
		
	}

    int index = 0;
    for(auto h = 0; h < outputIndex.size(); h++){
        if(outputIndex[h] < variableNumber + accuracy){
            ofs << "  BUF_X1  g" << index << "(.A(x" << outputIndex[h] << "),  .Z(out" << h << "));" << endl ;
            index++;
        }
    }


	for(auto p = 0; p < circuitRes.size(); p++){

		if(circuitIndex[p] == 18 || circuitIndex[p] == 29 || circuitIndex[p] == 40 || circuitIndex[p] == 51){
			ofs << "  " << circuitRes[p][0] << "  g" << p+index;
			if(atoi(circuitRes[p][1].c_str()) < variableNumber+accuracy){
				ofs << "(.A1(x" << circuitRes[p][1] << "), ";
			}

            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][1].c_str()));
                if(it != outputIndex.end()){
//                    ofs << "(.a(z" << circuitRes[p][1] << "), ";
                    ofs << "(.A1(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << "(.A1(new_n" << circuitRes[p][1] << "_" << "), ";
                }
            }
			// else if(atoi(circuitRes[p][1].c_str()) >= variableNumber+accuracy){
			// 	ofs << "(.a(new_n" << circuitRes[p][1] << "_" << "), ";
			// }

			if(atoi(circuitRes[p][2].c_str()) < variableNumber+accuracy){
				ofs << ".A2(x" << circuitRes[p][2] << "), ";
			}
			else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][2].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".A2(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".A2(new_n" << circuitRes[p][2] << "_" << "), ";
                }
            }

			if(atoi(circuitRes[p][3].c_str()) < variableNumber+accuracy){
				ofs << ".A3(x" << circuitRes[p][3] << "), ";
			}
			else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][3].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".A3(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".A3(new_n" << circuitRes[p][3] << "_" << "), ";
                }
            }

			if(atoi(circuitRes[p][4].c_str()) < variableNumber+accuracy){
				ofs << ".A4(x" << circuitRes[p][4] << "), ";
			}
			else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][4].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".A4(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".A4(new_n" << circuitRes[p][4] << "_" << "), ";
                }
            }

            auto it = find(outputIndex.begin(), outputIndex.end(), variableNumber+accuracy+p);
            if(it != outputIndex.end()){
                ofs << ".ZN(out" << it-outputIndex.begin() << "));" << endl;
            }
            else{
                ofs << ".ZN(new_n" << variableNumber+accuracy+p << "_));" << endl;
            }
		}

		if((circuitIndex[p] >= 64 && circuitIndex[p] <= 66) || (circuitIndex[p] >= 79 && circuitIndex[p] <= 81) ){

			int position1 = circuitRes[p][0].find("-");
			int position2 = circuitRes[p][0].find(",");

			string gateType = circuitRes[p][0].substr(0, position1);

			int a = circuitRes[p][0][position1+1] - '0';
			int b = circuitRes[p][0][position1+2] - '0';

			int c = circuitRes[p][0][position2+1] - '0';
			int d = circuitRes[p][0][position2+2] - '0';

			ofs << "  " << gateType << "  g" << p+index;
			if(atoi(circuitRes[p][a].c_str()) < variableNumber+accuracy){
				ofs << "(.A1(x" << circuitRes[p][a] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][a].c_str()));
                if(it != outputIndex.end()){
                    ofs << "(.A1(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << "(.A1(new_n" << circuitRes[p][a] << "_" << "), ";
                }
            }
			// else if(atoi(circuitRes[p][a].c_str()) >= variableNumber+accuracy){
			// 	ofs << "(.a(new_n" << circuitRes[p][a] << "_" << "), ";
			// }

			if(atoi(circuitRes[p][b].c_str()) < variableNumber+accuracy){
				ofs << ".A2(x" << circuitRes[p][b] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][b].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".A2(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".A2(new_n" << circuitRes[p][b] << "_" << "), ";
                }
            }

			if(atoi(circuitRes[p][c].c_str()) < variableNumber+accuracy){
				ofs << ".B1(x" << circuitRes[p][c] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][c].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".B1(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".B1(new_n" << circuitRes[p][c] << "_" << "), ";
                }
            }

			if(atoi(circuitRes[p][d].c_str()) < variableNumber+accuracy){
				ofs << ".B2(x" << circuitRes[p][d] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][d].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".B2(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".B2(new_n" << circuitRes[p][d] << "_" << "), ";
                }
            }

            auto it = find(outputIndex.begin(), outputIndex.end(), variableNumber+accuracy+p);
            if(it != outputIndex.end()){
                ofs << ".ZN(out" << it-outputIndex.begin() << "));" << endl;
            }
            else{
                ofs << ".ZN(new_n" << variableNumber+accuracy+p << "_));" << endl;
            }
		}

		else if((circuitIndex[p] >= 14 && circuitIndex[p] <= 17) || (circuitIndex[p] >= 25 && circuitIndex[p] <= 28) || (circuitIndex[p] >= 36 && circuitIndex[p] <= 39) || (circuitIndex[p] >= 47 && circuitIndex[p] <= 50)){

			int position = circuitRes[p][0].find("-");

			string gateType = circuitRes[p][0].substr(0, position);

			int a = circuitRes[p][0][position+1] - '0';
			int b = circuitRes[p][0][position+2] - '0';
			int c = circuitRes[p][0][position+3] - '0';

			ofs << "  " << gateType << "  g" << p+index;
			if(atoi(circuitRes[p][a].c_str()) < variableNumber+accuracy){
				ofs << "(.A1(x" << circuitRes[p][a] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][a].c_str()));
                if(it != outputIndex.end()){
                    ofs << "(.A1(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << "(.A1(new_n" << circuitRes[p][a] << "_" << "), ";
                }
            }

			if(atoi(circuitRes[p][b].c_str()) < variableNumber+accuracy){
				ofs << ".A2(x" << circuitRes[p][b] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][b].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".A2(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".A2(new_n" << circuitRes[p][b] << "_" << "), ";
                }
            }


			if(atoi(circuitRes[p][c].c_str()) < variableNumber+accuracy){
				ofs << ".A3(x" << circuitRes[p][c] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][c].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".A3(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".A3(new_n" << circuitRes[p][c] << "_" << "), ";
                }
            }

            auto it = find(outputIndex.begin(), outputIndex.end(), variableNumber+accuracy+p);
            if(it != outputIndex.end()){
                ofs << ".ZN(out" << it-outputIndex.begin() << "));" << endl;
            }
            else{
                ofs << ".ZN(new_n" << variableNumber+accuracy+p << "_));" << endl;
            }
		}

        else if((circuitIndex[p] >= 52 && circuitIndex[p] <= 63) || (circuitIndex[p] >= 67 && circuitIndex[p] <= 78)){

			int position = circuitRes[p][0].find("-");

			string gateType = circuitRes[p][0].substr(0, position);

			int a = circuitRes[p][0][position+1] - '0';
			int b = circuitRes[p][0][position+2] - '0';
			int c = circuitRes[p][0][position+3] - '0';

			ofs << "  " << gateType << "  g" << p+index;
			if(atoi(circuitRes[p][a].c_str()) < variableNumber+accuracy){
				ofs << "(.A(x" << circuitRes[p][a] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][a].c_str()));
                if(it != outputIndex.end()){
                    ofs << "(.A(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << "(.A(new_n" << circuitRes[p][a] << "_" << "), ";
                }
            }

			if(atoi(circuitRes[p][b].c_str()) < variableNumber+accuracy){
				ofs << ".B1(x" << circuitRes[p][b] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][b].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".B1(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".B1(new_n" << circuitRes[p][b] << "_" << "), ";
                }
            }


			if(atoi(circuitRes[p][c].c_str()) < variableNumber+accuracy){
				ofs << ".B2(x" << circuitRes[p][c] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][c].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".B2(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".B2(new_n" << circuitRes[p][c] << "_" << "), ";
                }
            }

            auto it = find(outputIndex.begin(), outputIndex.end(), variableNumber+accuracy+p);
            if(it != outputIndex.end()){
                ofs << ".ZN(out" << it-outputIndex.begin() << "));" << endl;
            }
            else{
                ofs << ".ZN(new_n" << variableNumber+accuracy+p << "_));" << endl;
            }
		}

		else if((circuitIndex[p] >= 8 && circuitIndex[p] <= 13) || (circuitIndex[p] >= 19 && circuitIndex[p] <= 24) || (circuitIndex[p] >= 30 && circuitIndex[p] <= 35) || (circuitIndex[p] >= 41 && circuitIndex[p] <= 46)){

//			int index = -1;
//			string tmp = circuitRes[p][0];
//			for(auto m = 0; m < circuitRes[p][0].length(); m++){
//				if( tmp.at(m) == "-"){
//					index = m;
//				}
//			}

			int position = circuitRes[p][0].find("-");

			string gateType = circuitRes[p][0].substr(0, position);

			int a = circuitRes[p][0][position+1] - '0';
			int b = circuitRes[p][0][position+2] - '0';

			ofs << "  " << gateType << "  g" << p+index;
			if(atoi(circuitRes[p][a].c_str()) < variableNumber+accuracy){
				ofs << "(.A1(x" << circuitRes[p][a] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][a].c_str()));
                if(it != outputIndex.end()){
                    ofs << "(.A1(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << "(.A1(new_n" << circuitRes[p][a] << "_" << "), ";
                }
            }

			if(atoi(circuitRes[p][b].c_str()) < variableNumber+accuracy){
				ofs << ".A2(x" << circuitRes[p][b] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][b].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".A2(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".A2(new_n" << circuitRes[p][b] << "_" << "), ";
                }
            }

            auto it = find(outputIndex.begin(), outputIndex.end(), variableNumber+accuracy+p);
            if(it != outputIndex.end()){
                ofs << ".ZN(out" << it-outputIndex.begin() << "));" << endl;
            }
            else{
                ofs << ".ZN(new_n" << variableNumber+accuracy+p << "_));" << endl;
            }
		}

		else if((circuitIndex[p] >= 0 && circuitIndex[p] <= 3)){

			int position = circuitRes[p][0].find("-");

			string gateType = circuitRes[p][0].substr(0, position);

			int a = circuitRes[p][0][position+1] - '0';

			ofs << "  " << gateType << "  g" << p;
			if(atoi(circuitRes[p][a].c_str()) < variableNumber+accuracy){
				ofs << "(.A(x" << circuitRes[p][a] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][a].c_str()));
                if(it != outputIndex.end()){
                    ofs << "(.A(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << "(.A(new_n" << circuitRes[p][a] << "_" << "), ";
                }
            }

            auto it = find(outputIndex.begin(), outputIndex.end(), variableNumber+accuracy+p);
            if(it != outputIndex.end()){
                ofs << ".ZN(out" << it-outputIndex.begin() << "));" << endl;
            }
            else{
                ofs << ".ZN(new_n" << variableNumber+accuracy+p << "_));" << endl;
            }
		}

        else if((circuitIndex[p] >= 4 && circuitIndex[p] <= 7)){

			int position = circuitRes[p][0].find("-");

			string gateType = circuitRes[p][0].substr(0, position);

			int a = circuitRes[p][0][position+1] - '0';

			ofs << "  " << gateType << "  g" << p;
			if(atoi(circuitRes[p][a].c_str()) < variableNumber+accuracy){
				ofs << "(.A(x" << circuitRes[p][a] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][a].c_str()));
                if(it != outputIndex.end()){
                    ofs << "(.A(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << "(.A(new_n" << circuitRes[p][a] << "_" << "), ";
                }
            }

            auto it = find(outputIndex.begin(), outputIndex.end(), variableNumber+accuracy+p);
            if(it != outputIndex.end()){
                ofs << ".Z(out" << it-outputIndex.begin() << "));" << endl;
            }
            else{
                ofs << ".Z(new_n" << variableNumber+accuracy+p << "_));" << endl;
            }
		}

        else if((circuitIndex[p] >= 82 && circuitIndex[p] <= 83)){
            int position = circuitRes[p][0].find("-");

			string gateType = circuitRes[p][0].substr(0, position);

            ofs << "  " << gateType << "  g" << p << "(";

            auto it = find(outputIndex.begin(), outputIndex.end(), variableNumber+accuracy+p);
            if(it != outputIndex.end()){
                ofs << ".Z(out" << it-outputIndex.begin() << "));" << endl;
            }
            else{
                ofs << ".Z(new_n" << variableNumber+accuracy+p << "_));" << endl;
            }

        }

        else if(circuitIndex[p] >= 102 && circuitIndex[p] <= 105){

			int position = circuitRes[p][0].find("-");

			string gateType = circuitRes[p][0].substr(0, position);

			int a = circuitRes[p][0][position+1] - '0';
			int b = circuitRes[p][0][position+2] - '0';
			int c = circuitRes[p][0][position+3] - '0';

			ofs << "  " << gateType << "  g" << p+index;
			if(atoi(circuitRes[p][a].c_str()) < variableNumber+accuracy){
				ofs << "(.A(x" << circuitRes[p][a] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][a].c_str()));
                if(it != outputIndex.end()){
                    ofs << "(.A(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << "(.A(new_n" << circuitRes[p][a] << "_" << "), ";
                }
            }

			if(atoi(circuitRes[p][b].c_str()) < variableNumber+accuracy){
				ofs << ".B(x" << circuitRes[p][b] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][b].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".B(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".B(new_n" << circuitRes[p][b] << "_" << "), ";
                }
            }


			if(atoi(circuitRes[p][c].c_str()) < variableNumber+accuracy){
				ofs << ".CI(x" << circuitRes[p][c] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][c].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".CI(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".CI(new_n" << circuitRes[p][c] << "_" << "), ";
                }
            }

            auto it = find(outputIndex.begin(), outputIndex.end(), (variableNumber+accuracy+p)*10);
            if(it != outputIndex.end()){
                ofs << ".CO(out" << it-outputIndex.begin() << "), ";
            }
            else{
                ofs << ".CO(new_n" << (variableNumber+accuracy+p)*10 << "_), ";
            }

            it = find(outputIndex.begin(), outputIndex.end(), (variableNumber+accuracy+p)*10+1);
            if(it != outputIndex.end()){
                ofs << ".S(out" << it-outputIndex.begin() << "));" << endl;
            }
            else{
                ofs << ".S(new_n" << (variableNumber+accuracy+p)*10+1 << "_));" << endl;
            }
		}


        else if((circuitIndex[p] >= 96 && circuitIndex[p] <= 101)){


			int position = circuitRes[p][0].find("-");

			string gateType = circuitRes[p][0].substr(0, position);

			int a = circuitRes[p][0][position+1] - '0';
			int b = circuitRes[p][0][position+2] - '0';

			ofs << "  " << gateType << "  g" << p+index;
			if(atoi(circuitRes[p][a].c_str()) < variableNumber+accuracy){
				ofs << "(.A(x" << circuitRes[p][a] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][a].c_str()));
                if(it != outputIndex.end()){
                    ofs << "(.A(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << "(.A(new_n" << circuitRes[p][a] << "_" << "), ";
                }
            }

			if(atoi(circuitRes[p][b].c_str()) < variableNumber+accuracy){
				ofs << ".B(x" << circuitRes[p][b] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][b].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".B(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".B(new_n" << circuitRes[p][b] << "_" << "), ";
                }
            }

            auto it = find(outputIndex.begin(), outputIndex.end(), (variableNumber+accuracy+p)*10);
            if(it != outputIndex.end()){
                ofs << ".CO(out" << it-outputIndex.begin() << "), ";
            }
            else{
                ofs << ".CO(new_n" << (variableNumber+accuracy+p)*10 << "_), ";
            }

            it = find(outputIndex.begin(), outputIndex.end(), (variableNumber+accuracy+p)*10+1);
            if(it != outputIndex.end()){
                ofs << ".S(out" << it-outputIndex.begin() << "));" << endl;
            }
            else{
                ofs << ".S(new_n" << (variableNumber+accuracy+p)*10+1 << "_));" << endl;
            }
		}

        else if((circuitIndex[p] >= 84 && circuitIndex[p] <= 95)){

			int position = circuitRes[p][0].find("-");

			string gateType = circuitRes[p][0].substr(0, position);

			int a = circuitRes[p][0][position+1] - '0';
			int b = circuitRes[p][0][position+2] - '0';
			int c = circuitRes[p][0][position+3] - '0';

			ofs << "  " << gateType << "  g" << p+index;
			if(atoi(circuitRes[p][a].c_str()) < variableNumber+accuracy){
				ofs << "(.A(x" << circuitRes[p][a] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][a].c_str()));
                if(it != outputIndex.end()){
                    ofs << "(.A(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << "(.A(new_n" << circuitRes[p][a] << "_" << "), ";
                }
            }

			if(atoi(circuitRes[p][b].c_str()) < variableNumber+accuracy){
				ofs << ".B(x" << circuitRes[p][b] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][b].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".B(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".B(new_n" << circuitRes[p][b] << "_" << "), ";
                }
            }


			if(atoi(circuitRes[p][c].c_str()) < variableNumber+accuracy){
				ofs << ".S(x" << circuitRes[p][c] << "), ";
			}
            else{
                auto it = find(outputIndex.begin(), outputIndex.end(), atoi(circuitRes[p][c].c_str()));
                if(it != outputIndex.end()){
                    ofs << ".S(out" << it-outputIndex.begin() << "), ";
                }
                else{
                    ofs << ".S(new_n" << circuitRes[p][c] << "_" << "), ";
                }
            }

            auto it = find(outputIndex.begin(), outputIndex.end(), variableNumber+accuracy+p);
            if(it != outputIndex.end()){
                ofs << ".Z(out" << it-outputIndex.begin() << "));" << endl;
            }
            else{
                ofs << ".Z(new_n" << variableNumber+accuracy+p << "_));" << endl;
            }
		}

        // auto it = find(outputIndex.begin(), outputIndex.end(), variableNumber+accuracy+p);
        // if(it != outputIndex.end()){
        //     ofs << ".O(out" << it-outputIndex.begin() << "));" << endl;
        // }
        // else{
        //     ofs << ".O(new_n" << variableNumber+accuracy+p << "_));" << endl;
        // }

		// if(p < gate-1){
		// 	ofs << ".O(new_n" << variableNumber+accuracy+p << "_));" << endl;
		// }
		// else if (p == gate-1){
		// 	ofs << ".O(z0));" << endl;
		// }
	}
	ofs << "endmodule" << endl;

	// system("abc -c \"read mcnc.genlib; read -m solution.v; print_stats; write_dot solution.dot\"");
    char cmd[1000];

    strcpy(cmd, "abc -c \"read ./gate_library_MinAC/nangate_45nm_typ.lib; read -m ");
	strcat(cmd, sol1);
    strcat(cmd, "; print_stats\"");
    system(cmd);

	return area;
}
