Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

Solutions:

Approach 1: Naive Backtracking and recursion
-> Traverse through the given string, letter by letter
-> Take another blank strign where we will keep appending one letter at a time and check whether it is there
    dictionary
 -> If the word exists in the dictionary then we dd that word to the answer and recurse to the rest of the string
 -> If any of the recursive calls fails, we will backtrack, in the send we will add the particular string to the
 answer string if and only if we it return true
 -> add another letter to the 'word' and make recusive call
 -> If at any point of time all the recusions return true then the whole stack will keep cascadingly return true 
 and at that point we have found our answer ;
 
 class Solution {
    
    bool wordBreakUtil(string s , set<string>wordDict , string answer ){
        
        if(s.size() == 0){
            //This will emphasize on the fact that now the decision of whether the word of can se broken
            //depends only on the character with which the empty is AND-ed
            // And it is the end of the breaking chain
            return true ;
        }

        //backtracking algo
        //1. Take one character at a time
        int length = s.size() ; //indexing starts with 1
        int index = 0 ;
        string word = "" ;
        while(index < length){
            
            word = s.substr(0,index+1) ; // decision pending
            
            //check if the string is present in the dictionary
            if(wordDict.find(word) != wordDict.end()){
                // check for the remaining letters by using recursive call
                
                if(wordBreakUtil(s.substr(index+1) , wordDict , answer + ' ' + word) ){
                    return true ;
                }
                else
                index++;
            } 
            else
            index++ ;         
        }
        return false ;        
    }
    
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        string answer ;
        
        set<string>Dict ;
        
        for(auto word:wordDict){
            Dict.insert(word);
        }
        
        if(wordBreakUtil(s , Dict , answer) == true){
            cout << answer ;
            return true ;
        }
        
        return false ; 
    }
};

Time complexity - O(2^n)
Space complexity - O(n) - required to make set and recursive stack which inbuilts also requires space
-> faces Time limit problems and thence, DP

//Approach 1 ends

//Approach 2: DP
-> Problem with above solution is that we keep finding solution for those word which we have seen in the earlier stages and hence instead we will 
keep tracking them using memoization techniques
-> We see overlapping subproblems and optimal substructure
-> Added hash map with will keep the track of the owrd but still is facing issues with time limit.

class Solution {
    
    bool wordBreakUtil(string s , set<string>wordDict , string answer , unordered_map<string,bool>memory){
        
        if(s.size() == 0){
            //This will emphasize on the fact that now the decision of whether the word of can se broken
            //depends only on the character with which the empty is AND-ed
            // And it is the end of the breaking chain
            return true ;
        }

        if(memory.find(s) != memory.end()){
            return memory[s] ; 
        }
        
        
        //backtracking algo
        //1. Take one character at a time
        int length = s.size() ; //indexing starts with 1
        int index = 0 ;
        string word = "" ;
        while(index < length){
            
            word = s.substr(0,index+1) ; // decision pending
            
            //check if the string is present in the dictionary
            if(wordDict.find(word) != wordDict.end()){
                // check for the remaining letters by using recursive call
                
                if(wordBreakUtil(s.substr(index+1) , wordDict , answer + ' ' + word , memory) ){
                    string temp = s.substr(index+1) ;
                    memory[temp] = true ;
                    return true ;
                }
                else
                index++;
            } 
            else
            index++ ;         
        }
        memory[s] = false ;
        return false ;        
    }
    
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        string answer ;
        
        set<string>Dict ;
        unordered_map<string,bool>memory ;
        
        for(auto word:wordDict){
            Dict.insert(word);
        }
        
        if(wordBreakUtil(s , Dict , answer , memory) == true){
            cout << answer ;
            return true ;
        }
        
        return false ; 
    }
};

//Approach 2 ends

//Approach3 : Advanced memoization
-> 




 


