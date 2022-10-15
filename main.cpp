#include<iostream>
#include"graph.h"
using namespace std;

vector<string> split(string str, char delimiter);
void DFS_use_recursion(int i, int **matrix, bool visited[], int size);
void DFS_use_stack(int start, int** matrix, bool visited[], stack<int> stk, int size);

int main(){
    ifstream readFile;
    readFile.open("SAMPLE");
    
    int graph_num = -1;
    string vertexs = "";
    string edges = "";
    int v_size = 0;
    int e_size = 0;
    
    if(readFile.is_open()){
        char arr[256];
        while(!readFile.eof()){
            readFile.getline(arr, 256);
            if(arr[0] == 't'){
                graph_num++;
            }
            if(arr[0] == 'v'){
                vertexs += arr;
                v_size++;
            }
            if(arr[0] == 'e'){
                edges += arr;
                edges += '/';
                e_size++;
            }

        }
    }
    readFile.close();

    graph g(graph_num, vertexs, edges, v_size, e_size);
    g.get_graph_num();
    g.print();
    cout << endl;
    g.DFS_use_stack();
    cout << endl;
    g.DFS_use_recursion();
    cout << endl;

    return 0;
}