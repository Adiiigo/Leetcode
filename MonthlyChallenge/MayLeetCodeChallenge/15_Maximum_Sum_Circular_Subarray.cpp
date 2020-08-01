Given a circular array C of integers represented by A, 
find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning 
of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, 
and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once. 
(Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist 
i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3

Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10

Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4

Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3

Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1

Note:

    -30000 <= A[i] <= 30000
    1 <= A.length <= 30000

  Hint #1  
For those of you who are familiar with the Kadane's algorithm, think in terms of 
that. For the newbies, Kadane's algorithm is used to finding the maximum sum 
subarray from a given array. This problem is a twist on that idea and it is 
advisable to read up on that algorithm first before starting this problem. 
Unless you already have a great algorithm brewing up in your mind in which case, 
go right ahead!

  Hint #1
What is an alternate way of representing a circular array so that it appears to 
be a straight array? Essentially, there are two cases of this problem that we 
need to take care of. Let's look at the figure below to understand those two cases:

case 1 : ________________________________________
         |    | max subarray in the middle |    |
         |____|____________________________|____|
         0                                      n-1
 case 2 : ________________________________________________________
         |    | max subarray in the middle |  split across  |     |
         |____|____________________________|________________|_____|
         0                                 n-1                    2n-1
        
 Hint #3  
The first case can be handled by the good old Kadane's algorithm. However, is there a smarter way of going about handling the
second case as well?

Approach 1 :
-> find max subarray sum considering it as linear array
-> find total sum of the array
-> find min subrray sum considering it as linear array
-> maximum of max , total-min

//approach 1 ends

Approach 2 :
-> find max subarray sum considering it as linear array
-> find total sum of the array
-> negative the values of the rray
-> find max subrray sum considering it as linear array
-> maximum of max , total+max(after negation)

class Solution {
    private:
    int kadane(vector<int> A){
        
        int sum = 0 ;  
        int result = INT_MIN ;
        
        for(int x : A) {
            sum = sum + x ;
            result = max(result , sum) ;
            sum = max(sum , 0) ;
        }
        
        return result ;
    }
    
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        int max_before = kadane(A) ;
        
        int total = 0 ;
        for(int x : A){
            total += x ;
        }
        
        int length = A.size() ;
        for(int i = 0 ; i < length ; i++){
            A[i] = -A[i] ;
        }
        
        int max_after = kadane(A) ;
        
        if(total+max_after == 0){
            return max_before ;
        }

        return max(max_before , total + max_after) ;
    }
};

//appraoch 2 ends










