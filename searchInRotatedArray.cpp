#include<iostream>
using namespace std ; 

int searchInRotatedArray(int* arr , int start , int end ,  int x){

    if(start > end){
        return -1;
    }

    while(start <= end){
        int mid = (start + end)/2 ; 
        if(arr[mid] == x){
            return mid ;
        }else if(arr[mid] > x){
            if(arr[mid] < arr[end]){
                end = mid -1; 
            }else{
                start = mid+1; 
            }

        }else{
            if(arr[mid] > arr[start]){
                start = mid+1; 
            }else{
                end = mid -1 ; 
            }
        }
    }

    return -1; 
}


int main(){
    int n ; 
    cin >> n ; 
    int arr[100001]; 
    for(int i=0 ;i<n ;i++){
        cin >> arr[i];
    }
    int x ; 
    cin >> x ; 
    cout << searchInRotatedArray(arr , 0 , n-1 , x) << endl;  
    return 0 ;
}