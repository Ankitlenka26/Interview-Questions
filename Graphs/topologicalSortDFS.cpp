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
        // l[y].push_back(x);  in topological sort there are directed edges 
        return ; 
    }

    void dfsHelper(int src , bool* &vis , list<int>& ordering){
        // mark the visited as true as the node has been visited
        vis[src] = true ; 
        // go to all the neighbours or in this case the dependencies
        for(int ele : l[src]){
            if(!vis[ele]){
                dfsHelper(ele , vis , ordering);
            }
        }
        // when all the dependencies and neighbours are done while traversing back push the src node to the front of the queue 
        ordering.push_front(src);
        return ;
    }

    void dfs(){
        bool* vis = new bool[V];
        list<int> ordering ;  
        for(int i=0 ;i<V ; i++){
            vis[i] = false;
        }
        int count =0; 
        for(int i=0 ;i<V ; i++){
            if(vis[i]==false){
                count++; 
                dfsHelper(i,vis,ordering);
            }
        }
        for(auto i : ordering){
            cout<< i << " " ;
        }
        cout << endl ;
        return; 
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
    g.dfs() ;
    return 0 ;
}