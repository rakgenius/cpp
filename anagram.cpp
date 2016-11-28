/*
 * =====================================================================================
 *
 *       Filename:  anagram.cpp
 *
 *    Description:  Program to find if two string are anagram of each other or not
 *
 *        Version:  1.0
 *        Created:  07/21/2016 19:04:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rakesh venaktesh
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int anagrams(string str1, string str2)
{
	unordered_map<int, int> table;
	int i;

	for (i=0; i< str1.length(); i++) {
		table[str1[i]]++;
	}

	for (i = 0; i< str2.length(); i++) {
		table[str2[i]]--;
	}

	for (i=0; i < str1.length(); i++) {
		if (table[str1[i]] != 0) {
			return 0;
		}
	}

	return 1;
}

int main()
{
	string str1 = "Rakesh", str2 = "Venkatesh";
	if (anagrams(str1, str2)) {
		cout << "Yes they are anagrams" ;
	} else {
		cout << "No they are not anagrams" ;
	}
}
