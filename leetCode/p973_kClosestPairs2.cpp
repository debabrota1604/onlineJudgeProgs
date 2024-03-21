#include<bits/stdc++.h>
using namespace std;

struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b) const{
        return (a.first * a.first + a.second * a.second) < (b.first * b.first + b.second * b.second);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multiset<pair<int, int>, compare> mem; //set will not input [1,0] if [0,1] is already present

        // insert into the set
        for(int iter=0; iter<points.size(); iter++){
            mem.insert({points[iter][0], points[iter][1]});
        }

        // construct result
        vector<vector<int>> res;
        int iter=0;
        for(auto item:mem){
            vector<int> tempRes {item.first, item.second};
            res.emplace_back(tempRes);
            if(++iter == k) break;
        }

        return res;
    }
};