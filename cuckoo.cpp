#include <iostream>

using namespace std;

#define INT_MIN 0

#define SIZE 11
#define TABLE 2

class cuckoo_hashTable
{
    private:
        unsigned int hashTable[TABLE][SIZE];

    public:
        int pos[TABLE];
        void insert(int key, int tableId, int count, int max);
        void initTable();
        void displayTable();
        int hash(int pos, int key);
};

void cuckoo_hashTable::initTable()
{
    int i,j;

    for(i=0;i<TABLE;i++) {
        for (j=0;j<SIZE;j++) {
            hashTable[i][j] = INT_MIN;
        }
    }

}

int cuckoo_hashTable::hash(int pos, int key)
{
    switch(pos) {
    case 0: return key % SIZE;
    case 1: return (key / SIZE) % SIZE;
    }
}

void cuckoo_hashTable::insert(int key, int tableId, int count, int max)
{
    //if we have called insert multiple times then there existsa cycle
    //rehash the entire table
    if (count == max) {
        cout << "Cycle exists. Please rehash\n";
        return;
    }

    //get the hash value for the key and check if the value alreadu exists
    //for (int i = 0; i<TABLE; i++) {
        pos[tableId] = hash(tableId, key);
        if (key == hashTable[tableId][pos[tableId]]) {
            return;
        }
    //}

    //insert the key in the table
    if (hashTable[tableId][pos[tableId]] != INT_MIN) {
        int tmp = hashTable[tableId][pos[tableId]];
        hashTable[tableId][pos[tableId]] = key;
        insert(key, (tableId+1) % TABLE, count++, max);
    } else {
        hashTable[tableId][pos[tableId]] = key;
    }

}

void cuckoo_hashTable::displayTable()
{
    int i,j;

    for (i=0;i<TABLE;i++) {
        for (j=0;j<SIZE;j++) {
            (hashTable[i][j] == INT_MIN) ? cout << INT_MIN : cout <<hashTable[i][j];
            cout << "\t";
        }
        cout << "\n";
    }
}
int main()
{
    cuckoo_hashTable *hash = new cuckoo_hashTable();
    int array[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39, 6};

    hash->initTable();

    for( int i =0; i<10; i++) {
        hash->insert(array[i], 0, 1, SIZE);
    }

    hash->displayTable();
    return 0;
}
