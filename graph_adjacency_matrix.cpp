#include <iostream>
#include <vector>
using namespace std;

class graph
{
    vector<vector <int>> adjMatrix;

public:
    
    graph(int n){
        adjMatrix = vector<vector<int >>( n , vector<int>(n, 0));
    }

    void add_edge(int u , int v){
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void print(){

        int size = adjMatrix.size();
        for(int i = 0; i< size; i++){
            for(int j = 0; j< size; j++){
                printf("%d " , adjMatrix[i][j]);
            }
            cout<<endl;
        }
    }
};

int main(){
    int n = 4;

    graph graph(4);
    graph.add_edge(0,0);
    graph.add_edge(0,3);
    graph.add_edge(1,1);
    graph.add_edge(1,2);
    graph.add_edge(2,2);
    graph.add_edge(3,3);

    graph.print();

    return 0;
}

