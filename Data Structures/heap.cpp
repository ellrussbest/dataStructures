// this is a min heap
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class MinHeap{
    int *harr; //pointer to array of elements in heap
    int capacity; //maximum possible size of min heap
    int heap_size; //current number of elements in min heap
    void decreaseKey(int i, int new_val); //util function

    public:
        MinHeap(int cap); //parameterized constructor
        ~MinHeap();
        int parent(int i); //Gets parent node
        int left(int i); //Gets left node
        int right(int i); //gets right node
        int getMin(); //gets minimum value (root node)
        int extractMin(); //Gets and removes minimum value(root node)
        void insertKey(int k); //insert new key/value/node
        void deleteKey(int i);
        void MinHeapify(int i);
        void linearSearch(int val);
        void printArray();
        int height();
};

MinHeap::MinHeap(int cap): heap_size(0), capacity(cap), harr(new int[cap]){}

MinHeap::~MinHeap(){
    delete[] harr;
}

void MinHeap::linearSearch(int val) {
    for ( int i = 0; i < heap_size; i++ ){
        if (harr[i] == val) {
            cout << "Value Found!\n";
            return;
        }
    }
    cout << "Value NOT found!" << endl;
}

void MinHeap::printArray(){
    for ( int i = 0; i < heap_size; i++ ) {
        cout << harr[i] << " ";
    }
    cout << "\n";
}

int MinHeap::height(){
    return ceil(log2(heap_size + 1)) - 1;
}

void MinHeap::insertKey(int k) {
    if ( heap_size == capacity ){
        cout << "Overflow: Heap full \n";
        return;
    }

    int i = heap_size++;
    harr[i] = k;

    while ( i != 0 && harr[parent(i)] > harr[i] ) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i); // return (i-1)/2
    }

}

int MinHeap::parent(int i) {
    return ( (i - 1)/2 );
}

int MinHeap::left(int i) {
    return (2*i + 1);
}

int MinHeap::right(int i) {
    return (2*i + 2);
}

int MinHeap::extractMin(){
    if (heap_size <= 0 ) return INT_MAX;
    if (heap_size == 1){
        heap_size--;
        return harr[0];
    }
    // Store the minimum value, and remove it from the heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return root;
}

void MinHeap::MinHeapify(int i){
    int l = left(i); //index of left child
    int r = right(i); //index of right child
    int smallest = i;

    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::getMin(){
    return harr[0];
}

void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;

    while ( i != 0 && harr[parent(i)] > harr[i] ) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

int main() {
    //take heap array size from user
    int s;
    cout << "Enter the size of the Min heap \n";
    cin >> s;

    MinHeap obj(s);

    //present heap operations using menu driven program
    int option, val;
    do{
        cout << "What operation do you want to perform? "
        <<" select Option number. Enter 0 to exit. \n";
        cout << "1. Insert Key/Node\n";
        cout << "2. Search Key/Node \n";
        cout << "3. Delete Key/Node \n";
        cout << "4. Get Min \n";
        cout << "5. Extract Min \n";
        cout << "6. Height of Heap \n";
        cout << "7. Print/Traversal Heap values \n";
        cout << "8. Clear screen \n";
        cout << "0. Exit Program \n";
        cin >> option;

        switch(option) {
            case 1:
                cout << "INSERT Operation - \n";
                cout << "Enter VALUE to INSERT in HEAP: ";
                cin >> val;
                obj.insertKey(val);
                cout << endl; break;
            case 2:
                cout << "SEARCH Operation -\n";
                cout << "Enter VALUE to SEARCH in HEAP: ";
                cin >> val;
                obj.linearSearch(val);
                break;
            case 3:
                cout << "DElETE Operation -\n";
                cout << "Enter INDEX of Heap Array to DELETE: ";
                cin >> val;
                obj.deleteKey(val);
                break;
            case 4:
                cout << "Get Min value: ";
                cout << obj.getMin() <<endl;
                break;
            case 5:
                cout << "EXTRACT Min value: ";
                cout << obj.extractMin() <<endl;
                break;
            case 6:
                cout << "HEAP TREE HEIGHT : ";
                cout << obj.height() << endl;
                break;
            case 7:
                cout << "PRINT  Heap Array: " <<endl;
                obj.printArray();
                break;
            case 8:
                system("clear");
                break;
            case 0:
                break;
            default:
                cout << "Enter Proper Option number \n";
        }

    }while(option != 0);

    //perform heap operations
    return 0;
}
