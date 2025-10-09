#include<bits/stdc++.h>
using namespace std;
class Node{ 
        public:
        int data;  
        Node* next; 
        Node* random;

        // constructor_1; used to initialise value of an obj
        public:
        Node(int data1,Node* next1, Node* random1){
            data=data1;
            next=next;
            random=random1;
        }
        // contructor_2
        public:
        Node(int data1){
            data=data1;
            next=nullptr;
            random=nullptr;
        }
};

// TC O(2N+2logN)
// SC (2N)
Node* replicatingLLwithRandomPtrs(Node* head){
    Node* temp=head;
    map<Node*,Node*>mpp;
    // creating copy of nodes with newnodes only and storing old nodes as keys.
    while(temp!=NULL){
        Node* newNode=new Node(temp->data);
        mpp[temp]=newNode; // (originalNode,replicaWithVal)
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        // linking the duplicate nodes to their destination in the original LL
        Node* copyNode=mpp[temp]; 
        copyNode->next=mpp[temp->next];
        copyNode->random=mpp[temp->random];
        temp=temp->next;
    }
    return mpp[head];
}

// optimized of CloningLL
Node* cloneLinkedList(Node* head) {
    Node* temp=head;
    // inserting copy nodes between original nodes with actual val diff addresses
    while(temp!=NULL){
        Node* newNode=new Node(temp->data);
        newNode->next=temp->next;
        temp->next=newNode;
        temp=temp->next->next;
    }
    
    temp=head;
    // connection random pts of the copy nodes as their parents
    while(temp!=NULL){
        if(temp->random) temp->next->random=temp->random->next;
        else temp->next->random=NULL;
        temp=temp->next->next;
    }
    
    temp=head;
    // connecting next ptrs with the help of dummy node & restoring original LL
    Node* dummyNode=new Node(-1);
    Node* res=dummyNode;
    while(temp!=NULL){
        res->next=temp->next;
        temp->next=temp->next->next;
        temp=temp->next;
        res=res->next;
    }
    return dummyNode->next;
        
    }

int main(){

}