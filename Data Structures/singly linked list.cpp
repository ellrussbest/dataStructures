#include <iostream>

using namespace std;
int n;

struct node{
    int data;
    struct node *next;
};

//checking if your linked list is empty
bool isEmpty(struct node *head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

//counting the nodes
void countNodes(struct node* head){
    if(isEmpty(head)){
        n = 0;
    }else{
        n = 0;
        struct node* temp = head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
    }
}
//displaying the nodes
void showNodes(struct node* head){
    if(isEmpty(head)){
        cout<<"The linked list is empty!!"<<endl;
    }else{
        struct node* temp = head;
        while(temp != NULL){
            cout<<temp->data;
            if(temp->next != NULL){
                cout<<" -> ";
            }
            temp = temp->next;
        }
    }
}
//adding a new node at the front
struct node* addAtFront(struct node* head, int d){
    struct node * temp = NULL;

    if(isEmpty(head)){
        head = new struct node;
        head->data = d;
        head->next = NULL;
    }else{
        temp = new struct node;
        temp->data = d;
        temp->next = head;
        head=temp;
    }

    return head;
}
//adding a new node at the end
struct node *addAtEnd(struct node *head, int data){
    if(isEmpty(head)){
        head = new struct node;
        head->data = data;
        head->next = NULL;
    }else{
        struct node *temp = head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = new struct node;
        temp->next->data = data;
        temp->next->next = NULL;
        temp = NULL;

    }
    return head;
}

//adding a node at a certain position
struct node* addAtPosition(struct node* head, int data, int pos){
    countNodes(head);
    if(isEmpty(head)){
        head = addAtFront(head, data);
        cout<<"the list was empty hence your data will be put in the first position"<<endl;
    }else if(pos == 1){
        addAtFront(head, data);
    }else if((pos<=n+1) && pos > 1){
        pos--;
        struct node* temp = head;
        while(pos != 1){
            temp = temp->next;
            pos--;
        }
        struct node *temp2 = new struct node;
        temp2->data = data;
        temp2->next = temp->next;
        temp->next = temp2;
        temp = NULL;
        temp2 = NULL;

    }else{
        cout<<"This operation cannot be done!!! There is no such position"<<endl;
    }
    return head;
}

//deleting the Front Node

struct node* deleteAtFront(struct node* head){
    if(isEmpty(head)){
        cout<<"The list is already empty"<<endl;
    }else{
        struct node *temp = head;
        temp = temp->next;
        delete head;
        head = temp;
    }
    return head;
}

//deleting the End Node

struct node* deleteAtEnd(struct node* head){
    if(isEmpty(head)){
        cout<<"The linked list is already Empty"<<endl;
    }else{
        struct node* temp = head;

        while(temp->next->next != NULL){
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        temp = NULL;
    }
    return head;
}

//deleting at a certain position
struct node* deleteAtPosition(struct node* head, int pos){
    countNodes(head);
    if(isEmpty(head)){
        cout<<"The list is already empty"<<endl;
    }else if(pos == 1){
        if(head->next == NULL){
            delete head;
            head = NULL;
        }else{
            struct node* temp = head;
            temp = temp->next;
            delete head;
            head = temp;
        }
    }else if((pos <= n) && pos >1){
        pos--;
        struct node* temp = head;
        while(pos != 1){
            temp = temp->next;
            pos--;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        temp2 = NULL;
    }else{
        cout<<"This operation cannot be completed!!! There is no such position"<<endl;
    }
    return head;
}
//reversing the list
struct node* reverseList(struct node *head){
    if(isEmpty(head)){
        cout<<"This list is empty and cannot be reversed"<<endl;
    }else{
        struct node* prev = NULL;
        struct node* next = NULL;

        while(head != NULL){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
    }
    return head;
}
int main()
{
    struct node *head = NULL;
    head = addAtFront(head, 3);
    head = addAtFront(head, 2);
    head = addAtFront(head, 1);
    head = addAtEnd(head, 4);
    head = addAtEnd(head, 5);
    head = addAtEnd(head, 6);
    head = addAtEnd(head, 7);
    cout<<"Here is your singly linked list"<<endl<<endl;
    showNodes(head);
    cout<<endl<<endl;
    cout<<"The reversed linked list is as follows"<<endl<<endl;
    head = reverseList(head);
    showNodes(head);
    cout<<endl;
    delete head;
    head = NULL;

    return 0;
}
