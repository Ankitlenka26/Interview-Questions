#include<iostream>
#include<vector> 
#include<unordered_map>
#include<algorithm>
using namespace std ; 
int arr[100001]; 

int maxLengthBalancedSubarray(int* arr , int n){
    for(int i=0 ;i<n ;i++){
        if(arr[i] == 0){
            arr[i] = -1; 
        }
    }

    // now we just have to find all the subarrays with sum 0 (the maximum)
    unordered_map<int, int> m ; 
    vector<int> presum(n,0);
    int sum =0 ;
    for(int i=0 ; i<n ;i++){
        sum += arr[i]; 
        presum[i] = sum ; 
        if(m.find(presum[i]) == m.end()){
            m[presum[i]] = i ;
        } 
    }
    int len =0 ;
    for(int i=0 ; i<n ;i++){
        if(presum[i] == 0){
            len = max(len , i+1); 
        }else{
            len = max(len , i - m[arr[i]] +1)
        }
    }

    return len ;
}
int main(){
    int n ; 
    cin >> n ; 
    for(int i= 0; i<n ;i++){
        cin >> arr[i]; 
    }
    int ans = maxLengthBalancedSubarray(arr , n);
    cout << ans << endl;
    return 0 ;
}