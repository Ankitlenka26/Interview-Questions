#include<iostream>
#include<algorithm>
using namespace std ; 

// Dp Approach : O(n^2) and O(n^2)
// In this way, make a jumps[] array from left to right such that jumps[i] indicates the minimum number of jumps needed to reach arr[i] from arr[0].
// To fill the jumps array run a nested loop inner loop counter is j and outer loop count is j.
// Outer loop from 1 to n-1 and inner loop from 0 to n-1.
// if i is less than j + arr[j] then set jumps[i] to minimum of jumps[i] and jumps[j] + 1. initially set jump[i] to INT MAX
// Finally, return jumps[n-1].

int minJumps(int* arr , int n){
    // jumps[n-1] will hold the result 
    int* jumps = new int[n]; 
    int i, j; 
  
    if (n == 0 || arr[0] == 0) 
        return INT_MAX; 
    // we don't have to jump if the destination and the source are the same
    jumps[0] = 0; 
  
    // Find the minimum number of jumps to reach arr[i] 
    // from arr[0], and assign this value to jumps[i] 
    for(i = 1; i < n; i++) { 
        jumps[i] = INT_MAX; 
        for (j = 0; j < i; j++) { 
            if (i <= j + arr[j] && jumps[j] != INT_MAX) { 
                jumps[i] = min(jumps[i], jumps[j] + 1); 
                break; 
            } 
        } 
    } 
    return jumps[n - 1]; 
}

int main(){
    int arr[] = { 1, 3, 6, 1, 0, 9 }; 
    int size = sizeof(arr) / sizeof(int); 
    cout << "Minimum number of jumps to reach end is "
         << minJumps(arr, size) << endl; 
    return 0; 
}