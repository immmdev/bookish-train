#include<bits/stdc++.h>
using namespace std;

// Definition
// A Doubly Linked List (DLL) is a type of linked data structure in which:
// Each node contains three parts:
// Data – the actual information stored in the node.
// Pointer to the next node (called next).
// Pointer to the previous node (called prev).
// The nodes are connected both forward and backward, unlike a singly linked list where movement is only in one direction.
// The head pointer points to the first node, and the tail pointer usually points to the last node (whose next = NULL).

// doubly LL initiation
class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};


// creating doubly linked list from an array
Node* array2DoublyLL(vector<int>nums){
    Node* head=new Node(nums[0]);
    Node* prev=head;
    int n=nums.size();
    for(int i=1; i<n; i++){
        Node* temp=new Node(nums[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

// printing doubly linked list
void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* deleteAllOcurrances(Node* head,int k){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==k){
            Node* prevNode=temp->back;
            Node* frontNode=temp->next;
             if(temp==head) head=head->next;
            if(frontNode) frontNode->back=prevNode;
            if(prevNode) prevNode->next=frontNode;
            delete temp;
            temp=frontNode;
        } else{
            temp=temp->next;
        }
    }
    return head;
}

int main(){
//  test your code here
}