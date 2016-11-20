#include <iostream>
using namespace std;

int main()
{
    int n = 22;

    do {
        cout << n << endl;

        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    }while (n != 1);
    return 0;
}
