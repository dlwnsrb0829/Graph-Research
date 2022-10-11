#include<iostream>
#include<cstring>
#include<fstream>
#include<sstream>
#include<vector>
#include<typeinfo>
#include"vertex.h"
#include"edge.h"
using namespace std;

vector<string> split(string str, char delimiter);
void DFS(int i, int **matrix, bool visited[], int size);

int main(){
    vector<vertex> vertexs;
    vector<edge> edges;
    ifstream readFile;
    readFile.open("SAMPLE");
    if(readFile.is_open()){
        char arr[256];
        while(!readFile.eof()){
            readFile.getline(arr, 256);
            // cout << arr << endl;
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

    int **adj_matrix;
    adj_matrix = new int *[vertexs.size()];
    for(int i = 0 ; i < vertexs.size() ; i++){
        adj_matrix[i] = new int[vertexs.size()];
        memset(adj_matrix[i], 0, sizeof(*adj_matrix[i]));
    }
    bool visited[vertexs.size()];
    memset(visited, false, sizeof(visited));

    for(int i = 0 ; i < edges.size() ; i++){
        adj_matrix[edges[i].getEdge()[0]][edges[i].getEdge()[1]] = 1;
        adj_matrix[edges[i].getEdge()[1]][edges[i].getEdge()[0]] = 1;
    }
    for(int i = 0 ; i < vertexs.size() ; i++){
        for(int j = 0 ; j < vertexs.size() ; j++){
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
    DFS(0, adj_matrix, visited, vertexs.size());
    cout << endl;
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

void DFS(int u, int** matrix, bool visited[], int size){
    cout << u << " ";
    visited[u] = true;
    for(int i = 0 ; i < size ; i++){
        if(matrix[u][i] == 1 && !visited[i]){
            DFS(i, matrix, visited, size);
        }
    }
}