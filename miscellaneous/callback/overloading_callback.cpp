#include <iostream>

typedef enum TypeTag {
    ADD,
    MUL,
    SUB,
    FIBO
} TypeTag;

typedef struct Node {
    TypeTag type;
    int result;
} Node;

int fibo(int x) {
    int *arr = new int[x];
    
    for(int i = 0; i < x; i++) {
        if(i < 1) arr[i] = 1;
        else arr[i] = arr[i-1] + arr[i-2];
    }
    
    return arr[x-2];
}

Node* add(int x, int y) {
    Node* result = new Node;
    result->type = ADD;
    result->result = x + y;
    return result;
}

Node* add(Node *x, Node* y) {
    Node* result = new Node;
    result->type = ADD;
    if(x == NULL || y == NULL) result->result = fibo(x == NULL ? y->result : x->result);
    else result->result = x->result + y->result;
    return result;
}

Node* sub(int x, int y) {
    Node* result = new Node;
    result->type = SUB;
    result->result = x - y;
    return result;
}

Node* sub(Node* x, Node* y) {
    Node* result = new Node;
    result->type = SUB;
    if(x == NULL || y == NULL) result->result = fibo(x == NULL ? y->result : x->result);
    else result->result = x->result - y->result;
    return result;
}

Node* mul(int x, int y) {
    Node* result = new Node;
    result->type = MUL;
    result->result = x * y;
    return result;
}

Node* mul(Node* x, Node* y) {
    Node* result = new Node;
    result->type = MUL;
    if(x == NULL || y == NULL) result->result = fibo(x == NULL ? y->result : x->result);
    else result->result = x->result * y->result;
    return result;
}


Node* ((*makeFuncInt(TypeTag type))(int, int)) {
    switch (type) {
        case ADD:
            return add;
        case SUB:
            return sub;
        case MUL:
            return mul;
        default:
            return nullptr;
    }
}

Node* ((*makeFuncNode(TypeTag type))(Node*, Node*)) {
    switch (type) {
        case ADD:
            return add;
        case SUB:
            return sub;
        case MUL:
            return mul;
        default:
            return nullptr;
    }
}

void calc(Node* result) {
    std::cout << result -> result << std::endl;
}

int main() {
    Node* add = (makeFuncInt(ADD)(10, 6));
    Node* mul = (makeFuncInt(MUL)(5, 4));
    Node* sub = (makeFuncNode(SUB)(mul, add));
    Node* fibo = (makeFuncNode(SUB)(sub, NULL));
    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);
    
}
