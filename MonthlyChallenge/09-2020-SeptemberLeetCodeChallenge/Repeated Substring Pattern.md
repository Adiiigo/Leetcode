Solution 1:

```
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        unordered_map<char,int> lookup ;
        int count ;
        
        if(s.size() <= 1){
            return false ;
        }
        
        for(char c : s ){
            lookup[c]++ ;
        }
        
        count = lookup.begin()->second ;
        for(auto itr = lookup.begin() ; itr != lookup.end() ; *itr++){
           
            if(itr->second != count){
                return false ;
            }
        }
        
        // came here => count is same.
        // we have to check if the all the occurances are same or not
        int substrSize = lookup.size() ;
        for(int i = 0 ; i < s.size()-substrSize ; i = i+substrSize){
            cout << s.substr(i,substrSize) << ":" << s.substr(i+substrSize,substrSize) << ";" << endl ;
            if(s.substr(i,substrSize) != s.substr(i+substrSize,substrSize)){
                return false ;
            }
        }
        
        return true ;
    }
};
```

/*
"abab"
"ababba"
"aba"
"abcabcabcabc"
"abcabcbca"
*/
