#include <iostream>
#include <climits>

using namespace std;

struct stackArray{
    unsigned int capacity;
    int top;
    int* arrayA;
};

bool isEmpty(int top){
    return top == -1;
}

bool isFull(int top, unsigned int capacity){
    return top == --capacity;
}


struct stackArray* createList(unsigned int capacity){
    struct stackArray *stuck = new struct stackArray;
    stuck->capacity = capacity;
    stuck->top = -1;
    stuck->arrayA = new int [capacity];
    return stuck;

}

struct stackArray* push(struct stackArray* stuck, int data){
    if(isFull(stuck->top, stuck->capacity)){
        cout<<"The stack is full"<<endl;
    }else{
        stuck->top++;
        stuck->arrayA[stuck->top] = data;
    }
    return stuck;
}

struct stackArray* pop(struct stackArray* stuck){
    if(isEmpty(stuck->top)){
        cout<<"The stack is empty"<<endl;
    }else{
        stuck->top--;
    }
    return stuck;
}

void peek(struct stackArray* stuck){
    if(isEmpty(stuck->top)){
        cout<<"The stack is empty"<<endl;
    }else{
        cout<<stuck->arrayA[stuck->top];
    }
}

int main(){

    struct stackArray* stuck = new stackArray;

    stuck = createList(5);
    stuck = push(stuck, 1);
    stuck = push(stuck, 2);
    stuck = push(stuck, 3);
    stuck = push(stuck, 4);
    stuck = push(stuck, 5);
    peek(stuck);

    return 0;
}
