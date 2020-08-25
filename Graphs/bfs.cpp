#include<iostream>
#include<map>
#include<utility>
#include<list>
#include<queue>
#include<climits>

using namespace std; 

class Graph{
    map<int , list<int>> l ;
    public : 
    
    void addEdge(int  x ,int  y){
        l[x].push_back(y); 
        l[y].push_back(x); 
    }

    void bfs(int src){
        map<int,bool> visited ; 
        queue<int> q;
        q.push(src); 
        visited[src] = true;
        while(q.size() > 0){
            int front = q.front(); 
            cout << front << " "; 
            q.pop(); 
            for(auto nbr : l[front]){
                if(!visited[nbr]){
                    q.push(nbr); 
                    visited[nbr] = true ; 
                }
            }
        }
        cout << endl; 
    }

    void ssspBFS(int src){
        map<int,int> dist;  /// it will keep the information of visited as well as the distance with the same data structure
        // if visited of key is not in the map itself then the node is unvisited else it will have some value 
        queue<int> q;

        for(auto node_pair : l){
            int node = node_pair.first;
            dist[node] = INT_MAX;
        }
        q.push(src); 
        dist[src] = 0;
        while(q.size() > 0){
            int front = q.front(); 
            // cout << front << " "; 
            q.pop(); 
            for(auto nbr : l[front]){
                if(dist[nbr] == INT_MAX){
                    q.push(nbr); 
                    dist[nbr] = dist[front] +1; 
                }
            }
        }
        // cout << endl; 

        for(auto node_pair : dist){
            cout << node_pair.first << " " << node_pair.second << endl; 
        }
    }
}; 
int main(){
    Graph g ; 
    g.addEdge(0,1); 
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs(0); 
    g.ssspBFS(0);
    return 0 ;
}