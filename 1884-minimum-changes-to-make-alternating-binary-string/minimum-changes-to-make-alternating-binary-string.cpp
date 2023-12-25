class Solution {
public:
    int count(string s, char prevLetter) {
        int val = 0;
        cout << s.size();
        for(int i = 1 ; i < s.size() ; i++) {
            char curLetter = s[i];
            if(curLetter == prevLetter) {
                val++;
                prevLetter = prevLetter == '0' ? '1' : '0';
            } else {
                prevLetter = curLetter;
            }
            
        }

        return val;

    }

public:
    int minOperations(string s) {
        char firstLetter = s[0];
        int count1 = count(s, firstLetter);
        int count2 = count(s, firstLetter=='0' ? '1' : '0')+1;
        return min(count1, count2);
    }


};