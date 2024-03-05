//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

/*
Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.
*/


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        int res = n*(n+1)/2;
        for(auto item:array) res-=item;
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends