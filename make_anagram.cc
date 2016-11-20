#include <iostream>
#include <string>

using namespace std;

void make_anagram(string str1, string str2)
{
    if (str1.length() == 0)
        cout << "String 1 is empty" << endl;

    if (str2.length() == 0)
        cout << "String 2 is empty" << endl;

    int count1[26] = {0}, count2[26] = {0};

    for (int i = 0 ; i < str1.length(); i++)
        count1[str1[i] - 'a']++;

    for (int i = 0; i < str2.length(); i++)
        count2[str2[i] - 'a']++;

    int result;

    for (int i = 0; i < 26; i++)
        result += abs(count1[i] - count2[i]);

    cout << result << endl;
}

int main()
{
    string str1 = "bcadeh";
    string str2 = "hea";

    make_anagram(str1, str2);
    return 0;
}

