#include"Algos.h"
int main(int argc, char** argv) {

    // process file
    Algos a(argv[1]);

    // run algos
    a.bruteForce();
    a.expFirstAlgo();
    a.customAlgo();
    return 0;
}

