#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std ; 
int dp[101][101]; 

// to print all the lcs strings the idea remains the same 
// the idea remains the same except the case of top and left so in that case we will go both in top and left direction and not just 
// in one direction 

// Function to return all LCS of substrings X[0..m-1], Y[0..n-1]



// it will only print only one string that is lcs and maynot guarantee every lcs print 
string printLcs(string s1 , string s2 , int m , int n){
    if(m==0 || n==0){
        return ""; 
    }

    if(s1[m-1] == s[n-1]){
        return printLcs(s1,s2,m-1,n-1) + s1[m-1]; 
    }

    if(dp[m-1][n] > dp[m][n-1]){
        return printLcs(s1,s2,m-1,n); 
    }
    else{
        return printLcs(s1,s2,m,n-1); 
    }

    return "" ;
}

int lcsLength(string s1 , string s2 , int m , int n){
    for(int i=0 ;i<=n ; i++){
        dp[0][i] = 0 ;
    }
    for(int i=0 ;i<=m ;i++){
        dp[i][0] = 0; 
    }

    for(int i=1;i<=m ;i++){
        for(int j=1; j<= n ;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1]; 
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]); 
            }
        }
    }

    return dp[m][n]; 
}

int main(){
    int t ; 
    cin >> t ; 
    while(t--){
        string s1 , s2 ; 
        cin >> s1 >> s2; 
        lcsLength(s1 , s2 , s1.size() , s2.size());
	    set<string> lcs = LCS(X, Y);

	// print set elements
	for (string str : lcs)
		cout << str << endl; 
    }

    return 0 ;
}