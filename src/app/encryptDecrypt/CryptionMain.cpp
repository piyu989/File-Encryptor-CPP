#include <iostream>
#include "Cryption.hpp"

using namespace std;

int main(int args,char* argv[]){

    if(args!=2){
        cerr<< "Usage: ./cryption <task_data>"<<endl;
        return 1;
    }
    executionCryption(argv[1]);
    return 0;
}