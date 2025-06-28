#include<bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/valid-anagram/description/
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;

        // Count chars for first string
        for(auto ch:s) freq[ch]++;

        // Compare and delete for second string
        for(auto ch:t){
            if(freq.find(ch) == freq.end()) return false;
            else{
                freq[ch]--;
                if(freq[ch] ==0) freq.erase(ch); // Remove when count reaches zero
            }
        }

        if(!freq.empty()) return false;
        else return true;
    }
};