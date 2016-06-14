/*
 * =====================================================================================
 *
 *       Filename:  kpalindrome.cpp
 *
 *    Description:  Function to implement to check if two strings are palindrome by
 *    			    removing k characters
 *
 *        Version:  1.0
 *        Created:  06/14/2016 10:40:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rakesh Venkatesh
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
/*
 * Function to implement the function to see if two strings can be made
 * palidrome by removing k characters
 *
 * @input : str1, str2, : two strings
 * @input : n , m : length of two strings
 * @output : boolean : true if they are palindrome, false if they arent
 */
bool
isKPalindrome(string str1, string str2, int n, int m)
{
	//create a 2d array to store the intermediate results
	int dp[n+1][m+1];

	for (int i =0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0) {
				dp[i][j]=j;
			} else if (j == 0) {
				dp[i][j] = i;
			} else if (str1[i-1] == str2[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[n][m];
}

bool kpalindrome(string str1, string str2, int n, int m, int k)
{
	return (isKPalindrome(str1, str2, n, m) <= k*2 );
}
int main()
{
	string str1 = "acdcb";
	string str2 = str1;
	reverse(str2.begin(), str2.end());

	int l = str1.length();

	kpalindrome(str1, str2, l ,l, 1) ? cout << "YES" : cout << "NO";
	cout <<endl;
}
