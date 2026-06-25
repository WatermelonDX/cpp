#include "hashtable.h"
#include <iostream>

using namespace std;

int main(){
    fstream file("thewords.txt");
    string val;
    table mytable;
    int i = 0;
    int coll = 0;
    
    if(!file.is_open()){
        cout << "Couldn't open file, retry" << endl;
        exit(-1);
    }

    while(file >> val){
        coll = coll + mytable.add(val, i, method);
        i++;
    }

    int total = mytable.show();
    cout << "Coliisions: " << coll  << "| Total entries: "<< total << endl; 
}



