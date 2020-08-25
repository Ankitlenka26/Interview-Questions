#include<iostream>
#include<list>
using namespace std ;

class Graph{
    int V ; 
    list<int>* l ; 
    public: 
    Graph(int v){
        this->V = v ; 
        l = new list<int>[V]; 
    }
    void addEdge(int x ,int y){
        l[x].push_back(y); 
        l[y].push_back(x);
        return ; 
    }

    void dfsHelper(int src , bool* &vis){
        vis[src] = true ; 
        cout << src << " "; 
        for(int ele : l[src]){
            if(!vis[ele]){
                dfsHelper(ele , vis); 
            }
        }
        return ;
    }

    void dfs(int src){
        bool* vis = new bool[V]; 
        return dfsHelper(src,vis);  
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
    g.dfs(0);
    return 0 ;
}