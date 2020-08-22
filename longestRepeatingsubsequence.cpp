#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std ; 
int dp[1001][1001]; 

int longestRepeatedSubsequence(string s , int n){
    for(int i=0 ;i<=n ;i++){
        for(int j=0 ; j<=n ; j++){
            if(i==0 || j==0){
                dp[i][j] =0 ;
            }else{
                if(s[i-1] == s[j-1] && i!=j){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]); 
                }
            }
        }
    }
    return dp[n][n]; 
}

int main(){
    int t; 
    cin >> t; 
    while(t--){
        int n ; 
        cin >> n ; 
        string s ; 
        cin >> s ; 
        // unordered_map<string ,int> state; 
        int ans = longestRepeatedSubsequence(s,n); 
        cout << ans << endl ;
    }
    
    return 0; 
}