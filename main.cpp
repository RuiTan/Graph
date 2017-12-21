#include <fstream>
#include "Graphmtx.h"
#include "Graphlnk.h"

int main(){
    ifstream file("infile.txt");
    if (!file){
        cout << "no file";
    }else{
        Graphmtx<int, int> graphmtx;
        file >> graphmtx;
        cout << graphmtx;

    }
    ifstream file2("infile2.txt");
    if (!file2){
        cout << "no file";
    }else{
        Graphlnk<char, int> graphlnk;
        file2 >> graphlnk;
        cout << graphlnk;
    }
}