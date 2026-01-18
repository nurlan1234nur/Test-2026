#include <iostream>
#include <queue>
using namespace std;

struct node {
        int value;
        node* rightNode;
        node* leftNode;
    };
bool bfs(node* node, int number);

int main(){

    node* Tree = new node;
    Tree->value = 7;
    Tree->leftNode = new node;
    Tree->rightNode = new node;
    Tree->leftNode->value = 5;
    Tree->rightNode->value = 10;

    Tree->leftNode->leftNode = nullptr;
    Tree->leftNode->rightNode = nullptr;
    Tree->rightNode->leftNode = nullptr;
    Tree->rightNode->rightNode = nullptr;

    
    int found = bfs(Tree, 10); 
    
    if(!found)
        cout << "ene too oldsongui!!";
    else
        cout << "Oldson";


    delete Tree->leftNode;
    delete Tree->rightNode;
    delete Tree;
    return 0;
}

bool bfs(node* root, int number){

    if(root == NULL) return -1;

    queue<node> nodes;
    nodes.push(*root);
        
    while(!nodes.empty()){
    root = &nodes.front();
    nodes.pop();
    
    if(root->value == number) return 1;
    if(root->leftNode != NULL)
        nodes.push(*root->leftNode);
    if(root->rightNode != NULL)
        nodes.push(*root->rightNode);
    }
    return 0;
}

