#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ; 

int canAttend(vector<int>& s , vector<int>& e , int n){
	sort(s.begin() , s.end()); 
	sort(e.begin(),e.end()); 
	int i =0 , j =0 , c=0 , max= 0;
	 // c indicating the no of current parties going on 
	 // max will contain the maximum value for all the the count values
	while(i < s.size() && j < e.size()){
		if(s[i] < e[j]){
			++c;
			i++ ;
		}else{
			--c;
			j++; 
		}

		if(c > max){
			max = c ;
		}
	}

	return max ;
}

int main(){
		int n ;
	    cin >> n ; 
		vector<int> s(n,0); 
		vector<int> e(n,0); 
		for(int i=0 ;i<n ;i++){
			int x , y;
			cin >> x;
			cin >> y; 
			s[i] = x , e[i] = y ;
		}
		int ans = canAttend(s,e,n); 
		cout << ans << endl; 
		return 0 ;
}