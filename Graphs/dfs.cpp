// pepcoding 3rd question where we have to print paths with constraints as well 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ; 

   class Edge {
    public : 
      int src;
      int nbr;
      int wt;

      Edge(int src, int nbr, int wt) {
         this->src = src;
         this->nbr = nbr;
         this->wt = wt;
      }
   };

    bool hasPath(vector<vector<Edge>>& graph, int src, int dest, bool* visited) {
      if (src == dest) {
         return true;
      }

      visited[src] = true;
      for (Edge e : graph[src]) {
         if (!visited[e.nbr]) {
            bool nbrHasPath = hasPath(graph, e.nbr, dest, visited);
            if (nbrHasPath) {
               return true;
            }
         }
      }

      return false;
   }

    int main(){

      int vertices;
      cin >> vertices;
      int edges; cin >> edges ; 
      vector<vector<Edge>> graph(vertices); 
      for (int i = 0; i < edges; i++) {
         int v1,v2,wt ; 
         cin >> v1 >> v2 >> wt ; 
         graph[v1].push_back(Edge(v1, v2, wt));
         graph[v2].push_back(Edge(v2, v1, wt));
      }
      int src , dest; 
      cin >> src >> dest; 

      bool* visited = new bool[vertices];
      bool flag = hasPath(graph, src, dest, visited);
      if(flag){
          cout << "true" << endl ;
      }else{
          cout << "false" << endl ;
      }
      return 0; 
   } 