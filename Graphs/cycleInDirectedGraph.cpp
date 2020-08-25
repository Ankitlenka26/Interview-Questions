#include<iostream>
#include<list>
using namespace std ;

class Graph {
    int V ; 
    list<int>* l ; 
    public: 
    Graph(int v){
        this->V = v ; 
        l = new list<int>[V]; 
    }
    void addEdge(int x ,int y){
        l[x].push_back(y);
        return ; 
    }
    bool cycleHelper(int node , bool* vis , bool* stack){
        // visit a node 
        vis[node] = true; 
        stack[node] = true ;

        for(int nbr : l[node]){
            // two cases 
            if(stack[nbr]){
                return true ;
            }else if(!vis[nbr])
                return cycleHelper(nbr , vis , stack);
            }
        //leave the node 
        stack[node] = false;
        return false; 
    }

    bool isCyclic(){
        bool* vis = new bool[V]; 
        bool* stack = new bool[V]; 
        return cycleHelper(0,vis,stack); 
    }

};

int main(){
    Graph g(7); 
    g.addEdge(0,1); 
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(4,6);
    if(g.isCyclic()){
        cout << "It is a cyclic directed graph" << endl; 
    }else{
        cout << "It is not a cyclic directed graph" << endl ;
    }
    return 0 ;
}