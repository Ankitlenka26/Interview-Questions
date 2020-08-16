#include<iostream>
#include<vector>
using namespace std ; 

int stairsRecursion(int n){
    if(n==1){
        return 1; 
    }
    if(n==2){
        return 2; 
    }
    if(n==3){
        return 4;
    }
    return stairsRecursion(n-1) + stairsRecursion(n-2) + stairsRecursion(n-3); 
}

int stairsMemo(int n , vector<int>& memo){
    if(n==1){
        return 1; 
    }
    if(n==2){
        return 2; 
    }
    if(n==3){
        return 4;
    }
    if(memo[n-1] != 0){
        return memo[n-1]; 
    }
    memo[n-1] = stairsMemo(n-1 , memo) + stairsMemo(n-2,memo) + stairsMemo(n-3,memo);
    return memo[n-1];
}

int stairsDp(int n){
    int* dp = new int[n]; 
    dp[0] = 1 ; 
    dp[1] = 2 ; 
    dp[2] = 4 ;

    for(int i=3 ;i<n ;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]; 
    }

    return dp[n-1]; 
}


int main(){
    int n ; 
    cin >> n ;
    vector<int> memo(n,0);

    int ans1 = stairsRecursion(n); 
    int ans2 = stairsMemo(n,memo); 
    int ans3 = stairsDp(n); 
    cout << ans1 << " "  << ans2 << " " << ans3 <<endl ;
    return 0 ;
}