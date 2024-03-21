#include<bits/stdc++.h>
using namespace std;

/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

Example 1:
    Input: s = "tree"
    Output: "eert"
    Explanation: 'e' appears twice while 'r' and 't' both appear once.
    So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
    Input: s = "cccaaa"
    Output: "aaaccc"
    Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
    Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
    Input: s = "Aabb"
    Output: "bbAa"
    Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
    Note that 'A' and 'a' are treated as two different characters.
 

Constraints:
    1 <= s.length <= 5 * 105
    s consists of uppercase and lowercase English letters and digits.
*/

class Solution {
public:
    string frequencySort(string s) {

        // Step1: Implement frequency counter
        map<char, size_t> freq;
        for(auto item:s) ++freq[item];
        
        // Step2: Define comparator function
        auto comp = [](pair<char, size_t>& a, pair<char, size_t>&b){ return a.second > b.second; };
        
        // Step3: Take it into a vector and sort it using comparator function
        vector<pair<char, size_t>> sortedFreq(freq.begin(), freq.end());
        sort(sortedFreq.begin(), sortedFreq.end(), comp);
        
        // Step 4: construct result string
        string res {};
        for(auto item:sortedFreq){
            for(size_t iter=0; iter<item.second; iter++) res += item.first;
        }
        return res;
    }
};

