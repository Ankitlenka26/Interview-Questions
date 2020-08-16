#include<iostream>
#include<string>
using namespace std ;
string reverse(string s){
    int i=0 , j= s.size()-1; 
    while(i<=j){
        char temp = s[i]; 
        s[i] = s[j] ; 
        s[j] = temp ;
    }

    return s ;
}
int main(){
    string s ; 
    cin >> s ; 
    cout << reverse(s) << endl; 
    return 0; 
}