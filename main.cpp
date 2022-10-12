#include<iostream>
#include<cstring>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>
#include<typeinfo>
#include<ctime>
#include"vertex.h"
#include"edge.h"
using namespace std;

vector<string> split(string str, char delimiter);
void DFS_use_recursion(int i, int **matrix, bool visited[], int size);
void DFS_use_stack(int start, int** matrix, bool visited[], stack<int> stk, int size);

int main(){
    vector<vertex> vertexs;
    vector<edge> edges;
    ifstream readFile;
    readFile.open("SAMPLE");
    if(readFile.is_open()){
        char arr[256];
        while(!readFile.eof()){
            readFile.getline(arr, 256);
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
        memset(adj_matrix[i], 0, sizeof(int) * vertexs.size());
    }
    bool visited[vertexs.size()];
    memset(visited, false, sizeof(bool) * vertexs.size());
    for(int i = 0 ; i < edges.size() ; i++){
        adj_matrix[edges[i].getEdge()[0]][edges[i].getEdge()[1]] = 1;
        adj_matrix[edges[i].getEdge()[1]][edges[i].getEdge()[0]] = 1;
    }
    stack<int> stk;

    for(int i = 0 ; i < vertexs.size() ; i++){
        for(int j = 0 ; j < vertexs.size() ; j++){
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

    clock_t start1, start2, end1, end2;

    cout << "use stack" << endl;
    start1 = clock();
    DFS_use_stack(0, adj_matrix, visited, stk, vertexs.size());
    end1 = clock();
    memset(visited, false, sizeof(bool) * vertexs.size());
    cout << "\nuse recursion" << endl;
    start2 = clock();
    DFS_use_recursion(0, adj_matrix, visited, vertexs.size());
    end2 = clock();
    cout << endl;
    cout << "use stack time : " << (double)(end1 - start1) << "ms" << endl;
    cout << "use recursion time : " << (double)(end2 - start2) << "ms" << endl;
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

void DFS_use_recursion(int u, int** matrix, bool visited[], int size){
    cout << u << " ";
    visited[u] = true;
    for(int i = 0 ; i < size ; i++){
        if(matrix[u][i] == 1 && !visited[i]){
            DFS_use_recursion(i, matrix, visited, size);
        }
    }
}

void DFS_use_stack(int start, int** matrix, bool visited[], stack<int> stk, int size) {
	int current = start;
	stk.push(current);
	visited[current] = true;
    cout << current<< " ";
	while (stk.size()) {
		current = stk.top();
		for (int i = 0; i < size; i++) {
			if (matrix[current][i] == 1 && !visited[i]) {
				current = i;
				stk.push(current);
				visited[current] = true;
                cout << current<< " ";
                break;
			}else if(i == size-1){
                stk.pop();
            }
		}
	}
}