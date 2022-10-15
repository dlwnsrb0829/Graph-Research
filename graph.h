#include<iostream>
#include<sstream>
#include<vector>
#include<fstream>
#include<string>
#include<stack>
#include<ctime>
#include<cstring>

using namespace std;

class graph{
private:
    vector<int> split(string input, char delimiter);
    void DFS_use_recursion(int u, bool visited[]);
    int ** adj_matrix;
    int graph_num;
    string vertexs;
    string edges;
    int v_size;
    int e_size;
    int start, end;
public:
    graph(){}
    graph(int graph_num, string vertexs, string edges, int v_size, int e_size){
        this->graph_num = graph_num;
        this->vertexs = vertexs;
        this->edges = edges;
        this->v_size = v_size;
        this->e_size = e_size;
        make_graph(vertexs, edges);
    }
    void make_graph(string data, string edges);
    void print();
    void get_graph_num();
    void DFS_use_recursion();
    void DFS_use_stack();
};

void graph :: make_graph(string vertesx, string edges){
    adj_matrix = new int *[v_size];
    for(int i = 0 ; i < v_size ; i++){
        adj_matrix[i] = new int[v_size];
        memset(adj_matrix[i], 0, sizeof(int) * v_size);
    }

    string temp = "";
    for(int i = 0 ; i < edges.size() ; i++){
        int count = 0;
        switch (edges[i])
        {
        case '/':
            for(int j = 0 ; j < temp.size() ; j++){
                vector<int> split_vector = split(temp, ' ');
                adj_matrix[split_vector[0]][split_vector[1]] = split_vector[2];
                adj_matrix[split_vector[1]][split_vector[0]] = split_vector[2];
            }
            temp = "";
            break;
        
        case 'e':
            i++;
            break;
        
        default:
            temp += edges[i];
            break;
        }
    }
}

void graph :: print(){
    for(int i = 0 ; i < v_size ; i++){
        for(int j = 0 ; j < v_size ; j++){
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void graph :: get_graph_num(){
    cout << "# " << graph_num << endl;
}

void graph :: DFS_use_recursion(){
    bool visited[v_size];
    memset(visited, false, sizeof(bool) * v_size);
    start = clock();
    DFS_use_recursion(0, visited);
    end = clock();
    cout << "\nuse recursion time : " << (double)(end - start) << "ms" << endl;
}

void graph :: DFS_use_recursion(int u, bool visited[]){
    cout << u << " ";
    visited[u] = true;
    for(int i = 0 ; i < v_size ; i++){
        if(adj_matrix[u][i] != 0 && !visited[i]){
            DFS_use_recursion(i, visited);
        }
    }
}

void graph :: DFS_use_stack() {
    stack<int> stk;

    bool visited[v_size];
    memset(visited, false, sizeof(bool) * v_size);

    int u = 0;

    start = clock();

	int current = u;
	stk.push(current);
	visited[current] = true;
    cout << current<< " ";
	while (stk.size()) {
		current = stk.top();
		for (int i = 0; i < v_size; i++) {
			if (adj_matrix[current][i] != 0 && !visited[i]) {
				current = i;
				stk.push(current);
				visited[current] = true;
                cout << current<< " ";
                break;
			}else if(i == v_size-1){
                stk.pop();
            }
		}
	}
    end = clock();
    cout << "\nuse stack time : " << (double)(end - start) << "ms" << endl;
}

vector<int> graph :: split(string input, char delimiter) {
    vector<int> result;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) {
        result.push_back(stoi(temp));
    }
    return result;
}