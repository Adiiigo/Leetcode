Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.

Example 1:

Input: "USA"
Output: True

Example 2:

Input: "FlaG"
Output: False

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

Solutions:

//Approach 1 :
-> Check first Letter for lowercase -> yes -> all letters should be lowercase
-> Check first Letter for loweercase -> no -> all letters shoudl be either uppercase or lowercase
-> else return false ;

class Solution {
    
    bool isCapital(char a){
        
        return a >=65 && a <= 91 ;
        
    }  
    
    bool checkWordLower(string word){

        int length = word.size() ;
        
        for(int i = 1 ; i < length ; i++){
            
            if(isCapital(word[i]) == true ){
                return false ;
            } 
        }
        return true ;
    }
    
     bool checkWordUpper(string word){

        int length = word.size() ;
        
        for(int i = 1 ; i < length ; i++){
            
            if(isCapital(word[i]) == false ){
                return false ;
            } 
        }
        return true ;
    }
    
public:
    bool detectCapitalUse(string word) {
        
        //first letter is not capital
        if(isCapital(word[0]) == false){
            
            return checkWordLower(word) ;
            
        }
        else{ //first letter is capital
            
            return checkWordLower(word) || checkWordUpper(word) ;
                //remainig letters is lower  //remaining letters are caps
  
        }
        
        return false ;
    }
};
