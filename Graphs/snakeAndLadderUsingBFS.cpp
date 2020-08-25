/*
Vivek takes out his Snakes and Ladders game and stares at the board, and wonders: If he had absolute control on the die (singular), and could get it to generate any number (in the range 1-6 ) he desired, what would be the least number of rolls of the die in which he'd be able to reach the destination square (Square Number 100) after having started at the base square (Square Number 1)?

RULES

Vivek has total control over the die and the face which shows up every time he tosses it.
you need to help him figure out the minimum number of moves in which he can reach the target square (100) after starting at the base (Square 1).

A die roll which would cause the player to land up at a square greater than 100, goes wasted, and the player remains at his original square. Such as a case when the player is at Square Number 99, rolls the die, and ends up with a 5.

If a person reaches a square which is the base of a ladder, (s)he has to climb up that ladder, and he cannot come down on it. If a person reaches a square which has the mouth of the snake, (s)he has to go down the snake and come out through the tail - there is no way to climb down a ladder or to go up through a snake.

Input - Output 
Sample Input
2
3
32 62
42 68
12 98
7
95 13
97 25
93 37
79 27
75 19
49 47
67 17
4
8 52
6 80
26 42
2 72
9
51 19
39 11
37 29
81 3
59 5
79 23
53 7
43 33
77 21 
Sample Output
3
5
*/
#include<iostream>
#include<utility>
#include<list>
#include<map>
#include<climits>
#include<queue>
#define pb push_back
using namespace std ; 
class Graph{
    int V; 
    list<int>* l ; 
    public : 
    Graph(int v){
        this->V = v ; 
        l = new list<int>[V]; 
    }
    void addEdge(int x , int y){
        l[x].pb(y);
    }

    int bfsSSSP(int src , int dest){

        int dist[101]; 
        int parent[101]; 
        for(int i=0 ;i<=100 ; i++){
            dist[i] = INT_MAX; 
        } 
        queue<int> q; 
        dist[src] = 0; 
        parent[src] = src; 
        q.push(src); 
        while(q.size() > 0 && dist[dest] == INT_MAX){
            int front = q.front();
            q.pop(); 
            for(auto element : l[front]){
                if(dist[element] == INT_MAX){
                    q.push(element); 
                    dist[element] = dist[front]+1; 
                    parent[element] = front ; 
                }
            }
        }

        int temp = dest ; 
        while(temp!= src){
            cout << temp << "<--" ; 
            temp = parent[temp];
        }
        cout << src << endl; 
        if(dist[dest] == INT_MAX){
            return -1; 
        }
        return dist[dest]; 
    }
}; 
int main(){
    int t; 
    cin >> t; 
    while(t--){
        int board[101] = {0};
        // adding the ladders and snakes to the board array
        int ladder ; cin>> ladder ; 
        for(int i=0 ;i<ladder ; i++){
            int x , y ; 
            cin >> x >> y ; 
            board[x] = y-x;
        } 
        int snakes ; cin >> snakes ; 
        for(int i=0 ;i<snakes ; i++){
            int x, y ; 
            cin >> x >> y ;
            board[x] = y-x; 
        }

        // for(int i=0 ;i<=100 ; i++){
        //     cout << i  << "->" << board[i] << endl; 
        // }

        // Add edges to the graph 
        Graph g(101); 
        for(int i=0; i<100 ;i++){
            for(int dice=1 ; dice<=6 ; dice++){
                int j = i+dice ; 
                j += board[j]; 
                if(j<= 100){
                    g.addEdge(i,j); 
                }
            }
        }
        g.addEdge(100,100);

        // find the shortest path to destination node 100th node ; 
        cout << g.bfsSSSP(0,100)<< endl; 
    }
    return 0 ;
}