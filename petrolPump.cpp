#include <bits/stdc++.h> 
using namespace std ; 

int petrolPump(vector<int> gas , vector<int> cost , int n){
	int net =0 , cur =0 , start =0 ; 
	for(int i=0 ;i<n ;i++){
		net += gas[i] - cost[i] ;
		cur += gas[i] - cost[i] ;
		if(cur < 0){
			cur = 0; 
			start = i+1; 
		}
	}
	if(net < 0){
		return -1; 
	}

	return start; 
}

int main(){
	int n ; 
	cin >> n ; 
	vector<int> gas(n,0); 
	vector<int> cost(n,0); 
	for(int i=0 ;i<n ;i++) cin >> gas[i] ; 
	for(int i=0 ;i<n ;i++) cin >> cost[i]; 

	int ans = petrolPump(gas,cost,n); 
    cout << ans << endl ;
	return 0 ;
}