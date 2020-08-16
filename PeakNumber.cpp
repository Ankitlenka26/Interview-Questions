#include<iostream>
#include<algorithm>
using namespace std ; 
int arr[1000001]; 

bool isPeak(int* arr ,int n){
    if(n<=1){
        return true; 
    }
    if(arr[0] > arr[1] || arr[n-2] < arr[n-1]){
        return true ; 
    }

    for(int i=1 ; i<n-1 ; i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            return true ; 
        }
    }

    return false; 

}

int main(){
    int n ; 
    cin >> n ;

    for(int i=0 ;i<n ;i++){
        cin >> arr[i] ; 
    }

    bool ans = isPeak(arr,n); 
    if(ans){
        cout << "true"; 
    }else{
        cout << "false";
    }
    return 0 ;
}