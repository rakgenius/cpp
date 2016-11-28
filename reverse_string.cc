#include <iostream>
#include <string>

using namespace std;

void reverse_string(string str1, string str2)
{
    str1 = str1 + str2;

    str2 = str1.substr(0, str1.length() - str2.length());
    str1 = str1.substr(str2.length());

    cout << str1 << "\t" << str2;
}

int main()
{
    string str1 = "Hello";
    string str2 = "world";

    reverse_string(str1, str2);
    return 0;
}
