Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].

 

Example 1:

Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
Output: [null,1,1,1,2,1,4,6]
Explanation: 
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.

Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.

 

Note:

    Calls to StockSpanner.next(int price) will have 1 <= price <= 10^5.
    There will be at most 10000 calls to StockSpanner.next per test case.
    There will be at most 150000 calls to StockSpanner.next across all test cases.
    The total time limit for this problem has been reduced by 75% for C++, and 50% for all other languages.


Approach 1:
-> Keep pushing values in the list whenever new values comes in
-> Keep the counter variable going from the price backwrads and increase the counter if the value of the stock is less that the 
   price, If at any point previous prices is more than the current day price. break the loop and return the counter value
   
class StockSpanner {
    
    vector<int> lookup ;
    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        lookup.push_back(price) ;
         int length = lookup.size() ;
        
        for(int i = 0 ; i < length; i++){
            cout << lookup[i] << "," ;
        }
       
        int count = 1 ;
        
        for(int i = length-2 ; i >= 0 ; i--){
            if(lookup[i] <= price){
                count++ ;
            }
            else{
                break ;
            }
        }
        return count ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

Time Complexity - Time limit Exceeded
Space complexity - it will keep on increasing as the new values come in.
The problme is that we can store the value in optimal vale and the reduce the space as well.

//Approach 1 ends

//Approach 2
->  Eg: [80,60,70,60,75,85]
         1  1  2   1  4  6

After adding day 1: 
 top - (80 , 1) 1 day <= 80

After adding day 2:
 top - (60 , 1) 1 day <= 60
       (80 , 1) 1 day <= 80
       
After adding day 3:
 top - (70 , 1) 1 day <= 60
       (60 , 1) 1 day <= 60
       (80 , 1) 1 day <= 80
       then,
 top - (70 , 2) 2 day <= 70   we have combined all the values as if the price 60 comes up again it will be anyways resetted
       (80 , 1) 1 day <= 80
       
After adding day 4:
 top - (75 , 1) 1 day <= 75
       (70 , 2) 2 day <= 70
       (80 , 1) 1 day <= 80
       
After adding day 5:
 top - (85 , 1) 1 day <= 85
       (75 , 1) 1 day <= 75
       (70 , 2) 2 day <= 70
       (80 , 1) 1 day <= 80
       then combining,
 top - (85 , 6) 6 day <= 85

-> saving space and time alltogether

class StockSpanner {
    
    stack<int> prices ;
    stack<int> span ;
    
public:
    StockSpanner() {

    }
    
    int next(int price) {
        prices.push(price) ;
        span.push(1) ;
        
        int cur_span = 0;
        
        while(!prices.empty() && prices.top() <= price ){
            cur_span += span.top() ;
            span.pop() ;
            prices.pop() ;
        }
        
        prices.push(price) ;
        span.push(cur_span) ;
        
        return span.empty() ? 0 : span.top() ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
 
 Time Complexity - O(N) - the number of times we call next
            [100,99,...,1,101] - empty the stack for 101 -> N
 
 https://www.youtube.com/watch?v=JsYyLiGXHsc

  

