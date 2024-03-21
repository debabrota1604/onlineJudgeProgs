#include<bits/stdc++.h>
using namespace std;


class Solution {
public: 
    //Not required, by default this comparison is implemented
    static bool comparator(vector<int> p1, vector<int> p2){
        return p1[0] < p2[0];
    }

    void disp(vector<vector<int>> v){
        cout << "[";
        for(int i=0; i< v.size(); i++){
            cout << "[";
            for(int j=0; j < v[0].size(); j++){
                cout << v[i][j] << " ";
            }
            cout << "]"; 
        }
        cout << "]\n";
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        //first, sort the intervals in ascending order of start index
        sort(intervals.begin(), intervals.end());

        // Step2: prepare the result vector
        vector<vector<int>> res; 
        res.emplace_back(intervals[0]);

        // Step3: For each subsequent indices, either merge the interval, or push new interval
        for(int it=1; it<intervals.size(); it++){
            int lastIndex = res.size()-1;
            if(res[lastIndex][1] >= intervals[it][0]){ // merge case, calculate the interval end
                res[lastIndex][1] = res[lastIndex][1] > intervals[it][1] ? res[lastIndex][1] : intervals[it][1];
            }
            else res.emplace_back(intervals[it]); // push new interval case
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
    s.disp(s.merge(v));
    vector<vector<int>> v2 = {{1,2},{2,5},{3,5},{4,5}};
    s.disp(s.merge(v2));
    
}