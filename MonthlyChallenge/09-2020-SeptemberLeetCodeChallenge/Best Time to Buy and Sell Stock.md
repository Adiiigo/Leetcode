
Solution 1 (not worked)
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minVal = INT_MAX ;
        int minIndex = 0 ;
        
        for(int i = 0 ; i < prices.size() ; i++){
            
           if(minVal > prices[i]){
               minVal = prices[i] ;
               minIndex = i ;
            }
                        
        }
        
        int maxVal = INT_MIN ;
        
        for(int i = minIndex+1 ; i < prices.size() ; i++){
            
            maxVal = max(maxVal , prices[i]) ;
            
        }
        
        if(maxVal == INT_MIN) return 0 ;
        
        return maxVal-minVal ;
        
    }
};

/*
Not worked for [2,4,1]
*/
```
