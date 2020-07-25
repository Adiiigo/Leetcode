Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

 

Constraints:

    board and word consists only of lowercase and uppercase English letters.
    1 <= board.length <= 200
    1 <= board[i].length <= 200
    1 <= word.length <= 10^3

Solutions:

//Approach 1: Backtracking and dfs
-> here we will traverse through the matrix and try to find the first letter that matches and only if it will then only we will apply dfs
-> in dfs first we will write the base cases
-> checking if the end letter is reached
-> checking for boundaries
-> Replacing character so that we do not visit it again
-> making recursive call
-> and replacing it again as for other recursion calls to use

class Solution {
    
    bool dfs(vector<vector<char>>& board, int row, int col, int count, string word){

        //We have reached til the end and beyond by one point
        if(count == word.size()){
            return true;
        }

        //checking for bounds
        if( row < 0 || row >= board.size() || 
            col < 0 || col >= board[row].size() || 
            word[count] != board[row][col] )
            return false;

        //If we have reached till here that means, we have a letter and it is not the final letter and it 
        //the letter which is present in the word

        //Since we dont want the same letter to be repeated again
        char temp = board[row][col] ;
        board[row][col] = '#' ;

        bool found= dfs(board , row-1 , col , count+1 , word) ||
                    dfs(board , row , col+1 , count+1 , word) ||
                    dfs(board , row+1 , col , count+1 , word) ||
                    dfs(board , row , col-1 , count+1 , word) ;

        // if we have reached here that means for all the four directions we didnt find the nect letter
        //Replacing it with the original letter for others to use
        board[row][col] = temp ;

        return found ;

    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int row = 0 ; row < board.size() ; row++){
            for(int col = 0 ; col < board[row].size(); col++){
                if(board[row][col] == word[0] && dfs(board , row, col , 0 , word)){
                    return true ;
                }  
            }
        }
        return false;
    }
};

Time Complexity : O(m*n) - since we will have to traverse through the matrix to check for the first letter in the best case we will not get the answer and we will not require recusion stack of dfs and in the worst case thw whole matrix letters will be utilized and that many recursion calls will be made
Space Complexity : O(m*n) - for the recursion stack, else we are processing inplace processing


