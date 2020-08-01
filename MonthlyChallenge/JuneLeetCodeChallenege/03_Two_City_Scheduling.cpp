There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], 
and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.

Note:

    1 <= costs.length <= 100
    It is guaranteed that costs.length is even.
    1 <= costs[i][0], costs[i][1] <= 1000

Solution: (Greedy and sorting)

-> We will be using differences between the values and leverāge that to find which person will fly into which city
-> The catch here is that we have sort the people based on the differences. This will us to get the min differ̥ēnces above which can be used 
initially.

class Solution {
    
    static bool mysortingAlgo(vector<int> i,vector<int> j) { 
        
        return abs(i[0]-i[1]) > abs(j[0]-j[1]) ; 
        
    }
    
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin() , costs.end() , mysortingAlgo) ;
        
        int cities = costs.size() ;
        int city = cities/2 ;
        
        int acity = 0 ; 
        int bcity = 0 ;
        int minCost = 0 ;
        
        for(int i = 0; i < cities ; i++) {
            if(costs[i][0] < costs[i][1]){
                //Acity
                if(acity < city){
                    acity++ ;
                    minCost += costs[i][0] ;
                }
                else{
                    bcity++ ;
                    minCost += costs[i][1] ;
                }
            }
            else{
                //Bcity
                if(bcity < city){
                    bcity++ ;
                    minCost += costs[i][1] ;
                }
                else{
                    acity++ ;
                    minCost += costs[i][0] ;
                }
            }
        }
        return minCost ;
    }
};
