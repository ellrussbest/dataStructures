#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

struct stackNode{
    int capacity;
    int top;
    char* str;
};

stackNode* createStack(int capacity){
    stackNode* newStack = new stackNode;
    newStack->capacity = capacity;
    newStack->top = -1;
    newStack->str = new char[capacity];

    return newStack;
}

bool isEmpty(int top){
    return top == -1;
}

bool isFull(int top, int capacity){
    return top == --capacity;
}

void push(stackNode* newStack, char data){
    if(!isFull(newStack->top, newStack->capacity)){
        newStack->top++;
        newStack->str[newStack->top] = data;
    }else{
        cout<<"The list is already Full"<<endl;
    }
}

stackNode* pop(stackNode* newStack){
    if(!isEmpty(newStack->top)){
        newStack->top--;
    }else{
        cout<<"This stack is empty!!!"<<endl;
    }
    return newStack;
}

char peek(stackNode* newStack){
    if(!isEmpty(newStack->top)){
        return newStack->str[newStack->top];
    }else{
        return '$';
    }
}

bool isOperand(char ch){
    return (ch >= '0' && ch<='9');
}

bool isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '^' || ch == '/');
}

bool isOpeningBracket(char ch){
    return (ch == '(');
}

bool isClosingBracket(char ch){
    return (ch == ')');
}

int precedence(char ch){
    switch(ch){
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
    }
    return -1;
}

string infixToPostfix(string expression){
    string expression2 = "";
    int i = 0;

    stackNode* newStack = createStack(expression.length());

    while(expression[i]){
        if(isOpeningBracket(expression[i]) || isClosingBracket(expression[i]) || isOperand(expression[i]) || isOperator(expression[i])){
            if(isOperand(expression[i])){
                expression2.push_back(expression[i]);
            }else if(isOpeningBracket(expression[i])){
                push(newStack, expression[i]);
            }else if(isClosingBracket(expression[i])){
                while(peek(newStack) != '('){
                    expression2.push_back(peek(newStack));
                    newStack = pop(newStack);
                }
                newStack = pop(newStack);
            }else if(isOperator(expression[i])){
               if(!isEmpty(newStack->top) || peek(newStack) == '('){
                push(newStack, expression[i]);
               }else{
                while(precedence(expression[i]) <= precedence(peek(newStack))){
                    expression2.push_back(peek(newStack));
                    newStack = pop(newStack);
                }
                push(newStack, expression[i]);
               }
            }
        }else{
            cout<<"Enter the correct value "<<endl;
            exit(1);
        }
        i++;
    }

    while(!isEmpty(newStack->top)){
        expression2.push_back(peek(newStack));
        newStack = pop(newStack);
    }
    return expression2;
}
int main(){
    string expression = "(1+2*3)^(4+6)-7/5/9";
    cout<<"The postfix expression for the following expression "<<expression<<"is:  "<< infixToPostfix(expression);
    return 0;
}

