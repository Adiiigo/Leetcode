You are given an array coordinates, coordinates[i] = [x, y], where [x, y] 
represents the coordinate of a point. Check if these points make a straight line in the XY plane.


Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:

    2 <= coordinates.length <= 1000
    coordinates[i].length == 2
    -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    coordinates contains no duplicate point.
    
   Hide Hint #1  
If there're only 2 points, return true.
   Hide Hint #2  
Check if all other points lie on the line defined by the first 2 points.
   Hide Hint #3  
Use cross product to check collinearity.

Solution by me:
class Solution {
private:
    double findSlope(vector<int> num2 , vector<int> num1){       
            return fabs(num2[1]-num1[1]) / fabs(num2[0]-num1[0]) ;
    }    

    bool areSame(double slope1 , double slope2){
          return std::fabs(slope1 - slope2) < std::numeric_limits<double>::epsilon();
    }
    
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int length = coordinates.size() ;
        
        if(length >= 0 && length < 3){
            return true ;
        }
        
        //If the statement comes here => there are more than 3 points
        vector<int> num1 = coordinates[0] ; 
        vector<int> num2 = coordinates[1] ;
        double slope_base = findSlope(num2 , num1 ) ;
        // cout << "slope_base" << slope_base << endl ;
        double slope = 0.0 ;
        
        for(int i = 2 ; i < length ; i++){
            num1 = coordinates[i] ;
            num2 = coordinates[i-1] ;
            slope = findSlope(num2 , num1) ;
            // cout << "slope" << slope << endl ;
            if(areSame(slope, slope_base) == false){
                return false ;
            }
        }
        return true ;        
    }
};

