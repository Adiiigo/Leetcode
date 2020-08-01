Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true

Example 2:

Input: 14
Output: false

Solution: 
(by me :Failed attempt)
class Solution {
private:
    bool unitsDigit(int num){
        
        int arr[] = {1,4,9,6,5} ;
        // cout << "num:" << num; 
        
        int units = num%10 ;
        // cout << "units:" << units ;
        
        for(int a : arr){
            if(a == units){
                return true ;
            }
        }
        return false ;
    }   
    
    int findSum(int num) {
        int sum = 0 ;
        
        while(num > 0){
            sum += num%10;
            num /= 10 ;
        }
        return sum ;
    }
    
    bool digitalRoots(int num) {
        
        int sum = 0 ;
        
        sum = findSum(num) ;
        
        while(sum > 9){
            sum = findSum(sum) ;
        }
        
        cout << "sum:" << sum ;

        int roots[] = {1,4,7,9} ;
        
        for(int a : roots){
            if(sum == a){
                return true ;
            }
        }
        return false ;
    }
    
    bool tensDigit(int num){
        
        int units = num%10 ;
        int tens = (num/10)%10 ;
        
        //checking for 6 
        if(units == 6) {    
            
            if(tens % 2 != 0){
                return true ;
            }
            
            return false ;
        }
        
        //checking for 5
        if(units == 5){
            
            if(tens == 2) {
                return true ;
            }
            
            return false ;
        }
        
        //cheecking for 1,4,9
        int arr[] = {1,4,9} ;
        for(int a: arr){
            if(a == units){ // for numbers like 801 or 808201
                if(tens%2 == 0){
                    int rem = num/100 ;
                    return isPerfectSquare(rem) ;
                }
                else{
                    return false ;
                }
            }            
        }
        return false ;
    }
    
public:
    bool isPerfectSquare(int num) {
        
        if(num == 0) {
            return true ;
        }
        
        int units = num%10 ;
        int tens = (num/10)%10 ;
        bool answer ;
        
        //for 100
        if(units == 0){
            if(tens == 0){
                int temp = num/100 ;
                answer = unitsDigit(temp) && digitalRoots(temp) && tensDigit(temp);
            }
            else{
                answer = false ;
            }
        }
        else{
                answer = unitsDigit(num) && digitalRoots(num) && tensDigit(num);
        }
       return answer ;
    }
};

Solution 2: Binary Search
(by Daose)

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1 ;
        int right = num ;
        
        int mid = 0 ;
        
        while(left <= right) {
            
            mid = left + (right-left)/2 ;
            long square = (long)mid*mid ;
            
            if(square == num) return true ;
            
            if(square > num) {
                right = mid - 1 ;
            }
            else{
                left = mid + 1 ; 
            }
        }
        return false ;
    }
};

Solution3 : Babylanion Method
(by Daose)
class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int temp = num ;
        int digits = 0 ;
        while(temp != 0) {
             temp /= 10 ;
            digits++ ;           
        }
        cout << "digits:" << digits << endl ;
        
        digits = (digits/2) + 1;
        float guess = 1 ;
        
        while(digits >= 0) {
            guess *= 10 ;
            digits-- ;
        }
        
        cout << "guess:" << guess << endl ;
        
        long prev = 0 ;
        while(prev != (int)guess) {
            prev = (int)guess  ;
            guess = 0.5f*(guess + num/guess) ;
        }
        if( prev*prev == num) return true ;
        if( (prev+1) * (prev+1) == num) return true ;
        return false ;        
    }
};
