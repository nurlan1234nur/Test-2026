#include <iostream>
using namespace std;


struct node {
        int value;
        node* rightNode;
        node* leftNode;
    };

    int dfs(node* node, int number);

int main(){
    int size;
    cout <<"size: "<< endl;
    cin >> size;

    if(size == 0){
        cout << " array hooson!!";
        return 0;
    }
    int *a = new int[size];

    cout <<"Elementuud: "<< endl;

    for(int i = 0; i < size;i++)  cin >> a[i]; 
    
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

    
    int found = dfs(Tree, 10); 
    
    if(!found)
        cout << "ene too oldsongui!!";
    else
        cout << "Oldson";


    delete Tree->leftNode;
    delete Tree->rightNode;
    delete Tree;
    return 0;
}

int dfs(node* root, int number){
        
        if(root == NULL) return -1;
        if(root->value == number) return 1;
        
        if(root->leftNode != NULL)
            if(dfs(root->leftNode, number)) return 1;
        if(root->rightNode != NULL)
            if(dfs(root->rightNode, number)) return 1;

        return -1;
    }

