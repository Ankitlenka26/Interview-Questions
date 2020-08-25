// pepcoding 3rd question where we have to print paths with constraints as well 
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
#include<queue> 
#include<utility>
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
   string sPath = ""; 
   int sPathwt = INT_MAX ;
   string lPath =""; 
   int lPathwt = INT_MIN; 
   string ceilPath = ""; 
   int ceilPathwt = INT_MAX ;
   string floorPath = ""; 
   int floorPathwt = INT_MIN;

   priority_queue<pair<int,string> , vector<pair<int,string>> , greater<pair<int,string>>> pq;

   void multiSolver(vector<vector<Edge>>& graph , int src, int dest, bool* visited,int criteria , int k , string  psf , int wsf) {
      if (src == dest) {
        //  cout << psf << endl;
        // smallest path 
        if(wsf < sPathwt){
            sPathwt = wsf; 
            sPath = psf; 
        }
        // largest path 
        if(wsf > lPathwt){
            lPathwt = wsf ; 
            lPath = psf ; 
        }
        // ceil Path 
        if(wsf > criteria && wsf < ceilPathwt){
            ceilPathwt = wsf ;
            ceilPath = psf ; 
        }

        // floor path 
        if(wsf < criteria && wsf > floorPathwt){
            floorPathwt = wsf ;
            floorPath = psf ; 
        }

        // kth largest path 
        if(pq.size() < k){
            pq.push({wsf,psf}); 
        }else{
            if(pq.top().first <= wsf){
                pq.pop(); 
                pq.push({wsf,psf}); 
            }
        }


         return;
      }

      visited[src] = true;
      for (Edge e : graph[src]) {
         if (!visited[e.nbr]) {
            multiSolver(graph, e.nbr, dest, visited,criteria,k , psf + to_string(e.nbr) , wsf + e.wt);
         }
      }
      visited[src] = false;

      return ;
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
      int criteria , k ; 
      cin >> criteria >> k ; 
      bool* visited = new bool[vertices];
    //   printAllPaths(graph, src, dest, visited, src + "");
      multiSolver(graph , src , dest , visited , criteria , k , to_string(src) , 0); 
      cout << "Smallest Path = " <<sPath << "@" << sPathwt << endl ;
      cout << "Largest Path = " <<lPath << "@" << lPathwt << endl ;
      cout <<"Just Larger Path than " << criteria << " = " <<  ceilPath << "@" << ceilPathwt << endl ; 
      cout <<"Just Smaller Path than " << criteria << " = " << floorPath << "@" << floorPathwt << endl; 
      cout << k << "th largest path = " << pq.top().second << "@" << pq.top().first; 
      return 0; 
   } 