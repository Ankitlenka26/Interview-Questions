#include <bits/stdc++.h> 
using namespace std; 
int arr[51][51]; 
pair<int,int> dp[51][51]; 

int areaRectangle(int arr[][51] , int m , int n){
    
}

int main(){
    int m , n ; cin >> m >> n ;
    for(int i=0 ;i<m ;i++){
        for(int j=0 ; j<n ; j++){
            cin >> arr[i][j] ;
        }
    }
    int ans = areaRectangle(arr,m,n);
    cout << ans << endl; 
    return 0 ;
}
