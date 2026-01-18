#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct node{
    vector<int> neighbors;
    int value = 0;
} typedef node;

class graph
{

public: vector <node*> adjList;
        bool isDirected;

public:
    graph(int Vertices, bool directed = false){

        adjList.resize(Vertices);
        isDirected = directed;

        for(int i = 0; i < Vertices; i++){
            adjList[i] = new node;
        }
    }

    void add_edge(int srcNode, int destNode){
        adjList[srcNode]->neighbors.push_back(destNode);

        if(!isDirected){
            adjList[destNode]->neighbors.push_back(srcNode);
        }
    }

    void add_value(int idx, int value){
        adjList[idx]->value = value;
    }

    void print(){
        for(int i = 0; i < adjList.size(); i++){

            cout << i <<  "(value: "<< adjList[i]->value << "): ";
            for(int j = 0; j < adjList[i]->neighbors.size(); j++){
                cout << adjList[i]->neighbors[j] <<" - > ";
            }
            cout << "NULL" << endl;
        }
    }
  
};

bool dfs(const graph& graph, int number){
    
    stack<node> nodes;
    vector<bool> visited(graph.adjList.size(),0); 
    int i = 0;
    nodes.push(*graph.adjList[i]);
    visited[i] = true;

    while(!nodes.empty()){
        node rootNode = nodes.top();
        nodes.pop();

        if(rootNode.value == number) return 1;
        for(int id : rootNode.neighbors){
            if(!visited[id]){
                visited[id] = true;
                nodes.push(*graph.adjList[id]);
            }
        }
    }
    return 0;

}


int main(){

    graph graph(5);

    graph.add_value(0,3);
    graph.add_value(1,4);
    graph.add_value(2,5);
    graph.add_value(3,6);
    graph.add_value(4,6);
    
    graph.add_edge(4,1);
    graph.add_edge(0,2);
    graph.add_edge(1,2);
    graph.add_edge(3,2);

    bool found = dfs(graph, 6);

    if(found) cout<< "too oldson"<< endl;
    else cout << "oldsongui" <<endl;

    graph.print();
    return 0;
}
