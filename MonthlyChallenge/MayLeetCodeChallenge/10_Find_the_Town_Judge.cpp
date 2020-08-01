In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

    1.The town judge trusts nobody.
    2.Everybody (except for the town judge) trusts the town judge.
    3.There is exactly one person that satisfies properties 1 and 2.

You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2

Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3

Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1

Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3

Note:

    1.1 <= N <= 1000
    2.trust.length <= 10000
    3.trust[i] are all different
    4.trust[i][0] != trust[i][1]
    5.1 <= trust[i][0], trust[i][1] <= N

Solution:
(by Me and daose)

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        if(trust.empty() && N == 1){
            return N ;
        }
        
        
        unordered_map<int , pair<int,int>> lookup ;
        
        int length = trust.size() ;
        
        for(int i = 0 ; i < length ; i++){
            lookup[trust[i][0]].second++ ;
            lookup[trust[i][1]].first++ ;
        }
        
        for(auto itr = lookup.begin() ; itr != lookup.end() ; itr++){
            if(itr->second.first == N-1 && itr->second.second == 0){
                return itr->first ;
            }
        }
        return -1 ;        
    }
};

Solution 2 (using single array) :
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        int length = trust.size() ;

         if(length < N-1){
            return -1 ;
        }
        
        vector<int> trustLevel(N+1) ;
        
        for(auto edge : trust){
            trustLevel[edge[0]]-- ;
            trustLevel[edge[1]]++ ;
        }
        
        for(int i= 1 ; i <= N ; i++){
            if(trustLevel[i] == N-1){
                return i ;
            }
        }
        return -1 ;        
    }
};

Solution3:
As we have seen the problem that the judge can be a person who each and every person trusts but that person should not trust 
anybody.

The catch here is that the indegree of that person is N-1(there are N people in the town) and ut degree is 0

We can use either unordered_map(solution 1) or one array(solution 2) keeping this information
and modifying the secodn approach(reducing the runtime complexity)

we will traverse only one time,i,e, we will randomly assign first person as town judge and then only assign the other person
as townjudge when the trustlevel of that judge is equal to N-1 

As we are aware of the fact that when someone trusts someone, they are no more judge => removing them from the candidancy
by setting their trustlevel as -1 and we are reducing the traverse time even more and traversing through only those who are 
remaining.

Look at the solution below for code implemenation.

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        int length = trust.size() ;

         if(length < N-1){
            return -1 ;
        }
        
        vector<int> trustLevel(N+1) ;
        
        //inserting potential judge
        int judge = 1 ;
        
        for(auto edge : trust){
            trustLevel[edge[0]] = -1 ;
            if(trustLevel[edge[1]] != -1){
                trustLevel[edge[1]]++ ;
            
                if( trustLevel[edge[1]] == N-1 ){
                    judge = edge[1] ;
                }
            }
        }
        
        // Do not have to traverse the whole array since that work is already done in the first iteration
        // for(int i= 1 ; i <= N ; i++){
        //     if(trustLevel[i] == N-1){
        //         return i ;
        //     }
        // }
                          
        return trustLevel[judge] == N-1 ? judge : -1 ;
       
    }
};
