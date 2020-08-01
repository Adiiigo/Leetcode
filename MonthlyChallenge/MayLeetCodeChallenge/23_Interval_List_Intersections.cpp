Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b. 
The intersection of two closed intervals is a set of real numbers that is either empty, 
or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

Example 1:

Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 

Note:

    0 <= A.length < 1000
    0 <= B.length < 1000
    0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9

Solutions:

-> There are differenct cases of overlap
  -------               -----------      ----------------
  |     |               |         |      |              |
  -------               -----------      ----------------
      ---------     --------                ---------
      |       |     |      |                |       |
      ---------     --------                ---------
      
-> The valid overlapping occurs only when we have the maximum of lower of intervals be less than the min of
  higher of intervals else there is no overlapping 
-> Discarding of the intervals will be done on the basis of the lower endpoints between the intervals as 
one with the smaller interval has already been evaluated

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<vector<int>> answer ;
       
        
        int lengthA = A.size() ;
        int lengthB = B.size() ;
        int i = 0 ; 
        int j = 0 ;
        
        while(i < lengthA && j < lengthB){
            int low = max(A[i][0], B[j][0]) ;
            int high = min(A[i][1],B[j][1]) ;
            
            
            if(low <= high){
                vector<int> temp ;
                temp.push_back(low) ;
                temp.push_back(high) ;
                answer.push_back(temp) ;
            }
            
            if(A[i][1] < B[j][1]){
                i++ ;
            }
            else{
                j++ ;
            }
        }
        return answer ;
    }
};

Time complexity - O(M+N)
Space complexity - O(M+N) 
