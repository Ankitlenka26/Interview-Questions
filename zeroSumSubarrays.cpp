#include <bits/stdc++.h> 
using namespace std ; 
#define ll long long int 
ll arr[1000001] , presum[1000001]; 

ll ZeroSubarray(ll* arr , ll n){ 
	unordered_map<ll,ll> m ; 
	m[0] = 1; 
	ll count =0 ;
	ll sum =0 ; 
	for(ll i=0 ;i<n ; i++){
		sum += arr[i]; 
		if(m.find(sum) != m.end()){
			count += m[sum]; 
			m[sum]++; 
		}else{
			m[sum]++; 
		}
	}

	return count ;
}


int main(){
	ll t ; 
	cin >> t; 
	while(t--){
		ll n;
		cin >> n ;
		for(ll i=0 ;i<n ;i++){
			cin >> arr[i]; 
		}

		ll count = ZeroSubarray(arr,n); 
		cout << count << endl ; 
	}

	return 0 ;
}