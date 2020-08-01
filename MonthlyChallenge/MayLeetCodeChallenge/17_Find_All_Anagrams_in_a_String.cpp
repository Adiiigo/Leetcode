Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

Solution:

Approach 1:
-> Keep the frequency of the numbers in one array and keep the frequency of the other number in other array.
-> Compare the both the arrays to see if they are anagrams.
-> two pointer which gets updated to reach till the end of the string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans ;
        vector<int> sMap(26, 0) ;
        vector<int> pMap(26, 0) ;
        
        int length = s.size() ;
        cout << length << endl;
        int window = p.size() ;
        cout << window << endl ;
        
        if(length < window) return ans ;
        
        int left = 0 ; 
        int right  = 0 ;
        
        for(int i = 0 ; i < window ; i++){
            sMap[ s[i] - 'a']++ ;
            pMap[ p[i] - 'a']++ ;
            right++ ;
         }
        
        right--;
        cout << right << endl ;

        while(right < length){
            
            if(pMap == sMap ){
                ans.push_back(left) ;
            }
            
            right++ ;
            if(right != length){
                sMap[s[right] - 'a']++ ;
            }
            sMap[s[left] - 'a']-- ;  
            left++ ;
            
        }
        
        return ans ;
        
    }
};
