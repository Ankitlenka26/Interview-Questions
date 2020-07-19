#include<bits/stdc++.h>
using namespace std;

string commonString(vector<string> v){
    if(v.size()==0){
        return "" ; 
    }
    string ans = v[0]; 
    for(int i= 1; i<v.size() ; i++){
        string temp= "" ; 
        for(int j=0 ; j<min(v[i].size() , ans.size()) ; j++){
            if(ans[j] == v[i].at(j)){
                temp += ans[j]; 
            }
            else{
                break ;
            }
        }

        ans = temp ;
    }

    return ans; 
}
int main()
{
    int n; 
    cin >> n ; 
    vector<string> v(n,""); 
    for(int i=0 ;i<n ;i++){
        cin >> v[i]; 
    } 
    string ans =  commonString(v); 
    cout << ans << endl; 
    return 0 ;

}