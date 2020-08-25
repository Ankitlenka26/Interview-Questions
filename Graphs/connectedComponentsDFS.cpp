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

    int dfs(){
        bool* vis = new bool[V]; 
        for(int i=0 ;i<V ; i++){
            vis[i] = false;
        }
        int count =0; 
        for(int i=0 ;i<V ; i++){
            if(vis[i]==false){
                count++; 
                dfsHelper(i,vis);
            }
        }
        return count ; 
    }
}; 

int main(){
    Graph g(9); 
    g.addEdge(0,1); 
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(4,6);
    g.addEdge(7,8); 
    cout << g.dfs() << endl;
    return 0 ;
}

// we can also use bredth first search instead of dfs the algorithm will entirely remain the same 