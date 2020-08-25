// shortest common supersequence
#include<iostream>
#include<string>
#include<algorithm>

using namespace std ; 
int dp[1001][1001]; 

string scsString(string s1 ,string s2 , int m , int n){
    if(m==0){
        return s2.substr(0,n); 
    }
    if(n==0){
        return s1.substr(0,m); 
    }

    if(s1[m-1] == s2[n-1]){
        return scsString(s1,s2,m-1,n-1) + s1[m-1]; 
    }

    if(dp[m-1][n] < dp[m][n-1]){
        return scsString(s1,s2,m-1,n) + s1[m-1];
    }else{
        return scsString(s1,s2,m,n-1) + s2[n-1];
    }
}

int scsLen(string s1 , string s2, int m ,int n){
    for(int i=0 ;i<=m ;i++){
        for(int j=0 ; j<=n ; j++){
            if(i==0 || j==0){
                dp[i][j] = i+j; 
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1]; 
            }else{
                dp[i][j] =  1 + min(dp[i][j-1] , dp[i-1][j]); 
            }
        }
    }
    return dp[m][n]; 
}

int main(){
    string s1,s2 ; 
    cin >> s1 >> s2 ; 
    cout << scsLen(s1,s2,s1.size(),s2.size()) << endl; 

    cout << scsString(s1,s2,s1.size(),s2.size()) << endl; 
    return 0; 
}