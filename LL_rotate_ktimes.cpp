#include<bits/stdc++.h>
using namespace std;

// doubly LL initiation
using namespace std;

class Node{ 
        public:
        int data;  
        Node* next; 

        // constructor_1; used to initialise value of an obj
        public:
        Node(int data1,Node* next1){
            data=data1;
            next=next;
        }
        // contructor_2
        public:
        Node(int data1){
            data=data1;
            next=nullptr;
        }
};

// TC O(2N);
// SC O(N);
// rotating right; picking k elements from the back and sending them in front
Node* rotateLLKtimes(Node* head,int k){
    if(head==NULL || k==0) return head;
    Node* tail=head;
    int lengthLL=1;
    while(tail->next!=NULL){
        tail=tail->next;
        lengthLL++;
    }
    k=k%lengthLL;
    if(k==0) return head;

    // it k is not 0 then connect current tail to head
    tail->next=head;

    // newtail will be at
    int newTailAtPosition=lengthLL-k; // finding tail at kth position from back
    int n=1;
    Node* newTail=head;
    while(newTail!=NULL){
        if(n==k) return newTail;
        newTail=newTail->next;
        n++;

    }
    // getting new tail and head
    Node* newHead=newTail->next;
    newTail->next=NULL;
    return newHead;
}

int main(){
    // test your code
}