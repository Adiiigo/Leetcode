You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once. Find this single element that appears only once.

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10

Note: Your solution should run in O(log n) time and O(1) space.

Solutions:

Approach 1:
-> use hashMap -> unordered_map 
-> store the frequency of each number on first iteration
-> iterate gain through the lookup table to find the number with the frequency as 1
-> return the number

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        unordered_map<int ,int> lookup ;
        
        for(int num : nums){
            lookup[num]++ ;
        }
        
        for(auto itr = lookup.begin() ; itr != lookup.end() ; itr++){
            if(itr->second == 1){
                return itr->first ;
            }
        }      
        return -1 ;
    }
};

Time complexity : max( O(n) , O((n-1)/2) )= O(n) 
Space Complexity(Extra) : O(n) 

Approach 1 ends //

Approach 2 :
-> Do not use the extra space 
-> Try to find the number in one itration
-> Randomly assign first number as the answer
-> If it is seen again , the set the answer variable as -1
-> If the answer is set to -1, then we are open to new number being as the candidate answer
-> Since, at one point we will never find answer number again, it will never be set as -1 again.
-> return the answer in the end 

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
     
        int length = nums.size() ;
        int answer = nums[0] ;
        
        for (int i = 1 ; i < length ; i++){
            if(answer == nums[i]){
                answer = -1 ;
            }            
            else if(answer == -1 ){
                answer = nums[i] ;
            }
        }
        return answer ;
    }
};

Time Complexity : O(n) 
Space Complexity(Extra) : O(1) ;

Approach 2 ends //

Approach 3:
-> We are aware that there are 2n+1 elements 
-> comparing the positions of 2n+1 elements with their original positions

EG :
Index = 0 1 2 3 4 5 6 7 8 9
Input = 1 1 2 3 3 4 4 8 8 
Org   = 1 1 2 2 3 3 4 4 8 8
    
Index = 0 1 2 3 4  5  6  7
Input = 3 3 7 7 10 11 11
Org   = 3 3 7 7 10 10 11 11
    
here every "even" index => start of the pair
            "odd" index => completion of the pair
            
 Terminating condition is when left == right, loop breaks
 
 class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int left = 0 ;
        int right = nums.size()-1 ;
        
        int mid = 0 ; 
        
        while(left < right){
            
            mid = left + (right-left)/2 ;
            
            //middle is even
            if(mid % 2 == 0){ //can also do (mid & 1 == 0)
                //mid+1 should be the partner
                if( nums[mid] != nums[mid+1] ){
                    //problem is there in the left part of the array
                    right = mid ;
                }
                else{ //looking into the original array, we will skip the pair and move to the next pair
                    left = mid + 2 ;
                }
            }
            else{ //mid i's odd
                //mid-1 should be the partner
                if(nums[mid] != nums[mid-1]){ // skip the start of the pair and move towards the front
                    right = mid - 1 ;
                }
                else{ //skip the end of the pair and moves towarsd the right
                    left = mid + 1 ;
                }
            }            
        }
        
        //left == right -> terminating condition
        return nums[left] ;
    }
};

Time Complexity - O(logn)
Space Complexity(Extra) - O(1)
    
Approach 3 ends //   

Youtube link referred:
https://www.youtube.com/watch?v=aFXhs190zeg
