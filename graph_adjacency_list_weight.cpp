#include <iostream>
#include <vector>
using namespace std;

class graph
{
    vector< vector<pair<int, int>>> adjList;
    bool isDirected;

public:
    graph(int Vertices, bool directed = false){

        adjList.resize(Vertices);
        isDirected = directed;
    }

    void add_edge(int src, int dest,int weight = 1){
        adjList[src].push_back({dest, weight});

        if(!isDirected){
            adjList[dest].push_back({src, weight});
        }
    }

    void print(){
        for(int i = 0; i < adjList.size(); i++){

            cout << i << ": ";
            for(int j = 0; j < adjList[i].size(); j++){
                cout << "("<<adjList[i][j].first<< ", " << adjList[i][j].second << ") - > ";
            }

            cout << "NULL" << endl;
        }
    }
  
};


int main(){

    graph graph(5);

    graph.add_edge(4,1);
    graph.add_edge(0,2);
    graph.add_edge(1,2);
    graph.add_edge(3,2);

    graph.print();
    return 0;
}
