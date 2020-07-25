Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

Solutions:

Approach 1: Backtracking
-> Here the word "all" gives us the hing that we have to look for all the possible answers ("Generate All" , "Print All" , "Compute All")
-> We have to exhuaste the search space. This doesnt mean we have to use brute force. Brute force implies that we have the wrost alog,
and we are using it to find "the" possible answer.
-> Backtracking implies we have to exhaustively find all the answer looking for the whole search space and finding all the alternative solutions.
Doesnt mean our alogirithm should be worst as well.
-> Usually string and arrays are loosely coupled characters which can be manipluated using the positions and arrangnments.

-> There we have traverse through all the charcters using the "for" loop and then apply recursive call to the remaining characters.
-> We keep doing this till we have no charcters left and we add it to the answer string
-> Since we have applied the permutation, we will reapply it to get the original array and o the same thing to the remaining string

class Solution {
    
    vector<vector<int>> answer ; 
    
    void swap(vector<int>& nums , int x , int y){
        int temp = nums[x] ;
        nums[x] = nums[y] ;
        nums[y] = temp ;
    }
    
    void permuteUtil(vector<int>& nums , int left , int size ){
        
        int x = 0 ;
        vector<int> temp ;
        
        if(left == size){
            //String permuataion is finished and no letter is there to traverse
            for(int i = 0 ; i < size ; i++ ){
                temp.push_back(nums[i]) ;
            }
            answer.push_back(temp) ;
        }
        else{
            //there are charcter which we have to traverse
            for(int x = left ; x < size ; x++){
                swap(nums , left , x) ;
                permuteUtil(nums , left+1 , size) ;
                swap(nums , left , x) ;
            }
        }
        
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        if(nums.size() == 0) return {{}} ;
        permuteUtil(nums, 0 , nums.size()) ;
        
        return answer ;
        
    }
};

Time Complexity : O(n * n!) - coz we have to linearly travers thorugh all teh characters and then we have to permute the remaining characters 
for that particular letter/char
Space Complexity : O(n * n!) - if we consder the recursive stack 
                   O(n) - if we only consider the final answer



