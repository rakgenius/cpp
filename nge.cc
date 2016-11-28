/*
 * =====================================================================================
 *
 *       Filename:  nge.cc
 *
 *    Description:  Program to display the next greater element in the array
 *
 *        Version:  1.0
 *        Created:  07/20/2016 21:34:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rakesh venkatesh 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void nge(vector<int> array)
{
	stack<int> st;
	u_int8_t i;

	//if array is empty, return
	if (array.size() == 0) {
		return;
	}

	//if array has onlu one element then no nge. print -1
	if (array.size() == 1) {
		cout << array[0] << "->" << "-1" << endl;
		return;
	}
	int top;
	//push the first element into the stack
	st.push(array[0]);

	//iterate through the array to find the nge for each element
	for (i=1;i<array.size(); i++) {
		//process if stack is not empty
		//pop the item from the stack and compare it with the current element
		u_int32_t current = array[i];
		top = st.pop();
		if (!st.empty()) {
			//while the popped element is less than the current element,
			//mark current as the nge for the popped element.
			while (top < current) {
				cout << top << "->" << current << endl;
				if (st.empty()) {
					break;
				}
				top = st.pop();
			}
			if (top > current)
				st.push(top);
		} else {
			st.push(current);
		}
	}
	while (!st.empty()) {
		top = st.pop();
		cout << top << "->" << "-1" << endl;
	}
}

