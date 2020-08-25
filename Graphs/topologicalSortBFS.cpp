#include<iostream>
#include<list>
#include<queue>
using namespace std ;

class Graph{
    int V ; 
    list<int>* l; 
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

    void topologicalSort(){
        int* inDegree = new int[V]; 
        // initialize with 0  inDegree 
        for(int i=0 ;i<V ;i++){
            inDegree[i] = 0 ;
        }
        // update indegree by traversing edges 
        for(int i=0 ;i<V; i++){
            for(auto it : l[i]){
                inDegree[it]++;
            }
        }
        // pushing all the nodes with inDegree 0 into the queue
        queue<int> q; 
        for(int i=0; i<V ; i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        // making the topological array 
        while(q.size() > 0){
            int front = q.front(); 
            q.pop();
            cout << front << " "; 
            for(int ele : l[front]){
                inDegree[ele]--; 
                if(inDegree[ele] == 0){
                    q.push(ele);
                }
            }
        }

        cout << endl ;
        return ; 
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
    g.topologicalSort();
    return 0 ;
}