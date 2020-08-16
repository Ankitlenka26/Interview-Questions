#include<iostream>
#include<string> 
#include<vector>
#include<climits>
using namespace std ; 

int wordDistance(vector<string> v , string word1 , string word2){
	int word1Index = -1 ; 
	int word2Index = -1 ;

	int distance = INT_MAX;

	for(int i=0 ;i< v.size(); i++){
		if(v[i] == word1){
			word1Index = i ;
			if(word2Index != -1) 
			distance = min(distance , word1Index - word2Index); 
		}
		else if(v[i] == word2){
			word2Index = i ; 
			if(word1Index != -1)
			distance = min(distance , word2Index - word1Index); 
		} 
	}

	return distance ;
}

int main(){
	int n ; 
	cin >> n ; 
	vector<string> v(n,""); 
	for(int i=0 ;i<n ;i++){
		cin >> v[i]; 
	}
	string word1 , word2; 
	cin >> word1 >> word2 ; 
	int ans = wordDistance(v , word1 , word2); 
	cout << ans ; 
	return 0 ;
}