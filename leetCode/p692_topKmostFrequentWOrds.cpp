#include<bits/stdc++.h>
using namespace std;

/*
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Example 1:
    Input: words = ["i","love","leetcode","i","love","coding"], k = 2
    Output: ["i","love"]
    Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
    Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
    Output: ["the","is","sunny","day"]
    Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 
Constraints:
    1 <= words.length <= 500
    1 <= words[i].length <= 10
    words[i] consists of lowercase English letters.
    k is in the range [1, The number of unique words[i]]
 

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?

*/


using map_iter = unordered_map<string, size_t>::iterator;

struct Compare{
    bool operator()(map_iter& a, map_iter& b){
        if(a->second == b->second) return a->first < b->first; //lexicographic order
        else return a->second > b->second; //min heap order
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Step1: Implement frequency counter
        unordered_map<string, size_t> ump;
        for(auto item:words) ++ump[item];

        //Step2: insert into min heap
        priority_queue<map_iter, vector<map_iter>, Compare> pq;
        for(auto iter=ump.begin(); iter!=ump.end(); ++iter){
            pq.emplace(iter);
            if(pq.size() >k) pq.pop();
        }

        vector<string> res(k);
        for(int iter=k-1; iter>=0; --iter){
            res[iter] = pq.top()->first;
            pq.pop();
        }

        return res;

    }
};


int main(){
    vector<string> v {"i","love","leetcode","i","love","coding"}, 
                    v2 {"the","day","is","sunny","the","the","the","sunny","is","is"};
    int k {2}, k2 {4};

    Solution s;

    for(auto item:s.topKFrequent(v,k)) cout << item << " ";
    cout << endl;

    for(auto item:s.topKFrequent(v2,k2)) cout << item << " ";
    cout << endl;

}
