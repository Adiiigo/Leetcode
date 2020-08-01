Given an arbitrary ransom note string and another string containing letters from all the magazines, 
write a function that will return true if the ransom note can be constructed from the magazines ; 
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

-Solution(by Me):

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int rSize = ransomNote.size() ;
        int mSize = magazine.size() ;
        
        //This states that the letters are not there in the magazine string => we cannot form ransomNote
        if(mSize == 0){            
            if(rSize == 0 ){
                return true ;
            }
            else
                return false ;
        }
        
        //If we have come to this if => there are some chars in magazine string but the ransomeNote to be 
        //contructed is NULL which can be formed from the magazine string
        if(rSize == 0 ){
            return true ;
        }
        
        //Sorting both the string to make it easier to compare
        cout << ransomNote << endl ;
        sort(ransomNote.begin() , ransomNote.end()) ;
        cout << ransomNote << endl;
        
        cout << magazine << endl ;
        sort(magazine.begin() , magazine.end()) ;
        cout << magazine << endl ;
        
        int i , j ;
        
        for(i = 0 , j = 0 ; i < rSize && j < mSize ; j++){
            if(ransomNote[i] == magazine[j]){
                i++;
            }
        }
        
        if(i == rSize){
            return true ;
        }
        
        return false ;    
    }
};

-Solution(by dasoe)
    class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int rSize = ransomNote.size() ;
        int mSize = magazine.size() ;
        int inventory[26] = {0};
        
        if(mSize == 0 && rSize == 0) return true ;
        if( mSize < rSize) return false ;
        
        int j = 0 ;// magazine index 
        for(int i = 0 ; i < rSize ; i++){
            char temp = ransomNote[i] ;
            if(inventory[temp-'a'] != 0){ //letter exists
                inventory[temp-'a']-- ;
            }
            else{
                while(true){
                    char letter = magazine[j] ;
                    j++;
                    if(letter == temp) break;
                    inventory[letter - 'a' ]++ ;
                    if(j == mSize) return false ;
                }
            }
        }
        return true; 
    }
};
