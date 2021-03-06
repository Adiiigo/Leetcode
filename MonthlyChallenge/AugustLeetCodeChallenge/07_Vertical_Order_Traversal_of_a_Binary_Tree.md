# Problem Description

Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

#### *If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.*
```
if the nodes are at the same level, then look at the values , 
if the nodes are not at the same level then one with the smaller level will come first
```

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

 
```
Example 1:

Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).
```
```
Example 2:

Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: 
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.
```

#### Note:

- The tree will have between 1 and 1000 nodes.
- Each node's value will be between 0 and 1000.

## Solutions:

### Approach 1:(Preorder)
- Using hash map to store the level and corresponding vector of node value which lie in that level
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    void helper(TreeNode* root , int level , map<int , vector<int>>& lookup){
        
        //base case 
        if(root == NULL) return ;
        
        //adding the number in the lookup for that particular level
        lookup[level].push_back(root->val) ;
        
        //for left subtree
        helper(root->left , level-1 , lookup) ;
        
        //for right subtree
        helper(root->right , level+1 , lookup) ;
        
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // levelNo | vector to number in that level
        map<int , vector<int>> lookup ;
        int level = 0 ;
        
        //to populate the lookup table
        helper(root , level , lookup) ;
        
        vector<vector<int>> answer ;
        for(auto eachPair : lookup){
            answer.push_back(eachPair.second) ;
        }
        
        return answer ;
    }
};
```

### Approach 2:(Level order traversal)
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
        
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> answer ;
        
        if(root == NULL) return answer ;
        
        // levelNo | vector to number in that level
        map<int , vector<int>> lookup ;
        int level = 0 ;
        
        //to populate the lookup table
        // node | level        
        queue<pair<TreeNode*,int>> q ;
        q.push({root, 0}) ;
        
        while(!q.empty()){
            pair<TreeNode*,int>front = q.front() ;
            q.pop() ;
            TreeNode* parent = front.first ;
            int level = front.second ;
            
            lookup[level].push_back(parent->val) ;
            
            if(parent->left) q.push({parent->left , level-1}) ;
            if(parent->right) q.push({parent->right , level+1}) ;
            
        }
        
      
        for(auto eachPair : lookup){
            sort(eachPair.second.begin() , eachPair.second.end()) ;
            answer.push_back(eachPair.second) ;
        }
        
        return answer ;
    }
};
```
TestCases :
```
[3,9,20,null,null,15,7]
[1,2,3,4,5,6,7]
[1,2,3,4,5,6,7,null,null,null,null,null,8,null,9]
[1,2,3,4,5,6,7,null,null,null,null,null,8,10,9,null,null,11,null,null,null,null,12]
[0,8,1,null,null,3,2,null,4,5,null,null,7,6]
[0,2,1,3,null,null,null,4,5,null,7,6,null,10,8,11,9]
[0,5,1,9,null,2,null,null,null,null,3,4,8,6,null,null,null,7]
```
Reference : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/777735/Clean-and-Concise-or-Logic-explained-or-Fully-commented-or-Beats-94-C%2B%2B
