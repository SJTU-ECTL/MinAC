# MinAC Overview

Given any input distribution and error bound, this project implements the exact-synthesis method to automatically produce minimal-area approximate 4-2 compressors. To directly obtain an area-optimal circuit using an industrial gate library, gates with multiple outputs are taken into account during the exact synthesis. 

Related papers:
- [1]: X. Wang and W. Qian, “MinAC: Minimal-Area Approximate Compressor Design Based on Exact Synthesis for Approximate Multipliers,” in ISCAS, 2022.

Reference papers:
- [2]: C.-H. Lin and I.-C. Lin, “High accuracy approximate multiplier with error correction,” in International Conference on Computer Design, 2013, pp. 33–38.
- [3]: A. Momeni, J. Han, P. Montuschi, and F. Lombardi, “Design and analysis of approximate compressors for multiplication,” IEEE Transactions on Computers, vol. 64, no. 4, pp. 984–994, 2014.
- [4]: S. Venkatachalam and S.-B. Ko, “Design of power and area efficient approximate multipliers,” IEEE Transactions on Very Large Scale Integration (VLSI) Systems, vol. 25, no. 5, pp. 1782–1786, 2017.
- [5]: Z. Yang, J. Han, and F. Lombardi, “Approximate compressors for error-resilient multiplier design,” in International Symposium on Defect and Fault Tolerance in VLSI and Nanotechnology Systems, 2015, pp. 183–186.
- [6]: M. Ha and S. Lee, “Multipliers with approximate 4-2 compressors and error recovery modules,” IEEE Embedded Systems Letters, vol. 10, no. 1, pp. 6–9, 2017.
- [7]: O. Akbari, M. Kamal, A. Afzali-Kusha, and M. Pedram, “Dual-quality 4:2 compressors for utilizing in dynamic accuracy configurable multipliers,” IEEE Transactions on Very Large Scale Integration (VLSI) Systems, vol. 25, no. 4, pp. 1352–1361, 2017.
- [8]: M. Ahmadinejad, M. H. Moaiyeri, and F. Sabetzadeh, “Energy and area efficient imprecise compressors for approximate multiplication at nanoscale,” AEU-International Journal of Electronics and Communications, vol. 110, p. 152859, 2019.
- [9]: A. G. M. Strollo, E. Napoli, D. D. Caro, N. Petra, and G. D. Meo, “Comparison and extension of approximate 4-2 compressors for low-power approximate multipliers,” IEEE Transactions on Circuits and Systems I: Regular Papers, vol. 67, no. 9, pp. 3021–3034, 2020.

## Requirements

