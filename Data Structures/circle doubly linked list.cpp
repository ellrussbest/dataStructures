#include <iostream>

using namespace std;

//global variable
int n;

//creating our node
struct node{
    int data;
    struct node* next;
};

//checking if your linked list is empty
bool isEmpty(struct node* tail){
    if(tail){
        return 0;
    }else{
        return 1;
    }
}

//counts the number of nodes in your linked list
void countNodes(struct node* tail){
    if(isEmpty(tail)){
        n = 0;
    }else{
        n = 1;
        struct node* temp = tail;
        while(temp->next != tail){
            n++;
            temp = temp->next;
        }
    }
}

//displays the nodes in your linked list
void showNodes(struct node* tail){
    if(isEmpty(tail)){
        cout<<"The list is emtpy!! There is nothing to show"<<endl;
    }else{
        struct node* temp = tail;
        while(temp->next != tail){
            cout<<temp->next->data<<" -> ";
            temp = temp->next;
        }
        cout<<temp->next->data;
        temp = NULL;
    }
}

//adds a new node on the front of the list
struct node* addAtFront(struct node* tail, int data){
    if(isEmpty(tail)){
        tail = new struct node;
        tail->data = data;
        tail->next = tail;
    }else{
        struct node* temp = new struct node;
        temp->data = data;
        temp->next = tail->next;
        tail->next = temp;
    }
    return tail;
}

//adds a new node at the end of the list
struct node* addAtEnd(struct node* tail, int data){
    if(isEmpty(tail)){
        tail = new struct node;
        tail->data = data;
        tail->next = tail;
    }else{
        struct node* temp = new struct node;
        temp->data = data;
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
    return tail;
}

//adds a node at a position specified by the user
struct node* addAtPosition(struct node* tail, int data, int position){
    countNodes(tail);

    if(isEmpty(tail) && position > 0){
        cout<<"The list is Empty hence we are going to add your value at the first position"<<endl;
        tail = new struct node;
        tail->data = data;
        tail->next = tail;
    }else if(position == 1){
        tail = addAtFront(tail, data);
    }else if(position == n+1){
        tail = addAtEnd(tail, data);
    }else if(position <= n && position > 0){
        struct node* temp = tail;
        while(position != 1){
            temp = temp->next;
            position--;
        }
        struct node* temp2 = new struct node;
        temp2->data = data;
        temp2->next = temp->next;
        temp->next = temp2;
        temp = NULL;
        temp2 = NULL;
    }else{
        cout<<"Error!! Please Enter the correct position!!"<<endl;
    }
    return tail;
}

//deleting the front node
struct node* deleteAtFront(struct node* tail){
    if(isEmpty(tail)){
        cout<<"The list is Empty and there is nothing to delete"<<endl;
    }else if(tail->next == tail){
        delete tail;
        tail = NULL;
    }else{
        struct node* temp = tail;
            temp = temp->next;
            tail->next = temp->next;
            delete temp;
            temp = NULL;
    }
    return tail;
}

//deleting the end node
struct node* deleteAtEnd(struct node* tail){
    if(isEmpty(tail)){
        cout<<"The list is already empty!!!"<<endl;
    }else if(tail->next == tail){
        delete tail;
        tail = NULL;
    }else{
        struct node* temp = tail;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = tail->next;
        delete tail;
        tail = temp;
    }
    return tail;
}

//deleting a node at a specific position
struct node* deleteAtPosition(struct node* tail, int position){
    countNodes(tail);

    if(isEmpty(tail) && position > 0){
        cout<<"This list is empty!!"<<endl;
    }else if(position == 1){
        tail = deleteAtFront(tail);
    }else if(position == n){
        tail = deleteAtEnd(tail);
    }else if(position < n && position > 0){
        struct node* temp = tail;
        while(position != 1){
            temp = temp->next;
            position--;
        }
        struct node* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        temp2 = NULL;
        temp = NULL;
    }else{
        cout<<"Error!! Please Enter an existing position"<<endl;
    }
    return tail;
}

//reversing the list
struct node* reverseList(struct node* tail){
    if(isEmpty(tail)){
        cout<<"The list is empty!!!"<<endl;
    }/*else if(tail->next == tail){
    }*/else{
        struct node* temp = tail;

        while(temp->next != tail){
            temp = temp->next;
        }

        struct node* next = NULL;
        struct node* current = NULL;
        struct node* prev = NULL;
        current = tail;

        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        while(temp->next != tail){
            temp = temp->next;
        }
        tail = temp;
    }
    return tail;
}
//searching an element

int main()
{
    struct node* tail = NULL;

    tail = addAtFront(tail, 2);
    tail = addAtFront(tail, 1);
    tail = addAtFront(tail, 0);
    tail = addAtEnd(tail, 3);
    tail = addAtEnd(tail, 4);
    tail = addAtEnd(tail, 5);
    cout<<"This is your List"<<endl;
    showNodes(tail);
    cout<<endl<<"This is your reversed linked list"<<endl;
    tail = reverseList(tail);
    showNodes(tail);
    delete tail;
    tail = NULL;

    return 0;
}
