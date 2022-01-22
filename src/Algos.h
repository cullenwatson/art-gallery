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
class Algos{
    int wallWidth, wallHeight, numPics;
    string fileName;
    vector<Painting> pSet;

    // for brute force
    vector<Painting> oSet;
    int optimalCost;

    void processFile(string);
    void makeSubset(vector<Painting>&, vector<Painting>&, int);
public:
    Algos(string);
    void bruteForce();

};
Algos::Algos(string file){
    // remove .txt from filename
    fileName = file;
    string target = ".txt";

    int found = -1;
    do{
        found = fileName.find(target, found+1);
        if(found!=-1){
            fileName=fileName.substr(0,found)+fileName.substr(found+target.length());
        }
    }while(found!=-1);

    /*target = "../input";
    found = -1;
    do{
        found = fileName.find(target, found+1);
        if(found!=-1){
            fileName=fileName.substr(0,found)+fileName.substr(found+target.length());
        }
    }while(found!=-1);*/


    // read in input
    processFile(file);
}

void Algos::processFile(string file){
    ifstream f(file);


    int picId, picValue, picWidth, picHeight;
    if(f){
        // read in num of paintings
        f >> wallWidth >> wallHeight >> numPics;

        // read in each individual painting
        while(f.good()){
            f >> picId >> picValue >> picWidth >> picHeight;
            Painting p(picId, picValue, picWidth, picHeight);

            //cout<<p;

            pSet.push_back(p);

        }

        f.close();
    }
    else{
        cout<<"Failed to open input file";
        exit(1);
    }
}
void Algos::bruteForce() {
    optimalCost = 0;
    vector<Painting> subset;
    makeSubset(pSet, subset, 0);

    // cout << "OPTIMAL SET\n";
    //cout<<fileName<<endl;
    ofstream f( fileName + "-bruteforce.txt");
    if(f){
        f << "       ---Value of Gallery $" << setprecision(2)<< fixed<<float(optimalCost) << "---"<<endl;
        f << setw(10)<<"[id]" << setw(10)<<"[value]"<< setw(10)<<"[width]"<< setw(10)<<"[height]"<<endl;

        for (int i = 0; i < oSet.size(); i++) {
            f << oSet[i];
        }
        f.close();
    }
    else{
        cout<<"Could not open output file for writing"<<endl;
    }

}
void Algos::makeSubset(vector<Painting>& a, vector<Painting>& subset, int index){

    if(index>0){
        int totalVal=0, totalWidth = 0;
        for(int i=0; i<subset.size();i++){
            //cout<<subset[i];
            totalVal+=subset[i].getVal();
            totalWidth+=subset[i].getWidth();

        }
        /*if(totalWidth>wallWidth)
            cout<<"TOO WIDE ";*/
        if(!(totalWidth>wallWidth)){
            if(totalVal > optimalCost){
                oSet = pSet;
                optimalCost = totalVal;
            }
        }
        // cout<< "$: "<<totalVal << endl << endl;
    }


    for (int i = index; i < a.size(); i++) {

        // include the A[i] in subset.
        subset.push_back(a[i]);

        // move onto the next element.
        makeSubset(a, subset, i + 1);

        // exclude the A[i] from subset and triggers
        // backtracking.
        subset.pop_back();
    }
}


#endif //CS3353_PA01_ALGOS_H
