Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

Solutions:

//Approach 1:
-> Create hashmap to store the frequency of the number 
-> count the number whose frequency has occured twice
-> push it into the answer vector

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //int | frequency
        unordered_map<int,int> lookup ;
        
        for(int num : nums){
            lookup[num]++ ;
        }
        
        vector<int> answer ;
        for(pair<int,int> eachPair : lookup ){
            if(eachPair.second == 2){
                answer.push_back(eachPair.first) ;
            } 
        }
        
        return answer ;
    }
};

Time Complexity - O(n) 
Space Complexity - o(n)

//Approach 2: (Accepted)
-> We could exploit the fact that each element of the array lies between 1 and n(size of array).
-> We can mutate the array to store information about the number of occurences of an element. 
-> We could do this by changing the sign of the element at nums[i] index
-> If we reach at an element for which the element at that index is negative, this implies that, that particular element has appeared before.
-> Say, nums = [4,3,2,7,8,2,3,1]. While traversing on the array we would change the sign of elements at nums[i] index and check whether the element at nums[i] is negative or not.

i = 0, [4,3,2,-7,8,2,3,1]      // change the sign of element at 4th index
i = 1, [4,3,-2,-7,8,2,3,1]     // change the sign of element at 3rd index
i = 2, [4,-3,-2,-7,8,2,3,1]    // change the sign of element at 2nd index
i = 3, [4,-3,-2,-7,8,2,-3,1]   // change the sign of element at 7th index
i = 4, [4,-3,-2,-7,8,2,-3,1]   // change the sign of element at 8th index
i = 5, [4,3,-2,-7,8,2,-3,1]    // here before changing the sign of element at 2nd index we will realize that it is already negative, which implies that 2 has appeared before in the array. So, we will push 2 in the ans
i = 6, [4,3,2,-7,8,2,-3,1]     // again we will encounter a negative element at 3rd index and we will push 3 into our ans
i = 7, [-4,3,-2,-7,8,2,-3,1]   // change the sign of element at 1st index
-> This way we could keep a track of element which appears again without requiring any extra space.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int>answer ;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            // if the duplicate exists then pushing the duplicate value in the array
            if(nums[abs(nums[i])-1] < 0 ){ 
                answer.push_back(abs(nums[i])) ;
            }
            // setting it to the negative value implying the position and number has already been visited
            else{
                nums[abs(nums[i])-1] *= -1 ;
            }
        }
        return answer ;
    }
};
Time Complexity - O(n) 
Space Complexity - O(1)
