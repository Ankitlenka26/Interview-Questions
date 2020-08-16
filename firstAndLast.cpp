#include <bits/stdc++.h> 
using namespace std ;

int getFirst(vector<int> arr , int n , int target){
	int s =0 , e = n-1; 
	while(s<=e){
		int mid = (s+e)/2; 
		if(arr[mid] != arr[mid-1] && arr[mid]==target){
			return mid ; 
		}else if ( (arr[mid] == arr[mid-1] && arr[mid] == target) || arr[mid] > target){
			e = mid -1; 
		}
		else{
			s = mid+1; 
		}
	}

	return -1; 
} 

int getLast(vector<int> arr , int n , int target){
	int s =0 , e = n-1; 
	while(s<=e){
		int mid = (s+e)/2; 
		if(arr[mid] != arr[mid+1] && arr[mid]==target){
			return mid ; 
		}else if ( (arr[mid] == arr[mid+1] && arr[mid] == target) || arr[mid] < target){
			s = mid+1; 
		}
		else{
			e = mid-1; 
		}
	}

	return -1; 

}

int main(){
	int n ;
	cin >> n ; 
	vector<int> arr(n,0); 
	int target ; 
	cin >> target ; 
	for(int i=0 ;i<n ;i++){
		cin >> arr[i]; 
	}

	int first = getFirst(arr,n,target); 
	int last = getLast(arr , n, target); 

	cout << first << " " << last << endl ;
	return 0 ; 
}