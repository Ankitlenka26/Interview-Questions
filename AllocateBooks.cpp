#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int;
ll arr[1000001]; 
bool isValidConfig(ll* arr , ll n , ll k ,ll ans){
	ll students = 1; 
	ll current_pages =0 ;
	for(int i=0 ;i<n ;i++){
		if(current_pages + arr[i] > ans){
			current_pages = arr[i]; 
			students++; 
			if(students > k){
				return false;
			}

		}else{
			current_pages += arr[i]
		}
	}

	return true;
}
ll allocateBooks(ll * arr , ll n , ll k){
	ll e= 0; 
	ll s= arr[n-1]; 
	for(ll i=0 ;i<n ;i++){
		e +=arr[i];  
	}
	int finalAns = s; 
	while(s<=e){
		ll mid = (s+e)/2; 
		if(isValidConfig(arr,n,k,mid)){
			// True 
			finalAns = mid; 
			e = mid-1; 
		}
		else{
			// false; 
			s = mid+1; 
		}
	}

	return finalAns ; 
}




int main(){
	ll n , k; 
	cin >> n >> k ; 
	for(ll i=0;i<n ;i++){
		cin >> arr[i];
	}

	cout << allocateBooks(arr , n, k) << endl; 
	return 0 ;
}