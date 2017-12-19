#include <fstream>
#include "Graphmtx.h"

int main(){
    ifstream file("infile.txt");
    if (!file){
        cout << "no file";
    }else{
        Graphmtx<int, int> graphmtx;
        file >> graphmtx;
        cout << graphmtx;
    }
}