
/////////////////////////////
// Longest substring Length 
#include<bits/stdc++.h>
using namespace std;


int helper(string s , int i , int j){
	if(i > j){
		return 0; 
	}

	if(i==j){
		return 1 ;
	}
	int ans1 , ans2 , ans3 ;
	if(s[i] == s[j]){
		 ans1 =  2 + helper(s,i+1,j-1); 
	}

	 ans2 = helper(s , i+1 , j); 
	 ans3 = helper(s , i , j-1); 
	if(s[i] != s[j]){
		return max(ans2 , ans3); 
	}
	else{
		return max(ans1 , max(ans2 , ans3));
	}

	return 0; 
}
int longestPalindromicSubstring(string s){
	int i =0 ; 
	int j = s.size() -1; 

	return helper(s, i ,j); 
}
int main(){
	int t; 
	cin >> t; 
	while(t--){
		string s ; 
		cin >> s ; 
		int ans = longestPalindromicSubstring(s); 
		cout << ans << endl ; 
	}

	return 0; 
}