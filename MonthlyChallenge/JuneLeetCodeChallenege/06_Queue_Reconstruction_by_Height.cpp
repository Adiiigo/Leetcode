Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), 
where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. 
Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

    Hide Hint #1  
What can you say about the position of the shortest person?
If the position of the shortest person is i, how many people would be in front of the shortest person?
    Hide Hint #2  
Once you fix the position of the shortest person, what can you say about the position of the second shortest person?

Solutions

//Approach 1:
-> Sort the people in descending order

For Eg :
 (7,0),(4,4),(7,1),(5,0),(6,1),(5,2)
 
 After sorting :
 (7,0),(7,1),(6,1),(5,0),(5,2),(4,4)

--> we will pick the people one by one and then put them on the basis of the 'k' value and kepe inserting
  other people on the basis of the value of K
 
class Solution {
    
    static bool mySortingFunc(vector<int>a , vector<int>b){

        return a[0] > b[0] || ( a[0] == b[0] && a[1] < b[1] ) ;
        
    }   
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin() , people.end() , mySortingFunc) ;
        
        vector<vector<int>> res ;
        
        for(auto &p : people){
            res.insert(res.begin() + p[1] , p);
        }
        return res ;
    }
};

Time Complexity : o(nlogn) - sorting ; o(n) - traversing through the people * o(n) shifting people accordingly -> O(n^2)
Space Complexity(extra except the answer vector) : O(1)

//Approach 1 ends

//Approach 2 
class Solution {
    
    static bool mySortingFunc(vector<int>a , vector<int>b){

        return a[0] < b[0] || ( a[0] == b[0] && a[1] < b[1] ) ;
        
    }
    
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin() , people.end() , mySortingFunc) ;
        
        vector<vector<int>> res(people.size() , vector(int)) ;
        int count = 0 ; 
        
        for(int i = 0 ; i < people.size() ; i++){
            count = 0 ;
            
            for(int j = 0 ; j < res.size() ; j++){
                if(res[j].empty()){
                    if(count == people[i][1]) break;
                    count++ ;
                }
            }
            
            res[j] = people[i] ; 
            
        }
        return res ;
        
        
    }
};
