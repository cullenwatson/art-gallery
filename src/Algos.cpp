#include"Algos.h"
#include <chrono>
void removeSubstring(string&, string);

void Algos::customAlgo(){
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    //get the current time, run the algo, then get the current time again
    start = std::chrono::high_resolution_clock::now();
    // reset optimal vars
    oSet.clear();
    optimalCost = 0;

    sort(pSet.begin(), pSet.end());

    int totalWidth = 0, totalVal = 0;

    for(int i=0;i<pSet.size(); i++){
        if(totalWidth == wallWidth)
            break;
        else if(pSet[i].getWidth() < 1000 && totalWidth + pSet[i].getWidth() <= wallWidth){
            oSet.push_back(pSet[i]);
            optimalCost += pSet[i].getVal();
            totalWidth += pSet[i].getWidth();
        }
    }
    removeSubstring(fileName,"-highvalue.txt");
    fileName += "-custom.txt";
    outputOptimalSet();
    end = std::chrono::high_resolution_clock::now();

    //calculate the duration between start and end and print to the terminal
    std::chrono::duration<double> time_in_seconds = end - start;
    cout<<".complete!"<<endl;
    std::cout << std::fixed << "Duration: " << time_in_seconds.count() << std::endl<<endl;

}
void Algos::expFirstAlgo(){
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    //get the current time, run the algo, then get the current time again
    start = std::chrono::high_resolution_clock::now();
    // reset optimal vars
    oSet.clear();
    optimalCost = 0;

    sort(pSet.begin(), pSet.end());

    int totalWidth = 0, totalVal = 0;

    for(int i=0;i<pSet.size(); i++){
        if(totalWidth == wallWidth)
            break;
        else if(totalWidth + pSet[i].getWidth() <= wallWidth){
            oSet.push_back(pSet[i]);
            optimalCost += pSet[i].getVal();
            totalWidth += pSet[i].getWidth();
        }
    }
    removeSubstring(fileName,"-bruteforce.txt");
    fileName += "-highvalue.txt";
    outputOptimalSet();
    end = std::chrono::high_resolution_clock::now();

    //calculate the duration between start and end and print to the terminal
    std::chrono::duration<double> time_in_seconds = end - start;
    cout<<".complete!";
    std::cout <<endl<< std::fixed << "Duration: " << time_in_seconds.count() << std::endl<<endl;


}

Algos::Algos(string file){
    // remove .txt from filename
    fileName = file;
    string target = ".txt";
    removeSubstring(fileName, target);
    target = "../input/";
    removeSubstring(fileName, target);
    // read in input
    processFile(file);
}
void Algos::outputOptimalSet(){
    ofstream f( fileName);
    if(f){
        f << "             Wall Size: " << wallWidth<<"x"<<wallHeight << "      "<<endl;
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


void Algos::bruteForce() {
    if(numPics>29)
        return;
    cout<<"Running brute force algo.."<<flush;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    //get the current time, run the algo, then get the current time again
    start = std::chrono::high_resolution_clock::now();

    optimalCost = 0;
    vector<Painting> subset;
    makeSubset(pSet, subset, 0);

    // cout << "OPTIMAL SET\n";
    //cout<<fileName<<endl;
    fileName += "-bruteforce.txt";
    outputOptimalSet();
    cout<<".complete!"<<endl;

    end = std::chrono::high_resolution_clock::now();

    //calculate the duration between start and end and print to the terminal
    std::chrono::duration<double> time_in_seconds = end - start;
    std::cout << std::fixed << "Duration: " << time_in_seconds.count() << std::endl<<endl;


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
void Algos::makeSubset(vector<Painting>& a, vector<Painting>& subset, int index){

    if(index>0){
        int totalCost=0, totalWidth = 0;
        for(int i=0; i<subset.size();i++){
            //cout<<subset[i];
            totalCost+=subset[i].getVal();
            totalWidth+=subset[i].getWidth();

        }
        /*if(totalWidth>wallWidth)
            cout<<"TOO WIDE ";*/
        if(totalWidth <= wallWidth && totalCost > optimalCost){
            oSet = subset;
            optimalCost = totalCost;
            //cout<<totalWidth<< " "<<totalCost<<endl;
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
void removeSubstring(string& str, string target){
    int found = -1;
    do{
        found = str.find(target, found+1);
        if(found!=-1){
            str=str.substr(0,found)+str.substr(found+target.length());
        }
    }while(found!=-1);
}