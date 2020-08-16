#include<iostream>
using namespace std ; 
int arr[1000001]; 

// sorting in linear time includes the sorting of certain numbers with some already defined pattern otherwise we can not sort in linear time 

void sort(int* arr , int n){
    int low = 0 , mid = 0 , high = n-1; 
    while(mid < high){
        if(arr[mid] == 0){
            int temp = arr[mid]; 
            arr[mid] = arr[low]; 
            arr[low] = temp ; 
            low++; 
            mid++; 
        }else if(arr[mid] == 1){
            mid++; 
        }else{
            int temp = arr[high]; 
            arr[high] = arr[mid]; 
            arr[mid] = temp ; 
            high--; 
        }
    }
    return ;
}
int main(){
    int n ; 
    cin >> n ; 
    for(int i=0 ; i< n ;i++){
        cin >> arr[i] ; 
    }
    sort(arr , n); 
    for(int ele : arr){
        cout << ele << " "; 
    }
    cout << endl; 
    return 0;   
}