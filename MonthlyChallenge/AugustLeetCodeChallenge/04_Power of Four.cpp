Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true

Example 2:

Input: 5
Output: false

Follow up: Could you solve it without loops/recursion?


Solutions:

//Approach 1 : Accepted : Using recursion/iteration

class Solution {
public:
    bool isPowerOfFour(int num) {
        
        if(num == 0) return false ;
        
        if(num == 1) return true ;
        
        if(num < 0) return false ;
        
        while(num > 1){
            
            if(num%4 == 0){
                num /= 4 ;
                if(num == 1){
                    return true ;
                }
            }
            else{
                return false ;
            }
        }
        return true ;
    }
};

Testcases - 
16
4
1
32
45
256
65
64
258
-64
-2147483648
-2147483647

Time Comp - O(n/4)
Space comp - O(1)
