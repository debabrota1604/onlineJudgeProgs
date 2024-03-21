#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;
/*
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?

Example 1:
    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5

Example 2:
    Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
    Output: 4

Constraints:
    1 <= k <= nums.length <= 105
    -104 <= nums[i] <= 104
*/

class Solution {
public:
    int partition(vector<int>& vec, int lo, int hi){ // Same fn for both kth largest and kth smallest
        int pivot = vec[hi], swapInd=lo;

        for(int iter=lo; iter<hi; iter++){
            if(vec[iter] < pivot) 
                swap(vec[iter], vec[swapInd++]);
        }
        swap(vec[swapInd], vec[hi]); //last swap with pivot location
        
        // cout << "PartitionRes: " << lo << " to " << hi << " = pivot " << pivot << ", sortedPos " << swapInd << ": ";
        // for(auto item:vec) cout << item << " ";
        // cout << endl;
        
        sleep(1);
        return swapInd;
    }
    int quickSelect(vector<int>& vec, int lo, int hi, int k){
        int pivotIndex, desiredPos = vec.size() - 1 -k;//desired pos is determining k-th smallest or largest
        while(1){
            //cout << "QS: " << k << ", lo: " << lo << ", hi: " << hi << endl;

            pivotIndex = partition(vec, lo, hi);
            if(pivotIndex == desiredPos) return vec[pivotIndex];
            else if(pivotIndex > desiredPos) 
                hi = pivotIndex -1;
            else 
                lo = pivotIndex +1;
        }
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, k-1);
    }
};


int main(){
    Solution s;
    vector<int> vec {3,2,1,5,6,4};
    int k = 2;
    cout << s.findKthLargest(vec,k) << endl;

    vector<int> vec2 {3,2,3,1,2,4,5,5,6};
    int k2 = 4;
    cout << s.findKthLargest(vec2,k2) << endl;
}