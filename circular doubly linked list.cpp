#include <iostream>

using namespace std;

//global variable
int n;

//creating the node
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
//checking if the nodes are empty
bool isEmpty(struct node* tail){
    if(tail){
        return 0;
    }else{
        return 1;
    }
}

//counting the number of nodes
void countNodes(struct node* tail){
    if(isEmpty(tail)){
        n = 0;
    }else{
        n = 0;
        struct node* temp = tail->next;
        do{
            n++;
            temp = temp->next;
        }while(temp != tail->next);
    }
}

//displaying the nodes
void showNodes(struct node* tail){
    if(isEmpty(tail)){
        cout<<"The list is empty!!! There is nothing to show"<<endl;
    }else{
        struct node *temp = tail->next;
        do{
            cout<<temp->data;

            if(temp->next != tail->next){
                cout<<" -> ";
            }
            temp = temp->next;
        }while(temp != tail->next);
        temp = NULL;
    }
}

//adding a new node on the front of the list
struct node *addAtFront(struct node* tail, int data){
    if(isEmpty(tail)){
       tail = new struct node;
       tail->data = data;
       tail->prev = tail;
       tail->next = tail;
    }else{
        struct node* temp = new struct node;
        tail->next->prev = temp;
        temp->next = tail->next;
        temp->prev = tail;
        tail->next = temp;
        temp->data = data;
    }
    return tail;
}

//adding a new node at the end of the list
struct node* addAtEnd(struct node* tail, int data){
    if(isEmpty(tail)){
        tail = new struct node;
        tail->data = data;
        tail->next = tail;
        tail->prev = tail;
    }else{
        struct node* temp = new struct node;
        temp->prev = tail;
        temp->next = tail->next;
        tail->next = temp;
        temp->next->prev = temp;
        temp->data = data;
        tail = temp;
    }
    return tail;
}

//add at specific position
struct node* addAtPosition(struct node* tail, int data, int position){
    countNodes(tail);
    if(isEmpty(tail) && position>0){
        tail = new struct node;
        tail->data = data;
        tail->next = tail;
        tail->prev = tail;
        cout<<"The list was empty. We are going to add your element to the First position"<<endl;
    }else if(position == 1){
        tail = addAtFront(tail, data);
    }else if(position == n+1){
        tail = addAtEnd(tail, data);
    }else if(position <= n && position > 0){
        position--;
        struct node* temp = tail->next;
        while(position != 1){
            temp = temp->next;
            position--;
        }
        struct node* temp2 = new struct node;
        temp2->next = temp->next;
        temp->prev = temp;
        temp->next = temp2;
        temp2->next->prev = temp2;
        temp2->data = data;
    }else{
        cout<<"Error!!! There's No such position"<<endl;
    }
    return tail;
}

//deleting the front node
struct node* deleteAtFront(struct node* tail){
    if(isEmpty(tail)){
        cout<<"The list is already empty there is nothing to delete"<<endl;
    }else if(tail->next == tail){
        delete tail;
        tail = NULL;
    }else{
        struct node* temp = tail->next->next;
        delete temp->prev;
        temp->prev = tail;
        tail->next = temp;
        temp = NULL;
    }
    return tail;
}
//deleting the end node
struct node* deleteAtEnd(struct node* tail){
    if(isEmpty(tail)){
        cout<<"The list is empty!!! There is nothing to delete"<<endl;
    }else if(tail->next == tail){
        delete tail;
        tail = NULL;
    }else{
        struct node* temp = tail->prev;
        temp->next = tail->next;
        tail->next->prev = temp;
        delete tail;
        tail = temp;
    }
    return tail;
}
//deleting the specified node
struct node* deleteAtPosition(struct node* tail, int position){
    countNodes(tail);
    if(isEmpty(tail) && position > 0){
        cout<<"The list is empty and There is nothing to delete"<<endl;
    }else if(position == 1){
        tail = deleteAtFront(tail);
    }else if(position == n){
        tail = deleteAtEnd(tail);
    }else if(position < n && position > 0){
        struct node* temp = tail->next;
        position--;
        while(position != 1){
            temp = temp->next;
            position--;
        }
        struct node* temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        delete temp2;
        temp2 = NULL;
        temp = NULL;
    }
    return tail;
}

//reversing the list
struct node* reverseList(struct node* tail){
    if(isEmpty(tail)){
        cout<<"The list is Empty"<<endl;
    }else{
        struct node* temp = tail->next;
        struct node* previous = NULL;
        struct node* current = tail;
        struct node* next = NULL;

        while(temp->next != tail){
            temp = temp->next;
        }

        while(current != NULL){
            next = current->next;
            current->next = previous;
            current->prev = next;
            previous = current;
            current = next;
        }
        tail->prev = temp;

        while(temp->next != tail){
            temp = temp->next;
        }
        tail = temp;
    }
    return tail;
}
int main(){
    struct node* tail = NULL;
    tail = addAtEnd(tail, 1);
    tail = addAtEnd(tail, 2);
    tail = addAtEnd(tail, 3);
    tail = addAtEnd(tail, 4);
    showNodes(tail);
    cout<<endl<<"This is your reversed Circular doubly linked list"<<endl;
    tail = reverseList(tail);
    showNodes(tail);

    delete tail;
    tail = NULL;
    return 0;
}
