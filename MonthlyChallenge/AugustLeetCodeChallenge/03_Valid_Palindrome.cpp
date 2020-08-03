Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:

Input: "race a car"
Output: false

Constraints:
    s consists only of printable ASCII characters.

TestCases :

" "
"  "
"A man, a plan, a canal: Panama"
"::A:a, b c e ecb a A ; ;"
"race a car"
"0P"
"A     A "

Solutions:

//Approach 1 : (Accepted)
- This approach goes till the every start and every end while looping inside for loops
- this answer will be correct as it will again check for the alphanum characters 
- we can cut start pointer short by limiting it to go till the end and end pointer till the start (approach 2)

class Solution {
    
    bool checkAlphanumeric (char s){
        
        int numFlag = false ;
        int alphaFlag = false ;
        
        // numric == false
        if( s >= 48 && s <= 57 ){
            numFlag = true ;
        }
        
            
        // alphabet == false
        if( (s >= 65 && s <= 90) || (s >= 97 && s <= 122) ){
            alphaFlag = true ;
        }
     
        return (numFlag || alphaFlag) ;
    }
    
    
public:
    bool isPalindrome(string s) {
     
        int start = 0 ; 
        int end = s.size()-1;
        
        while(start <= end){
            while(start < s.size() && !checkAlphanumeric(s[start]) ) start++ ;
            
            while(end >= 0 && !checkAlphanumeric(s[end]) ) end-- ;
            
            // cout << "start:" << start << " "<< s[start] << " end:" << end << " " << s[end] << endl ;
            
            if(start == s.size() || end == -1){
                return true ;
            }
            
            if(tolower(s[start]) == tolower(s[end])){
                start++ ;
                end-- ;
            }
            else{
                return false ;
            }
        }
        return true ;
    }
};

//Approach 2:

class Solution {
    
    bool checkAlphanumeric (char s){
        
        int numFlag = false ;
        int alphaFlag = false ;
        
        // numric == false
        if( s >= 48 && s <= 57 ){
            numFlag = true ;
        }
        
            
        // alphabet == false
        if( (s >= 65 && s <= 90) || (s >= 97 && s <= 122) ){
            alphaFlag = true ;
        }
     
        return (numFlag || alphaFlag) ;
    }
    
    
public:
    bool isPalindrome(string s) {
     
        int start = 0 ; 
        int end = s.size()-1;
        
        while(start <= end){
            while(start < end && !checkAlphanumeric(s[start]) ) start++ ;
            
            while(end > start && !checkAlphanumeric(s[end]) ) end-- ;
            
            // cout << "start:" << start << " "<< s[start] << " end:" << end << " " << s[end] << endl ;
            
            if(start > end){
                return true ;
            }
            
            if(tolower(s[start]) == tolower(s[end])){
                start++ ;
                end-- ;
            }
            else{
                return false ;
            }
        }
        return true ;
    }
};

Time Complexity - O(n) - in the worst case where we only have special characters we have to traverse the whole string
Space Cmplexity - O(1)
