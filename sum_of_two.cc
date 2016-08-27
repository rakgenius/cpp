/*
 * =====================================================================================
 *
 *       Filename:  sum_of_two.cc
 *
 *    Description:  Program to find if the sum of two numbers is equal to a given key
 *
 *        Version:  1.0
 *        Created:  08/27/2016 18:34:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rakesh Venkatesh
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <unordered_map>

using namespace std;
void
find_numbers(int array[], int size, int key)
{
	unordered_map<int, int> hash;

	for (int i = 0; i < size - 1; i++) {
		int tmp = key - array[i];
		if (hash.find(tmp) != hash.end()) {
			cout << array[i] << "\t" << tmp << endl;
		} else {
			hash.insert(make_pair(array[i], 1));
		}
	}
}
int main()
{
	int array[] = {1, 2, 3, 4, 5,6 ,7,8,9,10};
	int key = 9;
	int size = sizeof(array) / sizeof(array[0]);
	find_numbers(array, size, key);
	return 0;
}

