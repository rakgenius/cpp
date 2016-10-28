#include <iostream>
#include <string>
using namespace std;
int compare_string(string str1, string str2)
{
    if (str1.length() == 0 || str2.length() == 0) {
        cout << "Versions cant be empty" << endl;
        return 2;
    }

    int vnum1 , vnum2 ;
    int i, j;
    vnum1 = vnum2 = 0;
    for (i=0, j=0; (i < str1.length() || j < str2.length()); i++, j++) {
        
        while ((i < str1.length()) && str1[i] != '.') {
            vnum1 = vnum1 * 10 + (str1[i] - '0');
            i++;
        }

        while ((j < str2.length()) && str2[j] != '.') {
            vnum2 = vnum2 * 10 + (str2[j] - '0');
            j++;
        }

        if (vnum1 < vnum2) {
            return -1;
        }
        if (vnum1 > vnum2) {
            return 1;
        }
        vnum1 = vnum2 = 0;
    }
    return 0;
}

int main()
{
    string str1 = "1.9.31";
    string str2 = "1.9.31";

    int ver = compare_string(str1, str2);

    switch (ver) {
        case 0:
            cout << "versions are equal\n";
            break;
        case 1:
            cout << "Version 2 is greater than version 1\n";
            break;
        case -1:
            cout << "Version 1 is greater than version 2\n";
            break;
        case 2:
            cout << "Invalid versions\n";
            break;
    }
    return 0;
}
