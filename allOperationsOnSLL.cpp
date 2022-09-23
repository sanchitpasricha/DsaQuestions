#include<iostream>
using namespace std;

//structure to create a linked list

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *second = NULL;

// create a linked list of array

void create(int A[], int s){
    struct Node *t;
    struct Node *last;
    
    first = new struct Node;
    first -> data = A[0];
    first -> next = NULL;
    last = first;

    for(int i=1 ; i<s ; i++){
        t = new struct Node;
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }   
}

//display a linked list

void display(struct Node *p){
    while(p){
        cout<< p->data <<" ";
        p = p -> next;
    }
}

//recursive display for Linked list

void recursiveDisplay(struct Node *p){
    if(p != NULL){
        cout<< p -> data <<" ";
        recursiveDisplay(p->next);
    }
}

//counting nodes of a linked list

int countingNodes(struct Node *p){
    int count=0;

    while(p){
        count++;
        p = p -> next;
    }   

    return count;

}

//sum of all nodes

int sumOfAllNodes(struct Node *p){
    int sum = 0;

    while(p){
        sum += p -> data;
        p = p -> next;
    }

    return sum;
}

//finding max element

int maxElement(struct Node *p){
    int max = INT_MIN;

    while(p){

        if(max < p -> data){
            max = p -> data;
        }

        p = p->next;
    }
    return max;
}

//searching in a linkedlist

int searchEle(struct Node *p, int key){
    while(p){
        if(p->data == key){
            return 1;
        }
        p = p->next;
    }
    return -1;
}

//creating LinkedList using inserting

void createUsingInsert(int val){
    struct Node *last;
    struct Node *t;

    t = new struct Node;
    t -> data = val;
    t -> next = NULL;

    if(second == NULL){
        last=second=t;
    }
    else{
        last -> next = t;
        last = t;
    }
}

//inserting in a linked list

void insertingInLL(struct Node *p, int index, int val){
    struct Node *q;

    if(!p){
        cout<<"Create a linked list first !";
    }
    else{
        struct Node *t;
        t = new struct Node;
        t -> data = val;
        t -> next = NULL;

        if(index == 0){
            p = t;
            p -> next = first;
            first = t;
        }
        else{
            for(int i=1; i<index; i++){
                p = p->next;
            }
            q = p->next;
            p -> next = t;
            t -> next = q;
            p = q;
        }
    }
}

//inserting in a sorted Linked List

void insertInSortedLL(struct Node *p, int val){
    struct Node *q;
    struct Node *t;

    t = new struct Node;
    t -> data = val;
    t -> next = NULL;

    if(first == NULL){
        first = t;
    }

    while(p && p->data < val){
            q = p;
            p = p -> next;            
        }
        if(p == first){
            t -> next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
    }
}

//deleting a node from Linked list

void deletingInLL(int val, struct Node *p){
    struct Node *q;

    if(p->data == val){
        q = p;
        p = p->next;
        delete(q);
    }

    while(p){
        if(p -> data != val){
            q = p;
            p = p->next;
        }
        else{
            q -> next = p -> next;
            q = p;
            p = p -> next;
            delete(q);
        }
    }
    
}

//checking if linked list is sorted or not

int checkSorted(struct Node *p){
    int x = INT_MIN;

    while(p){
        if(p->data < x){
            return -1;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

int main(){

    int Arr[11] = {1,2,3,4,5,6,7,8,9,12,11};
    create(Arr,11);
    // display(first);
    // recursiveDisplay(first);
    // countingNodes(first);
    // sumOfAllNodes(first);
    // maxElement(first);
    // searchEle(first, 12);
    // createUsingInsert(10);
    // createUsingInsert(20);
    // createUsingInsert(30);
    // display(second);
    // insertingInLL(first, 0, 15);
    // insertingInLL(first, 3, 22);
    // display(first);
    // insertInSortedLL(first, 13);
    // display(first);
    // deletingInLL(22, first);
    // display(first);
    // cout<< checkSorted(first);

    return 0;

}