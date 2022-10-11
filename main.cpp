#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include <typeinfo>
#include"vertex.h"
#include"edge.h"
using namespace std;

vector<string> split(string str, char delimiter);

int main(){
    vector<vertex> vertexs;
    vector<edge> edges;
    ifstream readFile;
    readFile.open("SAMPLE");
    if(readFile.is_open()){
        cout << "file is open!" << endl;
        char arr[256];
        while(!readFile.eof()){
            readFile.getline(arr, 256);
            cout << arr << endl;
            vector<string> split_vector = split(arr, ' '); // split string
            if(split_vector[0] == "v"){
                vertex v;
                v.setId(stoi(split_vector[1]));
                v.setLabel(stoi(split_vector[2]));
                vertexs.push_back(v);
            }else if(split_vector[0] == "e"){
                edge e;
                e.setEdge(stoi(split_vector[1]), stoi(split_vector[2]));
                e.setLabel(stoi(split_vector[3]));
                edges.push_back(e);
            }
        }
    }
    readFile.close();

    // for(int i = 0 ; i < vertexs.size() ; i++){
    //     cout << vertexs[i].getId() << " " << vertexs[i].getLabel() << endl;
    // }
    // for(int i = 0 ; i < edges.size() ; i++){
    //     cout << edges[i].getEdge()[0] << " " << edges[i].getEdge()[1] << endl;
    // }
    int adjancency_matrix[vertexs.size()][vertexs.size()]; // initialization 2-d array to 0
    memset(adjancency_matrix, 0, sizeof(adjancency_matrix));
    for(int i = 0 ; i < edges.size() ; i++){
        adjancency_matrix[edges[i].getEdge()[0]][edges[i].getEdge()[1]] = 1;
    }
    for(int i = 0 ; i < vertexs.size() ; i++){
        for(int j = 0 ; j < vertexs.size() ; j++){
            cout << adjancency_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
    return result;
}