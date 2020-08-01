Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

Solutions:
//Approach - very similar to longest common subsequence

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>answer ;
        if(nums.size() == 0){
            return answer ;
        }
        
        /*
        * unsorted array - we will have to check the mod function twice for both the cases
        * sorted array - we will have to check for only one condition that the bigger num is divisible by the             * smaller num orvnot
        */
        sort(nums.begin() , nums.end()) ;
        
        /*
        * This is question is very much similar to longets increasing subsequence with the modification that
        * we will have to check for one more divisibility constraints
        */ 
        int length = nums.size() ;
        vector<int>lookup(length,0) ;
        lookup[0] = 1 ; // the first number considering will the largest subset containing itself
        int maxval = 1 ;
        for(int i = 1 ; i < length ; i++ ){
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i] && nums[i]%nums[j] == 0){
                    lookup[i] = max(lookup[i] , lookup[j]) ;
                }
            }
            lookup[i]++ ; // considering the number itself
            maxval = max(maxval , lookup[i]) ;
        }
        
        //Fetching the subset
        int i = length-1; 
        int prev = -1 ;
        for(int i = length-1 ; i >= 0 && maxval > 0 ; i--){
            if(lookup[i] == maxval && (prev%nums[i]==0 || prev == -1) ){
                answer.push_back(nums[i]) ;
                maxval--;
                prev = nums[i] ;
            }
        }
        
        // reverse(answer.begin() , answer.end()) ;
        
        return answer ;
    }
};

Time Complexity - O(NlogN[sorting] + N^2[populating lookup table] + N[finding subset])
Space Complexity - O(N) - dp lookup array
References - https://www.youtube.com/watch?v=Wv6DlL0Sawg
