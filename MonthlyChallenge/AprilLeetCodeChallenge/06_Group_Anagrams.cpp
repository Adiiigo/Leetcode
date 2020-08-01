Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.

Solutions:
-> Anagrams hava same letters, just the arrangement is different
-> This implies we can use sorting techniques to make them all equal and store them

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string , vector<string>> storage;
        string temp ;
        
        for(string word : strs){
            temp = word ;
            sort(word.begin(), word.end());
            storage[word].push_back(temp);
        }
        
        vector<vector<string>> result ;
            for(auto pp : storage){
                result.push_back(pp.second);
            }
        
        return result;
    }
};

Time Complexity - O(n)
Space Complexity - O(n) - map which is extra used for storing the sorted word and coreesponding anagrams
