#include<bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation: 
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
*/

class Solution {
public:
    bool isEqual(vector<int> freq1, vector<int> freq2){ //Compares two sets of char frequenies
        if(freq1.size() != freq2.size()) return false;
        for(int it=0; it<freq1.size(); it++){
            if(freq1[it] != freq2[it]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int slen = s.size(), plen = p.size();
        if(slen < plen) return {}; // Corner case when p is larger

        // Frequency arrays for p and window
        vector<int> winfreq (26,0), pfreq(26,0);
        for(int it=0; it<plen; it++){ //populate
            winfreq[s[it]-'a']++;
            pfreq[p[it]-'a']++;
        }

        vector<int> res;
        if(isEqual(pfreq, winfreq)) res.emplace_back(0); //i=0 case
        for(int it=1; plen+it <= slen; it++){ //sliding window
            int outgoingChar = s[it -1], incomingChar = s[plen + it -1];
            winfreq[outgoingChar -'a']--;
            winfreq[incomingChar -'a']++;

            if(isEqual(pfreq, winfreq)) res.emplace_back(it);// window matches p
        }
        return res;
    }
};