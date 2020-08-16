#include<iostream>
using namespace std ; 
int arr[100001];


void flip(int arr[] , int n , int t){
	cout << t+1 << " "; 
	int i = 0 , j = t; 
	while(i<j){
		int temp = arr[i] ; 
		arr[i] = arr[j] ;
		arr[j] = temp ; 
		i++ , j-- ; 
	}

	return ; 
} 

void sort(int arr[] , int n){
	int k = n-1;  
	for(int i=0 ; i<n ; i++){ 
	     int maxElement = -1; 
	     int maxIndex = -1;       
		for(int j=0 ; j<= k; j++){ 
            // find the maximum element between 0 and k 
            if(arr[j] > maxElement){
            	maxElement = arr[j] ; 
            	maxIndex = j ; 
            }
		} 
		if(maxElement != -1){
		flip(arr, n , maxIndex); 
		flip(arr , n ,k);
		k--; 
		}
		else{
			break ;
		}
	}

	return ;
}

int main(){
	int t; 
	cin >> t; 
	while(t--){
		int n ; 
		cin >> n ; 
		for(int i=0 ;i<n ;i++){
			cin >> arr[i]; 
		}

		sort(arr , n); 
		cout << endl ;
	}

	return 0 ;
}
