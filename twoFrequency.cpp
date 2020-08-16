#include <bits/stdc++.h> 
using namespace std ; 

void helper(vector<int> arr , int n , set<int>& s){
	for(int i=1 ;i<=n ;i++){
		int index = abs(arr[i]); 
		if(arr[index] < 0){
			s.insert(index); 
		}else{
			arr[index] *= -1; 
		}
	}

	return; 
}

int main(){
	int n ; 
	cin >> n ; 
	vector<int> arr(n+1,0); 
	for(int i=1 ;i<=n ;i++) cin >> arr[i];
	set<int> s ; 
	helper(arr, n, s); 
	for(int i:s){
		cout << i << " "; 
	}
	cout << endl ;
	return 0 ;
}