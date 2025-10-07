#include<bits/stdc++.h>
using namespace std;
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


// printing doubly linked list
// TC O(2N)
void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* reverseLL3(Node* head){
    Node* temp=head;
    Node* back=NULL;
    while(temp!=NULL){
        Node* front=temp->next;
        temp->next=back;
        back=temp;
        temp=front;
    }
    return back;
}
Node* getKthNode(Node* temp, int k){
    int n=1;
    while(n<k && temp!=NULL){
        temp=temp->next;
        n++;
    }
    return temp;
}
Node* reverseInGroupOfk(Node* head,int k){
    Node* temp=head;
    Node* prevNode;
    while(temp!=NULL){
        Node* kthNode=getKthNode(temp,k);

        if(kthNode==NULL) {
            if(prevNode) prevNode->next=temp; // link the nodes if k elements group not found
            break;
        }
        Node* nextTriHead=kthNode->next; // preserving next kthGroup head before  makiking it NULL
        kthNode->next=NULL;
        reverseLL3(temp);
        if(temp==head) {
            head=kthNode;
        } else {
            prevNode->next=kthNode;
        }
        prevNode=temp; // preserving prev node so that we can attach to it after reversing the next KthGroup
        temp=nextTriHead;
    }
    return head;
}

int main(){
    // test your code
}
