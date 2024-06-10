#include <iostream>
#include <list>
#include <cmath>

using namespace std;

class HashMapTable {
    int table_size;
    list<pair<int, int>> *table;

public:
    HashMapTable(int ts);
    int hashFunction1(int key);
    int hashFunction2(int key);
    int hashFunction3(int key);
    void insertElement(int key, int value);
    void deleteElement(int key);
    void displayHashTable();
};

HashMapTable::HashMapTable(int ts) {
    this->table_size = ts;
    table = new list<pair<int, int>>[table_size];
}

int HashMapTable::hashFunction1(int key) {
    return floor((key/22.5) * table_size);
}

int HashMapTable::hashFunction2(int key) {
    return (key % table_size);
}

int HashMapTable::hashFunction3(int key) {
    double A = (sqrt(5) - 1) / 2;
    return static_cast<int>(table_size * fmod(key * A, 1));
}

void HashMapTable::insertElement(int key, int value) {
    int index;
    // Choose hash function based on your preference
    // Uncomment the line corresponding to the desired hash function
     //index = hashFunction1(key);
     //index = hashFunction2(key);
    index = hashFunction3(key);

    table[index].push_back(make_pair(key, value));
}

void HashMapTable::deleteElement(int key) {
    int index;
    // Choose hash function based on your preference
    // Uncomment the line corresponding to the desired hash function
    // index = hashFunction1(key);
    // index = hashFunction2(key);
    index = hashFunction3(key);

    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == key) {
            table[index].erase(it);
            break;
        }
    }
}

void HashMapTable::displayHashTable() {
    for (int i = 0; i < table_size; i++) {
        cout << i;
        for (auto entry : table[i]) {
            cout << " ==> (" << entry.first << ", " << entry.second << ")";
        }
        cout << endl;
    }
}

int main() {
    HashMapTable ht(10);

    // Inserting elements into the hash table
    ht.insertElement(2, 20);
    ht.insertElement(12, 120);
    ht.insertElement(7, 70);
    ht.insertElement(18, 180);
    ht.insertElement(22, 220);
    ht.insertElement(16, 210);
    ht.insertElement(19, 190);
    ht.insertElement(3, 130);
    ht.insertElement(8, 80);
    ht.insertElement(15, 140);
    ht.insertElement(21, 230);

    // Deleting an element from the hash table
    ht.deleteElement(7);

    // Displaying the final data of the hash table
    ht.displayHashTable();

    return 0;
}
