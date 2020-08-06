Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.

Solutions:

//Approach 1 : Accepted

class WordDictionary {
    
    bool endString; 
    WordDictionary* lookup[26] ;
    
    bool searchWord(WordDictionary* root , string word ,int cur){
        
        if(cur == word.size()){
            return root->endString ;
        }
        
        if(word[cur] != '.'){
            int index = word[cur]-'a' ;
            if(root->lookup[index] == NULL){
                return false ;
            }
            
            return searchWord(root->lookup[index] , word , cur+1) ;
        }
        
        for(WordDictionary* it : root->lookup){
            if(it != NULL){
                if(searchWord( it , word, cur+1) == true ) {
                    return true ;
                }
            }
        }
        
        return false ;
    }
    
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        this->endString = false ;
        
        for(int i = 0 ; i < 26 ; i++){
            this->lookup[i] = NULL ;
        }
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
     
        WordDictionary* root = this ;    
            
        for(char c : word) {
            int index = c-'a' ;
            if(root->lookup[index] == NULL){
                root->lookup[index] = new WordDictionary() ;
            }
            root = root->lookup[index] ;
        }
        
        root->endString = true ;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
        WordDictionary* root = this ;    
        int cur = 0 ;
        
        return searchWord(root , word , cur) ;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
