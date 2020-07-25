Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

Solutions:

// Approach 1
/*
 * LeetCode_ReverseStringWordByWordII_main.cpp
 *
 *  Created on: 18-Jul-2020
 *      Author: aditi
 */
#include<iostream>
using namespace std ;

void reverseString(string& input){

	int i = 0 ;
	int j = input.size()-1 ;

	while(i <= j){
		// we can use difference in the char value and add it and subtract it we do not want to use extra variable
		char temp = input[i] ;
		input[i] = input[j] ;
		input[j] = temp ;
		i++;
		j--;
	}
}

void reverseString(string& input ,int i , int j){

	while(i <= j){
		// we can use difference in the char value and add it and subtract it we do not want to use extra variable
		char temp = input[i] ;
		input[i] = input[j] ;
		input[j] = temp ;
		i++;
		j--;
	}
}

void extractReverseStringWordByWord(string& input){

	int length = input.size()-1 ;

	for(int i = 0 ; i < length ; i++){
		if(input[i] != ' '){
			int j = i ;
			for(; j <= length ; j++){
				if(input[j] == ' '){
						break ;
				}
			}

			j--;
			reverseString(input,i,j);
			i = j ;
		}
	}
}

int main() {

	string input = {"the sky is blue and sun is rising high"} ;

	reverseString(input) ;

	extractReverseStringWordByWord(input) ;

	cout << input ;
	return 0 ;
}

Output : high rising is sun and blue is sky the
