/*
 * Brute force algo help found at https://www.geeksforgeeks.org/backtracking-to-find-all-subsets/
 */
#ifndef CS3353_PA01_ALGOS_H
#define CS3353_PA01_ALGOS_H
#include<vector>
#include<fstream>
#include<string>
#include<iomanip>
#include "Painting.h"
#include <algorithm>

class Algos{
    int wallWidth, wallHeight, numPics;
    string fileName;
    vector<Painting> pSet;

    // reset for each algo
    vector<Painting> oSet;
    int optimalCost;

    void processFile(string);
    void makeSubset(vector<Painting>&, vector<Painting>&, int);
    void outputOptimalSet();
public:
    Algos(string);
    void bruteForce();
    void expFirstAlgo();
    void customAlgo();

};


#endif //CS3353_PA01_ALGOS_H
