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

    bool helper(int src , int* &vis , int* &parent){
        vis[src] = 1; 
        // parent[src] = src; 

        for(int ele : l[src]){
            if(vis[ele] ==1 && parent[src] != ele){
                return false ;
            }else if(vis[ele] == 0){
                parent[ele] = src ; 
                return helper(ele,vis,parent); 
            }
        }

        return true ; 
    }

    bool isTree(int src){
        int* vis = new int[V]; 
        int* parent = new int[V]; 
        for(int i=0 ;i<V ; i++){
            vis[i] =0 ; 
            parent[i] = -1; 
        }
        parent[src] = src ;
        return helper(src , vis , parent); 
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
    if(g.isTree(0)){
        cout << "It is a Tree" << endl; 
    }else{
        cout << "It is not a Tree" << endl ;
    }
    return 0 ;
}