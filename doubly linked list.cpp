#include <iostream>

using namespace std;
int n;

//creating the node for the doubly linked list
struct node{
    struct node* previous;
    int data;
    struct node* next;
};

//checks whether the link is empty
bool isEmpty(struct node* head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

//count nodes
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
        cout<<"The list is empty!! There is nothing to show"<<endl;
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
struct node *addAtFront(struct node* head, int data){
    if(isEmpty(head)){
        head = new struct node;
        head->previous = NULL;
        head->data = data;
        head->next = NULL;
    }else{
        head->previous = new struct node;
        head->previous->previous = NULL;
        head->previous->data = data;
        head->previous->next = head;
        head = head->previous;
    }
    return head;
}

//adding a new node at the end
struct node* addAtEnd(struct node* head, int data){
    if(isEmpty(head)){
        head = new struct node;
        head->previous = NULL;
        head->data = data;
        head->next = NULL;
    }else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new struct node;
        temp->next->previous = temp;
        temp->next->data = data;
        temp->next->next = NULL;
        temp = head;
    }
    return head;
}

//adding a node at a certain position
struct node* addAtPosition(struct node* head, int data, int position){
    countNodes(head);
    if(isEmpty(head)){
        head = new struct node;
        head->previous = NULL;
        head->data = data;
        head->next = NULL;
        cout<<"The list was empty so we added it to the first position"<<endl;
    }else if(position == 1){
        head->previous = new struct node;
        head->previous->previous = NULL;
        head->previous->data = data;
        head->previous->next = head;
        head = head->previous;
    }else if((position <= n+1) && position > 1){
        position--;
        struct node* temp = head;
        while(position != 1){
            temp = temp->next;
            position--;
        }
        struct node* temp2 = new struct node;
        temp2->next = temp->next;
        temp->next = temp2;
        temp2->previous = temp;
        if(temp2->next != NULL){
            temp2->next->previous = temp2;
        }
        temp2->data = data;
        temp = NULL;
        temp2 = NULL;
    }else{
        cout<<"The operation cannot be done!!! There is no such position"<<endl;
    }
    return head;
}

//deleting the front node
struct node* deleteAtFront(struct node* head){
    if(isEmpty(head)){
        cout<<"The list is already empty!! There is nothing to delete"<<endl;
    }else if(head->next == NULL){
        delete head;
        head = NULL;
    }else{
        struct node* temp = head;
        temp = temp->next;
        temp->previous = NULL;
        delete head;
        head = temp;
    }
    return head;
}

//deleting the end node
struct node* deleteAtEnd(struct node* head){
    if(isEmpty(head)){
        cout<<"The list is Emtpy!! There is nothing to Delete"<<endl;
    }else if(head->next == NULL){
        delete head;
        head = NULL;
    }else{
        struct node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    return head;
}

//deleting at a certain position
struct node* deleteAtPosition(struct node* head, int position){
    countNodes(head);
    if(isEmpty(head)){
        cout<<"This list is empty and the operation cannot be done!!"<<endl;
    }else if(position == 1){
        head = deleteAtFront(head);
    }else if((position <= n) && position > 1){
        position--;
        struct node* temp = head;
        while(position != 1){
            temp = temp->next;
            position--;
        }
        struct node* temp2 = temp->next;
        temp->next = temp2->next;
        if(temp2->next != NULL){
            temp2->next->previous = temp;
        }
        delete temp2;
        temp2 = NULL;
    }else{
        cout<<"This operation cannot be done!!! There is no such position "<<endl;
    }
    return head;
}

//reversing the list
struct node* reverseList(struct node* head){
    if(isEmpty(head)){
        cout<<"The list is empty!! There is nothing to reverse"<<endl;
    }else{
        struct node* prev = NULL;
        struct node* foward = head;

        while(head != NULL){
            foward = head->next;
            head->previous = foward;
            head->next = prev;
            prev = head;
            head = foward;
        }
        head = prev;
    }
    return head;
}
int main()
{
    struct node* head = NULL;
    head = addAtEnd(head, 1);
    head = addAtEnd(head, 2);
    head = addAtEnd(head, 3);
    head = addAtPosition(head, 4, 4);
    head = addAtPosition(head, 5, 5);
    head = addAtPosition(head, 6, 6);
    head = addAtFront(head, 0);
    cout<<"Here is how your Doubly Linked list looks like"<<endl<<endl;
    showNodes(head);
    cout<<endl<<endl<<"The reversed list is as follows"<<endl<<endl;
    head = reverseList(head);
    showNodes(head);
    cout<<endl;
    delete head;
    head = NULL;

    return 0;
}

