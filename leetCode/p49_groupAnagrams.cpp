#include<bits/stdc++.h>
using namespace std;

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]



*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Step 1: Use map to store words per pattern
        unordered_map<string, vector<string>> anagrams;

        // Step 2: Use sorted str as key and value is vector of input strings matching the key
        for(auto str:strs){
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            anagrams[sorted].emplace_back(str);
        }

        // Step 3: Output the array with only the values vector inside a vector
        vector<vector<string>> res;
        for(auto anagram:anagrams){
            res.emplace_back(anagram.second);
        }
        return res;
    }
};