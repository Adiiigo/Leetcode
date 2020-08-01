Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

Solution:
(by Me)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int ,int> lookup ;
        
        for(int num : nums){
            lookup[num]++ ;
        }
        
        int ME_cond = (int)nums.size()/2 ;
        int answer = INT_MAX ;
        
        /* Traversing the whole lookup table
        *  Thinking that there might be two majority elements
        *  but it is not possible
        */
                
        /*  [3,3,2]
        *   for an element to be ME it has to have frequency more than 1 and less than 3
        *   implies 2 
        *   if two elements are having frequency = 2 => there have to be 2+2+1 elements => 5 which is contradicting
        *   the concept itself
        *   implies there can be only one ME
        */
        
        /* if above logic is not derived then
        *  for(auto itr = lookup.begin() ; itr != lookup.end() ; itr++){
        *      if(itr->second > ME_cond){
        *          answer = min(answer,itr->first) ;
        *          break ;
        *     }
        *  }
        *  considering that there can be multiple majority elements
        */
        
        for(auto itr = lookup.begin() ; itr != lookup.end() ; itr++){
            if(itr->second > ME_cond){
                answer = itr->first ;
                break ;
            }
        }
        return answer ;
    }
};


Solution 2(Boyer-Moore Voting Algorithm):
(by daose)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //3,2,3 //3,3,4
        
        int singles = 0 ;
        int candidate = -1 ;
        
        for(int num : nums){
            
            if(singles == 0 ){
                candidate = num;
            }

            singles += num==candidate ? +1 : -1 ;
            
            // if(num == candidate){
            //     singles++ ;
            // }
            // else{
            //     singles--; 
            // }
            
        }
        return candidate ;
    }
};
