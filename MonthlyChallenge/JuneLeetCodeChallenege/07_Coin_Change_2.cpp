You are given coins of different denominations and a total amount of money. 
Write a function to compute the number of combinations that make up that amount. 
You may assume that you have infinite number of each kind of coin.

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:

Input: amount = 10, coins = [10] 
Output: 1

Note:

You can assume that

    0 <= amount <= 5000
    1 <= coin <= 5000
    the number of coins is less than 500
    the answer is guaranteed to fit into signed 32-bit integer

solutions:

//Approach 1:

class Solution {
    
    int changeUtil(int amount, int length ,vector<int> coins){
        
        if(amount == 0){
            return 1 ;
        }
        
        if(amount < 0){
            return 0 ;
        }
        
        int res = 0 ;
        
        for(int i = 0 ; i < length ; i++ ){
            res += changeUtil(amount-coins[i] , length , coins) ;
        }
        
        return res ;
    }
    
    
public:
    int change(int amount, vector<int>& coins) {
        return changeUtil(amount, coins.size() , coins) ;
    }
};

//approach 2
class Solution {
    
    unordered_map<string,int> lookup;
    
    int changeUtil(int amount, int length ,vector<int> coins){
        
        if(amount == 0){
            return 1 ;
        }
        
        if(amount < 0 || length < 0){
            return 0 ;
        }
        
        string key = to_string(length) + '|' + to_string(amount) ;
        
        if(lookup.find(key) == lookup.end())
        {
            int include = changeUtil(amount-coins[length] , length , coins) ;
            int exclude = changeUtil(amount, length-1 , coins) ;
            
            lookup[key] = include+exclude;
        }
        return lookup[key] ;
    }
    
    
public:
    int change(int amount, vector<int>& coins) {
        return changeUtil(amount, coins.size()-1 , coins) ;
    }
};

//appraoch 3:
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<int> dp(amount+1,0) ;
        
        dp[0] = 1; 
        
        //iterate over coins
        for(int i = 0 ; i < coins.size() ; i++ ){
            for(int j = coins[i] ; j <= amount; j++){
                dp[j] += dp[j-coins[i]] ;
            }
        }
        return dp[amount] ;
    }
};