- OS: 64-bit Linux
- gcc
- g++
- EDA logic synthesis tools: [ABC](http://people.eecs.berkeley.edu/~alanmi/abc/) executable file
- SMT Solver: [Z3](https://github.com/Z3Prover/z3)

## Important Notes

- Since the program requires the EDA tools [ABC](http://people.eecs.berkeley.edu/~alanmi/abc/),[MVSIS](https://ptolemy.berkeley.edu/projects/embedded/mvsis/), and SMT Solver [Z3](https://github.com/Z3Prover/z3), please download the appropriate executable files or compile the source codes in your OS. 
 - For ABC, suppose the absolute directory containing the executable file `abc` is `<abc_exe_absolute_directory>`. Then, before compiling the MinSC program, please execute command: ` cp abc_exe_absolute_directory /usr/bin/abc`, which ensures ABC can run in an arbitrary path.
  
## Getting Started
### Configuration in Project
- Install Z3 at a self-defined path `Z3_Path`
- Set up a C++ project;
- Add the source files and header files in the folder `src/`;
- Configure the library path of Z3 for this project:

  Project->Property->
  - GCC C++ Complier->Includes->Include paths->Add->: `Z3_Path\src\api`;
  - GCC C++ Complier->Includes->Include paths->Add->: `Z3_Path\src\api\c++`;
  - GCC C++ Linker->Library search path(-L)->Add： `Z3_Path\build`;
  - GCC C++ Linker->Libraries(-l)->Add： `z3`;

### Input Format
- `errorBound e_b` : the MED error bound of the approximate 4-2 compressors.  
In our experiment, the inputs are set as uniformly distributed. Thus, the error bound `errorBound e_b` is represented as `e_b/256`, where the numerator is an integer. For each existing design, we calculate its MED e_b. Then, MinAC is applied to synthesize approximate 4-2 compressors with MED no more than e_b.  Below is the MED of approximate 4-2 compressors from Reference papers.
   ```
   approximate 4-2 compressors    MED `e_b`
    -------------------------------------
    Momeni[3]                    100
    Venka[4]                     37
    Yang1[5]                     1
    Yang2[5]                     10
    Yang3[5]                     16
    Lin[2]                       2
    Ha[6]                        16
    Akbar1[7]                    116
    Akbar2[7]                    38
    Ahma[8]                      55
    Strollo[9]                   4
   ```
   
 ## Program Organization

```
<program_dir>
| readme.md
|----src
|     |----(source files)
|----gate_library_MinAC
|     |----nangate_45nm_typ.lib
|     |----gate_multiple_output.txt(the gate library after extending nangate_45nm_typ.lib)
|----input_dir
|     |----vector42.txt (the PO number, PI number-PO number, and the truth table of the exact 4-2 compressor)
|----temp_dir
|     |----(temporary files)
|----output_MinAC
|     |----medBound116
|     |     |----solution0.v
|     |     |----summary0.txt
|     |     |----solution1.v
|     |     |----summary1.txt
|     |     |----bestSol_summary.txt
|     |----(and so on)
|----examples_demo_results
|     |----medBound116
|     |     |----solution0.v
|     |     |----summary0.txt
|     |     |----solution1.v
|     |     |----summary1.txt
|     |     |----bestSol_summary.txt
|     |----(and so on)
```

- `src`: contains all source files and header files.
- `gate_library_MinAC`: contains the nangate_45nm_typ.lib and gate_multiple_output.txt. The file gate_multiple_output.txt is the gate library after extending nangate_45nm_typ.lib. For a gate with the input number less than 4 or the output number less than 2, it is extended to a 4-input 2-output gate.
- `input_dir`: contains the input file called vector42.txt.
   Format of each row in the `vector42`.txt file:
```
   First row: (PI number) (PO number)
   Second row: the truth table of the exact 4-2 compressor, which is represented as the binary encoded number of all PO values.
```
- `temp_dir`: contains temporary files generated during the running of the program.
- `output_MinAC`: contains ten sub-folders with different MED bound `e_b`. For each sub-folder, it contains the following files:
  - `bestSol_summary.txt`: the overall summary of the best solution with minimal area.
  - `solution<num>.v`: the gate-level Verilog file for the solution with number `<num>`. 
  - `summary<num>.txt`: the summary of the solution with number `<num>`.  
  Different `solution<num>.v` are the solution Verilog files with different gate numbers. `solution0.v` is the verilog file with the smallest gate number `r_min` which satisfies the error requirement. Other verilog files `solution<num>.v` are the circuit with gate number `r_min+num` which satisfy the error requirement. For these Verilog files, we choose the circuit with the smallest area as the best solution, and the summary of the best solution is stored in `bestSol_summary.txt`.
- `examples_demo_results`: contains ten sub-folders with different MED bound `e_b`. The MED bound `e_b` is set as our paper [1]. For each sub-folder, it contains the following files:
  - `bestSol_summary.txt`: the overall summary of the best solution with minimal area.
  - `solution<num>.v`: the gate-level Verilog file for the solution with number `<num>`.
  - `summary<num>.txt`: the summary of the solution with number `<num>`.

If you have any questions or suggestions, please feel free to eamil to xuan.wang@sjtu.edu.cn, thanks!
