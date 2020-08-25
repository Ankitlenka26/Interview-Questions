// longest increasing subsequence 

#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std ; 

// 1.recursion 
int LISRec(int* arr ,int n , int prev){
    if(n==1){
        return 1; 
    }
    int inc= INT_MIN; 
    int exc = LISRec(arr+1 , n-1 , prev);
    if(arr[0] > prev){
        int inc = 1 + LISRec(arr+1,n-1,arr[0]); 
    } 

    return max(inc,exc); 
}

// 2. top-down approach 
int LISMemo(int* arr ,int n , int prev , unordered_map<int,int>& state){
    if(n==1){
        return 1;
    }

    if(state.find(n) != state.end()){
        return state[n]; 
    }

    int inc = INT_MIN ; 
    int exc = LISMemo(arr+1,n-1,prev,state); 
    if(arr[0] > prev){
        inc = LISMemo(arr+1 , n-1, arr[0] , state);
    }

    state[n] = max(inc,exc); 
    return state[n]; 
}
    
// 3. bottom-up approach 
int LISDp(int* arr ,int n){
    int dp[10001];
    dp[0] = 1; 
    int maximum =1; 
    for(int i=1 ;i<=n ;i++){
        dp[i] =1; 
        for(int j=0 ;j<i ; j++){
            if(arr[i] > arr[j] && 1+dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
           }
        }

        maximum = max(maximum , dp[i]); 
    }

    return maximum; 
}

// 4. print lis 
void printLis(int* arr , int n){
    vector<int>* dp = new vector<int>[n]; 
    dp[0].push_back(arr[0]); 
    int maximum = 1; 
    int index =0 ;
    for(int i=1 ; i<n ;i++){
        for(int j=0 ; j<i ; j++){
            if(arr[i] > arr[j] && dp[j].size() > dp[i].size()){
                dp[i] = dp[j];
            }
        }

        dp[i].push_back(arr[i]); 
        index = dp[i].size() > maximum ? i : index; 
        maximum = dp[i].size() > maximum ? dp[i].size() : maximum ; 
    }

    for(int i: dp[index]){
        cout << i << " " ; 
    }
    cout << endl; 
    return ;
}


int main(){
    int n; 
    cin >> n ; 
    int* arr = new int[n]; 
    for(int i=0 ;i<n ;i++){
        cin >> arr[i]; 
    }
    int ansrec = LISRec(arr , n , INT_MIN); 
    unordered_map<int,int> state; 
    int ansMemo = LISMemo(arr , n , INT_MIN ,state); 
    int ansDp = LISDp(arr,n); 
    printLis(arr,n); 
    cout << ansrec << " " << ansMemo << " " << ansDp << endl; 
    return 0 ;
}