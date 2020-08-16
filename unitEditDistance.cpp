#include<iostream>
#include<string>
using namespace std ; 


bool isEdit(string s1 , string s2){
	if(s1.size()==0 || s2.size()==0){
		return true;
	}else if(s1.size()==0){
		return true; 
	}else if(s2.size()==0){
		return true; 
	}else{
		if(s1[0] == s2[0]){
			return isEdit(s1.substr(1) , s2.substr(1)); 
		}else{
			bool op1 = isEdit(s1.substr(1) , s2.substr(1)); 
			bool op2 = isEdit(s1.substr(1) , s2); 
			bool op3 = isEdit(s1, s2.substr(1)); 
			return op1||op2||op3; 
		}
	}

	return false; 
}

int main(){
	string s1 , s2 ; 
	cin >> s1 >> s2 ; 
	bool ans = isEdit(s1,s2); 
	if(ans){
		cout << "True" << endl; 
	}else{
		cout << "False" << endl; 
	}

	return 0; 
}