#include <iostream>
#include <unordered_map>
using namespace std;
int find_subset(int arr1[], int arr2[], int m, int n)
{
    unordered_map <int, bool> hash;
    int i;

    for (i = 0; i < m;i++) {
        hash[arr1[i]] = true;
    }

    for (i =0; i < n; i++) {
        if (hash.find(arr2[i]) == hash.end()) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int arr1[] = { 1, 2, 3,4,5,6};
    int arr2[] = {9,3,5};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    if (find_subset(arr1, arr2, m , n)) {
        cout << "It is subset" << endl;
    } else {
        cout << "Its not a subset" << endl;
    }
    return 0;
}
