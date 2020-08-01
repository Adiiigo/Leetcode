Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

Approach 1:
class Solution {
public:
    string frequencySort(string s) {
        
    vector<pair<int,char>> lookup('z'+1 , {0,0}) ;
        
    for(char c :s){
        lookup[c] = {lookup[c].first+1 , c} ;
    }
        
    //sorted in ascending order
    sort(lookup.begin() , lookup.end()) ;
    
    string answer = "" ;
        
    for(auto c : lookup) {
        answer = string(c.first , c.second) + answer ;
    }
    
    return answer ;
        
    }
};
//Approach 1 ends

Approach 2:
class Solution {
public:
    string frequencySort(string s) {
        
        string toReturn = "" ;
        
        map<char , int> freq ;
        priority_queue<pair<int,char>> maxHeap ;
        
        for(char c: s){
            freq[c]++ ;
        }
        
        for(auto eachVal : freq ){
            cout << eachVal.second << eachVal.first << endl ;
            maxHeap.push({eachVal.second, eachVal.first}) ;
        }
        
        while(!maxHeap.empty()) {
            
            int howFreqCharacter = maxHeap.top().first ;
            char character = maxHeap.top().second ;
            
            for(int i = 0 ; i < howFreqCharacter ; i++){
                toReturn += character ;
            }
            
            maxHeap.pop() ;
        }
        
        return toReturn ;
        
    }
};
//Approach 2 ends
