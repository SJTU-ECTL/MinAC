#include "clause.h"


int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);  // Speed IO
    std::cin.tie(0);

    const int N = 4; //number of fanins for the operator
    const int maxFanout = 2;

    // first line: number of variables n and accuracy m
    // second line: gate r
    // following line:problem vector
    int variableNumber;
    int accuracy;
    int errorBound = 116;

    vector<int> featureVector;
    int temp;

    string prefix = "./";
    int maxIterationPerRun = 1;
    int gateKind = 106;

    int result = 0;
    int solutionNum = 0;

    ifstream ifs(prefix+"./input_dir/vector42.txt");
    auto line = string();
    getline(ifs, line); // first line
    stringstream ss;
    ss << line;
    ss >> variableNumber >> accuracy;

    ss.str(string());
    ss.clear();
    getline(ifs, line); // third line
    ss << line;
    while (ss >> temp)
    {
    	featureVector.push_back(temp);
    }

    char outputDir[100];
	strcpy(outputDir, "./output_MinAC/medBound");
	strcat(outputDir, std::to_string(errorBound).data());
	strcat(outputDir, "/");

    cout << "Variable number: " << variableNumber << endl;
    cout << "Accuracy: " << accuracy << endl;
    cout << "Error bound: " << errorBound << endl;
    cout << "The accurate outputs: ";
    for (auto f : featureVector)
    {
        cout << f << " ";
    }
    cout << endl << endl;

    map < vector<string>, string> gateLibrary;
    vector < vector <vector <int> > > gateTruthTable{};
    vector <double> gateArea{};
    vector <double> gateAreaTrue{};

    ifstream in(prefix+"./gate_library_MinAC/gate_multiple_output.txt");
    auto line1 = string();
    double area = 0;
    double areaTrue = 0;
    auto str1 = string();
    auto str2 = string();
    auto str3 = string();
    stringstream ss1;

    int num = 0;
    while(getline(in, line1)){
    	num++;
		if(num > gateKind){
			break;
		}

    	ss1.str(string());
    	ss1.clear();
    	ss1 << line1;
    	ss1 >> str1 >> area >> areaTrue >> str2 >> str3;
        vector <string> TB;
        TB.clear();
        TB.push_back(str2); //carry
        TB.push_back(str3); //sum
    	gateLibrary.insert(pair <vector<string>, string> (TB, str1));
    	gateArea.push_back(area);
        gateAreaTrue.push_back(areaTrue);
        

        vector < vector <int> > tmp0;

    	vector <int> tmp1;
    	tmp1.clear();

    	for(auto j = 0; j < str2.size(); j++){
    		tmp1.push_back(str2[j]-'0');
    	}

        tmp0.push_back(tmp1);

        vector <int> tmp2;
    	tmp2.clear();

    	for(auto j = 0; j < str3.size(); j++){
    		tmp2.push_back(str3[j]-'0');
    	}

        tmp0.push_back(tmp2);

    	gateTruthTable.push_back(tmp0);
    }

    int gateCate = 0;  // The number of gate indexes need to be added for each gate
    for(auto i = 0; i < gateArea.size(); i++){
        gateCate = gateCate + gateArea[i];
    }

    vector <int> gateNumSet(4, 100);
    vector <double> areaSet(4, 100);

    auto start = chrono::system_clock::now();
    int minGateNum = 100;
    double A0;
    int gate = 0;
    int flag = 1;
    int gateGap;

    if(errorBound < 5){
        gateGap = 1;
    }
    else if(errorBound == 16){
        gateGap = 3;
    }
    else{
        gateGap = 2;
    }

    while(gate <= minGateNum + gateGap){
        for(; gate < 100; gate++){
            cout << "gate Number:" << gate << endl;
            context c;
            solver s(c);

            auto solutionClause = ConstructClause(variableNumber, accuracy, gate, gateCate, gateKind, N, maxFanout, featureVector, gateTruthTable, c, gateLibrary);

            // open a file to store all CNF clauses
            ofstream outputfile;
            outputfile.open("./temp_dir/test53.cnf");

            cout << "Construct Main clause:" << endl;
            solutionClause.ConstructMainClause(outputfile, c, s);

            cout << "Construct First clause:" << endl;
            solutionClause.Construct1stClause(outputfile, c, s);

            cout << "Construct gate index constraint:" << endl;
            solutionClause.GateIndexConstraintZ3(outputfile, gateKind, gateArea, c, s);

            cout << "Construct output constraint:" << endl;
            solutionClause.ConstructOutputConstraint(outputfile, c, s);

            cout << "Construct error constraint:" << endl;
            solutionClause.errorConstraint(outputfile, c, s, errorBound);

            result = solutionClause.SMTSolverSingleSol(c, s, maxIterationPerRun);

            if(result == 1){
                if(flag){
                    minGateNum = gate;
                    flag = 0;
                }

                model m = s.get_model();
                A0 = solutionClause.PrintVerifyCircuitZ3WithoutXor(outputDir, m, gateArea, gateAreaTrue, errorBound, solutionNum, areaSet, gateNumSet);
                cout << endl << endl;
                break;
            }
        }

    //    for(A0 = 16; A0 > 0;){
        for(A0 = A0-1; A0 > 0;){
            cout << "gate Number:" << gate << ", ";
            cout << "with circuit area:" << A0 << endl;
            context c;
            solver s(c);

            auto solutionClause = ConstructClause(variableNumber, accuracy, gate, gateCate, gateKind, N, maxFanout, featureVector, gateTruthTable, c, gateLibrary);

            // open a file to store all CNF clauses
            ofstream outputfile;
            outputfile.open("./temp_dir/test53.cnf");


            cout << "Construct Main clause:" << endl;
            solutionClause.ConstructMainClause(outputfile, c, s);

            cout << "Construct First clause:" << endl;
            solutionClause.Construct1stClause(outputfile, c, s);

            cout << "Construct gate index constraint:" << endl;
            solutionClause.GateIndexConstraintZ3(outputfile, gateKind, gateArea, c, s);

            cout << "Construct output constraint:" << endl;
            solutionClause.ConstructOutputConstraint(outputfile, c, s);

            cout << "Construct area constraint:" << endl;
            solutionClause.areaConstraintZ3(outputfile, gateKind, gateArea, A0, c, s);

            cout << "Construct error constraint:" << endl;
            solutionClause.errorConstraint(outputfile, c, s, errorBound);

            result = solutionClause.SMTSolverSingleSol(c, s, maxIterationPerRun);

            if(result == 1){
                model m = s.get_model();
                double tmpArea = solutionClause.PrintVerifyCircuitZ3WithoutXor(outputDir, m, gateArea, gateAreaTrue, errorBound, solutionNum, areaSet, gateNumSet);
                A0 = tmpArea - 1;
                cout << endl << endl;
            }
            if(result == 0){
                solutionNum++;
                cout << "Find Optimal Area!" << endl;
                cout << endl << endl;
                break;
            }
        }
        gate++;

    }

    auto minPos = min_element(areaSet.begin(), areaSet.end());
	cout << "The optimal gate number is: " << gateNumSet[minPos - areaSet.begin()];
	cout << ", and the optimal area is: " << *minPos << endl << endl;

	char sol[1000];
	 strcpy(sol, outputDir);
	 strcat(sol, "bestSol_summary");
	 strcat(sol, ".txt");
	 ofstream out(sol);
	 out << "The optimal ASCP is stored in solution" << minPos - areaSet.begin() << ".v" << endl;
     out << "The optimal gate number is: " << gateNumSet[minPos - areaSet.begin()];
	 out << ", and the optimal area is: " << *minPos << endl << endl;   

    cout << "Total running time:" << endl;
    auto end1 = chrono::system_clock::now();
    auto duration1 = chrono::duration_cast<std::chrono::milliseconds>(end1 - start);
    auto milliseconds1 = duration1.count();
    cout << "milliseconds: " << milliseconds1 << endl;
    auto hours1 = milliseconds1 / 3600000;
    milliseconds1 -= hours1 * 3600000;
    auto minitues1 = milliseconds1 / 60000;
    milliseconds1 -= minitues1 * 60000;
    auto seconds1 = milliseconds1 / 1000;
    milliseconds1 -= seconds1 * 1000;
    cout << "Time used: ";
    cout << hours1 << ":";
    cout.fill('0');
    cout.width(2);
    cout << minitues1 << ":";
    cout.fill('0');
    cout.width(2);
    cout << seconds1 << ".";
    cout.fill('0');
    cout.width(3);
    cout << milliseconds1 << endl;
    cout << endl;

    return 0;
}

