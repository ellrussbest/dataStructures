#include <iostream>
#include <list>
#include <cstring>

using namespace std;

//hashtable to implement 905, jimmy

class HashTable {
    private:
        static const int hashGroups = 10;
        list<pair<int, string>>table[hashGroups];
    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();

};

bool HashTable::isEmpty() const{
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }

    if (!sum) return true;
    return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups;
}

void HashTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for ( ; bItr != end(cell); bItr++ ) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] Key exists. Value replaced. " << endl;
            break;
        }
    }

    if (!keyExists) cell.emplace_back(key, value);
    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for ( ; bItr != end(cell); bItr++ ) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Pair removed. " << endl;
            break;
        }
    }

    if (!keyExists) cout << "[WARNING] Key not found. Pair not removed." << endl;

    return;
}

void HashTable::printTable() {
    for (int i{}; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            cout << "[INFO] Key: " << bItr->first << " Value: " << bItr->second << endl;
        }
    }

    return;
}

int main() {
    HashTable HT;

    if (HT.isEmpty()) cout << "Correct answer. Good job. " << endl;
    else cout << "Oh oh. we need to check out code!" << endl;

    HT.insertItem(905, "Jim");
    HT.insertItem(201, "Tom");
    HT.insertItem(332, "Bob");
    HT.insertItem(124, "Sally");
    HT.insertItem(107, "Sandy");
    HT.insertItem(929, "Barb");
    HT.insertItem(928, "Rob");
    HT.insertItem(928, "Rick");

    HT.printTable();

    HT.removeItem(332);
    HT.removeItem(100);

    if (HT.isEmpty()) cout << "Oh oh. We need to check out code! " << endl;
    else cout << "Correct answer! Good job! " << endl;
    return 0;
}
