A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 7 x 3 grid. How many possible unique paths are there?

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:

Input: m = 7, n = 3
Output: 28

Constraints:

    1 <= m, n <= 100
    It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.

Solutions:

//Approach 1(Recursion+Backtracking) :
-> This is approach I have passed the startm and startn specifying the start of both m and n in that particular function
-> Bounds function is used to check the boundary that the number will remain within the limits of the m,n
-> right will count the possible values in the right subtree
-> down will calculate the number of possible values to reach finish in down subtree
-> this solution gives time limit exceeded as we are finding the value of the found paths again and thus to optimize it we will use DP
class Solution {
    
    bool bounds(int m , int n , int startm, int startn){
         return (startm<=m && startn<=n) ;
    }
    
    
    int uniquePathsUtil(int m , int n , int startm , int startn){
        
        //base case
        if(startm == m && startn == n){
            return 1 ;
        }
        
        int right = 0 ;
        int down = 0 ;
        
        //processing part 
        //right direction
        if(bounds(m,n,startm,startn+1)){
            right = uniquePathsUtil(m,n,startm,startn+1);
        }
           
        //down direction
        if(bounds(m,n,startm+1,startn)){
            down = uniquePathsUtil(m,n,startm+1,startn);
        }
           
         return right+down ;
    }
        
public:
    int uniquePaths(int m, int n) {
        
        if(m == 0 || n == 0){
            return 0 ;
        }

        return uniquePathsUtil(m,n,1,1) ;
        
    }
};

Time complexity - O(2^n-1))
Space Complexity - O(1) - use donly constants and no extra space is used

//Approach 2: Dynamic Programming
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>lookup(m, vector(n,1)) ;
        
        // for(int row = m+1 ; row >= 0 ; row--){
        //     for(int col = n+1 ; col >= 0 ; col--){
        //         if(col == n+1){
        //             lookup[row][col] = INT_MIN ;
        //         }
        //         else if(col == 0){
        //             lookup[row][col] = INT_MIN ;
        //         }
        //         else if(row == m+1){
        //             lookup[row][col] = INT_MIN ;
        //         }
        //         else if(row == 0){
        //             lookup[row][col] = INT_MIN ;
        //         }
        //     }
        // }    
        
        cout << "before" << endl ;
       for(int row = 0 ; row < m; row++){
            for(int col = 0 ; col < n ; col++){
               cout << lookup[row][col] << " " ;
            }
            cout << endl ;
        }
        
        for(int row = 1 ; row < m ; row++){
            for(int col = 1 ; col < n ; col++){
                lookup[row][col] = lookup[row-1][col] + lookup[row][col-1] ;
            }
        }
        
        cout << "after" << endl;
        for(int row = 0 ; row < m; row++){
            for(int col = 0 ; col < n ; col++){
               cout << lookup[row][col] << " " ;
            }
            cout << endl ;
        }
        
        return lookup[m-1][n-1] ;
    }
};

Time complexity = O(m-1,m-1)
space complexity = O(m*n)

//Approach 3 : DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(i==m-1 && j==n-1) dp[i][j] = 1;
                else if(i==m-1) dp[i][j] = dp[i][j+1];
                else if(j==n-1) dp[i][j] = dp[i+1][j];
                else dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
