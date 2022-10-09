#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main(){
    ifstream readFile;
    readFile.open("SAMPLE");
    if(readFile.is_open()){
        cout << "file is open!" << endl;
        char arr[256];
        while(!readFile.eof()){
            readFile.getline(arr, 256);
            cout << arr << endl;
            char *token = strtok(arr, " ");
            while(token != NULL){
                cout << token << "" << endl;
                token = strtok(NULL, " ");
            }
        }
        
    }
    readFile.close();

    return 0;
}