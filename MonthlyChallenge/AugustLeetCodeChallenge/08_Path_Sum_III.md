# Problem description
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:
```
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
```

## Solutions :
- The idea is that we have to traverse every node
- For every node we have look for the possible outcome path till the leaf nodes. Add all such paths for the particular node and return the value to the one common variable

### Approaches 1 :(Wrong Answer code)
- Based on the same approach

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
    
    
    void recHelper(TreeNode* root , int sum , int& path){
        
        if(sum < root->val){
            return ;
        }
        
        // base case
        // this means that that sum value has reached zero and no more subtraction is required
        if(sum == 0){
            cout << path << endl ;
            path++ ;
        }
        
        
        //This will recursively check for the reduced values of the sum considering that the subtration is possible
        if(root->val <= sum){
            int num = sum - root->val ;
            if(root->left) recHelper(root->left , num , path) ;
            if(root->right) recHelper(root->right , num , path) ;
            
            // if there is no left and right child, to stop the recursion at leaf nodes
            if(root->left == NULL && root->right == NULL) return ;
        }
        return; 
        
    }
    
    void helper(TreeNode* root , int sum , int& path){            
 
        //This will recursively check for the reduced values of the sum considering that the subtration is possible
        if(root->val <= sum){
            int num = sum - root->val ;
            if(root->left) recHelper(root->left , num , path) ;
            if(root->right) recHelper(root->right , num , path) ;
            
       }
        
        if(root->left) helper(root->left , sum , path) ;
        if(root->right) helper(root->right , sum , path) ;
        
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        
        if(root == NULL) return 0 ;
        
        int path = 0 ;
        
        helper(root , sum , path) ;
        
        return path ;
    }
};
```

### Approach 2:
- Base the same approach with correct solution
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
    
    
    int recHelper(TreeNode* root , int sum ){
        
        if(root == NULL) return 0 ;
        
        return (sum == root->val) + 
                recHelper(root->left , sum - root->val) + 
                recHelper(root->right , sum - root->val) ;
        
    }
    
    void helper(TreeNode* root , int sum , int& path){            
 
        if(root == NULL) return ;
       
        path += recHelper(root , sum ) ; 
        
        helper(root->left , sum , path) ;
        helper(root->right , sum , path) ;
        
    }
    
public:
    int pathSum(TreeNode* root, int sum) {

        
        int path = 0 ;
        
        helper(root , sum , path) ;
        
        return path ;
    }
};
```

### Approach 3:
- Using the observation in the above algorithm, we can store the number in the array
- This Approach stores the value in the array in such a way that paths may no be added correctly, by chance the sum of the number in such way is equal to what we want it will fail.
(initial observation)

```
input:
      1  
     /  \
    1    1
   / \    \
  1   1    1
      \
       1
```
- But after looking into the output, observed that we are passing new array for the subtrees and not passing the arrays by reference
```
1 
2 1 
3 2 1 
3 2 1 
2 1 
3 2 1 
4 3 2 1 
3 2 1 
```


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
    
    void print(vector<int>& pa){
    
        cout << endl ;
        for(int i = 0 ; i < pa.size() ; i++){
            cout << pa[i] << " ";
        }
    }
    
public:
    void pathsum2(TreeNode *root,int sum,vector<int>pa,int* res){
        if(root){
            for(int i=0;i<pa.size();i++){
                pa[i]+=root->val;
                if(pa[i]==sum){
                    (*res)++;
                }
            }
            if(root->val==sum){
                (*res)++;
            }
            pa.push_back(root->val);
            print(pa) ;
            pathsum2(root->left,sum,pa,res);
            pathsum2(root->right,sum,pa,res);
        }
    }
    
    int pathSum(TreeNode* root, int sum) {
        int res=0;
        vector<int>pa;
        pathsum2(root,sum,pa,&res);
        return res;
    }
};
```
