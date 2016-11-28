/*
 * =====================================================================================
 *
 *       Filename:  map.cc
 *
 *    Description:  program to implement hastable
 *
 *        Version:  1.0
 *        Created:  07/20/2016 15:59:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

void populateData(map<string, int> &data, unordered_map<string,int> &data2)
{
	data["Rakesh"] = 29;
	data["Pooja"] = 26;
	data["Malini"] = 49;
	data["Venkatesh"] = 58;
	data2["Rakesh"] = 29;
	data2["Pooja"] = 26;
	data2["Malini"] = 49;
	data2["Venkatesh"] = 58;
}

int main()
{
	map<string, int> family;
	unordered_map<string, int> family2;
	populateData(family, family2);
	map<string, int>::iterator it;
	unordered_map<string, int>::iterator it2;

	for (it = family.begin(); it != family.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	for (it2 = family2.begin(); it2 != family2.end(); it2++) {
		cout << it2->first << " " << it2->second << endl;
	}
	return 0;
}
