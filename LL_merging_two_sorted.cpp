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

// merging two LL in ascending order as they are separately in ascending too;
// TC O(N1+N2)
// SC O(1)
Node* mergeTwoSortedLL(Node* head1, Node* head2){
    Node* t1=head1;
    Node* t2=head2;
    // new linkedList will start from here
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode; // used to create new linkedList 
    while(t1!=NULL && t2!=NULL){
        if(t1->data<t2->data){
            temp->next=t1;
            temp=t1;
            t1=t1->next;
        } else {
            temp->next=t2;
            temp=t2;
            t2=t2->next;
        }
    }

    if(t1) temp->next=t1;
    if(t2) temp->next=t2;
    return dummyNode->next; 
}

int main(){
    // test your code
}