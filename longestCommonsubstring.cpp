#include<iostream>
#include<string>
#include<algorithm>
using namespace std ; 
int dp[1001][1001]; 
int LCSubstring(string s1 , string s2 , string& output){
    int m = s1.size(); 
    int n = s2.size(); 
    if(m==0 || n==0){
        return 0; 
    }
    int max_len = 0;
    int endIndex = -1;  
    for(int i=0 ;i<=m ;i++){
        for(int j=0 ;j<=n ;j++){
            if(i==0 || j==0){
                dp[i][j] =0; 
            }else{
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] =0 ;
                }
            }
            if(max_len < dp[i][j]){
                max_len = dp[i][j]; 
                endIndex = i ;
            }
        }
    }

    output = s1.substr(endIndex - max_len , max_len); 
    return max_len;
}

int main(){
    string s1 ,s2 ; 
    cin >> s1 >> s2 ; 
    string output = ""; 
    int  len = LCSubstring(s1,s2,output); 
    cout << len << " " << output << endl ;
    return 0 ;
}