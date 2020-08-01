Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3

And the value to search: 2

You should return this subtree:

      2     
     / \   
    1   3

In the example above, if we want to search the value 5, since there is no node with value 5, we should return NULL.

Note that an empty tree is represented by NULL, therefore you would see the expected output (serialized tree format) as [], not null.

Solutions:

//Approach 1:
-> Checking for the base cases 
    - if the root is NULL
    - if the root has the value then return that value itself
-> Looking at the recursive calls 
    - if the val is less that the parent val move left only if left exists
    - if the val is greater that thr parent val move right only if right exists
-> else return NULL ; since none of the cases are fulfilling


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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        //base cases
        if(root == NULL) return NULL ;
        
        if(root->val == val) return root ;
        
        //recursive cases
        if(val < root->val && root->left != NULL) return searchBST(root->left , val) ;
        else if(val > root->val && root->right != NULL) return searchBST(root->right , val) ;
        
        //neither left child nor right child
        return NULL ;
    }
};

Time Complexity - O(Logn)
Space Complexity - O(1) no extra space allocated
