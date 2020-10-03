```
class Solution {
    
    int answer = 0 ;
    int rows = 0 ;
    int cols = 0 ; 
    int finalAnswer = INT_MAX ;
    
    //left , top-left , top , top-right , right , bottom-right , bottom , bottom-left
    vector<vector<int>>directions={
        {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}
    };
    
    // vector<vector<int>>directions={
    //     {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}
    // };
    
    bool inbound(int x, int y){
        return x >= 0 && x < rows && y >= 0 && y < cols ;
     }
    
    void UtilFunc(vector<vector<int>>& grid,int start_row , int start_col){        
        
        //base case
        if(start_row == rows-1 && start_col == cols-1){
            // stop the recusion call
            // cout << answer << endl; 
            finalAnswer = min(finalAnswer , answer) ;
            return ;
        }
        
        //mark the cell as visited
        grid[start_row][start_col] = -1 ;
        answer++ ;
        
        for(vector<int>dir : directions){
            int new_row = start_row + dir[0] ;
            int new_col = start_col + dir[1] ;
            
            if(inbound(new_row,new_col) && grid[new_row][new_col]==0 ){
                UtilFunc(grid , new_row , new_col) ;
            }
        }
               
        //unmark it so that it can be used by other paths
        grid[start_row][start_col] = 0 ;
        answer-- ;
    }
    
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        
        //N*N matrix
        rows = grid.size() ;
        cols = grid[0].size() ;
        
        int start_row = 0 ;
        int start_col = 0 ; 
        
        if(grid[start_row][start_col] == 1) return -1 ;
        
        UtilFunc(grid , start_row , start_col) ;
        // cout <<finalAnswer <<endl ;
        
        if(finalAnswer == INT_MAX) return -1 ;
        
        return finalAnswer+1 ;
        
    }
};
```

```
Not working for 
[[0,1],[1,0]]
[[0,0,0],[1,1,0],[1,1,0]]
[[1,0,0],[1,1,0],[1,1,0]]
[[0,0,1,1,0,0],[0,0,0,0,1,1],[1,0,1,1,0,0],[0,0,1,1,0,0],[0,0,0,0,0,0],[0,0,1,0,0,0]] - time limit excceded 
after which tried removing top-left,left,bottom-left, down test cases didnt work

[[0,0,1,0,0,0,0],[0,1,0,0,0,0,1],[0,0,1,0,1,0,0],[0,0,0,1,1,1,0],[1,0,0,1,1,0,0],[1,1,1,1,1,0,1],[0,0,1,0,0,0,0]] 
- here top-left,left,bottom-left, down is getting used 
```
