#include<iostream>
#include<unordered_map>
#include<string>
using namespace std ; 
int lcsSpaceOptimizedArray(string s1 , string s2){
    int* curr = new int[n+1]; 
    int prev ; 
    /// only these two values are required to reduce our space from 2*n to n ; 
    for(int i=0 ;i<=m ;i++){
        prev = curr[0];  /// it is storing the prev value of the curr[j-1]
        for(int j=0 ;j<=n ;j++){
            int backup = curr[j]    /// it is storing the prev value of curr[j] 
            if(i==0 || j==0){
                curr[j] = 0; 
            }else{
                if(s1[i-1] == s2[j-1]){
                    curr[j] = prev +1; 
                }else{
                    curr[j] = max(backup , curr[j-1]);
                }
            }
            prev = backup; 
        }
    }

    return curr[n];
}
int lcsSpaceOptimized2Arrays(string s1 , string s2){
    // the second string should always be the onewith less size 
    // As long as we are just collecting length we don't need m*n space 
    int m = s1.size(); 
    int n = s2.size(); 
    int* curr = new int[n+1];
    int* prev = new int[n+1]; 
    for(int i=0 ;i<= m;i++){
        for(int j=0 ;j<=n ;j++){
            if(i==0 || j==0){
                curr[j] = 0 ;
            }else{
                if(s1[i-1] == s2[j-1]){
                    curr[j] = prev[j-1] + 1 ;
                }else{
                    curr[j] = max(prev[j] , curr[j-1]); 
                }
            }
        }
        for(int i=0 ;i<=n ;i++){
            prev[i] = curr[i]; 
        }
    }

    return curr[n]; 
}
int lcsDP(string s1 , string s2){
    int m = s1.size(); 
    int n = s2.size(); 
    vector<vector<int>> dp(m+1 , vector<int>(n+1,0)); 
    for(int i=0 ;i<=n ;i++){
        dp[0][i]  = 0 ;
    }
    for(int i=0 ;i<=m ;i++){
        dp[i][0] = 0; 
    }

    for(int i=1; i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[m-i] == s[n-j]){
                dp[i][j] = 1 + dp[i-1][j-1]; 
            }else{
                dp[i][j] = max(dp[i][j-1] , dp[i-1][j]); 
            }
        }
    }

    return dp[m][n];
}

int lcsMemo(string s1 , string s2 , unordered_map<string ,int>& state){
    int m = s1.size(); 
    int n = s2.size(); 
    if(m==0 || n==0){
        return 0 ;
    }

    string ans = to_string(m) + "|" + to_string(n); 
    if(state.find(ans)!=state.end()){
        return state[ans]; 
    }

    if(s1[0] == s2[0]){
        state[ans] = 1+ lcsMemo(s1.substr(1) , s2.substr(1) , state);
    }else{
        state[ans] = max(lcsMemo(s1.substr(1) , s2 , state) , lcsMemo(s1 , s2.substr(1) , state)); 
    }

    return state[ans];
}

int main(){
    string s1 , s2 ; 
    cin >> s1 >> s2 ; 
    cout << lcsDP(s1,s2) << endl;
    unordered_map<string,int> state;  
    cout << lcsMemo(s1,s2,state) << endl; 
    return 0; 
}