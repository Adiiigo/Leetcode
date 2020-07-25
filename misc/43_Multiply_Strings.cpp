Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

Note:

    The length of both num1 and num2 is < 110.
    Both num1 and num2 contain only digits 0-9.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.

Solutions:

//Approach 1:
-> Normal mutiplication method
-> but overflows for bigger intergers

class Solution {
public:
    string multiply(string num1, string num2) {
        
        int length1 = num1.size()-1 ;
        int length2 = num2.size()-1 ;
        
        int sum = 0 ;
        string product = "" ;
        int powerof10 = 1 ;
        int temp = 0 ;
        
        while(length2 >= 0){
            
            int multiplier = num2[length2]-'0' ;
            product = "" ;
            length1 = num1.size()-1 ;
            temp = 0 ;
            
            while(length1 >=0 || temp > 0){
                temp = ((length1>=0)?(num1[length1]-'0')*multiplier+temp:temp) ;
                product = char(temp%10 + '0') + product  ;
                temp = temp/10 ;
                length1--;
            }
            cout << "product" << product << endl ; 
            int temp2 = stoi(product) ;
            temp2 = temp2 * powerof10 ;
            sum +=temp2 ;
            powerof10 *= 10 ;
            
            length2--;
        }
        
        string answer = to_string(sum) ;
        
        return answer ;
    }
};

//Approach 2:
-> Using positions wisely and adding that position value too will forming sum

class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() +num2.size() , '0') ;
        
        for(int i = num1.size()-1 ; i >= 0 ; i--){
            int carry = 0 ;
            for(int j = num2.size()-1 ; j >= 0 ; j--){
                int tmp = (sum[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0') + carry ;
                sum[i+j+1] = tmp %10 +'0' ;
                carry = tmp/10 ;
            }
            sum[i] += carry ;
        }
        
        // cout << sum ;
        
        size_t startpos = sum.find_first_not_of("0");
        if (string::npos != startpos) {
            return sum.substr(startpos);
        }
        return "0";
    }
};
