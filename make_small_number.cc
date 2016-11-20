#include <iostream>
using namespace std;

int make_small_number(int number)
{
    int array[10] = {0};

    while (number) {
        int rem = number % 10;
        array[rem]++;
        number = number / 10;
    }

    int result;

    for (int i = 1; i <= 9; i++) {
        if (array[i] > 0) {
            result = array[i];
            array[i]--;
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        while (array[i] > 0) {
        result = result * 10 + i;
        array[i]--;
        }
    }

    return result;
}

int main()
{
    int number = 570107;
    cout << make_small_number(number) << endl;
    return 0;
}
