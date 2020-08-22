#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std ; 

int palindromicSubsequence(string s , int low , int high , unordered_map<string,int>& state){
    if(low > high){
        return 0; 
    }
    if(low == high){
        return 1; 
    }
    string ans = to_string(low) + "|" + to_string(high); 
    if(state.find(ans) != state.end()){
        return state[ans];
    }
    if(s[low] == s[high]){
        state[ans] = 2+palindromicSubsequence(s,low+1 , high-1,state); 
    }else{
        state[ans] = max(palindromicSubsequence(s,low+1,high,state) , palindromicSubsequence(s,low,high-1,state)); 
    }

    return state[ans]; 
}

int main(){
    string s ;
    cin >> s ; 
    int low =0 , high = s.size()-1; 
    unordered_map<string , int> state; 
    cout << palindromicSubsequence(s,low,high,state) << endl;
    return 0;  
}