#include<bits/stdc++.h>
using namespace std;
/*
You are given an array of strings products and a string searchWord.
Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.
Return a list of lists of the suggested products after each character of searchWord is typed.

Example 1:
    Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
    Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
    Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
    After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
    After typing mou, mous and mouse the system suggests ["mouse","mousepad"].

Example 2:
    Input: products = ["havana"], searchWord = "havana"
    Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
    Explanation: The only word "havana" will be always suggested while typing the search word.

Constraints:
    1 <= products.length <= 1000
    1 <= products[i].length <= 3000
    1 <= sum(products[i].length) <= 2 * 104
    All the strings of products are unique.
    products[i] consists of lowercase English letters.
    1 <= searchWord.length <= 1000
    searchWord consists of lowercase English letters.
*/


/*
Trie + Sort
Sort
n = number of charcters in the products list
Time: O(nlog(n))
Build Trie
k = 3
m = number of characters in the longest product
Time: O(n)
Space: O(nkm)
Output Result
s = number of characters in searchword
Time: O(s)
Space: O(sk)
*/
class Solution {
private:
    struct Node{
        unordered_map<int, Node*> map;
        vector<string> sugg;
        
        Node(){
            map = {};
            sugg = {};
        }
    };
    
    struct Node *root;
    
    void insert(string s){
        Node *curr = root;
        
        for(char c : s){
            if(curr->map.find(c) == curr->map.end()){
                curr->map[c] = new Node;
            }
            curr = curr->map[c];
            if(curr->sugg.size() < 3) curr->sugg.push_back(s);
        }
    }
    
    vector<string> search(char c, Node *&curr){
        
        if(curr->map.find(c) == curr->map.end()){
            curr = NULL;
            return {};
        }
        curr = curr->map[c];
        return curr->sugg;
    }
    
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        root = new Node;
        vector<vector<string>> out;
        
        sort(products.begin(), products.end());
        
        for(string s : products){
            insert(s);
        }
        
        Node *curr = root;
        
        for(char c : searchWord){
            if(!curr) out.push_back({});
            else out.push_back(search(c, curr));
        }
        
        return out;
    }
};