#include <iostream>
#include <string>
using namespace std;

int minimum(int x, int y, int z)
{
    return min(x, min(y, z));
}

int find_edit_distance(string str1, string str2, int n, int m)
{
    int i, j;
    int dp[n+1][m+1];

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m ; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }else {
                dp[i][j] = 1 + minimum(dp[i][j-1], dp[i-1][j],
                                   dp[i-1][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string str1 = "cat", str2 = "cut";

    cout << "edit distance is " << find_edit_distance(str1, str2, str1.length(), str2.length()) << endl;
    return 0;
}
