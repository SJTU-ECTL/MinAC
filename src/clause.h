#pragma once
#ifndef CLAUSE_H
#define CLAUSE_H

#include "z3++.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <sstream>
#include <unordered_map>
#include <map>
#include <assert.h>
#include <numeric>
#include <chrono>

using namespace std;
using namespace z3;
//using std::cout;
//using std::cin;
//using std::vector;
//using std::string;
//using std::unordered_map;
//using std::pair;
//using std::stringstream;
//using std::fstream;
//using std::ifstream;

typedef pair< vector<vector <int> >, vector < vector <int> >> MatInfo;
typedef pair< vector <int> , vector <int> > IndexRelation;

class ConstructClause{
public:
    ConstructClause(int _variableNumber, int _accuracy, int _gate, int _gateCate, int _gateKind, int N, int _maxFanout, vector <int> _featureVector, vector <vector <vector <int> >> _gateTruthTable, context& c, map <vector <string>, string> _gateLibrary);
    vector <vector <IndexRelation> > AddAdditionalVariable(context& c, MatInfo IndexMatrix, vector <int> largestCubeVector, vector <int> featureVector, vector <int> toBeAssignedCV1, int coarseGrain1, vector <int> toBeAssignedCV2, int coarseGrain2);

    void ConstructMainClause(ofstream& outputfile, context& c1, solver& s);
//    void ConstructMainClauseWithCutSet(ofstream& outputfile, vector < vector <int> > DAG, vector <int> cutEdge);
//    void ConstructMainClauseWithFence(ofstream& outputfile, vector < vector <int> > DAG);

    void SymmetryBreakingConstraints(ofstream& outputfile);
    void MaxFanout(ofstream& outputfile, int maxFanout);
    void MaxDepthConstraint(ofstream& outputfile, int maxFenceDepth, vector < vector <int> > DAG);

    void Construct1stClause(ofstream& outputfile, context& c, solver& s);

    MatInfo PrepareForConstruct2ndClause();

    void Construct2ndClause(ofstream& outputfile, vector < vector <int> > indexOfXn_mInG, vector <int> largestCubeVector, vector <int> cubeMat);

    void ConstructFVClause(string prefix, ofstream& outputfile, vector <int> featureVector, vector <int> largestCubeVector, vector<int> toBeAssignedCV, vector <IndexRelation> AllVarRelation, int coarseGrain, MatInfo IndexMatrix);

    void ConstructFVClauseWithoutESPRESSO(string prefix, ofstream& outputfile, vector <int> featureVector, vector <int> largestCubeVector, vector<int> toBeAssignedCV1, vector <vector <IndexRelation> > AllVarRelation, int coarseGrain1, MatInfo IndexMatrix, vector <int> toBeAssignedCV2, int coarseGrain2, context& c, solver& s);

    void ConstructOutputConstraint(ofstream& outputfile, context& c, solver& s);

    void GateLibrary(ofstream& outputfile, context& c, solver& s);

    void GateIndexConstraint(ofstream& outputfile, int gateKind, vector <int> gateArea);

    void GateIndexConstraintZ3(ofstream& outputfile, int gateKind, vector <double> gateArea, context& c, solver& s);

    void areaConstraintZ3(ofstream& outputfile, int gateKind, vector <double> gateArea, double maxArea, context& c, solver& s);

    void errorConstraint(ofstream& outputfile, context& c, solver& s, int errorBound);

    string SATSolver(int tryNum, int maxSolutionNum,string prefix, ofstream& outputfile, vector < vector <int> > indexOfXn_mInG);

    int SMTSolverMultipleSol(context& c, solver& s, int maxIterationPerRun, vector <int> gateArea, int errorBound, int runNum);

    int SMTSolverSingleSol(context& c, solver& s, int maxIterationPerRun);

    int PrintCircuit(string prefix, vector < vector <int> > indexOfXn_mInG);

    int PrintVerifyCircuitZ3(model& m, vector <int> gateArea, int errorBound, int solutionNum);

    double PrintVerifyCircuitZ3WithoutXor(char* outputDir, model& m, vector <double> gateArea, vector <double> gateAreaTrue, int errorBound, int solutionNum, vector <double>& areaSet, vector <int>& gateNumSet);

    void VerifyCircuit(string prefix, int solutionNum);
    void MappingAfterSAT(string prefix, int solutionNum);

    int variableNumber;
    int accuracy;
    int gate;
    int gateCate;
    int gateKind;
    int N;
    int maxFanout;
    vector <int> featureVector;
    vector < vector < vector <int> > > X_known;
    // vector < vector <int> > X_known;
    vector < vector <int> > X_unknown;

    vector < vector <int> > AssMatrix;
    vector < vector <int> > S;
    vector < vector <int> > f;
    vector < vector <int> > GateIndex;
    vector < vector <vector <int> >> gateTruthTable;
    vector <int> YVariable;
    vector <int> ZVariable;
    vector <int> SumColumn;
    map < vector<string>, string> gateLibrary;

    vector <int> probabilityVec;

    vector < vector < vector <expr> > > X_Unknown_Z3;
    vector < vector < vector <expr> > > outputGateIndex;
    vector < vector < vector <expr> > > outputGateIndex_INT;
    vector < vector <expr> > outputTruthTable;
    vector < vector <expr> > outputTruthTable_Z3_INT;
    vector < vector < vector <expr> > > S_Z3;
    vector < vector < vector <expr> > > S_Z3_INT;
    vector < vector < vector <expr> > > f_Z3;
    vector < vector <expr> > GateIndex_Z3;
    vector < vector <expr> > GateIndex_Z3_INT;
    vector <expr> Y_Variable_Z3;
    vector <expr> Z_Variable_Z3;

    vector <int> maximumfanout;
};

void dfs(int n, int k, int index, vector<int>& path, vector <vector <int> >& res);
vector <vector <int> > combine(int n, int k);
vector <vector <int>> ProduceBinComb(int n, int k);
int Bin_To_Dec(int b, int c, int d, int e);
void q(int n, int m, int i, int level, int k);
vector < vector <int> > GenerateFence(int gateNum);

#endif
