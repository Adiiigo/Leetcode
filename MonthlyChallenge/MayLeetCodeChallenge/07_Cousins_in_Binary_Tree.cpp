In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

 

Note:

    The number of nodes in the tree will be between 2 and 100.
    Each node has a unique integer value from 1 to 100.
   
Soltion:
(By me)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

private:
    
    bool isSibling(TreeNode* root , int num1 , int num2){
        
        if(root == NULL) {
            return false ;
        }  
        
        bool result_parent ;
        bool result_left ;
        bool result_right ;      
   
        
        if(root->left == NULL || root->right == NULL){
            result_parent = false ;
        }
        else{
            result_parent = (root->left->val == num1 && root->right->val == num2) || 
                            (root->left->val == num2 && root->right->val == num1) ;
        }
        
        if(root->left == NULL){
            result_left = false ;
        }
        else{
            result_left = isSibling(root->left , num1 , num2) ;
        }
        
        if(root->right == NULL) {
            result_right = false ;
        }
        else{
            result_right = isSibling(root->right , num1 , num2) ;
        }
        
        return result_parent || result_left || result_right ;  
        
        // return (root->left == NULL || root->right == NULL ? false : 
        //    ( (root->left->val == num1 && root->right->val == num2) || (root->left->val == num2 && root->right->val == num1))                     )||
        //     ( root->left == NULL ? false : isSibling(root->left , num1 , num2) ) ||
        //     ( root->right == NULL ? false : isSibling(root->right , num1 , num2) ) ;  
        
    } 
    
    int level(TreeNode* root , int num , int levelNo) {

        if(root == NULL){
            return 0 ;
        }
        
        if(root->val == num){
            // cout << "levelNo" <<levelNo << endl;
            return levelNo ;
        }
        
        int downlevel = level(root->left , num , levelNo+1) ;
        
        if(downlevel != 0){
            // cout << "downlevel" << downlevel << endl;
            return downlevel ;
        }
        
        return level(root->right , num , levelNo+1) ;        
    }   
    
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        if(level(root,x,0) == level(root,y,0) && !isSibling(root,x,y)){
            return true ;
        }       
        
        return false ;
        
    }
};
