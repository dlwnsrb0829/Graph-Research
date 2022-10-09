#include<iostream>

class vertex{
private:
    int id;
    int label;
public:
    void setId(int id);
    int getId();
    void setLabel(int label);
    int getLabel();
};

void vertex::setId(int id){
    this->id = id;
}
int vertex::getId(){
    return this->id;
}
void vertex::setLabel(int label){
    this->label = label;
}
int vertex::getLabel(){
    return this->label;
}