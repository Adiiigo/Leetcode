 Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters. 

Solution:

class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> lookup(26) ;
        
        int length = s.size() ;
        
        //Populating the array with the information
        for(int i = 0 ; i < length ; i++){
            if(lookup[s[i] - 'a' ] == 0 ){
               lookup[s[i] - 'a' ] = i+1 ;
            }
            else if(lookup[s[i] - 'a' ] > 0 ){
                lookup[s[i] - 'a' ] = -1 ;
            }
        }
        
        // for(int i = 0 ; i < lookup.size() ; i++){
        //     // if(lookup[i] > 1)
        //     cout << lookup[i] << ",";
        // }
        
        // cout << endl ;
        //find the  first unique letter
        int answer = INT_MAX ;
        for(int i = 0 ; i < lookup.size() ; i++){
            if(lookup[i] > 0)
            answer = min(answer , lookup[i]) ;
            // cout << answer << endl ;
        }
        
        return answer == INT_MAX ? -1 : answer-1 ; 
        
    }
};
