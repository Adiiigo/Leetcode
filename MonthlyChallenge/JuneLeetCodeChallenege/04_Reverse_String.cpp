Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

   Hide Hint #1  
The entire logic for reversing a string is based on using the opposite directional two-pointer approach!

Solutions:

Approach 1:
-> using the inbuild funciton reverse

Approach 2:
-> calling function which swap left and right points
-> calling this function recursively with increased left pointer and decreased right pointer
-> in place - yes 
-> O(1) space - no coz we are using recusrion stack which require extra space

Approach 3:
-> using the iterative version of the same using two pointers which will in-place swap the two characters
-> decrease the right pointer and increase the left pointer

Approach 4: (By Me)

class Solution {
public:
    void reverseString(vector<char>& s) {
         
        int left = 0; 
        int right = s.size() - 1 ; 
        int diff = 0 ;
        
        while(left <= right) {
            
            diff = s[right] - s[left] ;
            
            s[left] = s[left] + diff ;
            s[right] = s[right] - diff ;
            
            left++ ;
            right-- ;
            diff = 0 ;
        }        
    }
};

-> using the two pointer concept but instead of swapping we are using the differences in the ascii values and using them to add and decrease
it.
