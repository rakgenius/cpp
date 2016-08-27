#include <iostream>
#include <string>
using namespace std;

int
lcs(char *a, char *b, int m, int n)
{
    int lcs[m+1][n+1];

    for (int i=0; i <= m; i++) {
        for (int j =0; j <= n; j++) {
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
            } else {
                if (a[i-1] == b[j-1]) {
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
    }

    return lcs[m][n];
}

int main()
{
    char a[] = "abcd";
    char b[] = "abdc";

    int i = lcs(a, b, strlen(a), strlen(b));
    cout << i << endl;
    return 0;
}
