#include"Algos.h"
int main(int argc, char** argv) {

    if(argc==1){
        cout<<"Wrong number of arguments"<<endl;
        cout<<"Format: [exe] [inputfile.txt]"<<endl;
        exit(1);
    }
    // process file
    Algos a(argv[1]);

    // run algos
    a.bruteForce();

    cout<<"Running most expensive first algo.."<<flush;
    a.expFirstAlgo();



    cout<<"Running custom algo.."<<flush;
    a.customAlgo();


    return 0;
}

