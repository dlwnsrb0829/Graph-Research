#include<iostream>
#include<vector>

class edge{
private:
    int vertexs[2];
    int label;
public:
    void setEdge(int vertex1, int vertex2);
    int * getEdge();
    void setLabel(int label);
    int getLabel();
};

void edge::setEdge(int vertex1, int vertex2){
    (this->vertexs)[0] = vertex1;
    (this->vertexs)[1] = vertex2;
}
int * edge::getEdge(){
    return (this->vertexs);
}
void edge::setLabel(int label){
    this->label = label;
}
int edge::getLabel(){
    return this->label;
}