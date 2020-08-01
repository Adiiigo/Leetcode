Given a non-negative integer num represented as a string, remove k digits from the number so that 
the new number is the smallest possible.

Note:
    The length of num is less than 10002 and will be ≥ k.
    The given num does not contain any leading zero.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

Solutions:

Approach 1:
-> Not only the number but also the placevalue of the number matters
-> We will have to move from MSB to LSB
-> Moving from MSB to LSB , if the num[i++] > num[i] , good chance of decreasing the value of the number(Greediness : looking
best possible number at the present moment)
-> Use the stack to keep the track of top most digit and remove it whenevr smaller number comes
-> Do the above process till K times and as and when it is done look out of the for loop
-> While loop inside the for loop signifies that we should keep adding the number on the stack till we reach to the point
that there is a number present which is smaller than the current number
-> the for loop will go into infinite loop if there is no possible k available -> Run Time Error
-> There can possible case (num = 91111 k = 1) , the stack will have the number 9 removed but not added the remaning 1's then 
we have to make use of another loop to append the remaining characters
-> For removing the leading zeros, we will pop the numbers from the front
-> Finally, if the length of the string is 0 return "0" else the newly formed string
-> if the characters to be removed equal to the length of the string return "0"

Exceptions:
-> There are not possible situations where k numbers can be removed
-> There can the case where k is greater than the length of the string

class Solution {
public:
    string removeKdigits(string num, int k) {
     
        if(num.size() == k){
            return "0" ;
        }
        
        deque<char> lookup ;
        
        int length = num.size() ;
        int i = 0 ;
        lookup.push_back(num[i++]) ; // num[i=0] => i++ ;
        
        for(int j = 0 ; j < k ; j++ ){
            while(true){
             //top compares with nothing
            if(i == length){
                lookup.pop_back() ;
                break ;
            }
            //top compares with smaller number
            if(!lookup.empty() && lookup.back() > num[i]){
                lookup.pop_back();
                break ;
            }            
            //top compares with the larger number else add the number without any constraints
            lookup.push_back(num[i++]) ;
            }
        }
        
        //adding remaining number to the deque
        while(lookup.size() < length-k){
            lookup.push_back(num[i++]) ;
        }
        
        //remove the leading zeroes
        while(!lookup.empty() && lookup.front() == '0'){
            lookup.pop_front() ;
        }

        //build the string 
        string answer ;
        while(!lookup.empty()){
            answer.push_back(lookup.front());
            lookup.pop_front() ;
        }
        
        return answer.size() == 0 ? "0" : answer ;
        
    }
};

Time Complexity - O(N+K)
Space Complexity - Max(O(N):stack, O(N):String) = O(N)

//Approach 1 ends

Approach 2

-> The algorithm remains exactly same
-> Instead of stack modify the same string and use the variable "top" to keep the track of the numbers

Time Complexity - O(N+K)
Space Complexity - Max(O(N):String) = O(N)

//Approach 2 ends

Youtube Video : https://www.youtube.com/watch?v=9ZVwu2abL88
